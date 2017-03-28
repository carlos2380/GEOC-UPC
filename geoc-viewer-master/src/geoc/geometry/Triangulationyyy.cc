#include <geoc/geometry/Triangulation.h>
#include <geoc/geometry/Triangle.h>
#include <geoc/geometry/Circle.h>
#include <geoc/math/Math.h>
#include <geoc/scene/LineSegmentEnt.h>
#include <geoc/scene/TriangleEnt.h>
#include <geoc/GeocException.h>
#include <algorithm>
#include <sstream>
#include <cstdio>

using namespace geoc;
using namespace std;


class Edge;
class Vertice {
	public:
	Edge* incidente;
	Vector3 vertice;

	void setVertice(Vector3 v) {
		vertice = v;
	}
	
	Vector3 getVertice() {
		return vertice;
	}

	Vertice(Vector3 v){
		vertice = v;
	}
	
	Edge* getInc() {
		return incidente;
	}
	
	void setInc(Edge* edge) {
		incidente = edge;
	}
};

class Face;
class Edge {
	public:
	Edge* revers;
	Edge* next;
	Vertice* vertice;
	Face* face;

	Edge() {}
	Edge(Vertice* v, Face *f, Edge *n, Edge *r) {
		vertice = v;
		next = n;
		revers = r;
		face = f;
	}

	Vertice* getVertice() {
		return vertice;
	}
	
	void setVertice(Vertice* v) {
		vertice = v;
	}
	
	Edge* getNext() {
		return next;
	}
	
	void setNext(Edge* n) {
		next = n;
	}

	Face* getFace() {
		return face;
	}
	
	void setFace(Face* f) {
		face = f;
	}
	
	Edge* getRevers() {
		return revers;
	}
	
	void setReverse(Edge* r) {
		revers = r;
		r->revers = this;
	} 
	
		
};

class Face {
	public:
	Edge* edge;
	
	Face(Edge* e) {
		edge = e;
	}

	Edge* getEdge() {
		return edge;
	}
	
	void setEdge(Edge* newBound) {
		edge = newBound;
	}
};

Triangulation::Triangulation() {
}

Triangulation::~Triangulation() {
}

vector<Edge*> edges;
vector<Vertice*> vertices;
vector<Face*> faces;




