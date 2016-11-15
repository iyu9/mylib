class vector2 {
	public:
	float x, y;

    static const vector2 zero;
    static const vector2 one;

	vector2();
	vector2(float x, float y);
	vector2* operator + (vector2* v);
	vector2* operator - (vector2* v);
	vector2* operator * (float f);
	vector2* operator / (float f);
};

