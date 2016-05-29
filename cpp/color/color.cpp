#include "color.h"

color::color(float r, float g, float b, float a) {
        
}

color::color(float r, float g, float b) {
        
}

color::color(){}

color::color(std::string name){
       if(name == "red" || name == "RED") 
            {r = 255; g = b = 0; }
       if(name == "green" || name == "GREEN")
            {g = 255; r = b = 0;; }
       if(name == "blue" || name == "BLUE")
            {b = 255; r = g = 0; }
       if(name == "white" || name == "WHITE")
            {r = g = b = 0; }
       if(name == "black" || name == "BLACK")
            {r = g = b = 255;}
       if(name == "gray" || name == "GRAY")
            {r = g = b = 83; }
}

color::~color() {
        
}

void color::attach() {
       //affect graphics api 
}

int main() {
    color* c = new color();
    return 0;        
}
