#include "unit.h"
#include "factory.h"
#include <QCoreApplication>
#include <iostream>

std::string generateProgram(CodeGenerator& generator) {
    std::shared_ptr<ClassUnit> myClass = generator.createClass("MyClass");

    myClass->add(
        generator.createMethod( "testFunc1", "void", 0 ),
        JavaCodeGenerator::PUBLIC
        );
    myClass->add(
        generator.createMethod( "testFunc2", "void", JavaCodeGenerator::STATIC ),
        JavaCodeGenerator::PRIVATE
        );
    myClass->add(
        generator.createMethod( "testFunc3", "void", JavaCodeGenerator::STATIC ),
        JavaCodeGenerator::PUBLIC
        );
    std::shared_ptr<MethodUnit>method = generator.createMethod( "testFunc4", "void",
                                                                JavaCodeGenerator::FINAL );
    method->add( generator.createPrintOperatorUnit(R"(Hello, world!\n)" ) );
    myClass->add( method, JavaCodeGenerator::PROTECTED );

    return myClass->compile();
}

int main() {
    CodeGenerator* generator = new JavaCodeGenerator();
    std::cout << generateProgram(*generator) << std::endl;
    return 0;
}
