/*
 * Mathematics Interface class
 */
class IMath
{
  public:
	const float PI = 3.14159265;
	const float e = 2.71828;
	const float g = 9.8;

    double Sin(double x);      
    double Cos(double x);
	double Tan(double x);

	double ArcSin(double x);
	double ArcCos(double x);
	double ArcTan(double x);

	double RadianToEuler(double);
	double EulerToRadian(double);
};
