#include "Sphere.h"
#include <Novice.h>
#include "Matrix.h"

void Sphere::Init() {
	mPosition = { 640.0f, 360.0f };
	mVelocity = {};
	mIsShot = false;
	mRadius = 30.0f;
	mGravity = 9.8f;

	mFirstVelocity.y = -10.0f;
	mFirstVelocity.x = 3.0f;

	mFlame = 0.0f;
}
void Sphere::Update() {
	//Reset
	if (Novice::CheckHitKey(DIK_R)) {
		Init();
	}
	Shot();
	Fall();
}
void Sphere::Draw() {
	Novice::DrawEllipse(int(mPosition.x), int(mPosition.y), int(mRadius), int(mRadius), 0.0f, WHITE, kFillModeSolid);
}
void Sphere::Shot() {
	if (Novice::CheckHitKey(DIK_SPACE)) {
		mIsShot = true;
	}
}

void Sphere::Fall() {
	if (mIsShot) {
		mFlame += 1;
		mPosition = Add(mPosition, mVelocity);
		mVelocity.y = mGravity * (mFlame / 15.0f) + mFirstVelocity.y;
	}
}