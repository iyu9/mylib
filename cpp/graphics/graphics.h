#include "../common/common.h"

#include "../chrono/chrono.cpp"
#include "../vector/vector3.cpp"
#include "../object/object.cpp"

class graphics {
	private:
		vector3 obj_list[99];
		int obj_length;

		int state;

	public:
		graphics();
		~graphics();

		void init();
		static void render();
		void create_object(int type, vector3 pos);
		void draw_object();
};
