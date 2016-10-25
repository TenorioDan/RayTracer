#include "Triangle.h"

Triangle::Triangle()
	: A(Vect(1, 0, 0)), B(0, 1, 0), C(0, 0, 1), color(Color(0.5, 0.5, 0.5, 0))
{

}

Triangle::Triangle(Vect x, Vect y, Vect z, Color c)
	: A(x), B(y), C(z), color(c)
{

}

Vect Triangle::getNormalAt(Vect point)
{
	return normal;
}

Vect Triangle::getNormal()
{
	Vect CA = C - A;
	Vect BA = B - A;
	normal = CA.crossProduct(BA).normalize();
	return normal;
}

double Triangle::getDistance()
{
	normal = getNormal();
	distance = normal * A;
	return distance;
}

Color Triangle::getColor()
{
	return color;
}


// the distance from our ray origin to the point of intersection
double Triangle::findIntersection(Ray ray)
{
	Vect rayDirection = ray.getDirection();
	Vect rayOrigin = ray.getOrigin();

	normal = getNormal();
	distance = getDistance();

	double a = rayDirection*normal;

	if (a == 0)
	{
		// ray is parallel to the plane
		return -1.0;
	}
	else
	{
		// TODO return to this, it might be wrong
		double b = normal * (ray.getOrigin() - (normal*distance));
		double distanceToPlane = -1 * b / a;
		Vect Q = (rayDirection * distanceToPlane) + rayOrigin;

		Vect CA = C - A;
		Vect QA = Q - A;
		double test1 = CA.crossProduct(QA) * normal;

		Vect BC = B - C;
		Vect QC = Q - C;
		double test2 = BC.crossProduct(QC) * normal;

		Vect AB = A - B;
		Vect QB = Q - B;
		double test3 = AB.crossProduct(QB) * normal;

		if ((test1 >= 0) && (test2 >= 0) && (test3 >= 0)) {
			return distanceToPlane;
		}
		else {
			return -1;
		}
	}

}