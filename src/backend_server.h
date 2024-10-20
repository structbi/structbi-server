
#include "core/nebula_atom.h"
#include "handlers/backend_handler.h"

#include "functions/forms.h"

using namespace Atom;

class BackendServer : public Handlers::BackendHandler
{
    public:
        BackendServer() : Handlers::BackendHandler(){}
        virtual ~BackendServer() {}

        void AddFunctions_();

        void Process_() override;
};
