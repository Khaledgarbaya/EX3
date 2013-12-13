///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  Distributed under the MIT License  - http://opensource.org/licenses/MIT  //
//                                                                           //
//  Copyright (c) 2013 Gary Paluk      - http://www.plugin.io                //
//  Copyright (c) 2013 Panutat Tejasen - http://www.jimmysoftware.com        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#ifndef VERTEXFORMAT_H
#define VERTEXFORMAT_H

#include "../../Core/Assert/Assert.h"
#include "../../Core/Objects/EX3Object.h"

namespace EX3
{
    class VertexFormat : public EX3Object
    {
        enum
        {
            AM_MAX_ATTRIBUTES = 16,
            AM_MAX_TCOORD_UNITS = 8,
            AM_MAX_COLOR_UNITS = 2
        };

        enum AttributeType
        {
            AT_NONE,
            AT_FLOAT1,
            AT_FLOAT2,
            AT_FLOAT3,
            AT_FLOAT4,
            AT_HALF1,
            AT_HALF2,
            AT_HALF3,
            AT_HALF4,
            AT_UBYTE4,
            AT_SHORT1,
            AT_SHORT2,
            AT_SHORT4,
            AT_QUANTITY
        };

        enum AttributeUsage
        {
            AU_NONE,
            AU_POSITION,      // attr 0
            AU_NORMAL,        // attr 2
            AU_TANGENT,       // attr 14
            AU_BINORMAL,      // attr 15
            AU_TEXCOORD,      // attr 8-15
            AU_COLOR,         // attr 3-4
            AU_BLENDINDICES,  // attr 7
            AU_BLENDWEIGHT,   // attr 1
            AU_FOGCOORD,      // attr 5
            AU_PSIZE,         // attr 6
            AU_QUANTITY
        };

        public:
            VertexFormat (int numAttributes);
            virtual ~VertexFormat ();

            static VertexFormat* Create (int numAttributes, ...);

            void SetAttribute (int attribute, unsigned int streamIndex,
                                unsigned int offset, AttributeType type, AttributeUsage usage,
                                unsigned int usageIndex);

            void SetStride (int stride);

            inline int GetNumAttributes () const;

            inline unsigned int GetStreamIndex (int attribute) const;
            inline unsigned int GetOffset (int attribute) const;
            inline AttributeType GetAttributeType (int attribute) const;
            inline AttributeUsage GetAttributeUsage (int attribute) const;
            inline unsigned int GetUsageIndex (int attribute) const;

            void GetAttribute (int attribute, unsigned int& streamIndex,
                                unsigned int& offset, AttributeType& type, AttributeUsage& usage,
                                unsigned int& usageIndex) const;

            inline int GetStride () const;

            int GetIndex (AttributeUsage usage, unsigned int usageIndex = 0) const;

            inline static int GetComponentSize (AttributeType type);

            inline static int GetNumComponents (AttributeType type);

            inline static int GetTypeSize (AttributeType type);

        protected:
            class Element
            {
                public:
                    unsigned int StreamIndex;
                    unsigned int Offset;
                    AttributeType Type;
                    AttributeUsage Usage;
                    unsigned int UsageIndex;
            };

            int m_NumAttributes;
            Element m_Elements[AM_MAX_ATTRIBUTES];
            int m_Stride;

            static int msComponentSize[AT_QUANTITY];
            static int msNumComponents[AT_QUANTITY];
            static int msTypeSize[AT_QUANTITY];
        private:
    };

    //----------------------------------------------------------------------------
    inline int VertexFormat::GetNumAttributes () const
    {
        return m_NumAttributes;
    }
    //----------------------------------------------------------------------------
    inline unsigned int VertexFormat::GetStreamIndex (int attribute) const
    {
        if (0 <= attribute && attribute < m_NumAttributes)
        {
            return m_Elements[attribute].StreamIndex;
        }
        else
        {
            assertion(false, "Invalid index in GetStreamIndex\n");
            return 0;
        }
    }
    //----------------------------------------------------------------------------
    inline unsigned int VertexFormat::GetOffset (int attribute) const
    {
        if (0 <= attribute && attribute < m_NumAttributes)
        {
            return m_Elements[attribute].Offset;
        }
        else
        {
            assertion(false, "Invalid index in GetOffset\n");
            return 0;
        }
    }
    //----------------------------------------------------------------------------
    inline VertexFormat::AttributeType VertexFormat::GetAttributeType (
        int attribute) const
    {
        if (0 <= attribute && attribute < m_NumAttributes)
        {
            return m_Elements[attribute].Type;
        }
        else
        {
            assertion(false, "Invalid index in GetAttributeType\n");
            return AT_NONE;
        }
    }
    //----------------------------------------------------------------------------
    inline VertexFormat::AttributeUsage VertexFormat::GetAttributeUsage (
        int attribute) const
    {
        if (0 <= attribute && attribute < m_NumAttributes)
        {
            return m_Elements[attribute].Usage;
        }
        else
        {
            assertion(false, "Invalid index in GetAttributeUsage\n");
            return AU_NONE;
        }
    }
    //----------------------------------------------------------------------------
    inline unsigned int VertexFormat::GetUsageIndex (int attribute) const
    {
        if (0 <= attribute && attribute < m_NumAttributes)
        {
            return m_Elements[attribute].UsageIndex;
        }
        else
        {
            assertion(false, "Invalid index in GetUsageIndex\n");
            return 0;
        }
    }
    //----------------------------------------------------------------------------
    inline int VertexFormat::GetStride () const
    {
        return m_Stride;
    }
    //----------------------------------------------------------------------------
    inline int VertexFormat::GetComponentSize (AttributeType type)
    {
        return msComponentSize[type];
    }
    //----------------------------------------------------------------------------
    inline int VertexFormat::GetNumComponents (AttributeType type)
    {
        return msNumComponents[type];
    }
    //----------------------------------------------------------------------------
    inline int VertexFormat::GetTypeSize (AttributeType type)
    {
        return msTypeSize[type];
    }
    //----------------------------------------------------------------------------
}

#endif // VERTEXFORMAT_H
