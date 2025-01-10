#include <iostream> 
using namespace std; 
 
struct Node { 
    int data; 
    Node* left; 
    Node* right; 
     
    Node(int value) : data(value), left(nullptr), right(nullptr) {} 
}; 
 
class BinaryTree { 
private: 
    Node* root; 
     
    void inorderHelper(Node* node)  
 { 
        if (node == nullptr) return; 
         
        inorderHelper(node->left); 
        cout << node->data << " "; 
        inorderHelper(node->right);     
    } 
     
    void preorderHelper(Node* node) { 
        if (node == nullptr) return; 
         
        cout << node->data << " "; 
        preorderHelper(node->left);    
        preorderHelper(node->right);   
    } 
     
    void postorderHelper(Node* node) { 
        if (node == nullptr) return; 
         
        postorderHelper(node->left); 
        postorderHelper(node->right); 
        cout << node->data << " ";  
    } 
 
public: 
    BinaryTree() : root(nullptr) {} 
     
    void insert(int value)  
 { 
        if (root == nullptr)  
  { 
            root = new Node(value); 
            return; 
        } 
         
        Node* current = root; 
        while (true)  
  { 
            if (value < current->data)  
   { 
                if (current->left == nullptr)  
    { 
                    current->left = new Node(value); 
                    break; 
                } 
                current = current->left; 
            }  
   else  
   { 
                if (current->right == nullptr)  
    { 
                    current->right = new Node(value); 
                    break; 
                } 
                current = current->right; 
            } 
        } 
    } 
     
    void inorder()  
 { 
        cout << "\Inorder traversal: "; 
        inorderHelper(root); 
        cout <<endl; 
    } 
     
    void preorder()  
 { 
        cout << "\nPreorder traversal: "; 
        preorderHelper(root); 
        cout <<endl; 
    } 
     
    void postorder()  
 { 
        cout << "\nPostorder traversal: "; 
        postorderHelper(root); 
        cout <<endl; 
    } 
}; 
 
int main()  
{ 
    BinaryTree tree; 
     
    tree.insert(50); 
    tree.insert(30); 
    tree.insert(70); 
    tree.insert(20); 
    tree.insert(40); 
    tree.insert(60); 
    tree.insert(80); 
     
    tree.inorder();    
    tree.preorder(); 
    tree.postorder(); 
     
    return 0; 
}  
 
