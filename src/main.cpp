///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  Distributed under the MIT License  - http://opensource.org/licenses/MIT  //
//                                                                           //
//  Copyright (c) 2013 Gary Paluk      - http://www.plugin.io                //
//  Copyright (c) 2013 Panutat Tejasen - http://www.jimmysoftware.com        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "MathHeaders.h"
#include "GraphicsHeaders.h"

#include <iostream>
#include <assert.h>

#include "Math/Core/Float4.h"

#include "Graphics/Shaders/States/AlphaState.h"
#include "Graphics/Shaders/States/CullState.h"
#include "Graphics/Shaders/States/DepthState.h"
#include "Graphics/Shaders/States/StencilState.h"
#include "Graphics/Shaders/States/OffsetState.h"
#include "Graphics/Shaders/States/WireState.h"

using namespace EX3;

//----------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    // Math/Geom
    Tuple* tuple = new Tuple();
    delete tuple;

    Point* point = new Point();
    delete point;

    Quaternion* quaternion = new Quaternion();
    delete quaternion;

    Vector* vector = new Vector();
    delete vector;

    Matrix* matrix = new Matrix();
    delete matrix;

    Plane* plane = new Plane();
    delete plane;

    // Graphics/Resources
    IndexBuffer* indexBuffer = new IndexBuffer(3, 2);
    delete indexBuffer;

    VertexBuffer* vertexBuffer = new VertexBuffer(3, 4);
    delete vertexBuffer;

    Float4* float4 = new Float4();
    delete float4;

    // Graphics/Shaders/States
    AlphaState* alphaState = new AlphaState();
    delete alphaState;

    CullState* cullState = new CullState();
    delete cullState;

    DepthState* depthState = new DepthState();
    delete depthState;

    StencilState* stencilState = new StencilState();
    delete stencilState;

    OffsetState* offsetState = new OffsetState();
    delete offsetState;

    WireState* wireState = new WireState();
    delete wireState;


    return 0;
}
//----------------------------------------------------------------------------
