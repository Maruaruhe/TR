#pragma once
#include <Vector3.h>
#include <Vector2.h>
#include <math.h>

class Dirt
{
public:

	void Init();
	void Update();
	void Draw();
	void Fall();

	void setGravity(float gravity) { mGravity = gravity; }
	void setMass(float mass) { mMass = mass; }

	Vector2 mAddPosition;
	Vector2 mFirstPosition;
	Vector2 mPosition;

	Vector2 mFirstVelocity;
	Vector2 mVelocity;

	float mRadius;
	float mGravity;
	float mMass;

	float theta;

	float mFlame;
	int mSecond;

private:

};

