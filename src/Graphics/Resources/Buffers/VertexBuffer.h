///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  Distributed under the MIT License  - http://opensource.org/licenses/MIT  //
//                                                                           //
//  Copyright (c) 2013 Gary Paluk      - http://www.plugin.io                //
//  Copyright (c) 2013 Panutat Tejasen - http://www.jimmysoftware.com        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

#include "Buffer.h"

namespace EX3
{
    class VertexBuffer : public Buffer
    {
        public:
            VertexBuffer (int numVertices, int vertexSize, Usage usage = USAGE_STATIC);
            virtual ~VertexBuffer ();

            inline char* GetData () const;
    };

    //----------------------------------------------------------------------------
    inline char* VertexBuffer::GetData () const
    {
        return m_Data;
    }
    //----------------------------------------------------------------------------
}

#endif // VERTEXBUFFER_H
