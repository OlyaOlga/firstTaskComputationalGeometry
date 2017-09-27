#pragma once
#include "opencv2/imgproc.hpp"
#include<unordered_map>

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
	void output(Mat& mat)const;
	vector<pair<Point, double>>  calculate_angles();
	Vec<Point, 2> form_vector(Point main_point, Point first_point, Point second_point);
	friend Mat& operator<<(Mat& mat, const Triangle& tr);
};