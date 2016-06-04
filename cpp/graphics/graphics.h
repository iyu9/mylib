#include "../common/common.h"

#include "../chrono/chrono.cpp"
#include "../vector/vector3.cpp"
#include "../object/object.cpp"

class graphics {
	private:
		object obj_list[99];
		int obj_length;

		int state;

	public:
		graphics();
		~graphics();

		void init();
		static void render();
		void add_object(object obj);
		void draw_object();
};
