#include "base_window.h"

base_window::base_window()
{
}

base_window::~base_window()
{
}

void base_window::open()
{
    println("open");
}

void base_window::open(void(callback()))
{
    println("open");
    callback();
}

void base_window::close()
{
    println("close");
}

void base_window::close(void(callback()))
{
    println("close");
    callback();
}

void Test_CallBack()
{
    println("TEST_CALLBACK");        
}

/**/
int main()
{
    base_window* bw = new base_window();

    bw->open(Test_CallBack);
    bw->close(Test_CallBack);

    return 0;        
}
