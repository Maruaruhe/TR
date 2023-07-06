#include "GamePlay.h"
void GamePlay::Initialize(Sphere* sphere, Dirt* dirt) {
	sphere->Initialize();
	dirt->Initialize();
}

void GamePlay::Update(Sphere* sphere, Dirt* dirt) {
	sphere->Update();
	dirt->Update();
}

void GamePlay::Draw(Sphere* sphere, Dirt* dirt) {
	sphere->Draw();
	if (sphere->mIsHit) {
		dirt->Draw();
	}
}

float GamePlay::GetTheta(Sphere* sphere) {
	Vector2 delta;
	if (sphere->mIsHit) {
		delta.x = sphere->mCurrentPosition.x - sphere->mBeforePosition.x;
		delta.y = sphere->mCurrentPosition.y - sphere->mBeforePosition.y;
		float Radian;
		Radian = delta.x / delta.y;
		float theta = tanf(Radian);
		if (sphere->mCurrentPosition.x >= sphere->mBeforePosition.x&& theta<=0) {
			theta *= -1;
		}
		if (sphere->mCurrentPosition.x <= sphere->mBeforePosition.x && theta >= 0) {
			theta *= -1;
		}
		return theta;
	}
	return 0.0f;
}

Vector2 GamePlay::GetSpeed(Sphere* sphere) {
	Vector2 speed;
	float theta = GetTheta(sphere);
	speed.x = theta * 5;
	speed.y = -(sphere->mVelocity.y) / 3;
	return speed;
}