#pragma once
#include <Vector3.h>
#include <Vector2.h>
#include <math.h>

class Sphere
{
public:
	void Init();
	void Update();
	void Draw();
	void Shot();
	void FreeFall();

	void setGravity(float gravity) { mGravity = gravity; }
	void setMass(float mass) { mMass = mass; }

	Vector2 mAddPosition;
	Vector2 mFirstPosition;
	Vector2 mPosition;
	Vector2 mFirstVelocity;
	float mRadius;
	float mPower;
	Vector2 mArrow;
	int px;
	int py;
	float mGravity;
	float mMass;
	bool mIsShot;

	float theta;

	float mFlame;
	int mSecond;
};

