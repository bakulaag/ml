#include<bits/stdc++.h>
using namespace std;

int Knapsack(int capacity, vector<int>& wt, vector<int>& val, int n){\

    vector<vector<int>> dp(n+1, vector<int> (capacity+1,0));

    for(int i =1;i<=n; i++){
        for(int j = 0; j<=capacity;j++){
            if(wt[i-1]<=j){
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-wt[i-1]] + val[i-1]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }

    }
    return dp[n][capacity];
}

double fract(int capacity, vector<int>&wt, vector<int>&val, int n){
    vector<pair<double, int>> ratio(n);

    for(int i =0; i<n; i++){
        ratio[i] = {(double)val[i] / wt[i],i};
    }
    
    sort(ratio.rbegin(), ratio.rend());

    double maxval = 0.0;
    for(auto& r: ratio){
        int i = r.second;
        if(capacity>=wt[i]){
            capacity -= wt[i];
            maxval+=val[i];
        }
        else{
            maxval+= val[i] * ((double)capacity/wt[i]);
            break;
        }
    }
    return maxval;
}


int main(){
    int n, capacity;
    cout<<"ENter the size: " ;
    cin>> n;
    cout<<"Enter the capacity: " ;
    cin>> capacity;

    vector<int> wt(n), val(n);

    for(int i =0; i<n; i++){
        cout<<"Enter thr weight and value: " ;
        cin>>wt[i] >> val[i];
    }

    int ans01 = Knapsack(capacity,wt,val,n);
    cout<< "max value by 0_1 is: " << ans01 << endl;

    double ans = fract(capacity,wt,val,n);
    cout<< "max val by fractknap is: "<< ans << endl;
}

//input

// ENter the size: 4
// Enter the capacity: 100
// Enter thr weight and value: 20 122
// Enter thr weight and value: 50 22
// Enter thr weight and value: 99 111
// Enter thr weight and value: 10 12
// max value by 0_1 is: 156
// max val by fractknap is: 212.485