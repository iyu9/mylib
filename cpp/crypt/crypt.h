#include "../common/common.h"

class crypt {

private:
	int type;

public:
	crypt();
	crypt(int type_, int hash_);
	~crypt();

	bool encode(std::string filename);
	bool decode(std::string filename);
};
