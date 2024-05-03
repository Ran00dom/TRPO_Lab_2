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
