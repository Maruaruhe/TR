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
	void Fall();


	Vector2 mPosition;
	Vector2 mFirstVelocity;
	Vector2 mVelocity;
	float mRadius;
	float mPower;

	float mGravity;
	bool mIsShot;

	float mMass;

	float mFlame;
};

