#ifndef __RESIGN_H__
#define __RESIGN_H__

class Resign : public Action 
{
 public:
    void apply (Gamestate* state);
};

#endif
