#pragma once
#include "DXRenderer.h"
#include "MovementInput.h"
#include "SceneObject.h"

class Movement
{
public: //public functions
	Movement(DXRenderer* dxRenderer, SceneObject* sceneObject);
	virtual ~Movement() = default;

	/// <summary>
	/// Updates the current position using the provided movement input.
	/// </summary>
	/// <param name="input">Movement input data used to update position.</param>
	void updatePosition(const MovementInput& input);

private: //private variables
	DXRenderer* renderer = nullptr; //Non-owning pointer to DirectX renderer
	float speed = 0.05f; //Movement speed
	SceneObject* object = nullptr; //Non-owning pointer to the scene object
};
