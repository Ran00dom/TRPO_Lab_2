#ifndef CLASSUNIT_H
#define CLASSUNIT_H

#include <unit.h>

////////////////////////////////////////////////////////////////////////////////////////

class JavaClass: public ClassUnit
{
public:
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        DEFAULT
    };
    static const std::vector< std::string > ACCESS_MODIFIERS_SPECIFIC;
    explicit JavaClass(const std::string& name):ClassUnit(name){
            ACCESS_MODIFIERS = &ACCESS_MODIFIERS_SPECIFIC;
        };
    std::string compile( unsigned int level = 0 ) const;
};

const std::vector< std::string > JavaClass::ACCESS_MODIFIERS_SPECIFIC = { "public",
                                                              "protected", "private", "default" };

////////////////////////////////////////////////////////////////////////////////////////

class CplusClass: public ClassUnit
{
public:
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE
    };
    static const std::vector< std::string > ACCESS_MODIFIERS_SPECIFIC;
    explicit CplusClass(const std::string& name):ClassUnit(name){
            ACCESS_MODIFIERS = &ACCESS_MODIFIERS_SPECIFIC;
        };
};

const std::vector< std::string > CplusClass::ACCESS_MODIFIERS_SPECIFIC = { "public",
                                                              "protected", "private" };

////////////////////////////////////////////////////////////////////////////////////////

class CsharpClass: public ClassUnit
{
public:
    enum AccessModifier {
        PUBLIC,
        PROTECTED_INTERNAL,
        INTERNAL,
        PROTECTED,
        PRIVATE_PROTECTED,
        PRIVATE,
        FILE
    };
    static const std::vector< std::string > ACCESS_MODIFIERS_SPECIFIC;
    explicit CsharpClass(const std::string& name):ClassUnit(name){
        ACCESS_MODIFIERS = &ACCESS_MODIFIERS_SPECIFIC;
    };
    std::string compile( unsigned int level = 0 ) const;
};

const std::vector< std::string > CsharpClass::ACCESS_MODIFIERS_SPECIFIC = { "public","protected internal",	"protected	internal","private protected","private","file" };


#endif // CLASSUNIT_H

