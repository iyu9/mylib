/**
** Minimum Game Components
*/

#ifndef __COMMON_H__
#define __COMMON_H__

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
	Vec2 center;

	Rect(Vec2 _position, Vec2 _size)
	{
	  position = _position;
	  size = _size;
	  center = get_center();
	}
	Rect(double _x, double _y, double _w, double _h)
	{
	  position.x = _x; position.y = _y;
	  size.x = _w; size.y = _h;
	  center = get_center();
	}

	void set_center(Vec2 center)
	{
	  Vec2 pos =
	  {
		center.x - 0.5f * size.x,
		center.y - 0.5f * size.y
	  };
	  position = pos;
	}

	Vec2 get_center()
	{
	  Vec2 center =
	  {
		position.x + 0.5f * size.x,
		position.y + 0.5f * size.y
	  };
	  return center;
	}
};

#endif
