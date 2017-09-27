#include "Triangle.h"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <cmath>
#include <vector>
#include <unordered_map>
#include "Computation.h"
#include "TypeLineDefiner.h"
#include<iostream>

Triangle::Triangle(Point _a, Point _b, Point _c)
{
	vertices.push_back(_a);
	vertices.push_back(_b);
	vertices.push_back(_c);
}

vector<AbstractLine*> Triangle::get_lines_of_triangle()
{
	vector<AbstractLine*> lines;
	TypeLineDefiner definer;
	for (int i = 0; i < vertices.size(); ++i)
	{
		lines.push_back(definer.DefineType(vertices[i % 3], vertices[(i + 1) % 3]));
	}
	return lines;
}

vector<AbstractLine*> Triangle::get_bisectors()
{
	vector<AbstractLine*> lines_of_triangle = get_lines_of_triangle();
	vector<AbstractLine*> bisectors;
	TypeLineDefiner definer;
	

	for (int i = 0; i < lines_of_triangle.size(); ++i)
	{
		Mat field(1000, 1000, CV_8UC3);
		lines_of_triangle[i % 3]->drawLineByEquasion(field);
		lines_of_triangle[(i + 1) % 3]->drawLineByEquasion(field);
		double current_angle = AbstractLine::angleBetweenOXandBisector(lines_of_triangle[i % 3], lines_of_triangle[(i + 1) % 3]);
		bisectors.push_back(definer.DefineType(vertices[(i+1)%3].x, vertices[(i + 1) % 3].y, current_angle));
		bisectors[i]->drawLineByEquasion(field);
	}
	return bisectors;
}

void Triangle::output(Mat & mat)
{
	auto lines = get_lines_of_triangle();
	for (int i = 0; i < lines.size(); ++i)
	{
		lines[i]->drawLineByEquasion(mat);
	}
}

Vec<Point, 2> Triangle::form_vector(Point main_point, Point first_point, Point second_point)// forms vectors that comes from one point(main point)
{
	Point first(first_point.x - main_point.x, first_point.y - main_point.y);
	Point second(second_point.x - main_point.x, second_point.y - main_point.y);
	Vec<Point, 2> result;
	result[0] = first;
	result[1] = second;
	return result;
}

void Triangle::print_bisectors(Mat& field)
{	
	vector<AbstractLine*> bisectors = get_bisectors();
	for (int i = 0; i < 3; ++i)
	{
		bisectors[i]->drawLineByEquasion(field);
		std::cout << bisectors[i]->angleBetweenOXandLine()<<endl;
	}
}

vector<pair<Point, double>> Triangle::calculate_angles()//delete this
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
	for (int i = 0; i<tr.vertices.size(); ++i)
	{
		Scalar color(0, 255, 255);
		line(mat, tr.vertices[i % 3], tr.vertices[(i + 1) % 3], color);
		line(mat, tr.vertices[i % 3], tr.vertices[(i + 2) % 3], color);
	}
	imshow("", mat);
	return mat;
}
