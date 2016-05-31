#ifndef INCLUDE_GUARD
#define INCLUDE_GUARD

#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void print(std::string msg) {
   std::cout << msg;
}

void println(std::string msg) {
   std::cout << msg << std::endl;
}

void print(int i_msg) {
   std::cout << i_msg;
}

void println(int i_msg) {
   std::cout << i_msg << std::endl;
}

void print(float f_msg) {
   std::cout << f_msg;
}

void println(float f_msg) {
   std::cout << f_msg << std::endl;
}
#endif
