#include "../common/common.h"

class user {
private:

public:
	user(){}
	~user(){}

	int id;
	std::string s_id;
	std::string name;
	std::string family_name;
	std::string first_name;
	std::string secret_answer;

	int age;
	std::string adrress;
	std::string email;
	std::string phone_number;
	std::string first_login;
	std::string last_login;
};

int main()
{
	user* u = new user();
	return 0;		
}
