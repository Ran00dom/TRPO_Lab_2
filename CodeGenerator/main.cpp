#include "unit.h"
#include "factory.h"
#include <QCoreApplication>
#include <iostream>

std::string generateProgram_test1(CodeGenerator& generator) {
    std::shared_ptr<ClassUnit> myClass = generator.createClass("MyClass");
    std::shared_ptr<SyntaxCode> mySyntax = generator.createSyntaxCode();
    myClass->add(
        generator.createMethod( "testFunc1", "void", mySyntax->definitionFlags(SyntaxCode::MethodModifier::VIRTUAL) ),
        mySyntax->definitionFlags(SyntaxCode::AccessModifier::PUBLIC)
        );

    myClass->add(
        generator.createMethod( "testFunc2", "void", mySyntax->definitionFlags(SyntaxCode::MethodModifier::STATIC | SyntaxCode::MethodModifier::FINAL | SyntaxCode::MethodModifier::CONST) ),
        mySyntax->definitionFlags(SyntaxCode::AccessModifier::PRIVATE)
        );

    myClass->add(
        generator.createMethod( "testFunc3", "void", mySyntax->definitionFlags(SyntaxCode::MethodModifier::STATIC) ),
        mySyntax->definitionFlags(SyntaxCode::AccessModifier::DEFAULT)
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
    method->add( generator.createPrintOperatorUnit(R"(add file)" ) );

    myClass->add(
        method,
        mySyntax->definitionFlags(SyntaxCode::AccessModifier::DEFAULT)
        );
    myClass->add(generator.createMethod("size", "qint64&", mySyntax->definitionFlags(SyntaxCode::MethodModifier::CONST)), mySyntax->definitionFlags(SyntaxCode::AccessModifier::INTERNAL));
    myClass->add(generator.createMethod("name", "QString", mySyntax->definitionFlags(SyntaxCode::MethodModifier::CONST)), mySyntax->definitionFlags(SyntaxCode::AccessModifier::PRIVATE_PROTECTED));
    method = generator.createMethod("exist", "bool", mySyntax->definitionFlags(SyntaxCode::MethodModifier::CONST | SyntaxCode::MethodModifier::OVERRIDE));
    method->add( generator.createPrintOperatorUnit(R"(File exist!)" ) );
    myClass->add(method, mySyntax->definitionFlags(SyntaxCode::AccessModifier::PROTECTED_INTERNAL));
    myClass->add(generator.createMethod("Instance", "QFileInfo&", mySyntax->definitionFlags(SyntaxCode::MethodModifier::STATIC)), mySyntax->definitionFlags(SyntaxCode::AccessModifier::PUBLIC));
    myClass->add(generator.createMethod("checkSyffix", "std::string", mySyntax->definitionFlags(SyntaxCode::MethodModifier::CONST | SyntaxCode::MethodModifier::STATIC)), mySyntax->definitionFlags(SyntaxCode::AccessModifier::PRIVATE));
    myClass->add(generator.createMethod("correctPath", "bool", mySyntax->definitionFlags(SyntaxCode::MethodModifier::VIRTUAL)), mySyntax->definitionFlags(SyntaxCode::AccessModifier::PRIVATE));

    return myClass->compile();
}

int main() {
    std::string str;

    while(true)
    {
        std::cout << std::endl << "//////////////////////////////////////////////////////////////////////////////" << std::endl;
        std::cout << "Enter 'Cplus' 'Csharp' and 'Java' for select CodeGenerator!" << std::endl;
        CodeGenerator* generator = nullptr;
        std::cin >> str;
        if (str == "Cplus")
            generator = new CplusCodeGenerator();
        if (str == "Csharp")
            generator = new CsharpCodeGenerator();
        if (str == "Java")
            generator = new JavaCodeGenerator();

        if (generator != nullptr)
        {
            std::cout << "Select test > 'test1', 'test2'" << std::endl;
            std::cout << "Enter test name!" << std::endl;
            std::cin >> str;
            if (str == "test1")
                std::cout << std::endl << generateProgram_test1(*generator) << std::endl;
            if (str == "test2")
                std::cout << std::endl << generateProgram_test2(*generator) << std::endl;
        }
    }
    return 0;
}
