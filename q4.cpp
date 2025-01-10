#include <iostream> 
using namespace std; 
 
class Stack { 
    int top; 
    int arr[10]; 
 
public: 
    Stack() {  
        top = -1;  
    } 
     
    bool push(int x) { 
        if (top >= 9) { 
            cout << "Stack Overflow\n"; 
            return false; 
        } 
        arr[++top] = x; 
        cout << x << " pushed into stack\n"; 
        return true; 
    } 
     
    int pop() { 
        if (top < 0) { 
            cout << "Stack Underflow\n"; 
            return -1; 
        } 
        int x = arr[top--]; 
        return x; 
    } 
     
    void display() { 
        if (top < 0) { 
            cout << "Stack is empty\n"; 
            return; 
        } 
        cout << "Stack elements: "; 
        for (int i = top; i >= 0; i--) 
            cout << arr[i] << " "; 
        cout << endl; 
    } 
}; 
 
int main() { 
    Stack s; 
    int choice, value; 
     cout <<"\n1. Push\n2. Pop\n3. Display\n4. Exit\n"; 
    while(choice != 4) 
 { 
        cout<< "Enter your choice: "; 
        cin >> choice; 
         
        switch(choice)  
  { 
            case 1: 
            cout << "Enter value to push: "; 
            cin >> value; 
            s.push(value); 
            break; 
                 
            case 2: 
            value = s.pop(); 
            if(value != -1) 
                cout << "Popped value: " << value << endl; 
            break; 
                 
            case 3: 
                s.display(); 
                break; 
                 
            case 4: 
                cout << "Exiting...\n"; 
                break; 
                 
            default: 
                cout << "Invalid choice!\n"; 
        } 
    } 
     
    return 0; 
} 