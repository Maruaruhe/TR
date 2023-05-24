#include "Sphere.h"
#include <Novice.h>
#include "Matrix.h"

void Sphere::Init() {
	mPosition = { 640.0f, 360.0f };
	mVelocity = {};
	mIsShot = false;
	mRadius = 30.0f;
	mGravity = 0.4f;
}
void Sphere::Update() {
	//Reset
	if (Novice::CheckHitKey(DIK_R)) {
		Init();
	}
	Shot();
	if (mIsShot) {
		mPosition = Add(mPosition, mVelocity);
		mVelocity.y += mGravity;
	}
	if (!mIsShot) {
		Novice::GetMousePosition(&px, &py);
	}
	//x
	if (px > mPosition.x) {
		mArrow.x = mPosition.x - (px - mPosition.x);
	}
	else {
		mArrow.x = mPosition.x + (mPosition.x - px);
	}
	//y
	if (py > mPosition.y) {
		mArrow.y = mPosition.y - (py - mPosition.y);
	}else {
		mArrow.y = mPosition.y + (mPosition.y - py);
	}
}
void Sphere::Draw() {
	Novice::DrawEllipse(int(mPosition.x), int(mPosition.y), int(mRadius), int(mRadius), 0.0f, WHITE, kFillModeSolid);
	if (!mIsShot) {
		Novice::DrawLine(int(mPosition.x), int(mPosition.y), px, py, WHITE);
		Novice::DrawLine(int(mPosition.x), int(mPosition.y), int(mArrow.x), int(mArrow.y), WHITE);
	}
}
void Sphere::Shot() {
	if (Novice::CheckHitKey(DIK_SPACE)) {
		mIsShot = true;
		mVelocity = { (mArrow.x - mPosition.x) / 25,(mArrow.y - mPosition.y) / 25 };
	}
}