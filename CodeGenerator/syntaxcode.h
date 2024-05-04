#ifndef SYNTAXCODE_H
#define SYNTAXCODE_H

#include "unit.h"

class JavaSyntaxCode : public SyntaxCode
{
public:
    JavaSyntaxCode() {};

    Flags definitionFlags(AccessModifier flags);
    Flags definitionFlags(Flags flag);
};

class CsharpSyntaxCode : public SyntaxCode
{
public:
    CsharpSyntaxCode() {};

    Flags definitionFlags(AccessModifier flags);
    Flags definitionFlags(Flags flag);
};

class CplusSyntaxCode : public SyntaxCode
{
public:
    CplusSyntaxCode() {};

    Flags definitionFlags(AccessModifier flags);
    Flags definitionFlags(Flags flag);
};


#endif // SYNTAXCODE_H
