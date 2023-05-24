#include "Dirt.h"
#include <Novice.h>

void Dirt::Initialize() {
	mPosition = {};
	mVelocity = {};
	mRadius = 10;
	mGravity = 0.4f;
}
void Dirt::Update() {
	mPosition.x += mVelocity.x;
	mPosition.y += mVelocity.y;
	mVelocity.y += mGravity;
}
void Dirt::Draw() {
	Novice::DrawEllipse(int(mPosition.x), int(mPosition.y), int(mRadius), int(mRadius), 0.0f, GREEN, kFillModeSolid);
}