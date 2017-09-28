#pragma once
#include "opencv2/imgproc.hpp"
#include "AbstractLine.h"
#include<vector>
#include <cmath>

using namespace std;
using namespace cv;


	struct point_hasher 
	{	
		std::size_t operator () (const Point &p) const {
		auto h1 = std::hash<int>{}(p.x);
		auto h2 = std::hash<int>{}(p.y);
		return h1 ^ h2;
		}
	};

class Triangle
{
private:
	vector<Point> vertices;
	public:
	Triangle(Point _a, Point _b, Point _c);
	vector<AbstractLine*> get_lines_of_triangle();
	vector<AbstractLine*> get_bisectors();
	vector<double> get_sides_of_triangle();
	double getR();
	vector<Point> get_vertices();
	void output(Mat& mat);
	void print_by_sections(Mat& mat);
	vector<pair<Point, double>>  calculate_angles();
	Vec<Point, 2> form_vector(Point main_point, Point first_point, Point second_point);
	void print_bisectors(Mat& field);//debug method, to do
	Point2f find_median(Point2f first, Point2f second);
	Point find_center_of_big_circle();
	friend Mat& operator<<(Mat& mat, const Triangle& tr);
};