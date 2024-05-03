#ifndef FACTORY_H
#define FACTORY_H

#include "classunit.h"
#include "methodunit.h"
#include "printoperatorunit.h"
#include "unit.h"

class CodeGenerator
{
public:
    virtual ClassUnit* createClass(const std::string& name) = 0;
    virtual MethodUnit* createMethod(const std::string& name, const std::string& returnType, unsigned int flags) = 0;
    virtual PrintOperatorUnit* createPrintOperatorUnit(const std::string& text) = 0;
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

    ClassUnit* createClass(const std::string& name) {
        return new JavaClass(name);
    }
    MethodUnit* createMethod(const std::string& name, const std::string& returnType, unsigned int flags) {
        return new JavaMethod(name, returnType, flags);
    }
    PrintOperatorUnit* createPrintOperatorUnit(const std::string& text){
        return new JavaPrintOperator(text);
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

    ClassUnit* createClass(const std::string& name) {
        return new CsharpClass(name);
    }
    MethodUnit* createMethod(const std::string& name, const std::string& returnType, unsigned int flags) {
        return new CsharpMethod(name, returnType, flags);
    }
    PrintOperatorUnit* createPrintOperatorUnit(const std::string& text){
        return new CsharpPrintOperator(text);
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

    ClassUnit* createClass(const std::string& name) {
        return new CplusClass(name);
    }
    MethodUnit* createMethod(const std::string& name, const std::string& returnType, unsigned int flags) {
        return new CplusMethod(name, returnType, flags);
    }
    PrintOperatorUnit* createPrintOperatorUnit(const std::string& text){
        return new CplusPrintOperator(text);
    }
};

#endif // FACTORY_H
