#include <iostream>
#include <string>
class StringPointer {
public:
    std::string *operator->() {return pointer;}
    operator std::string*() {return pointer;}
    StringPointer(std::string *Pointer)
    {
        if (Pointer == NULL)
            pointer = new std::string("");
        else
        pointer = Pointer;
    }
    ~StringPointer() 
    {
        if (*pointer == "")
            delete pointer;
    }
private:
    std::string *pointer;
};

int main()
{
    std::string s1 = "Hello, world!";

    StringPointer sp1(&s1);
    StringPointer sp2(NULL);

    std::cout << sp1->length() << std::endl;
    std::cout << *sp1 << std::endl;
    std::cout << sp2->length() << std::endl;
    std::cout << *sp2 << std::endl;
    return 0;
}
