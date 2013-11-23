#ifndef __ENPASSENT_H__
#define __ENPASSENT_H__

class EnPassent : public ChessMove 
{
 public:
    void apply (Gamestate* state);
};

#endif
