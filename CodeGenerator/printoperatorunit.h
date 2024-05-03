#ifndef PRINTOPERATORUNIT_H
#define PRINTOPERATORUNIT_H

#include "unit.h"

///////////////////////////////////////////////////////////////////////

class JavaPrintOperator : public PrintOperatorUnit
{
public:
    explicit JavaPrintOperator( const std::string& text ) : PrintOperatorUnit(text) { }
    std::string compile( unsigned int level = 0 ) const {
        return generateShift( level ) + "System.out.println( \"" + m_text + "\" );\n";
    }
};

///////////////////////////////////////////////////////////////////////

class CsharpPrintOperator : public PrintOperatorUnit
{
public:
    explicit CsharpPrintOperator( const std::string& text ) : PrintOperatorUnit(text) { }
    std::string compile( unsigned int level = 0 ) const {
        return generateShift( level ) + "Console.WriteLine( \"" + m_text + "\" );\n";
    }
};

///////////////////////////////////////////////////////////////////////

class CplusPrintOperator : public PrintOperatorUnit
{
public:
    explicit CplusPrintOperator( const std::string& text ) : PrintOperatorUnit(text) { }
    std::string compile( unsigned int level = 0 ) const {
        return generateShift( level ) + "printf( \"" + m_text + "\" );\n";
    }
};

#endif // PRINTOPERATORUNIT_H
