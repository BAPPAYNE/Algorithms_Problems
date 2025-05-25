#include "link_list.hpp"
#include<string>

int main(int argc, char const *argv[])
{
    SingleList<char *> dummy;
    dummy.insert("Hello");
    dummy.insert("World");
    dummy.insert("From", 1);
    dummy.insert("C++", 0);
    dummy.insert("C++", 4);
    dummy.insert("C++", 5);
    SingleList<int> dummy2 ;
    dummy2.insert(10);
    dummy2.insert(-14);
    dummy2.insert(28);

    dummy.print();
    dummy2.print();
    printf("%d\n",dummy2.size);
    SingleList<std::string> dummy3;
    dummy.insert("A");
    dummy3.insert("B");
    dummy.print();  // shows both A and B
    dummy3.print(); // shows the same A and B
    
    return 0;
}