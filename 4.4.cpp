#include "MyString.h"
#include <iostream>

int main() {
    // Тест 1: Замена и дополнение символов
    MyString str1("ABCDEF");
    MyString str2("123456789");

    std::cout << "Test 1:" << std::endl;
    std::cout << "Original string: " << str1 << " (length: " << str1.getLength() << ")" << std::endl;
    std::cout << "Modifier string: " << str2 << " (length: " << str2.getLength() << ")" << std::endl;

    str1.addMissingChars(str2);
    std::cout << "Result after addMissingChars: " << str1 << " (length: " << str1.getLength() << ")" << std::endl;
    std::cout << "Expected result: 123456789" << std::endl << std::endl;

    // Тест 2: Частичная замена символов
    MyString str3("HelloWorld");
    MyString str4("12345");

    std::cout << "Test 2:" << std::endl;
    std::cout << "Original string: " << str3 << " (length: " << str3.getLength() << ")" << std::endl;
    std::cout << "Modifier string: " << str4 << " (length: " << str4.getLength() << ")" << std::endl;

    str3.addMissingChars(str4);
    std::cout << "Result after addMissingChars: " << str3 << " (length: " << str3.getLength() << ")" << std::endl;
    std::cout << "Expected result: 12345World" << std::endl << std::endl;

    // Тест 3: Вторая строка короче
    MyString str5("PrefixAText");
    MyString str6("ABC");

    std::cout << "Test 3:" << std::endl;
    std::cout << "Original string: " << str5 << " (length: " << str5.getLength() << ")" << std::endl;
    std::cout << "Modifier string: " << str6 << " (length: " << str6.getLength() << ")" << std::endl;

    str5.addMissingChars(str6);
    std::cout << "Result after addMissingChars: " << str5 << " (length: " << str5.getLength() << ")" << std::endl;
    std::cout << "Expected result: ABCixText" << std::endl;

    return 0;
} 