#include <iostream>
#include <fstream>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "Curve.h"
#include "Triangle.h"
#include "Computation.h"
#include "TypeLineDefiner.h"

using namespace std;
using namespace cv;

void data()
{


	Point a(100, 6);
	Point b(10, 100);
	Point c(100, 100);
}
void data_2()
{
	Point a(5, 5);
	Point b(5, 100);
	Point c(100, 100);
}

void data_3()
{
	Point a(30, 100);
	Point b(100, 30);
	Point c(40, 40);
}

void data_4()
{
	Point a(100, 100);
	Point b(30, 300);
	Point c(130, 300);
}

void data_5()
{
	Point a(500, 50);
	Point b(5, 300);
	Point c(100, 10);
}

void data_6()
{
	Point a(100, 110);
	Point b(30, 310);
	Point c(130, 330);
}
void smaller_circle()
{
	int size = 1000;

	Point a(5, 5);
	Point b(5, 100);
	Point c(100, 100);

	Triangle tr(a, b, c);
	Mat field(size, size, CV_8UC3);
	field = Scalar(255, 255, 255);
	field << tr;
	imshow("", field);
	Point center = tr.findCenterOfSmallCircle();
	waitKey();
}
void bigger_circle()
{
	int size = 1000;
	Point a(200, 300);
	Point b(400, 300);
	Mat main_mat(size, size, CV_8UC3);
	Curve curve;
	fstream curvePoints("points.txt");
	curvePoints >> curve;
	vector<AbstractLine*> lines;
	vector<Point> allImportantPoints = curve.getPoints();
	TypeLineDefiner definer;
	for (int i = 1; i < allImportantPoints.size(); ++i)
	{
		lines.push_back(definer.DefineType(allImportantPoints[i - 1], allImportantPoints[i]));
		lines.back()->drawLine(allImportantPoints[i - 1], allImportantPoints[i], main_mat);
	}
	imshow("", main_mat);
	waitKey();
	for (int j = 0; j < allImportantPoints.size() - 1; ++j)
	{
		for (int i = allImportantPoints[j].x; i < allImportantPoints[j + 1].x; ++i)
		{
			Mat mat;
			Point c(i, lines[j]->get_a()*i + lines[j]->get_b());
			Triangle tr(a, b, c);
			tr.find_center_of_big_circle();
			waitKey(30);
		}
	}
	waitKey();
}
void main()
{
	//bigger_circle();
	smaller_circle();
	system("pause");
}