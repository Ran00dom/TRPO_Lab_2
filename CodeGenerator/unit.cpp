
#include "unit.h"


void ClassUnit::add( const std::shared_ptr< Unit >& unit, Flags flags ) {
    unsigned int accessModifier = 0;
    if( flags < ACCESS_MODIFIERS->size() ) {
        accessModifier = flags;
    }
    m_filds[accessModifier].push_back(unit);
}

std::string ClassUnit::compile( unsigned int level) const
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

void MethodUnit::add( const std::shared_ptr< Unit >& unit, Flags flags )
{
    m_filds.resize(1);
    m_filds[0].push_back( unit );
}


std::string MethodUnit::compile( unsigned int level) const {
    std::string result = generateShift( level );
    if( m_flags <= separator) {
        result += MODIFIRES->at(m_flags) + " ";
    }
    result += m_returnType + " ";
    result += m_name + "()";

    if( m_flags > separator) {
        result += MODIFIRES->at(m_flags);
    }

    for( const auto& b : m_filds[0] ) {
        result += b->compile( level + 1 );
    }
    result += generateShift( level ) + "}\n";
    return result;
}
