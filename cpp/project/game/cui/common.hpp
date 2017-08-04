/*
** Minimum game components
*/
 class Vec2
 {
 public:
   double x, y;
 };

 class Rect
 {
 public:
   Vec2 position;
   Vec2 size;

   Rect(){}
   Rect(Vec2 _position, Vec2 _size)
   {
	 position = _position;
	 size = _size;
   }
   Rect(double _x, double _y, double _w, double _h)
   {
	position.x = _x; position.y = _y;
	size.x = _w; size.y = _h;
   }

   void set_center(Vec2 center_pos)
   {
     double x = center_pos.x - 0.5f * size.x;
     double y = center_pos.y - 0.5f * size.y;

     position.x = x;
     position.y = y;
   }

   Vec2 get_center()
   {
     double x = position.x + 0.5f * size.x;
     double y = position.y + 0.5f * size.y;

     Vec2 center_pos = {x, y};
	 return center_pos;
   }
 };
