///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  Distributed under the MIT License  - http://opensource.org/licenses/MIT  //
//                                                                           //
//  Copyright (c) 2013 Gary Paluk      - http://www.plugin.io                //
//  Copyright (c) 2013 Panutat Tejasen - http://www.jimmysoftware.com        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "VertexBuffer.h"

using namespace EX3;

//----------------------------------------------------------------------------
VertexBuffer::VertexBuffer (int numVertices, int vertexSize, Usage usage)
    :
    Buffer(numVertices, vertexSize, usage)
{
}
//----------------------------------------------------------------------------
VertexBuffer::~VertexBuffer ()
{
    //TODO - Unbind this resource from the renderers
}
//----------------------------------------------------------------------------
