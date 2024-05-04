#ifndef FACTORY_H
#define FACTORY_H

#include "classunit.h"
#include "methodunit.h"
#include "printoperatorunit.h"
#include "syntaxcode.h"
#include "unit.h"

class CodeGenerator
{
public:
    virtual std::shared_ptr<ClassUnit>  createClass(const std::string& name) = 0;
    virtual std::shared_ptr<MethodUnit> createMethod(const std::string& name, const std::string& returnType, unsigned int flags) = 0;
    virtual std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text) = 0;
    virtual std::shared_ptr<SyntaxCode> createSyntaxCode() = 0;
};

///////////////////////////////////////////////////////////////////////////////

class JavaCodeGenerator : public CodeGenerator
{
public:
    /*
    enum AccessModifier {
        PUBLIC = 0,
        PROTECTED = 1,
        PRIVATE = 3,
        DEFAULT = 4
    };

    enum Modifier {
        STATIC = 1,
        FINAL = 2
    };
    */
    std::shared_ptr<ClassUnit> createClass(const std::string& name) {
        return std::make_shared<JavaClass>(name);
    }
    std::shared_ptr<MethodUnit> createMethod(const std::string& name, const std::string& returnType, unsigned int flags) {
        return std::make_shared<JavaMethod>(name, returnType, flags);
    }
    std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text){
        return std::make_shared<JavaPrintOperator>(text);
    }
    std::shared_ptr<SyntaxCode> createSyntaxCode(){
        return std::make_shared<JavaSyntaxCode>();
    }
};

////////////////////////////////////////////////////////////////////////////////

class CsharpCodeGenerator : public CodeGenerator
{
public:
    /*
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        INTERNAL,
        PROTECTED_INTERNAL,
        PRIVATE_PROTECTED,
        FILE
    };
    enum Modifier {
        STATIC = 1,
        VIRTUAL = 2,
        OVERRIDE = 3

    };
    */
    std::shared_ptr<ClassUnit> createClass(const std::string& name) {
        return std::make_shared<CsharpClass>(name);
    }
    std::shared_ptr<MethodUnit> createMethod(const std::string& name, const std::string& returnType, unsigned int flags) {
        return std::make_shared<CsharpMethod>(name, returnType, flags);
    }
    std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text){
        return std::make_shared<CsharpPrintOperator>(text);
    }
    std::shared_ptr<SyntaxCode> createSyntaxCode(){
        return std::make_shared<CsharpSyntaxCode>();;
    }
};

////////////////////////////////////////////////////////////////////////////////

class CplusCodeGenerator : public CodeGenerator
{
public:
    /*
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE
    };

    enum Modifier {
        STATIC = 1,
        VIRTUAL = 2,
        CONST = 3
    };
    */
    std::shared_ptr<ClassUnit> createClass(const std::string& name) {
        return std::make_shared<CplusClass>(name);
    }
    std::shared_ptr<MethodUnit> createMethod(const std::string& name, const std::string& returnType, unsigned int flags) {
        return std::make_shared<CplusMethod>(name, returnType, flags);
    }
    std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text){
        return std::make_shared<CplusPrintOperator>(text);
    }
    std::shared_ptr<SyntaxCode> createSyntaxCode(){
        return std::make_shared<CplusSyntaxCode>();
    }
};

#endif // FACTORY_H
