#include <cstring>
#include <iostream>

class MyString {
private:
    char* data;
    size_t length;

public:
    MyString();
    MyString(const char* str);
    MyString(const MyString& other);
    MyString(MyString&& other) noexcept;
    ~MyString();

    MyString& operator=(const MyString& other);
    MyString& operator=(MyString&& other) noexcept;

    size_t getLength() const;
    const char* c_str() const;

    void insertChar(char c, size_t pos);
    void trimLeadingSpaces();
    void addMissingChars(const MyString& other);

    friend std::ostream& operator<<(std::ostream& os, const MyString& str);
    friend std::istream& operator>>(std::istream& is, MyString& str);
};
