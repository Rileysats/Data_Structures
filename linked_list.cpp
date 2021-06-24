#include <iostream>
#include <cstddef>

class Node{
  public:
    Node* prev = nullptr;
    Node* next = nullptr;
    int data;
    
    Node(int d){
      data = d;
    }
    // insert node with value at index given
    void insert(int index, int val){
      Node* n = this;
      Node* insert = new Node(val);
      int count = 0;
      while (n->next != nullptr){
        if (count == index-1){
          n->next->prev = insert;
          insert->next = n->next;
          n->next = insert;
          insert->prev = n;
          return;
        }
        else{
          n = n->next;
          count++;
        }
      }
    }
    // remove nodes from linked list and patch the list
    void remove(int index){
      Node* n = this;
      int count = 0;
      while (n->next != nullptr){
        if (index == count){
          n->prev->next = n->next;
          n->next->prev = n->prev;
          return;
        }
        n = n->next;
        count++;
      }
      
    }
    // gets value at given the given index otherwise return -1
    int get_index(int index){
      Node* n = this;
      int count = 0;
      while (n->next != nullptr){
        if (count == index){
          return n->data;
        }
        n = n->next;
        count++;
      }
      return -1;
    }
    // Displays all values in linked list
    void display_all(){
      Node* n = this;
      std::cout << n->data << std::endl;

      while(n->next != nullptr){
        n = n->next;
        std::cout << n->data << std::endl;
      }
    }
    // appends to linked list
    void append(int val){
        Node* end = new Node(val);
        Node* n = this; 
        while (n->next != nullptr){
          n = n->next;
        }
        n->next = end;
        end->prev = n;
    }
};