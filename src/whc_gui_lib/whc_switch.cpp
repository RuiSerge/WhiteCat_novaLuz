#include "whc_switch.h"

std::map<int,ol::Bitmap> whc_switch::map_switch_bmp;
std::map<int,ol::Bitmap> whc_switch::map_switch_label;

whc_switch::whc_switch()
{
	//ctor
}

whc_switch::~whc_switch()
{
	//dtor
}

void whc_switch::init_map_switch_bmp()
{
	map_switch_bmp[1].Load("gfx/onIcon.png");
	map_switch_bmp[0].Load("gfx/offIcon.png");
}
