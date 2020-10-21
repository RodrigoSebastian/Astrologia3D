#include "mRGB.h"

mRGB::mRGB() { 
	r = g = b = 0; 
}

mRGB::mRGB(mRGB& p) {
	r = p.r; 
	g = p.g; 
	b = p.b; 
}

mRGB::mRGB(uchar rr, uchar gg, uchar bb) { 
	r = rr; 
	g = gg; 
	b = bb; 
}

void mRGB::set(uchar rr, uchar gg, uchar bb) {
	r = rr; 
	g = gg; 
	b = bb; 
}