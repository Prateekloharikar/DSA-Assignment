#include <iostream> 
using namespace std; 
 
struct Node { 
    int data; 
    Node* next; 
     
    Node(int value)  
 { 
        data = value; 
        next = nullptr; 
    } 
}; 
 
class CircularLinkedList { 
private: 
    Node* last; 
     
public: 
    CircularLinkedList()  
 { 
        last = nullptr; 
    } 
     
    void insertAtEnd(int value)  
 { 
        Node* newNode = new Node(value); 
         
        if (last == nullptr)  
  { 
            last = newNode; 
            last->next = last; 
            return; 
        } 
         
        newNode->next = last->next;   
        last->next = newNode;         
        last = newNode;               
    } 
     
    void display()  
 { 
        if (last == nullptr)  
  { 
            cout << "List is empty" << endl; 
            return; 
        } 
         
        Node* temp = last->next; 
        do  
  { 
            cout << temp->data << " "; 
            temp = temp->next; 
        }  
  while (temp != last->next); 
         
  cout << endl; 
    } 
}; 
 
int main()  
{ 
    CircularLinkedList cll; 
     
    int value; 
     
    cll.insertAtEnd(10); 
    cll.insertAtEnd(20); 
    cll.insertAtEnd(30); 
    cll.insertAtEnd(40); 
 
    cout << "Current Linked List: "; 
    cll.display(); 
     
    cout << "\nEnter an element to insert at the end: "; 
    cin >> value; 
    cll.insertAtEnd(value); 
     
    cout << "\nUpdated Circular Linked List: "; 
    cll.display(); 
     
    return 0; 
}