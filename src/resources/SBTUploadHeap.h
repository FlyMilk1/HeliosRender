#pragma once
#include "resources/DXResource.h"
class SBTUploadHeap :
    public DXResource
{
    public: //Public Functions
    SBTUploadHeap(ID3D12Device* device, const UINT& size);
	~SBTUploadHeap() override = default;
};

