#include "Plane.h"

Plane::Plane()
	: normal(Vect()), distance(0), color(Color())
{

}

Plane::Plane(Vect n, double d, Color c)
	: normal(n), distance(d), color(c)
{

}

Vect Plane::getNormalAt(Vect point)
{
	return normal;
}


// the distance from our ray origin to the point of intersection
double Plane::findIntersection(Ray ray)
{
	Vect rayDirection = ray.getDirection();
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
		//std::cout << -1 * b / a << std::endl;
		return -1 * b/a; // the distance from the ray origin to the intersection
	}

}