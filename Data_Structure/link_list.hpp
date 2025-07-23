#ifndef LINK_LIST
#define LINK_LIST

#include<stdio.h>
#include<stdlib.h>
// #include<string>
#include<iostream>

template<typename type>
struct linklist {
    private:
        long long size_ = 0;

    public:
        type data;
        linklist *next = nullptr;
        linklist *prev = nullptr;
        linklist *head = nullptr;
        linklist *tail = nullptr;

        ~linklist(){
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

            linklist<type> *new_Node = (linklist<type> *)malloc(sizeof(linklist<type>));
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
                head = new_Node;
                tail = new_Node;
                size_ = 1 ;
                return 0;
            }

            // Case 2: position == -1, then insert at last. Which is by default if no position is specified.
            if(position == -1){
                tail->next = new_Node;
                prev = tail;
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
            linklist *current = head ;
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
            // linklist is empty
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
                    linklist<type> *current = head;
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
                linklist *temp = head;
                head = temp->next;
                temp->data.~type();
                free(temp);
                size_--;
                return 0;
            }
            long long current_Pos = 0;
            linklist<type> *current = head;
            while(current->next!=nullptr && current_Pos + 1 != position){
                current=current->next;
                current_Pos++;
            }
            linklist<type> *temp = current->next;
            current->next = current->next->next;
            temp->data.~type();
            free(temp);
            size_--;
            return 0;
            
        }


        // Printing linklist
        void print(){
            // if(size_ == 0){
            //     fprintf(stderr,"");
            // }
            linklist<type> *current = head;
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

        // Clearing(Emptying) linklist
        void clear() {
            linklist* current = head;
            while (current) {
                current->data.~type(); // Call destructor
                linklist* temp = current;
                current = current->next;
                free(temp); // Free memory
            }
            head = nullptr;
            size_ = 0;
        }

        linklist *get(long long position){
            linklist *current = head;
            for(long long i = 0 ; i < position ; i++){
                current = current->next;
            }
            return current ;
        }

        linklist* clone() const{
            linklist<type> *new_List;
                linklist<type> *current = head;
                while (current != nullptr) {
                    new_List->insert(current->data);
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

};

#endif // LINK_LIST
