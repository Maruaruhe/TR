#pragma once
#include <Vector3.h>
#include <Vector2.h>

class Sphere
{
public:
	void Initialize();
	void Update();
	void Draw();
	void Shot();

	Vector2 mPosition;
	Vector2 mBeforePosition;
	Vector2 mCurrentPosition;
	Vector2 mDirtPosition;
	Vector2 mVelocity;
	Vector2 mDirtVelocity;
	float mRadius;
	float mPower;
	Vector2 mArrow;
	int px;
	int py;
	float mGravity;
	bool mIsShot;
	bool mIsHit;
	int mFloor;
};