void Triangulation::triangulate(const vector<Vector3>& ps,
                                const vector<int>& idxs,
                                vector<LineSegmentEnt>& segments,
                                vector<TriangleEnt>& triangles,
                                vector<TriangleEnt>& triangles_pruned) {
	printf("Compiling student triangulation\n");

	double maxX = ps[0][0];
	double minX = ps[0][0];
	double maxY = ps[0][1];
	double minY = ps[0][1];

	double size =  ps.size();
	double pointX = 0;
	double pointY = 0;

	for (int i = 0; i < ps.size(); ++i) {

		pointX =  pointX + ps[i][0];
		pointY =  pointY + ps[i][1];

		if(maxX < ps[i][0]) maxX = ps[i][0];
		if(minX > ps[i][0]) minX = ps[i][0];
		if(maxY < ps[i][1]) maxY = ps[i][1];
		if(minY > ps[i][1]) minY = ps[i][1];
	
		////cout << "Max " << maxX << " : " << maxY<< endl;
		////cout << "Min " << minX << " : " << minY << endl<< endl<< endl; 
	}
	pointX = pointX/size;
	pointY = pointY/size;
	//cout << "Max " << maxX << " : " << maxY<< endl;
	//cout << "Min " << minX << " : " << minY << endl<< endl<< endl; 

	//Points of Big Triangle
	double tAx, tBx, tCx, tAy, tBy, tCy, zero;

	zero = 0;
	tAx = minX - abs((maxY-minY));
	tAy = minY - 1000;
	tCx = maxX + abs((maxY-minY));
	tCy = minY - 1000;

	tBx = minX + abs((maxX - minX)/2);
	tBy = maxY + abs(maxX - minX);

	Vector3 *tA = new Vector3(tAx, tAy, zero);
	Vector3 *tB = new Vector3(tBx, tBy, zero);
	Vector3 *tC = new Vector3(tCx, tCy, zero);
			
	Vertice* vA = new Vertice(*tA);
	Vertice* vB = new Vertice(*tB);
	Vertice* vC = new Vertice(*tC);
	vertices.push_back(vA);
	vertices.push_back(vB);
	vertices.push_back(vC);
	
	Face* exterior = new Face(NULL/*, true*/);
	Face* face = new Face(NULL);
	faces.push_back(exterior);
	faces.push_back(face);
	
	Edge* eab = new Edge(vA, exterior, NULL, NULL);
	Edge* eca = new Edge(vC, exterior, eab, NULL);
	Edge* ebc = new Edge(vB, exterior, eca, NULL);
	Edge* eba = new Edge(vB, face, NULL, eab);
	Edge* ecb = new Edge(vC, face, eba, ebc);
	Edge* eac = new Edge(vA, face, ecb, eca);
	edges.push_back(eab);
	edges.push_back(eca);
	edges.push_back(ebc);
	edges.push_back(eba);
	edges.push_back(ecb);
	edges.push_back(eac);
							
	exterior->setEdge(eab);
	face->setEdge(eba);
	
	vA->setInc(eab); 
	vB->setInc(eba);
	vC->setInc(ecb);
	
	eab->setNext(ebc);
	eba->setNext(eac);
	eab->setReverse(eba);
	eca->setReverse(eac);
	ebc->setReverse(ecb);


	for (int i = 0; i < ps.size(); ++i) {

		Vector3 point = ps[i];


	////BUSCAR LA CARA////////////////////////////////
	//
		Face* faceSearch = face;
		bool trobat = false;

		while (not trobat) {

			Edge* edge = faceSearch->getEdge();
			bool haveEdge = false;
			int iter = 0;
			while(iter < 3 and not haveEdge) {
				Vector3 p = edge->getVertice()->getVertice();
				Vector3 q = edge->getNext()->getVertice()->getVertice();
				if (Math::orientation2D(p, q, point) == 1) {
					faceSearch = edge->getRevers()->getFace();
					haveEdge = true;
					
				}
				edge = edge->getNext();
				++iter;
			}
			if (not haveEdge) {
				trobat = true;
			}
		}
		Face *faceFound = faceSearch;
	//
	////////////////////////////////////////////////////	

	////INSERT POINT//////////////////
	//

		Edge *edge = faceFound->getEdge();
		bool enEdge = false;

		int iter = 0;
		while(iter < 3 and not enEdge){
			if (Math::orientation2D(edge->getVertice()->getVertice(), edge->getNext()->getVertice()->getVertice(), point) == 0) enEdge = true;
			else edge = edge->getNext();
			
			++iter;
		}

		Edge *ba, *ac, *cb;
		Vertice *vA, *vB, *vC;

		ba = edge;
		ac = ba->getNext();
		cb = ba->getNext()->getNext();

		vA = ba->getVertice();
		vB = ac->getVertice();
		vC = cb->getVertice();


		Vertice* v = new Vertice(point);
		vertices.push_back(v);

		if (enEdge) {
			Edge* ab = ba->getRevers();
			Edge* bd = ab->getNext();
			Edge* da = ab->getNext()->getNext();

			Vertice* vD = da->getVertice();
			Face* faceBack = bd->getFace();
			Face* faceNew = new Face(da);
			Face* faceNewBack = new Face(ac);
			faces.push_back(faceNew);
			faces.push_back(faceNewBack);

			Edge* evc = new Edge(v, faceFound, cb, NULL);
			Edge* evAv = new Edge(vA, faceFound, evc, NULL);
			Edge* evb = new Edge(v, faceBack, bd, evAv);
			Edge* evDv = new Edge(vD, faceBack, evb, NULL);
			Edge* evvD = new Edge(v, faceNew, da, evDv);
			Edge* evCb = new Edge(vC, faceNewBack, ba, evc);

			edges.push_back(evc);
			edges.push_back(evAv);
			edges.push_back(evb);
			edges.push_back(evDv);
			edges.push_back(evvD);
			edges.push_back(evCb);

			v->setInc(evb);
			vA->setInc(bd);
			vB->setInc(ac);

			faceFound->setEdge(cb);
			faceBack->setEdge(bd);

			ba->setVertice(v);
			ba->setFace(faceNewBack);
			ac->setFace(faceNewBack);
			ab->setFace(faceNew);
			bd->setFace(faceBack);
			da->setFace(faceNew);
			ac->setNext(evCb);
			cb->setNext(evAv);
			ab->setNext(evvD);
			bd->setNext(evDv);
			da->setNext(ab);
			evc->setReverse(evCb);
			evAv->setReverse(evb);
			evDv->setReverse(evvD);
		}else {

			Face* faceA = new Face(ac);
			faces.push_back(faceA);
			Face* faceB = new Face(cb);
			faces.push_back(faceB);
			face = faceA;
			
			Edge* eva = new Edge(v, faceFound, ba, NULL);
			Edge* evBv = new Edge(vB, faceFound, eva, NULL);
			Edge* evvA = new Edge(v, faceA, ac, evBv);
			Edge* evCv = new Edge(vC, faceA, evvA, NULL);
			Edge* evvC = new Edge(v, faceB, cb, evCv);
			Edge* evAv = new Edge(vA, faceB, evvC, eva);

			edges.push_back(eva);
			edges.push_back(evBv);
			edges.push_back(evvA);
			edges.push_back(evCv);
			edges.push_back(evvC);
			edges.push_back(evAv);
			
			v->setInc(eva);
			ba->setNext(evBv);
			ac->setFace(faceA);
			ac->setNext(evCv);
			cb->setFace(faceB);
			cb->setNext(evAv);
			eva->setReverse(evAv);
			evBv->setReverse(evvA);
			evCv->setReverse(evvC);
		}
	}
//
///////////////////////////
	
////PAINT
//	
	for(int i = 1; i < faces.size(); ++i) {
		Vector3 v1 = faces[i]->getEdge()->getVertice()->getVertice();
		Vector3 v2 = faces[i]->getEdge()->getNext()->getVertice()->getVertice();
		Vector3 v3 = faces[i]->getEdge()->getNext()->getNext()->getVertice()->getVertice();
		triangles.push_back(Triangle(v1, v3, v2));
	}
//
//////////////////////////
}