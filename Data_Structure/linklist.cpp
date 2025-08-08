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
    cout << dummy->tail << endl ;
    dummy->insert("World");
    cout << dummy->tail << endl ;
    dummy->insert("From", 1);
    cout << dummy->tail << endl ;
    dummy->insert("C++", 0);
    cout << dummy->tail << endl ;
    dummy->insert("C++", 4);
    cout << dummy->tail << endl ;
    dummy->insert("C++", 5);
    dummy->print();
    dummy->remove(3);
    cout << dummy->tail << endl ;
    dummy->print();
    dummy->print();
    // dummy->clear();
    // dummy->print();
    dummy->insert("asd",-3);
    cout << dummy->tail << endl ;
    dummy->print();
    linklist<std::string> *val = dummy->tail;
    cout << val << endl ;

    // linklist<std::string> *dummy2 = dummy->clone() ;
    // dummy2->print() ;
    
    // delete[] dummy;
    return 0;
}