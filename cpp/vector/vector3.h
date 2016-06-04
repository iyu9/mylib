
class vector3 {
	public:
	float x, y, z;	

	vector3();
	vector3(float x, float y, float z);
	vector3* operator + (vector3* v);
	vector3* operator - (vector3* v);
	vector3* operator * (float f);
	vector3* operator / (float f);
};
