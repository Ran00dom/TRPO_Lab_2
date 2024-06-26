#ifndef UNIT_H
#define UNIT_H

#include <memory>
#include <vector>

class Unit {
public:
    using Fields = std::vector< std::shared_ptr< Unit > >;
    using Flags = unsigned int;
public:
    virtual ~Unit() = default;
    virtual void add( const std::shared_ptr< Unit >& , Flags = 0) {
        throw std::runtime_error( "Not supported" );
    }
    virtual std::string compile( unsigned int level = 0 ) const = 0;
protected:
    virtual std::string generateShift( unsigned int level ) const
    {
        static const auto DEFAULT_SHIFT = " ";
        std::string result;
        for( unsigned int i = 0; i < level; ++i ) {
            result += DEFAULT_SHIFT;
        }
        return result;
    }

    std::vector<Fields> m_filds;
};

class ClassUnit : public Unit {
protected:
    std::string name;
public:

    const std::vector<std::string> *ACCESS_MODIFIERS;

    explicit ClassUnit( const std::string& name ) : name( name ) {
       // m_filds.resize( ACCESS_MODIFIERS->size() );
    }
    void add( const std::shared_ptr< Unit >& unit, Flags flags );
};


class MethodUnit : public Unit {
private:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;

public:

    Flags separator = 1; // разделяет вектор на модификаторы перед методом и после
    const std::vector<std::string> *MODIFIRES;

    MethodUnit( const std::string& name, const std::string& returnType, Flags flags ) :
        m_name( name ), m_returnType( returnType ), m_flags( flags ) {
            m_filds.resize(1);
    }

    void add( const std::shared_ptr< Unit >& unit, Flags /* flags */ = 0 );
    std::string compile( unsigned int level = 0 ) const;
};

class PrintOperatorUnit : public Unit {
public:
    explicit PrintOperatorUnit( const std::string& text ) : m_text( text ) { }
protected:
    std::string m_text;
};

class SyntaxCode {
protected:
    //static const unsigned int AccessModifierSize = 8;
    //static const unsigned int MethodModifierSize = 6;
public:
    using Flags = unsigned int;
    enum AccessModifier {
        PUBLIC = 0,
        PRIVATE,
        PROTECTED,
        INTERNAL,
        PROTECTED_INTERNAL,
        PRIVATE_PROTECTED,
        FILE,
        DEFAULT
    };

    enum MethodModifier {
        STATIC = 1 << 0,
        OVERRIDE = 1 << 1,
        VIRTUAL = 1 << 2,
        CONST = 1 << 3,
        FINAL = 1 << 4
    };

    virtual Flags definitionFlags(AccessModifier flags) = 0;
    virtual Flags definitionFlags(Flags flag) = 0;
};


#endif // UNIT_H
