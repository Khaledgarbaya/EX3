///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  Distributed under the MIT License  - http://opensource.org/licenses/MIT  //
//                                                                           //
//  Copyright (c) 2013 Gary Paluk      - http://www.plugin.io                //
//  Copyright (c) 2013 Panutat Tejasen - http://www.jimmysoftware.com        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "IndexBuffer.h"

using namespace EX3;

//----------------------------------------------------------------------------
IndexBuffer::IndexBuffer (int numIndices, int indexSize, Usage usage)
    :
    Buffer(numIndices, indexSize, usage),
    m_Offset(0)
{
}
//----------------------------------------------------------------------------
IndexBuffer::~IndexBuffer ()
{
    //TODO - Unbind this resource from the renderers
}
//----------------------------------------------------------------------------
