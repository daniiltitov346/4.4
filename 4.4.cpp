#include "string.h"
#include <iostream>

int main() {
    // Тестирование конструкторов
    MyString s1("  Hello");
    MyString s2("World!");
    MyString s3 = s1;
    MyString s4 = std::move(s2);

    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2 (moved from): " << s2 << std::endl;  // Должно быть пусто
    std::cout << "s3 (copy of s1): " << s3 << std::endl;
    std::cout << "s4 (moved from s2): " << s4 << std::endl;

    // Тестирование вставки символа
    s1.insertChar('X', 3);
    std::cout << "s1 after insert 'X' at pos 3: " << s1 << std::endl;

    // Тестирование удаления ведущих пробелов
    s1.trimLeadingSpaces();
    std::cout << "s1 after trim leading spaces: " << s1 << std::endl;

    // Тестирование добавления отсутствующих символов
    MyString s5("123");
    MyString s6("ABCDEF");
    s5.addMissingChars(s6);
    std::cout << "s5 after adding missing chars from s6: " << s5 << std::endl;

    return 0;
}