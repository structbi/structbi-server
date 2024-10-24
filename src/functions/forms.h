

#include <list>

#include "core/nebula_atom.h"
#include "handlers/backend_handler.h"
#include "functions/function.h"

using namespace Atom;

class Forms
{
    public:
        Forms();

        std::list<Functions::Function::Ptr>& get_functions()
        {
            auto& var = functions_;
            return var;
        }

    protected:
        void Read_();
        void Add_();
        void Modify_();
        void Delete_();

    private:
        std::list<Functions::Function::Ptr> functions_;
};
