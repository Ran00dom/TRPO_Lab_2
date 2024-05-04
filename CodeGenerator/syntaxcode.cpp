#include "syntaxcode.h"

SyntaxCode::Flags JavaSyntaxCode::definitionFlags(AccessModifier flags)
{
    if (flags == AccessModifier::DEFAULT)
        return 3;
    if (flags > AccessModifier::PROTECTED && flags < AccessModifier::DEFAULT)
        return AccessModifier::PUBLIC;
    return flags;
}


SyntaxCode::Flags JavaSyntaxCode::definitionFlags(Flags flags)
{
    Flags newFlags = 0;
    if (MethodModifier::STATIC & flags)
        newFlags = newFlags | 1 << 0;
    if (MethodModifier::FINAL & flags)
        newFlags = newFlags | 1 << 1;
    return newFlags;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

SyntaxCode::Flags CsharpSyntaxCode::definitionFlags(AccessModifier flags)
{
    if (flags == AccessModifier::DEFAULT)
        return AccessModifier::PUBLIC;
    return flags;
}


SyntaxCode::Flags CsharpSyntaxCode::definitionFlags(Flags flags)
{
    Flags newFlags = 0;
    if (MethodModifier::STATIC & flags)
        newFlags = newFlags | 1 << 0;
    if (MethodModifier::VIRTUAL & flags)
        newFlags = newFlags | 1 << 1;
    if (MethodModifier::OVERRIDE & flags)
        newFlags = newFlags | 1 << 2;
    return newFlags;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

SyntaxCode::Flags CplusSyntaxCode::definitionFlags(AccessModifier flags)
{
    if (flags > AccessModifier::PROTECTED)
        return AccessModifier::PUBLIC;
    return flags;
}


SyntaxCode::Flags CplusSyntaxCode::definitionFlags(Flags flags)
{
    Flags newFlags = 0;
    if (MethodModifier::STATIC & flags)
        newFlags = newFlags | 1 << 0;
    if (MethodModifier::VIRTUAL & flags)
        newFlags = newFlags | 1 << 1;
    if (MethodModifier::CONST & flags)
        newFlags = newFlags | 1 << 2;
    return newFlags;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
