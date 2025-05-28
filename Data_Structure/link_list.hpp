#ifndef LINK_LIST
#define LINK_LIST

#include<stdio.h>
#include<stdlib.h>
// #include<string>
#include<iostream>

template<typename type>
struct SingleList {
    private:
        long long size_ = 0;

    public:
        type data;
        SingleList *next = nullptr;
        SingleList *head = nullptr;
        SingleList *tail = nullptr;

        ~SingleList(){
            clear();
        }
        unsigned insert(type new_Value, int position = -1){
            // Invalid position
            if(position < -1){
                fprintf(stderr,"Error: Position cannot be negative (except -1 for end)\n");
                return 1;
            }
            // A position where node cannot be inserted.
            if(position > size_ && position != -1){
                fprintf(stderr,"Insert position out of Range\n") ;
                return 1;
            }

            SingleList<type> *new_Node = (SingleList<type> *)malloc(sizeof(SingleList<type>));
            // Checking if node is created or not 
            if (!new_Node) {
                fprintf(stderr, "Memory allocation failed\n");
                return 1;
            }
            //Value assigned
            // new_Node->data = new_Value ;
            // Special handling for pointer types
            if constexpr (std::is_pointer_v<type>) {
                new_Node->data = new_Value;  // Simple assignment for pointers
            }
            else {
                new (&new_Node->data) type(new_Value);  // Placement new for objects
            }
            // new (&new_Node->data) type(new_Value);
            new_Node->next = nullptr;

            // Case 1: List is empty, new node becomes head
            if(head == nullptr && position == -1){
                head = new_Node ;
                tail = new_Node;
                size_ = 1 ;
                return 0;
            }

            // Case 2: position == -1, then insert at last. Which is by default if no position is specified.
            if(position == -1){
                tail->next = new_Node;
                tail = new_Node;
                size_++;
                return 0;
            }

            // If position == 0, then it means noew node is inserted at beginning.
            if(position == 0){
                new_Node->next = head ;
                head = new_Node;
                size_++;
                return 0;
            }
            SingleList *current = head ;
            long long current_Pos = 0;
            while(current_Pos + 1 != position && current->next != nullptr){
                current = current->next ;
                current_Pos++;
            }
            new_Node->next = current->next ;
            current->next = new_Node ;
            // Update tail if inserted at last position
            if (new_Node->next == nullptr) {
                tail = new_Node;
            }
            size_++;
            return 0 ;
        }


        // remove node function 
        unsigned remove(long long position = -1){
            // SingleList is empty
            if(head == nullptr){
                return 1;
            }

            if(position < -1){
                fprintf(stderr,"Error: Position cannot be negative (except -1 for end)\n");
                return 1;
            }

            if(position >= size_ && position != -1){
                fprintf(stderr,"delete position out of Range");
                return 1;
            }
            if(position == -1 || position == size_-1){
                if(head == tail){
                    tail->data.~type();
                    free(tail);
                    head = tail = nullptr;
                    size_ = 0;
                    return 0;
                }
                if(tail != nullptr){
                    SingleList<type> *current = head;
                    while (current->next->next != nullptr)
                    {
                        current = current->next;
                    }
                    tail = current ;
                    current->data.~type();
                    free(current->next);
                    current->next = nullptr ;
                    size_--;
                    return 0;
                }
                return 1;
            }
            // Delete at beginning
            if(position == 0){
                SingleList *temp = head;
                head = temp->next;
                temp->data.~type();
                free(temp);
                size_--;
                return 0;
            }
            long long current_Pos = 0;
            SingleList<type> *current = head;
            while(current->next!=nullptr && current_Pos + 1 != position){
                current=current->next;
                current_Pos++;
            }
            SingleList<type> *temp = current->next;
            current->next = current->next->next;
            temp->data.~type();
            free(temp);
            size_--;
            return 0;
            
        }


        // Printing SingleList
        void print() const {
            // if(size_ == 0){
            //     fprintf(stderr,"");
            // }
            SingleList<type> *current = head;
            while (current != nullptr) {
                std::cout << current->data << " -> ";
                current = current->next;
            }
            // for(long long i = 0 ; i < size_ ; i++){
            //     std::cout << current->data << " -> ";
            //     current = current->next;
            // }
            std::cout << "nullptr\n";
        }

        // Clearing(Emptying) SingleList
        void clear() {
            SingleList* current = head;
            while (current) {
                current->data.~type(); // Call destructor
                SingleList* temp = current;
                current = current->next;
                free(temp); // Free memory
            }
            head = nullptr;
            size_ = 0;
        }

        SingleList *get(long long position){
            SingleList *current = head;
            for(long long i = 0 ; i < position ; i++){
                current = current->next;
            }
            return current ;
        }

        SingleList *clone() const{
            SingleList<type> new_List;
                SingleList<type> *current = head;
                while (current != nullptr) {
                    new_List.insert(current->data);
                    current = current->next;
                }
            return new_List;
            
        }

        bool isempty() const{
            return head == nullptr;
        }


        long long size() const{
            return size_ ;
        }
        
    // Some private things
    private:

};
// Initialize static members
// template<typename type>
// SingleList<type> *SingleList<type>::head = nullptr;

// template<typename type>
// SingleList<type> *SingleList<type>::tail = nullptr;

// template<typename type>
// long long SingleList<type>::size_ = 0;

// int main(int argc, char const *argv[])
// {
//     SingleList<std::string> dummy;
//     dummy.insert("Hello");
//     dummy.insert("World");
//     dummy.insert("From", 1);
//     dummy.insert("C++", 0);
//     dummy.insert("C++", 4);
//     dummy.insert("C++", 5);

//     dummy.print();
//     return 0;
// }



#endif // LINK_LIST