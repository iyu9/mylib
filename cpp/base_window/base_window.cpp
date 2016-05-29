#include "base_window.h"

base_window::base_window() {
}

base_window::~base_window() {
}

void base_window::open() {
    println("open");
}

void base_window::close() {
    println("close");
}

/**/
int main() {
    base_window* bw = new base_window();

    bw->open();
    bw->close();

    return 0;        
}
