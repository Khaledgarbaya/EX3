///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  Distributed under the MIT License  - http://opensource.org/licenses/MIT  //
//                                                                           //
//  Copyright (c) 2013 Gary Paluk      - http://www.plugin.io                //
//  Copyright (c) 2013 Panutat Tejasen - http://www.jimmysoftware.com        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#ifndef CULLSTATE_H
#define CULLSTATE_H

#include "../../../Core/Objects/EX3Object.h"

namespace EX3
{
    class CullState : public EX3Object
    {
        public:
            CullState();
            virtual ~CullState();

            bool Enabled;   // default: true
            bool CCWOrder;  // default: true

        protected:
        private:
    };
}

#endif // CULLSTATE_H
