#include "rect.h"

rect::rect()
{
    x = y = w = h = 0;
}

rect::~rect()
{

}

rect::rect(int x_, int y_, float w_, float h_)
{
    x = x_;
    y = y_;
    w = w_;
    h = h_;
}

rect::rect(float w_, float h_)
{
    w = w_;
    h = h_;        
}

void rect::set_position(int x_, int y_)
{
    x = x_;
    y = y_;
}

void rect::set_size(float w_, float h_)
{
    w = w_;
    h = h_;  
}

/**/
int main()
{
  rect* r = new rect();

  return 0;
}
/**/
