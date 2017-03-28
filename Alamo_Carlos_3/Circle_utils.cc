#include <geoc/geometry/Circle.h>
#include <geoc/scene/Point.h>
#include <geoc/math/Math.h>

using namespace geoc;
using namespace std;

void geoc::classify(const Circle& c, const Vector3& p, Colour3& colour, std::string& desc) {
	//Exercise 3.
	colour = Colour3(1, 1, 1);
	desc = "To-do";

	num orientation = Math::orientation25D( c[0], c[1], c[2],p );

	if (orientation > 0)
	{
		colour = Colour3(0, 0, 1);
		desc = "Exterior";
	} else if (orientation < 0)
	{
		colour = Colour3(1, 0, 0);
		desc = "INTERIOR";
	}else if (orientation == 0)
	{
		colour = Colour3(0, 1, 0);
		desc = "INLINE";
	}
}
