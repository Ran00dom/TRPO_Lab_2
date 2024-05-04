# TRPO_Lab_2
## Задача
Используя шаблон проектирования "Абстрактная фабрика", создать праграмму генерирующую код для языков программирования (JAVA, C#, С++).

### Использование
При запуске нужно ввести название языка программирования (Java, Csharp, Cplus), после чего программа запросит ввести имя теста (test1, test2).

## Архитектура
1. CodeGenerator: абстракная фабрика, наследники: JavaCodeGenerator, CsharpCodeGenerator, CplusCodeGenerator.
2. Unit: базовый класс сущьностей языка, наследники: ClassUnit, MethodUnit, PrintOperationUnit. 
3. ClassUnit: продут типа класса, наследники: JavaClass, CsharpClass, CplusClass.
3. MethodUnit: продукт типа метод, наследники: JavaMethod, CsharpMethod, CplusMethod.
4. PrintOperationUnit: продукт типа оператор печати, наследники: JavaPrintOperation, CsharpPrintOperationUnit, CplusPrintOperationUnit.
5. SyntaxCode: продукт типа синтаксис языка, не наследуется от Unit, наследники: JavaSyntaxCode, CsharpSyntaxCode, CplusSyntaxCode.

## UML-диаграмма
![Иллюстрация к проекту](https://github.com/Ran00dom/TRPO_Lab_2/raw//task_description/UML_2.jpeg)

Система сборки: Qmake

Фреймворк: QT 5.15.2
