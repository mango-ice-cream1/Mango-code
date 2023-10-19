#pragma once


class Box
{
public:
	Box();
	Box(int l, int w, int h);

	Box(const Box& b);
	Box(const Box& b1, const Box& b2);

	void compute_perimeter();
	void compute_area();
	void compute_volume();

private:
	int length;
	int width;
	int height;
};