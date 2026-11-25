#pragma once
#include "resources/DXResource.h"
#include "camera/CameraBuffer.h"
class CameraBufferResource :
    public DXResource
{
public:
    CameraBufferResource(ID3D12Device* device);
    virtual ~CameraBufferResource() = default;

    /// <summary>
	/// Updates the camera constant buffer data
    /// </summary>
    /// <param name="cameraCB">Camera constant buffer data</param>
    void updateCameraCB(const CameraCB cameraCB);

    
private:
	CameraCB cameraData = {};
};

