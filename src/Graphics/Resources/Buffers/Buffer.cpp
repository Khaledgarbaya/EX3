///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  Distributed under the MIT License  - http://opensource.org/licenses/MIT  //
//                                                                           //
//  Copyright (c) 2013 Gary Paluk      - http://www.plugin.io                //
//  Copyright (c) 2013 Panutat Tejasen - http://www.jimmysoftware.com        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "Buffer.h"
#include "../../../Core/Assert/Assert.h"

using namespace EX3;

//----------------------------------------------------------------------------
Buffer::Buffer ()
    :
    m_NumElements(0),
    m_ElementSize(0),
    m_Usage(Buffer::USAGE_QUANTITY),
    m_NumBytes(0),
    m_Data(0)
{
}
//----------------------------------------------------------------------------
Buffer::Buffer (int numElements, int elementSize, Usage usage)
    :
    m_NumElements(numElements),
    m_ElementSize(elementSize),
    m_Usage(usage),
    m_NumBytes(numElements*elementSize)
{
    assertion(m_NumElements > 0, "Number of elements must be positive\n");
    assertion(m_ElementSize > 0, "Element size must be positive\n");

    // TODO reference counted objects
    //m_Data = new1<char>(m_NumBytes);
    m_Data = new char[m_NumBytes];
}
//----------------------------------------------------------------------------
Buffer::~Buffer ()
{
    // TODO reference counted objects
    // delete1(m_Data);
    delete [] m_Data;
}
//----------------------------------------------------------------------------
