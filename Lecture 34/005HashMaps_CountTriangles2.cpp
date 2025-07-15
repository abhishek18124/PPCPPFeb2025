/*
	Given N cartesian points in a 2D plane, count the number of right-angled triangles that
	can be formed such that the base or perpendicular is parallel to the x-axis or y-axis.

	Examples

	Input : {(0, 0),
	         (2, 0),
	         (0, 1)}

	Output: 1

	Input : {(1, 2),
			 (2, 0),
			 (2, 2),
			 (2, 3),
			 (4, 2)}

	Output: 4
*/

#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Point {
public:
	int x;
	int y;

	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

int main() {

	vector<Point> points = {
		Point(1, 2),
		Point(2, 0),
		Point(2, 2),
		Point(2, 3),
		Point(4, 2)
	};

	// time : O(nlogn)
	// space: O(n) due to xFreqMap and yFreqMap, assume x and y coorinates of all points are distinct

	map<int, int> xFreqMap;
	map<int , int> yFreqMap;

	for (Point p : points) {
		xFreqMap[p.x]++;
		yFreqMap[p.y]++;
	}

	int cnt = 0; // to track no. of valid triangles in the plane

	for (Point p : points) {

		// find out no. of valid triangles with 'p' as pivot

		// 1. find out no. of points in the 2d plane
		// whose x coordinate matches p.x

		// 2. find out no. of points in the 2d plane
		// whose y coordinate matches p.y

		int a = xFreqMap[p.x];
		int b = yFreqMap[p.y];

		a--; // you don't want to count pivot
		b--; // you don't want to count pivot

		cnt += a * b;


	}

	cout << cnt << endl;

	return 0;
}