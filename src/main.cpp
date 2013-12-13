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

using namespace EX3;

//----------------------------------------------------------------------------
int main(int argc, char* argv[])
{
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

    IndexBuffer* indexBuffer = new IndexBuffer(3, 2);
    delete indexBuffer;

    VertexBuffer* vertexBuffer = new VertexBuffer(3, 4);
    delete vertexBuffer;

    return 0;
}
//----------------------------------------------------------------------------
