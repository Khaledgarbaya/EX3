///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  Distributed under the MIT License  - http://opensource.org/licenses/MIT  //
//                                                                           //
//  Copyright (c) 2013 Gary Paluk      - http://www.plugin.io                //
//  Copyright (c) 2013 Panutat Tejasen - http://www.jimmysoftware.com        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#ifndef WIRESTATE_H
#define WIRESTATE_H

#include "../../../Core/Objects/EX3Object.h"

namespace EX3
{
    class WireState : public EX3Object
    {
        public:
            WireState();
            virtual ~WireState();

            bool Enabled;  // default: false
    };
}

#endif // WIRESTATE_H
