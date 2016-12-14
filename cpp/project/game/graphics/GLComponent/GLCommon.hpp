#ifndef INCLUDE_ONCE_GLCOMMON_H
#define INCLUDE_ONCE_GLCOMMON_H

namespace GLCommon
{
  class IntVector2
  {
  public:
	int x, y;

  public:
	IntVector2(int x_, int y_)
	{
	  x = x_; y = y_;  
	};

	IntVector2* zero()
	{
	  x = y = 0;
	  return this;
	}

	IntVector2* one()
	{
	  x = y = 1;
	  return this;
	}

	IntVector2 operator+(IntVector2 opt)
	{
	  IntVector2* vec = new IntVector2(x + opt.x, y + opt.y);
	  return *vec;
	}

	IntVector2 operator-(IntVector2 opt)
	{
	  IntVector2* vec = new IntVector2(x - opt.x, y - opt.y);
	  return *vec;
	}

	IntVector2 operator*(double opt)
	{
	  IntVector2* vec = new IntVector2((int)(x * opt), (int)(y * opt));
	  return *vec;
	}

	IntVector2 operator/(double opt)
	{
	  IntVector2* vec = new IntVector2((int)(x / opt), (int)(y / opt));
	  return *vec;
	}
  };

  class Vector2
  {
  public:
	double x, y;

  public:
	Vector2(double x_, double y_)
	{
	  x = x_; y = y_;  
	};

	Vector2* zero()
	{
	  x = y = 0;
	  return this;
	}

	Vector2* one()
	{
	  x = y = 1;
	  return this;
	}

	Vector2* operator+(Vector2 opt)
	{
	  Vector2* vec = new Vector2(x + opt.x, y + opt.y);
	  return vec;
	}

	Vector2* operator-(Vector2 opt)
	{
	  Vector2* vec = new Vector2(x - opt.x, y - opt.y);
	  return vec;
	}

	Vector2* operator*(double opt)
	{
	  Vector2* vec = new Vector2(x * opt, y * opt);
	  return vec;
	}

	Vector2* operator/(double opt)
	{
	  Vector2* vec = new Vector2(x / opt, y / opt);
	  return vec;
	}
  };

  class Vector3
  {
  public:
	double x, y, z;

  public:
	Vector3(double x_, double y_, double z_)
	{
	  x = x_; y = y_; z = z_;  
	};

	Vector3* zero()
	{
	  x = y = z = 0;
	  return this;
	}

	Vector3* one()
	{
	  x = y = z = 1;
	  return this;
	}

	Vector3* operator+(Vector3 opt)
	{
	  Vector3* vec = new Vector3(x + opt.x, y + opt.y, z + opt.z);
	  return vec;
	}

	Vector3* operator-(Vector3 opt)
	{
	  Vector3* vec = new Vector3(x - opt.x, y - opt.y, z + opt.z);
	  return vec;
	}

	Vector3* operator*(double opt)
	{
	  Vector3* vec = new Vector3(x * opt, y * opt, z * opt);
	  return vec;
	}

	Vector3* operator/(double opt)
	{
	  Vector3* vec = new Vector3(x / opt, y / opt, z / opt);
	  return vec;
	}
  };

  class Vector4
  {
  public:
	double x, y, z, w;

  public:
	Vector4(double x_, double y_, double z_, double w_)
	{
	  x = x_; y = y_; z = z_; w = w_;
	};

	Vector4* zero()
	{
	  x = y = z = w = 0;
	  return this;
	}

	Vector4* one()
	{
	  x = y = z = w = 1;
	  return this;
	}

	Vector4* operator+(Vector4 opt)
	{
	  Vector4* vec = new Vector4(x + opt.x, y + opt.y, z + opt.z, w + opt.w);
	  return vec;
	}

	Vector4* operator-(Vector4 opt)
	{
	  Vector4* vec = new Vector4(x - opt.x, y - opt.y, z - opt.z, w - opt.w);
	  return vec;
	}

	Vector4* operator*(double opt)
	{
	  Vector4* vec = new Vector4(x * opt, y * opt, z * opt, w * opt);
	  return vec;
	}

	Vector4* operator/(double opt)
	{
	  Vector4* vec = new Vector4(x / opt, y / opt, z / opt, w / opt);
	  return vec;
	}
  };
};

#endif
