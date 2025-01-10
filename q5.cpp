#include <iostream> 
using namespace std; 
 
class CircularQueue { 
private: 
    int *arr; 
    int front, rear; 
    int size; 
 
public: 
    CircularQueue(int s)  
 { 
        size = s; 
        arr = new int[size]; 
        front = rear = -1; 
    } 
    void enqueue(int value)  
 { 
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))  
  { 
            cout << "Queue is full!" << endl; 
            return; 
        } 
        if (front == -1)  
  { 
            front = rear = 0; 
        }else if (rear == size - 1 && front != 0)  
  { 
            rear = 0; 
        }else  
  { 
            rear++; 
        } 
        arr[rear] = value; 
        cout << value << " enqueued successfully" << endl; 
    } 
 
    void dequeue() { 
        if (front == -1) { 
            cout << "Queue is empty!" << endl; 
            return; 
        } 
 
        cout << arr[front] << " dequeued successfully" << endl; 
 
        if (front == rear) {   
        front = rear = -1; 
        } else if (front == size - 1) { 
            front = 0; 
        } else { 
            front++; 
        } 
    } 
 
    void display() { 
        if (front == -1) { 
            cout << "Queue is empty!" << endl; 
            return; 
        } 
 
        cout << "Queue elements: "; 
        if (rear >= front) { 
            for (int i = front; i <= rear; i++) { 
                cout << arr[i] << " "; 
            } 
        } else { 
            for (int i = front; i < size; i++) { 
                cout << arr[i] << " "; 
            } 
            for (int i = 0; i <= rear; i++) { 
                cout << arr[i] << " "; 
            } 
        } 
        cout << endl; 
    } 
}; 
 
int main()  
{ 
    CircularQueue q(5); 
    int choice, value; 
 cout << "\n1. Enqueue\n2. Dequeue \n3. Display\n4. Exit"<<endl; 
    while (choice != 4) 
  { 
        cout << "Enter your choice: "; 
        cin >> choice; 
 
        switch (choice)  
  { 
            case 1: 
                cout << "Enter value to enqueue: "; 
                cin >> value; 
                q.enqueue(value); 
                break; 
            case 2: 
                q.dequeue(); 
                break; 
            case 3: 
                q.display(); 
                break; 
            case 4: 
                cout << "Exiting program..." << endl; 
                break; 
            default: 
                cout << "Invalid choice!" << endl; 
        } 
    } 
    return 0; 
} 
