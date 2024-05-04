#ifndef CLASSUNIT_H
#define CLASSUNIT_H

#include <unit.h>

////////////////////////////////////////////////////////////////////////////////////////

class JavaClass: public ClassUnit
{
public:
    /*
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        DEFAULT
    };
    */
    static const std::vector< std::string > ACCESS_MODIFIERS_SPECIFIC;
    explicit JavaClass(const std::string& name):ClassUnit(name){
            ACCESS_MODIFIERS = &ACCESS_MODIFIERS_SPECIFIC;
            m_filds.resize( ACCESS_MODIFIERS->size() );
        };
    std::string compile( unsigned int level = 0 ) const;
};


////////////////////////////////////////////////////////////////////////////////////////

class CplusClass: public ClassUnit
{
public:
    /*
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE
    };
    */
    static const std::vector< std::string > ACCESS_MODIFIERS_SPECIFIC;
    explicit CplusClass(const std::string& name):ClassUnit(name){
            ACCESS_MODIFIERS = &ACCESS_MODIFIERS_SPECIFIC;
            m_filds.resize( ACCESS_MODIFIERS->size() );
        };
    std::string compile( unsigned int level = 0 ) const;
};


////////////////////////////////////////////////////////////////////////////////////////

class CsharpClass: public ClassUnit
{
public:
    /*
    enum AccessModifier {
        PUBLIC,
        PRIVATE,
        PROTECTED,
        INTERNAL,
        PROTECTED_INTERNAL,
        PRIVATE_PROTECTED,
        FILE
    };
    */
    static const std::vector< std::string > ACCESS_MODIFIERS_SPECIFIC;
    explicit CsharpClass(const std::string& name):ClassUnit(name){
        ACCESS_MODIFIERS = &ACCESS_MODIFIERS_SPECIFIC;
        m_filds.resize( ACCESS_MODIFIERS->size() );
    };
    std::string compile( unsigned int level = 0 ) const;
};


#endif // CLASSUNIT_H

