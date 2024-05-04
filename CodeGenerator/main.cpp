#include "unit.h"
#include "factory.h"
#include <QCoreApplication>
#include <iostream>

std::string generateProgram_test1(CodeGenerator& generator) {
    std::shared_ptr<ClassUnit> myClass = generator.createClass("MyClass");
    std::shared_ptr<SyntaxCode> mySyntax = generator.createSyntaxCode();
    myClass->add(
        generator.createMethod( "testFunc1", "void", 0 ),
        mySyntax->definitionFlags(SyntaxCode::AccessModifier::PUBLIC)
        );

    myClass->add(
        generator.createMethod( "testFunc2", "void", mySyntax->definitionFlags(SyntaxCode::MethodModifier::STATIC | SyntaxCode::MethodModifier::FINAL) ),
        mySyntax->definitionFlags(SyntaxCode::AccessModifier::PRIVATE)
        );

    myClass->add(
        generator.createMethod( "testFunc3", "void", mySyntax->definitionFlags(SyntaxCode::MethodModifier::STATIC) ),
        mySyntax->definitionFlags(SyntaxCode::AccessModifier::PUBLIC)
        );
    std::shared_ptr<MethodUnit>method = generator.createMethod( "testFunc4", "void",
                                                                mySyntax->definitionFlags(SyntaxCode::MethodModifier::FINAL) );
    method->add( generator.createPrintOperatorUnit(R"(Hello, world!\n)" ) );
    myClass->add(method, mySyntax->definitionFlags(SyntaxCode::AccessModifier::PROTECTED) );

    return myClass->compile();
}

std::string generateProgram_test2(CodeGenerator& generator)
{
    std::shared_ptr<ClassUnit> myClass = generator.createClass("QFileInfo");
    std::shared_ptr<SyntaxCode> mySyntax = generator.createSyntaxCode();

    std::shared_ptr<MethodUnit> method = generator.createMethod( "printDir", "void", 0 );
     method->add( generator.createPrintOperatorUnit(R"(C:\lab2.txt)" ) );

    myClass->add(
        method,
        mySyntax->definitionFlags(SyntaxCode::AccessModifier::DEFAULT)
        );
    myClass->add(generator.createMethod("size", "qint64&", mySyntax->definitionFlags(SyntaxCode::MethodModifier::CONST)), mySyntax->definitionFlags(SyntaxCode::AccessModifier::INTERNAL));
    myClass->add(generator.createMethod("name", "QString", mySyntax->definitionFlags(SyntaxCode::MethodModifier::CONST)), mySyntax->definitionFlags(SyntaxCode::AccessModifier::PRIVATE_PROTECTED));
    myClass->add(generator.createMethod("exist", "bool", mySyntax->definitionFlags(SyntaxCode::MethodModifier::CONST)), mySyntax->definitionFlags(SyntaxCode::AccessModifier::PROTECTED_INTERNAL));
    myClass->add(generator.createMethod("Instance", "QFileInfo&", mySyntax->definitionFlags(SyntaxCode::MethodModifier::STATIC)), mySyntax->definitionFlags(SyntaxCode::AccessModifier::PUBLIC));
    myClass->add(generator.createMethod("checkSyffix", "std::string", mySyntax->definitionFlags(SyntaxCode::MethodModifier::CONST | SyntaxCode::MethodModifier::STATIC)), mySyntax->definitionFlags(SyntaxCode::AccessModifier::PRIVATE));
    myClass->add(generator.createMethod("correctPath", "bool", mySyntax->definitionFlags(SyntaxCode::MethodModifier::VIRTUAL)), mySyntax->definitionFlags(SyntaxCode::AccessModifier::PRIVATE));

    return myClass->compile();
}

int main() {
    CodeGenerator* generator = new CplusCodeGenerator();
    std::cout << generateProgram_test2(*generator) << std::endl;
    return 0;


}
