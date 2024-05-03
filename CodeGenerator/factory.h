#ifndef FACTORY_H
#define FACTORY_H

#include "classunit.h"
#include "methodunit.h"
#include "printoperatorunit.h"
#include "unit.h"

class CodeGenerator
{
public:
    virtual std::shared_ptr<ClassUnit>  createClass(const std::string& name) = 0;
    virtual std::shared_ptr<MethodUnit> createMethod(const std::string& name, const std::string& returnType, unsigned int flags) = 0;
    virtual std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text) = 0;
};

///////////////////////////////////////////////////////////////////////////////

class JavaCodeGenerator : public CodeGenerator
{
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        DEFAULT
    };

    enum Modifier {
        STATIC = 1,
        FINAL = 2
    };

    std::shared_ptr<ClassUnit> createClass(const std::string& name) {
        return std::make_shared<JavaClass>(name);
    }
    std::shared_ptr<MethodUnit> createMethod(const std::string& name, const std::string& returnType, unsigned int flags) {
        return std::make_shared<JavaMethod>(name, returnType, flags);
    }
    std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text){
        return std::make_shared<JavaPrintOperator>(text);
    }
};

////////////////////////////////////////////////////////////////////////////////

class CsharpCodeGenerator : public CodeGenerator
{
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE
    };

    enum Modifier {
        STATIC = 1,
        OVERRIDE = 2,
        VIRTUAL = 3
    };

    std::shared_ptr<ClassUnit> createClass(const std::string& name) {
        return std::make_shared<CplusClass>(name);
    }
    std::shared_ptr<MethodUnit> createMethod(const std::string& name, const std::string& returnType, unsigned int flags) {
        return std::make_shared<CplusMethod>(name, returnType, flags);
    }
    std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text){
        return std::make_shared<CplusPrintOperator>(text);
    }
};

////////////////////////////////////////////////////////////////////////////////

class CplusCodeGenerator : public CodeGenerator
{
    enum AccessModifier {
        PUBLIC,
        PROTECTED_INTERNAL,
        INTERNAL,
        PROTECTED,
        PRIVATE_PROTECTED,
        PRIVATE,
        FILE
    };

    enum Modifier {
        STATIC = 1,
        VIRTUAL = 2,
        CONST = 3
    };

    std::shared_ptr<ClassUnit> createClass(const std::string& name) {
        return std::make_shared<CplusClass>(name);
    }
    std::shared_ptr<MethodUnit> createMethod(const std::string& name, const std::string& returnType, unsigned int flags) {
        return std::make_shared<CplusMethod>(name, returnType, flags);
    }
    std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text){
        return std::make_shared<CplusPrintOperator>(text);
    }
};

#endif // FACTORY_H
