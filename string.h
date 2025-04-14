#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

class MyString {
private:
    char* data;
    size_t length;

    // Вспомогательные функции для работы со строками
    static size_t strLen(const char* str);
    static void strCopy(char* dest, const char* src);

public:
    // Конструкторы
    MyString();                          // Конструктор по умолчанию
    MyString(const char* str);           // Конструктор с параметром
    MyString(const MyString& other);      // Конструктор копирования
    MyString(MyString&& other) noexcept;  // Конструктор перемещения

    // Деструктор
    ~MyString();

    // Операторы присваивания
    MyString& operator=(const MyString& other);  // Копирующее присваивание
    MyString& operator=(MyString&& other) noexcept;  // Перемещающее присваивание

    // Методы
    size_t getLength() const;            // Получить длину строки
    const char* c_str() const;           // Получить C-style строку

    // Операторы ввода/вывода
    friend std::ostream& operator<<(std::ostream& os, const MyString& str);
    friend std::istream& operator>>(std::istream& is, MyString& str);

    // Операции со строками
    void insertChar(char c, size_t pos);  // Вставка символа в позицию
    void trimLeadingSpaces();             // Удаление ведущих пробелов
    void addMissingChars(const MyString& other);  // Добавление отсутствующих символов
};

#endif // MYSTRING_H#pragma once
