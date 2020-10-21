#pragma once
typedef unsigned short ushort;
typedef unsigned long ulong;
typedef unsigned char uchar;

class mRGB {
public:
	unsigned char r, g, b;

	mRGB();
	mRGB(mRGB& p);
	mRGB(uchar rr, uchar gg, uchar bb);
	void set(uchar rr, uchar gg, uchar bb);
};
