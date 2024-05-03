#ifndef METHODUNIT_H
#define METHODUNIT_H

#include <unit.h>

////////////////////////////////////////////////////////////////////////////////////////

class JavaMethod : public MethodUnit
{
public:

    enum Modifier {
        STATIC,
        FINAL
    };

    static const std::vector<std::string> MODIFIERS_SPECIFIC;
    JavaMethod( const std::string& name, const std::string& returnType, Flags flags ):MethodUnit(name,  returnType,  flags) {
        MODIFIRES = &MODIFIERS_SPECIFIC;
        separator = 1;
    }
};
const std::vector<std::string> JavaMethod::MODIFIERS_SPECIFIC = {"static", "final"};

////////////////////////////////////////////////////////////////////////////////////////

class CsharpMethod : public MethodUnit
{
public:

    enum Modifier {
        STATIC,
        OVERRIDE,
        VIRTUAL
    };

    static const std::vector<std::string> MODIFIERS_SPECIFIC;
    CsharpMethod( const std::string& name, const std::string& returnType, Flags flags ):MethodUnit(name,  returnType,  flags) {
        MODIFIRES = &MODIFIERS_SPECIFIC;
        separator = 3;
    }
};
const std::vector<std::string> CsharpMethod::MODIFIERS_SPECIFIC = {"static", "override", "virtual"};

////////////////////////////////////////////////////////////////////////////////////////

class CplusMethod : public MethodUnit
{
public:

    enum Modifier {
        STATIC,
        VIRTUAL,
        CONST
    };

    static const std::vector<std::string> MODIFIERS_SPECIFIC;
    CplusMethod( const std::string& name, const std::string& returnType, Flags flags ):MethodUnit(name,  returnType,  flags) {
        MODIFIRES = &MODIFIERS_SPECIFIC;
        separator = 1;
    }
};
const std::vector<std::string> CplusMethod::MODIFIERS_SPECIFIC = {"static", "virtual", "const"};

#endif // METHODUNIT_H
