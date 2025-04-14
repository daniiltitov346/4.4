#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

class MyString {
private:
    char* data;
    size_t length;

    // ��������������� ������� ��� ������ �� ��������
    static size_t strLen(const char* str);
    static void strCopy(char* dest, const char* src);

public:
    // ������������
    MyString();                          // ����������� �� ���������
    MyString(const char* str);           // ����������� � ����������
    MyString(const MyString& other);      // ����������� �����������
    MyString(MyString&& other) noexcept;  // ����������� �����������

    // ����������
    ~MyString();

    // ��������� ������������
    MyString& operator=(const MyString& other);  // ���������� ������������
    MyString& operator=(MyString&& other) noexcept;  // ������������ ������������

    // ������
    size_t getLength() const;            // �������� ����� ������
    const char* c_str() const;           // �������� C-style ������

    // ��������� �����/������
    friend std::ostream& operator<<(std::ostream& os, const MyString& str);
    friend std::istream& operator>>(std::istream& is, MyString& str);

    // �������� �� ��������
    void insertChar(char c, size_t pos);  // ������� ������� � �������
    void trimLeadingSpaces();             // �������� ������� ��������
    void addMissingChars(const MyString& other);  // ���������� ������������� ��������
};

#endif // MYSTRING_H#pragma once
