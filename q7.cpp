#include <iostream> 
using namespace std; 
 
struct Node { 
    int data; 
    Node* next; 
    Node* prev; 
     
    Node(int val) : data(val), next(nullptr), prev(nullptr) {} 
}; 
 
class DoublyCircularList { 
private: 
    Node* head; 
 
public: 
    DoublyCircularList() : head(nullptr) {} 
     
    void insert(int val)  
 { 
        Node* newNode = new Node(val); 
         
        if (!head)  
  { 
            head = newNode; 
            head->next = head->prev = head; 
            return; 
        } 
         
        Node* last = head->prev; 
        last->next = newNode; 
        newNode->prev = last; 
        newNode->next = head; 
        head->prev = newNode; 
    } 
    void deleteAtPosition(int position)  
 { 
        if (!head)  
  { 
            cout << "List is empty!" << endl; 
            return; 
        } 
         
        Node* temp = head; 
         
        if (head->next == head && position == 1)  
  { 
            delete head; 
            head = nullptr; 
            return; 
        } 
         
        for (int i = 1; i < position && temp->next != head; i++)  
  { 
            temp = temp->next; 
        } 
         
        temp->prev->next = temp->next; 
        temp->next->prev = temp->prev; 
         
        if (temp == head)  
  { 
            head = head->next; 
        } 
         
        delete temp; 
    } 
     
    void display()  
 { 
        if (!head)  
  { 
            cout << "List is empty!" << endl; 
            return; 
        } 
         
        Node* temp = head; 
        do  
  { 
            cout << temp->data << " "; 
            temp = temp->next; 
        }  
  while (temp != head); 
   
        cout << endl; 
    } 
}; 
 
int main()  
{ 
    DoublyCircularList list; 
     
    list.insert(1); 
    list.insert(2); 
    list.insert(3); 
    list.insert(4); 
    list.insert(5); 
     
    cout << "Original list: "; 
    list.display(); 
     
    list.deleteAtPosition(3); 
    cout << "After deleting element at position 3: "; 
    list.display(); 
     
    list.deleteAtPosition(1); 
    cout << "After deleting element at position 1: "; 
    list.display(); 
     
    return 0; 
}