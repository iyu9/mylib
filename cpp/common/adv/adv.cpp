#include "../common/common.h"

class adv {

public:
	std::string msg_list[3];
	int msg_index;
	int char_index;
	float char_time;
	int is_next_msg;

	adv() {
		msg_list[0] = "test_msg_1";
		msg_list[1] = "test_msg_2";	
		msg_list[2] = "test_msg_3";	
	}

	~adv();

	std::string get_msg() {
		std::string sub = msg_list[msg_index].substr(0, char_index);
		return sub;
	}

	void set_message(int msg_index_) {
		msg_index = msg_index_;
		
		is_next_msg = 0;
		char_index = 0;
		char_time = 0;	
	}

	void prev_msg() {
		if(msg_index > 0){
			msg_index--;
		}
		is_next_msg = 0;

		char_index = 0;
		char_time = 0;	
	}

	void next_msg() {
		if(msg_index < 3 - 1) {
			msg_index++;
		}
		is_next_msg = 0;

		char_index = 0;
		char_time = 0;	
	}

	void update() {
		int msg_length = 10;
		float char_next_time = 0.1f;

		std::cout << get_msg() << std::endl;

		if(char_time > char_next_time) {
					
			if(char_index < msg_length) {
				char_index++;
			} else {
				is_next_msg = 1;
				next_msg();
			}
			char_time = 0;
		} else {
			char_time += 0.001;
		}
	}
};

/**/
int main() {
	adv* a = new adv();

	while (1) {
		a->update();
	}

	return 0;	
}
/**/
