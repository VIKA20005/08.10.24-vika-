#include <iostream>

class MyString {
private:
    char* str;
    size_t length;

    
    size_t my_strlen(const char* s) const 
    {
        size_t len = 0;
        while (s[len] != '\0') 
        {
            ++len;
        }
        return len;
    }

    
    void my_strcpy(char* dest, const char* src) 
    {
        while ((*dest++ = *src++));
    }

public:
    
    MyString() : str(nullptr), length(0) {}

    
    MyString(const char* s) 
    {
        length = my_strlen(s);
        str = new char[length + 1];
        my_strcpy(str, s);
    }

    
    MyString(const MyString& other) : length(other.length) 
    {
        str = new char[length + 1];
        my_strcpy(str, other.str);
    }

    
    MyString& operator=(const MyString& other) 
    {
        if (this != &other) 
        {
            delete[] str;
            length = other.length;
            str = new char[length + 1];
            my_strcpy(str, other.str);
        }
        return *this;
    }

    
    ~MyString() {
        delete[] str;
    }

    
    char& operator[](size_t index) 
    {
        if (index >= length) 
        {
            std::cout << "Index out of range" << std::endl;
            return str[0]; 
        }
        return str[index];
    }

    const char& operator[](size_t index) const 
    {
        if (index >= length) 
        {
            std::cout << "Index out of range" << std::endl;
            return str[0]; 
        }
        return str[index];
    }

    
    size_t size() const 
    {
        return length;
    }

   
    void print() const 
    {
        if (str) 
        {
            std::cout << str << std::endl;
        }
        else
        {
            std::cout << "Empty string" << std::endl;
        }
    }
};

int main()
{
    MyString s("Hello");
    s.print();

    std::cout << "Первый символ строки: " << s[0] << std::endl;

    MyString s2 = s;
    s2.print();

    
    std::cout << "Попытка доступа к некорректному индексу: " << s[10] << std::endl;

    return 0;
}