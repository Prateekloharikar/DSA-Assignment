#include <iostream> 
using namespace std; 
 
void reverseArray(int arr[], int start, int end)  
{ 
 
    if (start >= end) 
        return; 
    int temp = arr[start]; 
    arr[start] = arr[end]; 
    arr[end] = temp; 
    reverseArray(arr, start + 1, end - 1); 
} 
 
int main()  
{ 
    int n; 
    int arr[10]; 
    cout << "Enter the size of array: "; 
    cin >> n; 
     
    cout << "Enter elements: "<<endl; 
    for(int i = 0; i < n; i++)  
    { 
        cin >> arr[i]; 
    } 
 
    cout << "Array--> "; 
    for(int i = 0; i < n; i++)  
    { 
        cout << arr[i] << " "; 
    } 
    reverseArray(arr, 0, n-1); 
     
    cout << "\nReversed array--> "; 
    for(int i = 0; i < n; i++)  
    { 
        cout << arr[i] << " "; 
    } 
    return 0; 
} 
