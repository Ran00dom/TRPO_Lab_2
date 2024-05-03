#include "classunit.h"
#include <iostream>
#include <ostream>

std::string JavaClass::compile( unsigned int level) const
{
    std::string result = generateShift( level ) + "class " + name + " {\n";
    for( size_t i = 0; i < ACCESS_MODIFIERS->size(); ++i ) {
        if( m_filds[ i ].empty() ) {
            continue;
        }
        for( const auto& f : m_filds[ i ] ) {
            result += ACCESS_MODIFIERS->at(i) ;
            result += f->compile( level + 1 );
        }
        result += "\n";
    }
    result += generateShift( level ) + "};\n";
    return result;
}

std::string CsharpClass::compile( unsigned int level) const
{
    std::string result = generateShift( level ) + "class " + name + " {\n";
    for( size_t i = 0; i < ACCESS_MODIFIERS->size(); ++i ) {
        if( m_filds[ i ].empty() ) {
            continue;
        }
        for( const auto& f : m_filds[ i ] ) {
            result += ACCESS_MODIFIERS->at(i) + " ";
            result += f->compile( level + 1 );
        }
        result += "\n";
    }
    result += generateShift( level ) + "};\n";
    return result;
}

std::string CplusClass::compile( unsigned int level) const
{
    std::string result = generateShift( level ) + "class " + name + " {\n";

    for( size_t i = 0; i < ACCESS_MODIFIERS->size(); ++i ) {
        if( m_filds[ i ].empty() ) {
            continue;
        }
        result += ACCESS_MODIFIERS->at(i) + ":\n";
        for( const auto& f : m_filds[ i ] ) {
            result += f->compile( level + 1 );
        }
        result += "\n";
    }
    result += generateShift( level ) + "};\n";
    return result;
}

const std::vector< std::string > JavaClass::ACCESS_MODIFIERS_SPECIFIC = { "public",
                                                                       "protected", "private", "default" };
const std::vector< std::string > CplusClass::ACCESS_MODIFIERS_SPECIFIC = { "public",
                                                                        "protected", "private" };
const std::vector< std::string > CsharpClass::ACCESS_MODIFIERS_SPECIFIC = { "public","private","protected", "internal", "protected	internal","private protected","file" };

