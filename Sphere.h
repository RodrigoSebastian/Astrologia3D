#pragma once
class Sphere
{
private:
	float radius = 1;
	float PI = 3.14159;
	float translate[3] = {0.0, 0.0, 0.0};
	float points[30 + 1][30 + 1][3];
	float speed = 0.05;
	float year;

	int stacks = 30;
	int slices = 30;

	bool finishCalc = false;

	void LogicSphere();
	float Map(float value, float start1, float stop1, float start2, float stop2) {
		return start2 + (stop2 - start2) * ((value - start1) / (stop1 - start1));
	}
	void DoRotation();

public:
	Sphere(float _r);
	Sphere();
	void SetSpeedAndTranslation(float _speed, float t0, float t1, float t2);

	void HaSolidSphere();
	void HaWireSphere(float _pointSize);
};

