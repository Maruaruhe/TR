#include "Dirt.h"
#include <Novice.h>
#include "Matrix.h"

void Dirt::Init() {
	mFirstPosition = {};
	mAddPosition = {};
	mPosition = mFirstPosition;
	mVelocity = {};
	mFirstVelocity = {};
	mFirstVelocity.y = -15.0f;
	mRadius = 30.0f;

	mGravity = 9.8f;
	mMass = 10.0f;

	mFlame = 0.0f;
	mSecond = 0;
}
void Dirt::Update() {
	//Reset
	if (Novice::CheckHitKey(DIK_R)) {
		Init();
	}
	Fall();
}
void Dirt::Draw() {
	Novice::DrawEllipse(int(mPosition.x), int(mPosition.y), int(mRadius), int(mRadius), 0.0f, WHITE, kFillModeSolid);
}

void Dirt::Fall() {
		mFlame += 1;
		mVelocity.y = mGravity * (mFlame / 15.0f) + mFirstVelocity.y;
		mPosition = Add(mPosition, mVelocity);
}