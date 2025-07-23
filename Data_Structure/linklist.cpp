#include "link_list.hpp"
#include<string>
#include<vector>
// #include<iostream>
int main(int argc, char const *argv[])
{
    linklist<std::string> *dummy = new linklist<std::string>;
    printf("%d\n",sizeof(dummy));
    dummy->data = "10";
    dummy->insert("Hello");
    dummy->insert("World");
    dummy->insert("From", 1);
    dummy->insert("C++", 0);
    dummy->insert("C++", 4);
    dummy->insert("C++", 5);
    dummy->print();
    dummy->remove(3);
    dummy->print();
    dummy->print();

    // linklist<std::string> *dummy2 = dummy->clone() ;
    // dummy2->print() ;
    
    // delete[] dummy;
    return 0;
}