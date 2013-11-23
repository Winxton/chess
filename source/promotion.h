#ifndef __PROMOTION_H__
#define __PROMOTION_H__

class Promotion : public ChessMove 
{
 public:
    void apply (Gamestate* state);
};

#endif
