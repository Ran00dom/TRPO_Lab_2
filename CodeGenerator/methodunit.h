#ifndef METHODUNIT_H
#define METHODUNIT_H

#include <unit.h>

////////////////////////////////////////////////////////////////////////////////////////

class JavaMethod : public MethodUnit
{
public:
    /*
    enum Modifier {
        STATIC = 1,
        FINAL = 2
    };
    */
    static const std::vector<std::string> MODIFIERS_SPECIFIC;
    JavaMethod( const std::string& name, const std::string& returnType, Flags flags ):MethodUnit(name,  returnType,  flags) {
        MODIFIRES = &MODIFIERS_SPECIFIC;
        separator = 2;
    }
};
const std::vector<std::string> JavaMethod::MODIFIERS_SPECIFIC = {"static", "final"};

////////////////////////////////////////////////////////////////////////////////////////

class CsharpMethod : public MethodUnit
{
public:
    /*
    enum Modifier {
        STATIC = 1,
        OVERRIDE = 2,
        VIRTUAL = 3
    };
    */
    static const std::vector<std::string> MODIFIERS_SPECIFIC;
    CsharpMethod( const std::string& name, const std::string& returnType, Flags flags ):MethodUnit(name,  returnType,  flags) {
        MODIFIRES = &MODIFIERS_SPECIFIC;
        separator = 3;
    }
};
const std::vector<std::string> CsharpMethod::MODIFIERS_SPECIFIC = {"static", "virtual", "override"};

////////////////////////////////////////////////////////////////////////////////////////

class CplusMethod : public MethodUnit
{
public:
    /*
    enum Modifier {
        STATIC = 1,
        VIRTUAL = 2,
        CONST = 3
    };
    */
    static const std::vector<std::string> MODIFIERS_SPECIFIC;
    CplusMethod( const std::string& name, const std::string& returnType, Flags flags ):MethodUnit(name,  returnType,  flags) {
        MODIFIRES = &MODIFIERS_SPECIFIC;
        separator = 2;
    }
};

const std::vector<std::string> CplusMethod::MODIFIERS_SPECIFIC = {"static", "virtual", "const"};

#endif // METHODUNIT_H
