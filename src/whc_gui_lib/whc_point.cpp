#include "whc_point.h"

whc_point::whc_point()
{
	x=0;
	y=0;
}

whc_point::~whc_point()
{
	//dtor
}

whc_point::whc_point(unsigned int xx, unsigned int yy)
{
	x=xx; y=yy;
}

