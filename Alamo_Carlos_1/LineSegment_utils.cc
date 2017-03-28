#include <geoc/geometry/LineSegment.h>
#include <geoc/math/Math.h>
#include <iostream>

using namespace geoc;
using namespace std;


void geoc::classifyIntersection(const LineSegment& s, const LineSegment& t, Colour3& colour, std::string& desc)
{
    //cout << "PAREJAAAAAAAAAAAAAAAA"<< endl;
    //r1 -> Comprobamos s con t1 
	num r1 = Math::orientation2D(s[0], s[1], t[0]);

	////cout << "r1 " << r1 << endl;
    //r2 -> Comprobamos s con t2
	num r2 = Math::orientation2D(s[0], s[1], t[1]);
	////cout << "r2 " << r2 << endl;
    //Si r1 != r2 & (r1 != 0 & r2 != 0)
	if((r1 != r2) && (r1 != 0 && r2 != 0)) {
		//r3 -> Comprobamos t con s1
		num r3 = Math::orientation2D(t[0], t[1], s[0]);
		//r4 -> Comprobamos t com s2
		num r4 = Math::orientation2D(t[0], t[1], s[1]);
		//result => r3 != r4 o (r3 = 0 & r4 = 0) se CORTAN
		if(r3 != r4 && (r3 != 0 and r4 != 0) ) {
			desc = "SE CORTAN - FORMA X";
			colour = Colour3(1, 1, 1);
		}
		else if((r3 == 0 and r4 != 0) || (r3 =! 0 and r4 == 0)) {
			desc = "SE CORTAN - FORMA T";
			colour = Colour3(1, 1, 0);
		}
		else {
			desc = "NO SE CORTAN";
		}
	} else if(r1 == 0 && r2 != 0) {
		//Si r1 = 0 then t[0] en linea con s
		//Comprobamos s0,t1,t0 i s1,t1,t0 diferentes o T o L
		num r3 = Math::orientation2D(s[0], t[1], t[0]);
		num r4 = Math::orientation2D(s[1], t[1], t[0]);
		if(r3 != r4 && (r3 != 0 && r4 != 0)) {
			desc = "SE CORTAN - FORMA T";
			colour = Colour3(1, 1, 0);
		}
		else if(r3 == 0) {
			//Check que s[0] = t[0]
			desc = "SE CORTAN - FORMA L (s[0] = t[0])";
			colour = Colour3(0, 1, 1);
		}
		else if(r4 == 0) {
			//Check que s[1] = t[0]
			desc = "SE CORTAN - FORMA L (s[1] = t[0])";
			colour = Colour3(0, 1, 1);
		}
		else {
			colour = Colour3(1, 0, 1);
			desc = "NO SE CORTAN";
		}
	} else if(r1 != 0 && r2 == 0) {
		//Si r2 = 0 then t[0] en linea con s
		//Comprobamos s0,t1,t0 i s1,t1,t0 diferentes o T o L
		num r3 = Math::orientation2D(s[0], t[0], t[1]);
		num r4 = Math::orientation2D(s[1], t[0], t[1]);
		if(r3 != r4 && (r3 != 0 && r4 != 0)) {
			desc = "SE CORTAN - FORMA T";
			colour = Colour3(1, 1, 0);
		}
		else if(r3 == 0) {
			//Check que s[0] = t[0]
			desc = "SE CORTAN - FORMA L (s[0] = t[1])";
			colour = Colour3(0, 1, 1);
		}
		else if(r4 == 0) {
			//Check que s[1] = t[0]
			desc = "SE CORTAN - FORMA L (s[1] = t[1])";
			colour = Colour3(0, 1, 1);
		}
		else {
			colour = Colour3(1, 0, 1);
			desc = "NO SE CORTAN";
		}
	}else if(r1 == 0 && r2 == 0) {

		//Create paralel segment p0 from s0
		Vector3 p0 = s[1] - s[0];
		Vector3 aux = p0;
		p0[0] = -aux[1];
		p0[1] = aux[0];
		p0 = p0 + s[0];

		//Create paralel segment p0 from s0
		Vector3 p1 = s[0] - s[1];
		aux = p1;
		p1[0] = -aux[1];
		p1[1] = -aux[0];
		p1 = p1 + s[1];

		//Check position of t
		num s0r0 = Math::orientation2D(s[0], p0, t[0]);
		num s0r1 = Math::orientation2D(s[0], p0, t[1]);
		num s1r0 = Math::orientation2D(s[1], p1, t[0]);
		num s1r1 = Math::orientation2D(s[1], p1, t[1]);
		num s1s0 = Math::orientation2D(s[0], p0, s[1]);
		num s0s1 = Math::orientation2D(s[1], p1, s[0]);


		//cout << endl << "s0r0: " << s0r0 << " s0r1: " << s0r1 << " s1r0: " << s1r0 << " s1r1: " << s1r1 << endl;

		if((s0r0 == 0 and s1r1 == 0) or (s1r0 == 0 and s0r1 == 0)) {
			desc = "SEGMENTOS IGUALES";
			colour = Colour3(0.3, 0, 0.8);
		} else if(s1s0 != s0r0 and s1s0 != s0r1 and s0r0 == s0r1) {
			//El segmento pasa al otro
			desc = "NO SE CORTAN - SEGMENTOS COMPARTEN LINEA";
			colour = Colour3(0.4, 0.3, 0.8);
		} else if(s0s1 != s1r0 and s1s0 != s1r1 and s1r0 == s1r1) {
			desc = "NO SE CORTAN - SEGMENTOS COMPARTEN LINEA";
			colour = Colour3(0.4, 0.3, 0.8);
		} else if((s0r0 > 0) and (s0r1 > 0) and (s1r0 > 0) and (s1r1 > 0)) {
			//Un segmento y despues el otro
			desc = "NO SE CORTAN - SEGMENTOS COMPARTEN LINEA";
			colour = Colour3(0.4, 0.3, 0.8);
		} else if((s0r0 < 0) and (s0r1 < 0) and (s1r0 < 0) and (s1r1 < 0)) {
			desc = "NO SE CORTAN - SEGMENTOS COMPARTEN LINEA";
			colour = Colour3(0.4, 0.3, 0.8);
		}else if(s0r0 == 0) {
			//Comprovamos las cuatro posibilidades de vertices
			if(s1s0 != s0r1) {
				desc = "SEGMENTOS COMPARTEN VETICE - SEGMENTOS COMPARTEN LINEA";
				colour = Colour3(0.1, 0.6, 0.3);
			} else {
				desc = "SEGMENTOS SOLAPADOS";
				colour = Colour3(0.5, 0.5, 0.5);
			}
		} else if(s0r1 == 0) {
			if(s1s0 != s0r0) {
				desc = "SEGMENTOS COMPARTEN VETICE - SEGMENTOS COMPARTEN LINEA";
				colour = Colour3(0.1, 0.6, 0.3);
			} else {
				desc = "SEGMENTOS SOLAPADOS";
				colour = Colour3(0.5, 0.5, 0.5);
			}
		} else if(s1r0 == 0) {
			if(s0s1 != s1r1) {
				desc = "SEGMENTOS COMPARTEN VETICE - SEGMENTOS COMPARTEN LINEA";
				colour = Colour3(0.1, 0.6, 0.3);
				colour = Colour3(0.1, 0.6, 0.3);
			} else {
				desc = "SEGMENTOS SOLAPADOS";
				colour = Colour3(0.5, 0.5, 0.5);
			}
		} else if(s1r1 == 0) {
			if(s0s1 != s1r0) {
				desc = "SEGMENTOS COMPARTEN VETICE - SEGMENTOS COMPARTEN LINEA";
				colour = Colour3(0.1, 0.6, 0.3);
			} else {
				desc = "SEGMENTOS SOLAPADOS";
				colour = Colour3(0.5, 0.5, 0.5);
			}
		} else {
			//cout << "OMITIR EL DE ARRIBA" << endl;
			desc = "SEGMENTOS SOLAPADOS";
			colour = Colour3(0.5, 0.5, 0.5);
		}
	} else {
		desc = "NO SE CORTAN";
		colour = Colour3(1, 0, 1);
	}

	//cout <<  endl <<  endl;
}

