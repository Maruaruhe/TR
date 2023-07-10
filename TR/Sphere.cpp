#include "Sphere.h"
#include <Novice.h>
#include "Matrix.h"

void Sphere::Init() {
	mFirstPosition = { 640.0f, 360.0f };
	mAddPosition = { 3.0f, 0.0f };
	mPosition = mFirstPosition;
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
	mPosition = Add(mPosition, mAddPosition);
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
		/*mFirstVelocity = { (mArrow.x - mAddPosition.x) / 25,(mArrow.y - mAddPosition.y) / 25 };*/
		/*mFirstVelocity.y = -15.0f;*/
	}
	if (mIsShot) {

		mFlame += 1.0f;
		/*if (mFlame % 60 == 0) {
			mSecond += 1;
		}*/
		//ˆÊ’u
		mAddPosition.y = (mFirstVelocity.y * (mFlame/60.0f)) + (0.5f * mGravity * (mFlame/60.0f) * (mFlame/60.0f));
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

void Sphere::FreeFall() {

}