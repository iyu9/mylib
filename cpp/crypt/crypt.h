#include "../common/common.h"
#include "./sha1.cpp"

const int TYPE_SHA1 = 0;

class crypt {

private:
	int type;

public:
  std::string value;

	crypt();
	crypt(int type, std::string value);
	~crypt();

	bool encode(std::string filename);
	bool decode(std::string filename);
};
