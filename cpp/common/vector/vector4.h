
class vector4 {
public:
	float x, y, z, w;	

	vector4();
	vector4(float x, float y, float z, float w);
	vector4* operator + (vector4* v);
	vector4* operator - (vector4* v);
	vector4* operator * (float f);
	vector4* operator / (float f);
};
