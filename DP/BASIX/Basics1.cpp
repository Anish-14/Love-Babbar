#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<unordered_map> 
#include<list>
using namespace std;

// 1. Implementing top-down DP (Recursion + Memoization) Memoization means storing the values which we've
// already got instead of calling a function for it.
// 2. Implementing Tabulation DP  (Bottom UP)
// 3. Space Optimization

// Nth Fibonacci number
// https://www.naukri.com/code360/problems/nth-fibonacci-number_74156?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

// this is top-Down approach
// TC(O(n)) & SC(2*O(n))

int NthFibonacci(int n, vector<int> &dp){
        // base case
    if(n==0 || n==1){           // Normal Recursion
        return n;
    }

    // Improvement with DP.

    if(dp[n] != -1){            // we're using the stored values to save time by avoiding function calls.
        return dp[n];
    }

    dp[n] = NthFibonacci(n-2,dp) + NthFibonacci(n-1,dp);    // this is called memoization, we're storing values so that we can use them

    return dp[n];
}

int main()
{
    int n;
    cin>>n;

    vector<int> dp(n+1);
    fill(dp.begin(),dp.end(),-1);

    int ans = NthFibonacci(n,dp);
    cout<<ans;
}


// Tabulation DP
// without recursion kaam ho jaata hai.
// TC(O(n)) & SC(1*O(n)) recursion waali space bach jaati hai.

// 1. dp[n+1]
// 2. dp[1] == 1
//    dp[2] == 0
// 3. for(int i = 2; i<=n; i++){
//         dp[i] = dp[i-1] + dp[i-2]
//    }
// 4. return dp[n]



// Space Optimization
// TC(O(n)) && SC(O(1))

int main(){
    int n; 
    cin>>n;

    int prev1 = 1;
    int prev2 = 0;

    if(n == 0){
        cout<<0<<endl;
    }

    for(int i =2; i<=n; i++){
        int curr = prev1 + prev2;
        // shift logic
        prev2 = prev1;
        prev1 = curr;
    }
    // prev1 ya curr me se kuchh bhi return karwa skte ho but prev1 karaane ka faayda ye hai ki 1 ke liye base case nhi likhna padta.
    cout<<prev1<<endl;  // this will fail for n == 0 hence we've to make a base case for it.
}

