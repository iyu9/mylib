
class vector2 {
	public:
	float x, y;	

	vector2();
	vector2(float x, float y);
	vector2* operator + (vector2* v);
	vector2* operator - (vector2* v);
	vector2* operator * (float f);
	vector2* operator / (float f);
};
