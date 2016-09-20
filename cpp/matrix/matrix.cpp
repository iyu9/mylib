#include "matrix.h"

matrix::matrix()
{ 
    this->size_x = 100;
    this->size_y = 100;
}

matrix::matrix(int size_x, int size_y)
{
    this->size_x = size_x;
    this->size_y = size_y;
}

matrix::~matrix(){}

void matrix::print()
{
    for(int j = 0; j < size_y; j++)
	{
        for(int i = 0; i < size_x; i++)
		{
                std::cout << this->val[i][j] << ", ";
        }
        std::cout << std::endl;
    }        
}

void matrix::clear()
{
    for(int j = 0; j < size_y; j++)
	{
        for(int i = 0; i < size_x; i++)
		{
             val[i][j] = 0;
        }
    }        
}

/**/
int main()
{
    matrix* mat = new matrix(10, 10);
    mat->print(); 

    return 0;        
}
/**/
