#include "../common/common.h"

/*
 * 境界内の値を得る
 */
float cut(float val, float lower, float upper)
{
    if (val < lower)
    {
        return lower;
    }

    if (val > upper)
    {
        return upper;
    }

    return val;
}

/*
 * 値の境界判定
 */
bool is_between(float val, float lower, float upper)
{
    if (val < lower)
    {
        return false;
    }

    if (val > upper)
    {
        return false;
    }

    return true;
}

/**/
int main()
{ 
    int cut_test = cut(180, 170, 190);
    bool is_between_test = is_between(180, 170, 190);
 
    std::cout << cut_test << std::endl;

    return 0;
}
/**/
