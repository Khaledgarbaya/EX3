///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  Distributed under the MIT License  - http://opensource.org/licenses/MIT  //
//                                                                           //
//  Copyright (c) 2013 Gary Paluk      - http://www.plugin.io                //
//  Copyright (c) 2013 Panutat Tejasen - http://www.jimmysoftware.com        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#ifndef BUFFER_H
#define BUFFER_H

#include "../../../Core/Objects/EX3Object.h"

namespace EX3
{
    class Buffer: public EX3Object
    {
        public:
            enum Usage
            {
                USAGE_STATIC,
                USAGE_DYNAMIC,
                USAGE_RENDERTARGET,
                USAGE_DEPTHSTENCIL,
                USAGE_TEXTURE,
                USAGE_QUANTITY
            };

            virtual ~Buffer();

            inline int GetNumElements () const;
            inline int GetElementSize () const;
            inline Usage GetUsage () const;

            inline void SetNumElements (int numElements);

            inline int GetNumBytes () const;
            inline const char* GetData () const;

        protected:
            Buffer();
            Buffer (int numElements, int elementSize, Usage usage);

            int m_NumElements;
            int m_ElementSize;
            Usage m_Usage;
            int m_NumBytes;
            char* m_Data;
    };

    //----------------------------------------------------------------------------
    inline int Buffer::GetNumElements () const
    {
        return m_NumElements;
    }
    //----------------------------------------------------------------------------
    inline int Buffer::GetElementSize () const
    {
        return m_ElementSize;
    }
    //----------------------------------------------------------------------------
    inline Buffer::Usage Buffer::GetUsage () const
    {
        return m_Usage;
    }
    //----------------------------------------------------------------------------
    inline void Buffer::SetNumElements (int numElements)
    {
        m_NumElements = numElements;
    }
    //----------------------------------------------------------------------------
    inline int Buffer::GetNumBytes () const
    {
        return m_NumBytes;
    }
    //----------------------------------------------------------------------------
    inline const char* Buffer::GetData () const
    {
        return m_Data;
    }
    //----------------------------------------------------------------------------
}

#endif // BUFFER_H
