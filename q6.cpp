#include <iostream> 
using namespace std; 
 
struct Node { 
    int data; 
    Node* prev; 
    Node* next; 
}; 
 
class DoublyList { 
private: 
    Node* head; 
 
public: 
    DoublyList()  
    { head = NULL; } 
    void insertAtStart(int value)  
    { 
        Node* newNode = new Node{value, NULL, head}; 
        if (head) head->prev = newNode; 
        head = newNode; 
    } 
    void insertAtPosition(int value, int pos)  
    { 
        if (pos < 1) return; 
         
        if (pos == 1)  
        { 
            insertAtStart(value); 
            return; 
        } 
         
        Node* temp = head; 
        for (int i = 1; i < pos-1 && temp; i++)  
        { 
            temp = temp->next; 
        } 
         
        if (!temp)  
        return; 
         
        Node* newNode = new Node{value, temp, temp->next}; 
        if (temp->next) temp->next->prev = newNode; 
        temp->next = newNode; 
    } 
     
    void insertAtEnd(int value)  
    { 
        if (!head)  
        { 
            insertAtStart(value); 
            return; 
        } 
         
        Node* temp = head; 
        while (temp->next)  
        { 
            temp = temp->next; 
        } 
         
        Node* newNode = new Node{value, temp, NULL}; 
        temp->next = newNode; 
    } 
     
    void display()  
    { 
        Node* temp = head; 
        while (temp)  
        { 
            cout << temp->data << " "; 
            temp = temp->next; 
        } 
        cout << endl; 
    } 
}; 
 
int main()  
{ 
    DoublyList list; 
    int choice, value, position; 
        cout << "1. Insert at Start\n2. Insert at End\n3. Insert at Position\n4. Display List\n5. Exit\n"; 
    while(choice != 5) 
    { 
        cout << "Enter your choice: "; 
        cin >> choice; 
        switch(choice)  
        { 
            case 1: 
                cout << "Enter value to insert: "; 
                cin >> value; 
                list.insertAtStart(value); 
                break; 
                 
            case 2: 
                cout << "Enter value to insert: "; 
                cin >> value; 
                list.insertAtEnd(value); 
                break; 
                 
            case 3: 
                cout << "Enter value to insert: "; 
                cin >> value; 
                cout << "Enter position: "; 
                cin >> position; 
                list.insertAtPosition(value, position); 
                break; 
                 
            case 4: 
                cout << "Current list: "; 
                list.display(); 
                break; 
                 
            case 5: 
                cout << "Exiting program\n"; 
                break; 
                 
            default: 
                cout << "Invalid choice!\n"; 
        } 
    } 
     
    return 0; 
}