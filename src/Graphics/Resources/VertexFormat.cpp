///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  Distributed under the MIT License  - http://opensource.org/licenses/MIT  //
//                                                                           //
//  Copyright (c) 2013 Gary Paluk      - http://www.plugin.io                //
//  Copyright (c) 2013 Panutat Tejasen - http://www.jimmysoftware.com        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "VertexFormat.h"
#include <cstdarg>

using namespace EX3;

int VertexFormat::msComponentSize[AT_QUANTITY] =
{
    0,  // AT_NONE
    4,  // AT_FLOAT1
    4,  // AT_FLOAT2
    4,  // AT_FLOAT3
    4,  // AT_FLOAT4
    2,  // AT_HALF1
    2,  // AT_HALF2
    2,  // AT_HALF3
    2,  // AT_HALF4
    1,  // AT_UBYTE4
    2,  // AT_SHORT1
    2,  // AT_SHORT2
    2   // AT_SHORT4
};

int VertexFormat::msNumComponents[AT_QUANTITY] =
{
    0,  // AT_NONE
    1,  // AT_FLOAT1
    2,  // AT_FLOAT2
    3,  // AT_FLOAT3
    4,  // AT_FLOAT4
    1,  // AT_HALF1
    2,  // AT_HALF2
    3,  // AT_HALF3
    4,  // AT_HALF4
    4,  // AT_UBYTE4
    1,  // AT_SHORT1
    2,  // AT_SHORT2
    4   // AT_SHORT4
};

int VertexFormat::msTypeSize[AT_QUANTITY] =
{
    0,  // AT_NONE
    4,  // AT_FLOAT1
    8,  // AT_FLOAT2
    12, // AT_FLOAT3
    16, // AT_FLOAT4
    2,  // AT_HALF1
    4,  // AT_HALF2
    6,  // AT_HALF3
    8,  // AT_HALF4
    4,  // AT_UBYTE4
    2,  // AT_SHORT1
    4,  // AT_SHORT2
    8   // AT_SHORT4
};

//----------------------------------------------------------------------------
VertexFormat::VertexFormat (int numAttributes)
    :
    m_NumAttributes(numAttributes),
    m_Stride(0)
{
    assertion(m_NumAttributes > 0, "Number of attributes must be positive\n");

    for (int i = 0; i < AM_MAX_ATTRIBUTES; ++i)
    {
        m_Elements[i].StreamIndex = 0;
        m_Elements[i].Offset = 0;
        m_Elements[i].Type = AT_NONE;
        m_Elements[i].Usage = AU_NONE;
        m_Elements[i].UsageIndex = 0;
    }
}
//----------------------------------------------------------------------------
VertexFormat::~VertexFormat ()
{
    //TODO - Unbind this resource from the renderers
}
//----------------------------------------------------------------------------
VertexFormat* VertexFormat::Create (int numAttributes, ...)
{
    VertexFormat* vformat = new VertexFormat(numAttributes);

    va_list arguments;
    va_start(arguments, numAttributes);

    unsigned int offset = 0;
    for (int i = 0; i < numAttributes; ++i)
    {
        int usage = va_arg(arguments, int);
        int type = va_arg(arguments, int);
        unsigned int usageIndex = va_arg(arguments, unsigned int);
        vformat->SetAttribute(i, 0, offset, (AttributeType)type,
            (AttributeUsage)usage, usageIndex);
        offset += msTypeSize[type];
    }
    vformat->SetStride((int)offset);

    va_end(arguments);

    return vformat;
}
//----------------------------------------------------------------------------
void VertexFormat::SetAttribute (int attribute, unsigned int streamIndex,
    unsigned int offset, AttributeType type, AttributeUsage usage,
    unsigned int usageIndex)
{
    assertion(0 <= attribute && attribute < m_NumAttributes,
        "Invalid index in SetAttribute\n");

#ifdef _DEBUG
    if (attribute > 0)
    {
        assertion(offset > m_Elements[attribute-1].Offset,
            "Offsets must be increasing with attribute index.\n");
    }
    else
    {
        assertion(offset == 0,
            "The offset of the first attribute must be zero.\n");
    }
#endif

    Element& element = m_Elements[attribute];
    element.StreamIndex = streamIndex;
    element.Offset = offset;
    element.Type = type;
    element.Usage = usage;
    element.UsageIndex = usageIndex;
}
//----------------------------------------------------------------------------
void VertexFormat::SetStride (int stride)
{
    assertion(stride > 0, "Stride must be positive\n");
    m_Stride = stride;
}
//----------------------------------------------------------------------------
void VertexFormat::GetAttribute (int attribute, unsigned int& streamIndex,
    unsigned int& offset, AttributeType& type, AttributeUsage& usage,
    unsigned int& usageIndex) const
{
    assertion(0 <= attribute && attribute < m_NumAttributes,
        "Invalid index in GetAttribute\n");

    const Element& element = m_Elements[attribute];
    streamIndex = element.StreamIndex;
    offset = element.Offset;
    type = element.Type;
    usage = element.Usage;
    usageIndex = element.UsageIndex;
}
//----------------------------------------------------------------------------
int VertexFormat::GetIndex (AttributeUsage usage, unsigned int usageIndex)
    const
{
    for (int i = 0; i < m_NumAttributes; ++i)
    {
        if (m_Elements[i].Usage == usage
        &&  m_Elements[i].UsageIndex == usageIndex)
        {
            return i;
        }
    }
    return -1;
}
//----------------------------------------------------------------------------
