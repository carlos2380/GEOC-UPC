#include <geoc/geometry/Triangle.h>
#include <geoc/geometry/LineSegment.h>
#include <geoc/scene/Point.h>
#include <geoc/math/Math.h>
#include <geoc/GeocException.h>

using namespace geoc;
using namespace std;

void geoc::classify(const Triangle& t, const Vector3& p, Colour3& colour, std::string& desc) {

	//Exercise 2.
	colour = Colour3(1, 1, 1);
	desc = "To-do";
	//Orientation
	num orientation = Math::orientation2D(t[0], t[1], t[2]);
	//cout << endl << "t[0]: " << t[0] << " t[01]: " << t[1] << " t[2]: " << t[2] << " p: " << p << endl;
	//Orientation Triangles a b c
	num a = Math::orientation2D(t[0], t[1], p);
	num b = Math::orientation2D(t[1], t[2], p);
	num c = Math::orientation2D(t[2], t[0], p);
	//cout << endl << "o: " << orientation << " a: " << a << " b: " << b << " c: " << c << endl;
	if(a == orientation and  b == orientation and c == orientation) {
		//Inside
		desc = "INSIDE";
		colour = Colour3(0, 1, 0);
	}else if(a == 0 and  b == orientation and c == orientation) {
		//Edge
		desc = "IN EDGE";
		colour = Colour3(1, 0, 1);
	}else if(a == orientation and  b == 0 and c == orientation) {
		//Edge
		desc = "IN EDGE";
		colour = Colour3(1, 0, 1);
	}else if(a == orientation and  b == orientation and c == 0) {
		//Edge
		desc = "IN EDGE";
		colour = Colour3(1, 0, 1);
	}else if(a == 0 and  b == 0 and c == orientation) {
		//Vertex
		desc = "IN VERTEX";
		colour = Colour3(0, 1, 1);
	}else if(a == orientation and  b == 0 and c == 0) {
		//Vertex
		desc = "IN VERTEX";
		colour = Colour3(0, 1, 1);
	}else if(a == 0 and  b == orientation and c == 0) {
		//Vertex
		desc = "IN VERTEX";
		colour = Colour3(0, 1, 1);
	}else {
		//Outside
		desc = "IN VERTEX";
		colour = Colour3(1, 0, 0);
	}
	
}
