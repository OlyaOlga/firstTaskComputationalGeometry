#include "Computation.h"




double Computation::count_norm(Point2f vect)
{
	return sqrt(pow(vect.x, 2) + pow(vect.y, 2));
}

double Computation::scalar_product(Point p1, Point p2)
{
	return p1.x*p2.x + p1.y * p2.y;
}

double Computation::cos_of_angle(Point vect1, Point vect2)
{
	return(scalar_product(vect1, vect2) / (count_norm(vect1) * count_norm(vect2)));
}

double Computation::arc_cos(double cos)
{
	return acos(cos) * 180 / PI;
}

double Computation::find_angle(Point v1, Point v2)
{
	return arc_cos(cos_of_angle(v1, v2));
}

double Computation::from_rad_to_degree(double rad)
{
	return rad*180/PI;
}

pair<Point2f, Point2f> Computation::intersection_of_circle_and_plane(AbstractLine* line, double r, Mat& m)
{
	Point2f firstRes;
	Point2f secondRes;
	//y = (r ^ 2 — R ^ 2 — a ^ 2 — b ^ 2 — 2ax) / 2b.
	double A = line->get_a()*line->get_a() + 1;
	double B = 2 * line->get_a()*line->get_b();
	double C = line->get_b()*line->get_b() - r*r;
	double D = B*B - 4 * A*C;
	double x0 = (-B + sqrt(D)) / (2 * A);
	double x1 = (-B - sqrt(D)) / (2 * A);
	double y0 = line->get_a()*x0 + line->get_b();
	double y1 = line->get_a()*x1 + line->get_b();
	firstRes.x = x0;
	firstRes.y = y0;
	secondRes.x = x1;
	secondRes.y = y1;
	return make_pair(firstRes, secondRes);
}


