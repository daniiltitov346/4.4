#include "MyString.h"
#include <iostream>

MyString::MyString() : data(nullptr), length(0) {}

MyString::MyString(const char* str) {
    if (str) {
        length = strlen(str);
        data = new char[length + 1];
        strcpy_s(data, length + 1, str);
    }
    else {
        data = nullptr;
        length = 0;
    }
}

MyString::MyString(const MyString& other) {
    length = other.length;
    if (other.data) {
        data = new char[length + 1];
        strcpy_s(data, length + 1, other.data);
    }
    else {
        data = nullptr;
    }
}

MyString::MyString(MyString&& other) noexcept
    : data(other.data), length(other.length) {
    other.data = nullptr;
    other.length = 0;
}

MyString::~MyString() {
    delete[] data;
}

MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        delete[] data;
        length = other.length;
        if (other.data) {
            data = new char[length + 1];
            strcpy_s(data, length + 1, other.data);
        }
        else {
            data = nullptr;
        }
    }
    return *this;
}

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

size_t MyString::getLength() const {
    return length;
}

const char* MyString::c_str() const {
    return data;
}

std::ostream& operator<<(std::ostream& os, const MyString& str) {
    if (str.data) {
        os << str.data;
    }
    return os;
}

std::istream& operator>>(std::istream& is, MyString& str) {
    char buffer[1024];
    is >> buffer;
    str = MyString(buffer);
    return is;
}

void MyString::insertChar(char c, size_t pos) {
    if (pos > length) return;

    char* newData = new char[length + 2];
    strncpy_s(newData, length + 2, data, pos);
    newData[pos] = c;
    strcpy_s(newData + pos + 1, length - pos + 1, data + pos);

    delete[] data;
    data = newData;
    length++;
}

void MyString::trimLeadingSpaces() {
    if (!data) return;

    size_t leadingSpaces = 0;
    while (data[leadingSpaces] == ' ') {
        leadingSpaces++;
    }

    if (leadingSpaces == 0) return;

    size_t newLength = length - leadingSpaces;
    char* newData = new char[newLength + 1];
    strcpy_s(newData, newLength + 1, data + leadingSpaces);

    delete[] data;
    data = newData;
    length = newLength;
}

void MyString::addMissingChars(const MyString& other) {
    if (!other.data) return;

    size_t newLength = (length > other.length) ? length : other.length;
    char* newData = new char[newLength + 1];

    for (size_t i = 0; i < newLength; ++i) {
        if (i < other.length) {
            newData[i] = other.data[i];
        }
        else if (i < length) {
            newData[i] = data[i];
        }
        else {
            newData[i] = ' ';
        }
    }
    newData[newLength] = '\0';

    delete[] data;
    data = newData;
    length = newLength;
}