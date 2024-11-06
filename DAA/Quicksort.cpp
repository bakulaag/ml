#include<bits/stdc++.h>
using namespace std;

int partIndx(vector<int>&arr, int low, int high){
    int n = arr.size();
    int i = low;
    int j = high;
    int piviot = arr[low];

    while(i<j){
        while(arr[i] <= piviot && i<= high-1 ){
            i++;
        }
        while(arr[j] > piviot && j>= low+1){
            j--;
        }
        if(i<j){
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[j], arr[low]);
    return j;
}

void QS(vector<int>& arr, int low, int high){
    if(low<high){
        int partI = partIndx(arr,low,high);
        QS(arr,low,partI-1);
        QS(arr,partI+1, high);
    }
}

vector<int> quicksort(vector<int>arr){
    QS(arr, 0, arr.size()-1);
    return arr;
}

int main(){
    vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};
    int n = arr.size();
    cout<<" array before QS......" << endl;
    for(int i = 0; i<n; i++){
        cout<< arr[i] << " " ;
    }
    cout<< endl;

    arr = quicksort(arr);

    cout<<" array after QS...." << endl;
    for(int i = 0; i<arr.size(); i++){
        cout<< arr[i] << " " ;
    }
    cout<< endl;
    return 0;
    
}