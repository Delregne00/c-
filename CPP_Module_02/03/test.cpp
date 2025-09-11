#include <iostream>

int main(void){
	int ax = 0;
	int ay = 4;
	int bx = 2;
	int by = 6;
	int cx = 3;
	int cy = 4;

	int area = (ax * (by - cy) + bx * (cy - ay) + cx * (ay - by)) / 2;
	if (area < 0)
		area *= -1;
	std::cout << "Area triangulo: " << area << std::endl;
	return 0;
}
