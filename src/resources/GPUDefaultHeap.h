#pragma once
#include "resources/DXResource.h"
#include <vector>
#include "utils/Vertex.h"
class GPUDefaultHeap : public DXResource
{
public:
    GPUDefaultHeap(ID3D12Device* device, UINT verticesCount);
};

