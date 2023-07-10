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
}
void Sphere::Draw() {
	Novice::DrawEllipse(int(mPosition.x), int(mPosition.y), int(mRadius), int(mRadius), 0.0f, WHITE, kFillModeSolid);
}
void Sphere::Shot() {
	if (Novice::CheckHitKey(DIK_SPACE)) {
		mIsShot = true;
	}
}