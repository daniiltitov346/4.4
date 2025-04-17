#include "string.h"
#include <iostream>

//  функция для вычисления длины строки
size_t MyString::strLen(const char* str) {
    if (!str) return 0;
    size_t len = 0;
    while (str[len] != '\0') ++len;
    return len;
}

//  функция для копирования строки
void MyString::strCopy(char* dest, const char* src) {
    if (!src) {
        dest = nullptr;
        return;
    }
    size_t i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        ++i;
    }
    dest[i] = '\0';
}

MyString::MyString() : data(nullptr), length(0) {}

MyString::MyString(const char* str) {
    if (str) {
        length = strLen(str);
        data = new char[length + 1];
        strCopy(data, str);
    }
    else {
        data = nullptr;
        length = 0;
    }
}

// Конструктор копирования
MyString::MyString(const MyString& other) {
    length = other.length;
    if (other.data) {
        data = new char[length + 1];
        strCopy(data, other.data);
    }
    else {
        data = nullptr;
    }
}

// Конструктор перемещения
MyString::MyString(MyString&& other) noexcept
    : data(other.data), length(other.length) {
    other.data = nullptr;
    other.length = 0;
}

// Деструктор
MyString::~MyString() {
    delete[] data;
}

// Копирующее присваивание
MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        delete[] data;
        length = other.length;
        if (other.data) {
            data = new char[length + 1];
            strCopy(data, other.data);
        }
        else {
            data = nullptr;
        }
    }
    return *this;
}

// Перемещающее присваивание
MyString& MyString::operator=(MyString&& other) noexcept {
    if (this != &other) {
        delete[] data;
        data = other.data;
        length = other.length;
        other.data = nullptr;
        other.length = 0;
    }
    return *this;
}

// Получить длину строки
size_t MyString::getLength() const {
    return length;
}

const char* MyString::c_str() const {
    return data;
}

// Оператор вывода
std::ostream& operator<<(std::ostream& os, const MyString& str) {
    if (str.data) {
        os << str.data;
    }
    return os;
}

// Оператор ввода
std::istream& operator>>(std::istream& is, MyString& str) {
    char buffer[1024];
    is >> buffer;
    str = MyString(buffer);
    return is;
}

// Вставка символа в позицию
void MyString::insertChar(char c, size_t pos) {
    if (pos > length) return;  

    char* newData = new char[length + 2];  // +1 для нового символа, +1 для '\0'
    size_t i = 0;
    for (; i < pos; ++i) {
        newData[i] = data[i];
    }
    newData[pos] = c;
    for (; i < length; ++i) {
        newData[i + 1] = data[i];
    }
    newData[length + 1] = '\0';

    delete[] data;
    data = newData;
    length++;
}

// Удаление ведущих пробелов
void MyString::trimLeadingSpaces() {
    if (!data) return;

    size_t leadingSpaces = 0;
    while (data[leadingSpaces] == ' ') {
        leadingSpaces++;
    }

    if (leadingSpaces == 0) return;  // Нет ведущих пробелов

    size_t newLength = length - leadingSpaces;
    char* newData = new char[newLength + 1];

    for (size_t i = 0; i < newLength; ++i) {
        newData[i] = data[i + leadingSpaces];
    }
    newData[newLength] = '\0';

    delete[] data;
    data = newData;
    length = newLength;
}

void MyString::addMissingChars(const MyString& other) {
    if (!other.data) return;  // Если вторая строка пуста, ничего не делаем

    // Определяем новую длину (максимальная из двух строк)
    size_t newLength = (length > other.length) ? length : other.length;

    char* newData = new char[newLength + 1];

    for (size_t i = 0; i < newLength; ++i) {
        // Если в текущей строке символ есть, но во второй строке тоже есть символ на этой позиции
        if (i < other.length && other.data[i] != '\0') {
            // Заменяем символ из второй строки
            newData[i] = other.data[i];
        }
        // Если в текущей строке символ есть, а во второй строке нет символа на этой позиции
        else if (i < length && data[i] != '\0') {
            // Оставляем символ из текущей строки
            newData[i] = data[i];
        }
        // Если в обеих строках нет символа на этой позиции
        else {
            // Заполняем пробелом (или другим значением по умолчанию)
            newData[i] = ' ';
        }
    }
    newData[newLength] = '\0';  // Завершаем строку

    // Освобождаем старые данные и сохраняем новые
    delete[] data;
    data = newData;
    length = newLength;
}