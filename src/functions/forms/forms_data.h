
#ifndef STRUCTBI_FUNCTIONS_FORMSDATA
#define STRUCTBI_FUNCTIONS_FORMSDATA

#include "tools/function_data.h"
#include "tools/actions_data.h"

namespace StructBI
{
    namespace Functions
    {
        class FormsData;
    }
}

using namespace StructBI;
using namespace NAF;

class StructBI::Functions::FormsData : public Tools::FunctionData
{
    public:
        FormsData(FunctionData& function_data);

    protected:
        struct FileProcessing
        {
            bool Save();
            bool Delete();

            NAF::Files::FileManager::Ptr file_manager;
            Query::Parameter::Ptr param;
            bool modify = false;
            std::string filepath = "";
        };
        struct ParameterVerification
        {
            ParameterVerification(
                Query::Field::Ptr length
                ,Query::Field::Ptr required
                ,Query::Field::Ptr default_value
                ,Query::Field::Ptr column_type
                ,FileProcessing file_processing
            ) :
                length(length)
                ,required(required)
                ,default_value(default_value)
                ,column_type(column_type)
            {
                this->file_processing = file_processing;
            }
            bool Verify(Query::Parameter::Ptr param);

            Query::Field::Ptr length;
            Query::Field::Ptr required;
            Query::Field::Ptr default_value;
            Query::Field::Ptr column_type;
            FileProcessing file_processing;
        };

        void Read_();
        void ReadSpecific_();
        void ReadFile_();
        void Add_();
        void Modify_();
        void Delete_();

    private:
        Tools::ActionsData actions_;
};

#endif //STRUCTBI_FUNCTIONS_FORMSDATA