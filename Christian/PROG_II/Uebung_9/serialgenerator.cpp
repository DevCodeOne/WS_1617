#include "serialgenerator.h"

static int serialnr = 0;

int create_object_serial() {
	return serialnr++;
}

int next_object_serial() {
	return serialnr+1;
}
