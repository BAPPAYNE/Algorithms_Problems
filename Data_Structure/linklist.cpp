#include "link_list.hpp"
#include<string>
#include<vector>
int main(int argc, char const *argv[])
{
    SingleList<std::string> *dummy = new SingleList<std::string>;
    dummy->data = "10";
    printf("%s\n", dummy->data);
    dummy->insert("Hello");
    dummy->insert("World");
    dummy->insert("From", 1);
    dummy->insert("C++", 0);
    dummy->insert("C++", 4);
    dummy->insert("C++", 5);
    dummy->print();
    dummy->remove(3);
    dummy->print();
    printf("%lld\n", dummy->size());
    
    // delete[] dummy;
    return 0;
}