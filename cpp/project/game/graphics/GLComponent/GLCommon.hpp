#ifndef ONCE_GLCOMMON
#define ONCE_GLCOMMON

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
  };

  class Vector3
  {
  public:
	double x;
	double y;
	double z;

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
  };

  class Vector4
  {
  public:
	double x;
	double y;
	double z;
	double w;

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
  };
};

#endif
