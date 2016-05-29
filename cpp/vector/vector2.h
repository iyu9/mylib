
class Vector2 {
	public:
	float x, y;	

	Vector2();
	Vector2(float x, float y);
	Vector2* operator + (Vector2* v);
	Vector2* operator - (Vector2* v);
	Vector2* operator * (float f);
	Vector2* operator / (float f);
};
