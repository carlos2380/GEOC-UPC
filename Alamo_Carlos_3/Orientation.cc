#include <geoc/math/Math.h>
#include <geoc/math/Vector.h>
#include <iostream>

using namespace geoc;
using namespace std;

num Math::orientation2D(const Vector3& p, const Vector3& q, const Vector3& r)
{
    //Exercise 1.

    double result = ((q[0]-p[0])*(r[1]-p[1])) - ((q[1]-p[1])*(r[0]-p[0]));
    //int result = p[0]*q[1] + p[1]*r[0] + q[0]*r[1] - q[1]*r[0] -p[1]*q[0] - p[0]*r[1];
    //cout << "RESULT ->" << result << endl;

    if (result > 0) return 1;
    else if (result < 0) return -1;
    return	0;
}


num Math::orientation25D(const Vector2& p, const Vector2& q, const Vector2& r, const Vector2& t)
{
    //Exercise 3.
    double orient = ((q[0]-p[0])*(r[1]-p[1])) - ((q[1]-p[1])*(r[0]-p[0]));
   	double result = 	((((r[0]-q[0])*(r[0]+q[0]))+((r[1]-q[1])*(r[1]+q[1]))) * (((t[0]-q[0])*(p[1]-q[1]))-((t[1]-q[1])*(p[0]-q[0])))) +
    				((((t[0]-q[0])*(t[0]+q[0]))+((t[1]-q[1])*(t[1]+q[1]))) * (((r[0]-q[0])*(p[1]-q[1]))-((r[1]-q[1])*(p[0]-q[0])))) +
    				((((p[0]-q[0])*(p[0]+q[0]))+((p[1]-q[1])*(p[1]+q[1]))) * (((r[0]-q[0])*(t[1]-q[1]))-((r[1]-q[1])*(t[0]-q[0]))));


    return	orient*result;
}

