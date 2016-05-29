#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

/*
 * Auto C++ template header-class generator
 *
 * written by tomii
 */
int main (int argc, char** argv) {

    //check param
    if(argc != 2) {
        std::cout << "Argument error" << std::endl;
        std::cout << "Usage: " << argv[0] << " <class name>" << std::endl;
        return 1;
    }

    std::string arg = argv[1];
    std::string h = arg + ".h";
    std::string c = arg + ".cpp";

    const char* header_name = h.c_str();
    const char* source_name = c.c_str();

    //.h
    std::ofstream ofs;
    ofs.open(header_name);
    ofs << "#include \"" << arg << ".h\"" << std::endl << std::endl;
    ofs << "class " << arg << " {" << std::endl; 
    ofs << "private:" << std::endl << std::endl;
    ofs << "public:" << std::endl;
    ofs << "  " << arg << "();" << std::endl;
    ofs << "  " << "~" << arg << "();" << std::endl;
    ofs << "};" << std::endl;
    ofs.close();

    //.cpp
    ofs.open(source_name);
    ofs << "#include \"../common/common.h\"" << std::endl << std::endl;
    ofs << arg << "::" << arg << "() {" << std::endl << std::endl << "}" << std::endl << std::endl;
    ofs << arg << "::~" << arg << "() {" << std::endl << std::endl << "}";
    ofs << "/**/" << std::endl;
    ofs << "int main() {" << std::endl;
    ofs << "  "<< arg << "* " << arg[0] << " = new " << arg << "();"  << std::endl << std::endl;
    ofs << "  return 0;" << std::endl;
    ofs << "}" << std::endl;
    ofs.close();

    //makefile
    ofs.open("makefile_test");
    ofs << arg << ":" << std::endl;
    ofs << "    " << "g++ " << source_name;
    ofs.close();

    //README.txt
    ofs.open("README.txt");
    ofs << "initial message";
    ofs.close();

    //result
    std::cout << arg << ".cpp, " << arg << ".h, makefile, README have been generated." << std::endl;

    return 0;        
}
