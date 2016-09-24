#ifndef INCLUDE_GUARD
#define INCLUDE_GUARD

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define LENGTH(array) (sizeof(array) / sizeof(array[0]) )
#define FOR(i, until) for(int i = 0; i < until; i++)

void clear()
{
   system("clear"); 
}

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
