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
          break;
        }
        else{
          n = n->next;
          count= count + 1;
        }
      }
    }

    void remove(int n){}

    void display(int n){
      std::cout << this->data;
    }

    void display_all(){
      Node* n = this;
      std::cout << n->data << std::endl;

      while(n->next != nullptr){
        n = n->next;
        std::cout << n->data << std::endl;
      }
    }

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

int main(){

  Node n(5);
  n.append(1);
  n.append(2);
  n.append(3);
  n.append(4);
  n.display_all();
  std::cout << "\n\n";
  n.insert(2, 99);
  n.display_all();
}