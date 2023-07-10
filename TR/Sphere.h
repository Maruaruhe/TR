#pragma once
#include <Vector3.h>
#include <Vector2.h>

class Sphere
{
public:
	void Init();
	void Update();
	void Draw();
	void Shot();

	Vector2 mPosition;
	Vector2 mVelocity;
	float mRadius;
	float mPower;

	float mGravity;
	bool mIsShot;
};

