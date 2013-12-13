///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  Distributed under the MIT License  - http://opensource.org/licenses/MIT  //
//                                                                           //
//  Copyright (c) 2013 Gary Paluk      - http://www.plugin.io                //
//  Copyright (c) 2013 Panutat Tejasen - http://www.jimmysoftware.com        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#ifndef EX3OBJECT_H
#define EX3OBJECT_H

#include "../CoreLib.h"

namespace EX3
{
    class EX3Object
    {
        public:
            virtual ~EX3Object();

            void SetName (const std::string& name);
            const std::string& GetName () const;
        protected:
            EX3Object();
        private:
            std::string m_Name;
    };
}

#endif // EX3OBJECT_H
