///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  Distributed under the MIT License  - http://opensource.org/licenses/MIT  //
//                                                                           //
//  Copyright (c) 2013 Gary Paluk      - http://www.plugin.io                //
//  Copyright (c) 2013 Panutat Tejasen - http://www.jimmysoftware.com        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#ifndef INDEXBUFFER_H
#define INDEXBUFFER_H

#include "Buffer.h"

#include "../../../Core/Assert/Assert.h"

namespace EX3
{
    class IndexBuffer : public Buffer
    {
        public:
            IndexBuffer (int numIndices, int indexSize, Usage usage = USAGE_STATIC);
            virtual ~IndexBuffer ();

            inline char* GetData () const;
            inline void SetOffset (int offset);
            inline int GetOffset () const;

        protected:
            int m_Offset;
    };

    //----------------------------------------------------------------------------
    inline char* IndexBuffer::GetData () const
    {
        return m_Data;
    }
    //----------------------------------------------------------------------------
    inline void IndexBuffer::SetOffset (int offset)
    {
        if (offset >= 0)
        {
            m_Offset = offset;
        }
        else
        {
            assertion(false, "The offset must be nonnegative\n");
        }
    }
    //----------------------------------------------------------------------------
    inline int IndexBuffer::GetOffset () const
    {
        return m_Offset;
    }
    //----------------------------------------------------------------------------
}

#endif // INDEXBUFFER_H
