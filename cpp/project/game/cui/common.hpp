 struct Vec2
 {
   double x, y;
 };

 class Rect
 {
 public:
   Vec2 position;
   Vec2 size;

   void set_center(Vec2 center_pos)
   {
     double x = center_pos.x - 0.5f * size.x;
     double y = center_pos.y - 0.5f * size.y;

     position.x = x;
     position.y = y;
   }

   void get_center()
   {
     double x = position.x + 0.5f * size.x;
     double y = position.y + 0.5f * size.y;

     Vec2 center_pos;
     center_pos.x = x;
     center_pos.y = y;
   }
 };
