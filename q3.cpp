#include<iostream> 
using namespace std; 
int main() 
{ 
 int arr[] = {1,2,3,4,5,6,7,8,9,10}; 
 int n = sizeof(arr) / sizeof(arr[0]); 
 int x,i; 
 cout<<"Enter elemnts you like to find : "; 
 cin>>x; 
 int l=0; 
 int h=n-1; 
 int mid; 
 while(l<=h) 
 { 
  mid = l+(h-l)/2 ; 
  if (arr[mid] ==x) 
  { 
   cout << "Element found at index: " << mid << endl; 
   break; 
  } 
  else if(arr[mid]<x) 
  { 
   l= mid +1; 
  } 
  else 
  { 
   h=mid-1; 
  } 
 } 
 if(arr[mid] != x) 
 { 
  cout<<"Element not found"; 
 } 
 return 0; 
} 
 
