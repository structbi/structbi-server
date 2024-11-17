
#ifndef STRUCTBI_FUNCTIONS_ORGANIZATIONS_GROUPS_H
#define STRUCTBI_FUNCTIONS_ORGANIZATIONS_GROUPS_H


#include "tools/function_data.h"
#include "tools/actions_data.h"

namespace StructBI
{
    namespace Functions
    {
        namespace Organizations
        {
            class Groups;
        }
    }
}

using namespace StructBI;
using namespace NAF;

class StructBI::Functions::Organizations::Groups : public Tools::FunctionData
{
    public:
        Groups(Tools::FunctionData& function_data);
        
    protected:
        void Read_();

    private:
        Tools::ActionsData actions_;

};

#endif //STRUCTBI_FUNCTIONS_ORGANIZATIONS_GROUPS_H