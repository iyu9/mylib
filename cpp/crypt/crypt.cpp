#include "crypt.h"

//constructors
crypt::crypt() {
		
}

crypt::crypt(int type, std::string value) {
  //SHA-1
  if(type == TYPE_SHA1) {
    this->value = sha1(value); 
  }

  //AES
  if(type == TYPE_AES) {
    this->value = -1;
  }	
}

crypt::~crypt() {
		
}

//methods
bool crypt::encode(std::string filename_) {
		
}

bool crypt::decode(std::string filename_) {
		
}

/**/
int main() {

  crypt* crpt = new crypt(0, "test");
  print("test: ");
  print(crpt->value);

  return 0;		
}
/**/
