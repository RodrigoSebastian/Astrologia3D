#pragma once
class Lights
{
private:
	void GlobalLight();
	void SunLight();
	float lightAndSphere[4];
	float colorLight[4];

public:
	Lights(float sunLx, float sunLy, float sunLz, float r, float g, float b);
	void SetSunLight(float r, float g, float b);
};

