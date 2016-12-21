#include <iostream>
#include <cmath>
#include <ctime>

#include "complexpolygon.h"
#include "svgfile.h"
#include "debug.h"

int main() {

	complexpolygon c{{0, 0}, {0, 100}};
	complexpolygon c2{{100, 100}, {100, 0}};

	SVGFile s("out.svg");

	c += c2;

	std::cout << c << std::endl;

	s.add(c.to_svg());

	return 0;
}
