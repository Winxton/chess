#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include <sstream>
#include "window.h"

using namespace std;

void setBoardBackground();
void setCoordinates();


Xwindow::Xwindow(int width, int height) {

  d = XOpenDisplay(NULL);
  if (d == NULL) {
    cerr << "Cannot open display" << endl;
    exit(1);
  }
  s = DefaultScreen(d);
  w = XCreateSimpleWindow(d, RootWindow(d, s), 10, 10, width, height, 1,
                          BlackPixel(d, s), WhitePixel(d, s));
  XSelectInput(d, w, ExposureMask | KeyPressMask);
  XMapRaised(d, w);

  Pixmap pix = XCreatePixmap(d,w,width,
        height,DefaultDepth(d,DefaultScreen(d)));
  //fontinfo = XLoadQueryFont(d,"6x10");
  gc = XCreateGC(d, pix, 0,(XGCValues *)0);

  XFlush(d);
  XFlush(d);

  // Set up colours.
  XColor xcolour;
  Colormap cmap;
  char color_vals[10][10]={"black", "white", "red", "blue", "cyan", "yellow", "magenta", "orange", "burlywood", "peru"};

  cmap=DefaultColormap(d,DefaultScreen(d));
  for(int i=0; i < 10; ++i) {
      if (!XParseColor(d,cmap,color_vals[i],&xcolour)) {
         cerr << "Bad colour: " << color_vals[i] << endl;
      }
      if (!XAllocColor(d,cmap,&xcolour)) {
         cerr << "Bad colour: " << color_vals[i] << endl;
      }
      colours[i]=xcolour.pixel;
  }

  XSetForeground(d,gc,colours[Black]);

  // Make window non-resizeable.
  XSizeHints hints;
  hints.flags = (USPosition | PSize | PMinSize | PMaxSize );
  hints.height = hints.base_height = hints.min_height = hints.max_height = height;
  hints.width = hints.base_width = hints.min_width = hints.max_width = width;
  XSetNormalHints(d, w, &hints);

  XSynchronize(d,True);

  //setCoordinates();
  setBoardBackground();
}

Xwindow::~Xwindow() {
  XFreeGC(d, gc);
  XCloseDisplay(d);
}

void Xwindow::fillRectangle(int x, int y, int width, int height, int colour) {
  XSetForeground(d, gc, colours[colour]);
  XFillRectangle(d, w, gc, x, y, width, height);
  XSetForeground(d, gc, colours[Black]);
}

void Xwindow::drawString(int x, int y, string msg, int colour) {
  XSetForeground(d, gc, colours[colour]);
  XDrawString(d, w, gc, x, y, msg.c_str(), msg.length());
  XSetForeground(d, gc, colours[Black]);
  XFlush(d);
}

void Xwindow::removePiece(int col,int row){
	if ((col%2 == 0 && row%2 == 0) || (col%2 == 1 && row%2 == 1))
		fillRectangle(col*squareLength+30,squareLength*7-row*squareLength,squareLength,squareLength,9);
       else
		fillRectangle(col*squareLength+30,squareLength*7-row*squareLength,squareLength,squareLength,8);
}

void Xwindow::putPiece(int col, int row, string piece){
	drawString(52+col*squareLength, 380-row*squareLength, piece, 0);
}

void Xwindow::setBoardBackground(){
    usleep(10000);
    for (int row = 7; row >= 0; row--) {
        for (int col = 0; col <=7; col++) {
            if ((col%2 == 0 && row%2 == 0) || (col%2 == 1 && row%2 == 1))
		fillRectangle(col*squareLength+30,row*squareLength,squareLength,squareLength,8); //burlywood colour
	     else
		fillRectangle(col*squareLength+30,row*squareLength,squareLength,squareLength,9); //peru colour
        }
    }
	setCoordinates();
}

void Xwindow::setCoordinates(){
	stringstream s;
	for (int i = 8 ; i>0;i--){
		s << i;
		drawString(12, 30+squareLength*(8-i), s.str(), 0);
		s.str("");
	}
	for (int i = 1 ; i<9;i++){
		s << char(i + '`');
		drawString(2+squareLength*i, 415, s.str(), 0);
		s.str("");
	}
}

void Xwindow::clearBoardBackground(){
    XClearWindow(d,w);
}