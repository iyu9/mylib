#include "math.h"

math::math() {

}

math::~math() {

}

int cut_lower(int val, int lower_lim)
{
  if (val < lower_lim)
  {
	val = lower_lim;
  }
}

int cut_upper(int val, int upper_lim)
{
  if (val > upper_lim)
  {
	val = upper_lim;
  }
}

int cut_area(int val, int lower_lim, int upper_lim)
{ 
  if (val < lower_lim)
  {
	val = lower_lim;
  }

  if (val > upper_lim)
  {
	val = upper_lim;
  }
}

/**/
int main() {
  math* m = new math();

  return 0;
}
/**/
