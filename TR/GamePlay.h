#pragma once
#define _USE_MATH_DEFINE
#include "Sphere.h"
#include "Dirt.h"
#include <math.h>

class GamePlay
{
public:
	void Initialize(Sphere* sphere,Dirt* dirt);
	void Update(Sphere* sphere, Dirt* dirt);
	void Draw(Sphere* sphere, Dirt* dirt);
	float GetTheta(Sphere* sphere);
	Vector2 GetSpeed(Sphere* sphere);
};

