#include <iostream> 
using namespace std; 
 
struct Node { 
    int data; 
    Node* left; 
    Node* right; 
     
    Node(int value)  
 { 
        data = value; 
        left = nullptr; 
        right = nullptr; 
    } 
}; 
 
class BST { 
private: 
    Node* root; 
     
    Node* insertHelper(Node* node, int value)  
 { 
        if (node == nullptr)  
  { 
            return new Node(value); 
        } 
         
        if (value < node->data)  
  { 
            node->left = insertHelper(node->left, value); 
        } 
        else if (value > node->data)  
  { 
            node->right = insertHelper(node->right, value); 
        } 
         
        return node; 
    } 
     
    Node* minValueNode(Node* node)  
 { 
        Node* current = node; 
        while (current && current->left != nullptr)  
  { 
            current = current->left; 
        } 
        return current; 
    } 
     
    Node* deleteHelper(Node* node, int value)  
 { 
        if (node == nullptr)  
  { 
            return node; 
        } 
         
        if (value < node->data)  
  { 
            node->left = deleteHelper(node->left, value); 
        } 
        else if (value > node->data)  
  { 
            node->right = deleteHelper(node->right, value); 
        } 
        else  
  { 
            if (node->left == nullptr)  
   { 
                Node* temp = node->right; 
                delete node; 
                return temp; 
            } 
            else if (node->right == nullptr)  
   { 
                Node* temp = node->left; 
                delete node; 
                return temp; 
            } 
             
            Node* temp = minValueNode(node->right); 
            node->data = temp->data; 
            node->right = deleteHelper(node->right, temp->data); 
        } 
        return node; 
    } 
     
    void inorderHelper(Node* node)  
 { 
        if (node != nullptr)  
  { 
            inorderHelper(node->left); 
            cout << node->data << " "; 
            inorderHelper(node->right); 
        } 
    } 
     
public: 
    BST()  
 { 
        root = nullptr; 
    } 
     
    void insert(int value)  
 { 
        root = insertHelper(root, value); 
    } 
     
    void remove(int value)  
 { 
        root = deleteHelper(root, value); 
    } 
     
    void display()  
 { 
        if (root == nullptr)  
  { 
            cout << "Tree is empty" << endl; 
            return; 
        } 
        inorderHelper(root); 
        cout << endl; 
    } 
}; 
 
int main()  
{ 
    BST tree; 
    int choice, value; 
    cout << "\n1. Insert Node\n2. Delete Node\n3. Display Tree\n4. Exit"; 
    while(choice != 4) 
 { 
        cout << "\nEnter your choice: "; 
        cin >> choice; 
         
        switch(choice) { 
            case 1: 
                cout << "Enter value to insert: "; 
                cin >> value; 
                tree.insert(value); 
                break; 
                 
            case 2: 
                cout << "Enter value to delete: "; 
                cin >> value; 
                tree.remove(value); 
                break; 
                 
            case 3: 
                cout << "Binary Search Tree (Inorder): "; 
                tree.display(); 
                break; 
                 
            case 4: 
                cout << "Exiting program\n"; 
                break; 
                 
            default: 
                cout << "Invalid choice!\n"; 
        } 
    } 
     
    return 0; 
} 
