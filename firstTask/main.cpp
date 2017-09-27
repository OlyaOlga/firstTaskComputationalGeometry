#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "Curve.h"
#include "Triangle.h"
#include "Computation.h"
#include "TypeLineDefiner.h"

void data()
{
	Point a(5, 5);
	Point b(5, 100);
	Point c(100, 100);
}
using namespace std;
using namespace cv;
void main()
{
	int size = 1000;
	Point a(100, 6);
	Point b(10, 100);
	Point c(100, 100);
	Triangle tr(a, b, c);	
	Mat field(size, size, CV_8UC3);
	field = Scalar(255, 255, 255);
	auto angles = tr.calculate_angles();
	for (int i = 0; i < angles.size(); ++i)
	{
	//	cout << angles[i].first << " " << angles[i].second << endl;
	}
	
	field << tr;
	tr.print_bisectors(field);
	imshow("", field);
	waitKey();
	system("pause");
}