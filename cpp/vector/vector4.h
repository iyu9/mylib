/*
 *	4-Dimentions-Vector
 *	tomii
 */
class Vector4 {
	public:
	float x, y, z, w;	

	Vector4();
	Vector4(float x, float y, float z, float w);
	Vector4* operator + (Vector4* v);
	Vector4* operator - (Vector4* v);
	Vector4* operator * (float f);
	Vector4* operator / (float f);
};
