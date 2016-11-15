#include "../common/common.h"

class base_window {

public:
    base_window();
    ~base_window();

	void open();
    void close();

	void open(void(callback()));
    void close(void(callback()));
};
