
#ifndef STRUCTBI_FUNCTIONS_ORGANIZATIONS_H
#define STRUCTBI_FUNCTIONS_ORGANIZATIONS_H


#include "tools/function_data.h"
#include "tools/actions_data.h"

namespace StructBI
{
    namespace Functions
    {
        class Organizations;
    }
}

using namespace StructBI;
using namespace NAF;

class StructBI::Functions::Organizations : public Tools::FunctionData
{
    public:
        Organizations(Tools::FunctionData& function_data);
        
    protected:
        void Read_();
        void Modify_();

    private:
        Tools::ActionsData actions_;

};

#endif //STRUCTBI_FUNCTIONS_ORGANIZATIONS_H