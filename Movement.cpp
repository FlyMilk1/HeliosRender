#include "Movement.h"
#include "CameraSceneObject.h"
#include <cmath>

Movement::Movement(DXRenderer* dxRenderer, SceneObject* sceneObject)
	: renderer(dxRenderer), object(sceneObject)
{
}

void Movement::updatePosition(const MovementInput& input)
{
	if (!object || !renderer) {
		return;
	}

	float x = 0.0f, y = 0.0f, z = 0.0f; //Summation of movement in each axis
	if (input.moveForward)
		z += speed;
	if (input.moveBackward)
		z -= speed;
	if (input.moveLeft)
		x -= speed;
	if (input.moveRight)
		x += speed;
	if (input.moveUp)
		y += speed;
	if (input.moveDown)
		y -= speed;

	float CCWyaw = -object->getRotation().y; //Convert to counter-clockwise for correct movement direction
	object->setPosition(DirectX::XMFLOAT3(
		object->getPosition().x + (x * std::cos(CCWyaw) - z * std::sin(CCWyaw)),
		object->getPosition().y + y,
		object->getPosition().z + (x * std::sin(CCWyaw) + z * std::cos(CCWyaw))
	));
	// Update the camera buffer with the new position deltas
	renderer->updateCameraBuffer(static_cast<CameraSceneObject*>(object)->getCameraBuffer());
}
