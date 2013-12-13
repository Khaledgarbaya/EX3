///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  Distributed under the MIT License  - http://opensource.org/licenses/MIT  //
//                                                                           //
//  Copyright (c) 2013 Gary Paluk      - http://www.plugin.io                //
//  Copyright (c) 2013 Panutat Tejasen - http://www.jimmysoftware.com        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#ifndef OFFSETSTATE_H
#define OFFSETSTATE_H

#include "../../../Core/Objects/EX3Object.h"

namespace EX3
{
    class OffsetState : public EX3Object
    {
        public:
            OffsetState();
            virtual ~OffsetState();

            bool FillEnabled;   // default: false
            bool LineEnabled;   // default: false
            bool PointEnabled;  // default: false

            float Scale;  // default: 0
            float Bias;   // default: 0
    };
}

#endif // OFFSETSTATE_H
