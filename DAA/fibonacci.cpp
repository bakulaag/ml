
// fibonacci series

#include<bits/stdc++.h>
using namespace std;

int fibM(int n){

if(n<=1){
  return n;
}
return fibM(n-1)+fibM(n-2);



}

void print_rec_fib(int m){
  for(int i=0; i<m; i++){
   cout<< fibM(i)<<" ";
  }
  cout<<endl;
}

void printfibo_nonrecursive(int x){
int a=0;
int b=1;
for(int i=0; i<x; i++){
  cout<<a<<" ";
  int next=a+b;
  a=b;
  b=next;
}
cout<<endl;


}


int main(){
int k;
cout<<"enter k";
cin>> k;
cout<<"the fibonacci series is :"<<endl;

print_rec_fib(k);
cout<<" printed no recursively"<<endl;
printfibo_nonrecursive(k);









}