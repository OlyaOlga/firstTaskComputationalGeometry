#include "Triangle.h"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <cmath>
#include <vector>
#include <unordered_map>
#include "Computation.h"

Triangle::Triangle(Point _a, Point _b, Point _c)
{
	vertices.push_back(_a);
	vertices.push_back(_b);
	vertices.push_back(_c);
}

void Triangle::output(Mat & mat)const
{
	for(int i=0; i<vertices.size();++i)
	{
		Scalar color(0, 255, 255);
		line(mat, vertices[i % 3], vertices[(i + 1)%3], color);
		line(mat, vertices[i % 3], vertices[(i + 2)%3], color);
	}
	imshow("", mat);
}

Vec<Point, 2> Triangle::form_vector(Point main_point, Point first_point, Point second_point)
{
	Point first(first_point.x - main_point.x, first_point.y - main_point.y);
	Point second(second_point.x - main_point.x, second_point.y - main_point.y);
	Vec<Point, 2> result;
	result[0] = first;
	result[1] = second;
	return result;
}

vector<pair<Point, double>> Triangle::calculate_angles()
{
	vector<pair<Point, double>> points_angles;
	for (int i = 0; i < vertices.size(); ++i) 
	{
		Vec<Point,2> vectors = form_vector(vertices[i%vertices.size()], vertices[(i+1)%vertices.size()], vertices[(i+2)%vertices.size()]);
		double angle = Computation::find_angle(vectors[0], vectors[1]);
		points_angles.push_back(make_pair(vertices[i], angle));
	}
	return points_angles;
}


Mat & operator<<(Mat & mat, const Triangle & tr)
{
	tr.output(mat);
	return mat;
}
