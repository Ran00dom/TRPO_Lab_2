#include "classunit.h"

std::string JavaClass::compile( unsigned int level) const
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
