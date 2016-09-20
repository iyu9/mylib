#include "../common/common.h"

class matrix
{
private:
    int size_x;
    int size_y;

public:
    float val[100][100];

    matrix();
    matrix(int size_x, int size_y);
    ~matrix();

    void clear();
    void print();
};
