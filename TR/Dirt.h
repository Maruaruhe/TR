#pragma once
#include "Vector2.h"

class Dirt
{
public:
	void Initialize();
	void Update();
	void Draw();

	Vector2 mPosition;
	Vector2 mVelocity;
	float mRadius;
	float mGravity;
};

