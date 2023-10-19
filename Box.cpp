
#include"Box.h"
#include<iostream>
using namespace std;

Box::Box()
{

}

Box::Box(int l, int w, int h) :length(l), width(w), height(h)
{
	this->length = l;
	this->width = w;
	this->height = h;
}

Box::Box(const Box& b)
{
	this->length = 2 * b.length;
	this->width = 2 * b.width;
	this->height = 2 * b.height;
}

Box::Box(const Box& b1, const Box& b2)
{
	this->length = b1.length + b2.length;
	this->width  = b1.width + b2.width;
	this->height = b1.height + b2.height;
}

void Box::compute_perimeter()
{
	cout << "立方体周长为：";
	cout << 2*(this->length + this->width + this->height) << endl;

}

void Box::compute_area()
{
	cout << "立方体的表面积是：";
	cout << 2 * (this->length * this->width +
				this->length * this->height +
				this->width * this->height) << endl;
}

void Box::compute_volume()
{
	cout << "立方体的体积是：";
	cout << this->length * this->width * this->height << endl;
}

