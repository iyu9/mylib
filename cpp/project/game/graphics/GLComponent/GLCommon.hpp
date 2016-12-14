namespace GLCommon
{
  class IntVector2
  {
  public:
	int x, y;
	IntVector2(int x_, int y_);

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
	Vector2(double x_, double y_);
  };

  class Vector3
  {
  public:
	double x;
	double y;
	double z;
  };

  class Vector4
  {
  public:
	double x;
	double y;
	double z;
	double w;
  };
};
