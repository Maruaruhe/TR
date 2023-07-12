#include "Sphere.h"
#include <Novice.h>
#include "Matrix.h"

void Sphere::Init() {
	mFirstPosition = { 640.0f, 360.0f };
	mAddPosition = { 3.0f, 0.0f };
	mPosition = mFirstPosition;
	mVelocity = {};
	mFirstVelocity = {};
	mFirstVelocity.y = -15.0f;
	mIsShot = false;
	mRadius = 30.0f;

	mGravity = 9.8f;
	mMass = 10.0f;

	mFlame = 0.0f;
	mSecond = 0;
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
	if (!mIsShot) {
		Novice::DrawLine(int(mFirstPosition.x), int(mFirstPosition.y), px, py, WHITE);
		Novice::DrawLine(int(mFirstPosition.x), int(mFirstPosition.y), int(mArrow.x), int(mArrow.y), WHITE);
	}
}
void Sphere::Shot() {
	if (Novice::CheckHitKey(DIK_SPACE)) {
		mIsShot = true;
	}
	if (!mIsShot) {
		Novice::GetMousePosition(&px, &py);
	}
	//x
	if (px > mFirstPosition.x) {
		mArrow.x = mFirstPosition.x - (px - mFirstPosition.x);
	}
	else {
		mArrow.x = mFirstPosition.x + (mFirstPosition.x - px);
	}
	//y
	if (py > mFirstPosition.y) {
		mArrow.y = mFirstPosition.y - (py - mFirstPosition.y);
	}
	else {
		mArrow.y = mFirstPosition.y + (mFirstPosition.y - py);
	}
}

void Sphere::Fall() {
	if (mIsShot) {
		mFlame += 1;
		mVelocity.y = mGravity * (mFlame / 15.0f) + mFirstVelocity.y;
		mPosition = Add(mPosition, mVelocity);
	}
}