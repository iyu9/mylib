/*
 *	3-Dimentions-Vector
 *	tomii
 */
class Vector3 {
	public:
	float x, y, z;	

	Vector3();
	Vector3(float x, float y, float z);
	Vector3* operator + (Vector3* v);
	Vector3* operator - (Vector3* v);
	Vector3* operator * (float f);
	Vector3* operator / (float f);
};
