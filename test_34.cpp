

#include<iostream>
using namespace std;

#include"Box.h"


int main() {
	int l, w, h;
	char flag = 'y';
	while (flag == 'y') {
		cout << "Please input the length, width and height of the box: ";
		cin >> l >> w >> h;
		Box b1(l, w, h);
		b1.compute_perimeter();
		b1.compute_area();
		b1.compute_volume();
		Box b2(b1);
		cout << "The perimeter, superficialarea and volume of a box with double length, width and height is as follows:" << endl;
		b2.compute_perimeter();
		b2.compute_area();
		b2.compute_volume();
		Box b3(b1, b2);
		cout << "The perimeter, superficialarea and volume of a box with merging the length, width and height of box1 and box2 is as follows:" << endl;
		b3.compute_perimeter();
		b3.compute_area();
		b3.compute_volume();
		cout << "Do you want to continue to compute the perimeter, superficialarea and volume of a box(y or n)? ";
		cin >> flag;
	}
	
	return 0;
}
