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

    Vector3 a = Vector3(p[0], p[1], p[0]*p[0] + p[1]*p[1]);
    Vector3 b = Vector3(q[0], q[1], q[0]*q[0] + q[1]*q[1]);
    Vector3 c = Vector3(r[0], r[1], r[0]*r[0] + r[1]*r[1]);
    Vector3 x = Vector3(t[0], t[1], t[0]*t[0] + t[1]*t[1]);
    
    int sign = orientation2D(a,b,c);
    
    double A11 = b[0] - a[0];
    double A12 = b[1] - a[1];
    double A13 = (b[0] - a[0])*(b[0] + a[0])+(b[1]-a[1])*(b[1]+a[1]);
    double A21 = c[0] - a[0];
    double A22 = c[1]-a[1];
    double A23 = (c[0] - a[0])*(c[0] + a[0])+(c[1]-a[1])*(c[1]+a[1]);
    double A31 = x[0]-a[0];
    double A32 = x[1]-a[1];
    double A33 = (x[0] - a[0])*(x[0] + a[0])+(x[1]-a[1])*(x[1]+a[1]);
    
    double det = A11*(A22*A33-A23*A32)-A12*(A21*A33-A23*A31)+A13*(A21*A32-A22*A31);
    
    return det*sign;

    /*double orient = ((q[0]-p[0])*(r[1]-p[1])) - ((q[1]-p[1])*(r[0]-p[0]));
   	double result = 	((((r[0]-q[0])*(r[0]+q[0]))+((r[1]-q[1])*(r[1]+q[1]))) * (((t[0]-q[0])*(p[1]-q[1]))-((t[1]-q[1])*(p[0]-q[0])))) +
    				((((t[0]-q[0])*(t[0]+q[0]))+((t[1]-q[1])*(t[1]+q[1]))) * (((r[0]-q[0])*(p[1]-q[1]))-((r[1]-q[1])*(p[0]-q[0])))) +
    				((((p[0]-q[0])*(p[0]+q[0]))+((p[1]-q[1])*(p[1]+q[1]))) * (((r[0]-q[0])*(t[1]-q[1]))-((r[1]-q[1])*(t[0]-q[0]))));


    return	orient*result;*/
}

