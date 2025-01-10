#include <iostream> 
using namespace std; 
 
int main()  
{ 
    int r,c; 
    int arr[10][10]; 
    cout << "Enter size row and column of matrix: "<<endl; 
    cin >> r>>c; 
    cout << "Enter matrix elements:" << endl; 
   
    for(int i = 0; i < r; i++)  
    { 
        for(int j = 0; j < c; j++)  
        { 
            cin >> arr[i][j]; 
        } 
    } 
     
    cout << "Diagonal elements: "; 
    for(int i = 0; i < r; i++) 
    { 
        cout << arr[i][i] << " "; 
    } 
    cout << endl; 
    return 0; 
} 