
#include "functions/forms.h"
#include <functions/action.h>

Forms::Forms()
{
    Read_();
    ReadSpecific_();
    Add_();
    Modify_();
    Delete_();
}

void Forms::Read_()
{
    // Function GET /api/forms/read
    Functions::Function::Ptr function = 
        std::make_shared<Functions::Function>("/api/forms/read", HTTP::EnumMethods::kHTTP_GET);

    auto action = function->AddAction_("a1");
    action->set_sql_code("SELECT * FROM forms");

    functions_.push_back(function);
}

void Forms::ReadSpecific_()
{
    // Function GET /api/forms/read/id
    Functions::Function::Ptr function = 
        std::make_shared<Functions::Function>("/api/forms/read/id", HTTP::EnumMethods::kHTTP_GET);

    auto action = function->AddAction_("a1");
    action->set_sql_code("SELECT * FROM forms WHERE id = ?");

    // Parameters and conditions
    action->AddParameter_("form_id", Tools::DValue(""), true)
    ->SetupCondition_("condition-identifier", Query::ConditionType::kError, [](Query::Parameter::Ptr param)
    {
        if(param->get_value().ToString_() == "")
        {
            param->set_error("El identificador del formulario no puede estar vacío");
            return false;
        }
        return true;
    });

    functions_.push_back(function);
}

void Forms::Add_()
{
    // Function POST /api/forms/add
    Functions::Function::Ptr function = 
        std::make_shared<Functions::Function>("/api/forms/add", HTTP::EnumMethods::kHTTP_POST);

    // Action 1: Verify that the form identifier don't exists
    auto action1 = function->AddAction_("a1");
    action1->set_sql_code("SELECT id FROM forms WHERE identifier = ?");
    action1->SetupCondition_("verify-form-existence", Query::ConditionType::kError, [](Functions::Action* action)
    {
        if(action->get_results()->size() > 0)
        {
            action->set_custom_error("Un formulario con este identificador ya existe");
            return false;
        }

        return true;
    });

    action1->AddParameter_("identifier", Tools::DValue(""), true)
    ->SetupCondition_("condition-identifier", Query::ConditionType::kError, [](Query::Parameter::Ptr param)
    {
        if(param->get_value().ToString_() == "")
        {
            param->set_error("El identificador no puede estar vacío");
            return false;
        }
        return true;
    });

    // Action 2: Add the new form
    auto action2 = function->AddAction_("a2");
    action2->set_sql_code("INSERT INTO forms (identifier, name, state, description, id_cloud_organization) VALUES (?, ?, ?, ?, 1)");

    action2->AddParameter_("identifier", Tools::DValue(""), true)
    ->SetupCondition_("condition-identifier", Query::ConditionType::kError, [](Query::Parameter::Ptr param)
    {
        if(param->get_value().get_type() != Tools::DValue::Type::kString)
        {
            param->set_error("El identificador debe ser una cadena de texto");
            return false;
        }
        if(param->get_value().ToString_() == "")
        {
            param->set_error("El identificador no puede estar vacío");
            return false;
        }
        if(param->get_value().ToString_().size() < 3)
        {
            param->set_error("El identificador no puede ser menor a 3 dígitos");
            return false;
        }
        return true;
    });
    action2->AddParameter_("name", Tools::DValue(""), true)
    ->SetupCondition_("condition-name", Query::ConditionType::kError, [](Query::Parameter::Ptr param)
    {
        if(param->get_value().get_type() != Tools::DValue::Type::kString)
        {
            param->set_error("El nombre debe ser una cadena de texto");
            return false;
        }
        if(param->get_value().ToString_() == "")
        {
            param->set_error("El nombre no puede estar vacío");
            return false;
        }
        if(param->get_value().ToString_().size() < 3)
        {
            param->set_error("El nombre no puede ser menor a 3 dígitos");
            return false;
        }
        return true;
    });
    action2->AddParameter_("state", Tools::DValue(""), true)
    ->SetupCondition_("condition-state", Query::ConditionType::kError, [](Query::Parameter::Ptr param)
    {
        if(param->get_value().get_type() != Tools::DValue::Type::kString)
        {
            param->set_error("El estado debe ser una cadena de texto");
            return false;
        }
        if(param->get_value().ToString_() == "")
        {
            param->set_error("El estado no puede estar vacío");
            return false;
        }
        if(param->get_value().ToString_().size() < 3)
        {
            param->set_error("El estado no puede ser menor a 3 dígitos");
            return false;
        }
        return true;
    });
    action2->AddParameter_("description", Tools::DValue(""), true);

    functions_.push_back(function);
}

void Forms::Modify_()
{
    
}

void Forms::Delete_()
{

}