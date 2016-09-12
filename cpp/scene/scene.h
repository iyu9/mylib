#include "../common/common.h"

class scene {

private:
	int id;
	std::string name;
	enum StateType {
		state_enter,
		state_update,
		state_exit		
	};
	int state;

protected:
	virtual void on_update();
	virtual void on_enter();
	virtual void on_exit();

public:
	scene();
	scene(int id);
	scene(std::string name);
	scene(int id, std::string name);
	
	~scene();

	virtual void update();
	virtual bool is_exit();
	void set_exit();
};
