#include <iostream>
#include <cmath>
#include <ctime>

#include "complexnumber.h"
#include "complexvector.h"
#include "svgfile.h"

int main() {
	srand(time(nullptr));

	complexnumber points[100];

	std::string colors[] = {"blue", "red", "yellow", "gray", "green", "purple", "orange", "black"};

	SVGFile s("out.svg");

	for (int i = 0; i < 100; i++) {
		points[i].real(rand() % 100);
		points[i].imag(rand() % 100);
		points[i].color(colors[rand() % 8]);
	}

	for (int i = 0; i < 100; i+= 2) {
		complexvector cv{points[i], points[(i + 1) % 100]};
		cv.color(colors[rand() % 8]);
		s.add(cv.to_svg());	
	}

	return 0;
}
