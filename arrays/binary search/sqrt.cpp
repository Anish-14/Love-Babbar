#include<iostream>
using namespace std;

// Problem statement
// we have to find the square root of the given integer to the precision asked in O(logn) TC.

 long long int sqrtInteger(int n) {
        
        int s = 0;
        int e = n;
        long long int mid = s + (e-s)/2;
        
        long long int ans = -1;
        while(s<=e) {
            
            long long int square = mid*mid;
            
            if(square == n)
                return mid;
            
            if(square < n ){
                ans = mid;
                s = mid+1;
            }
            else
            {
                e = mid - 1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }

double morePrecision(int n, int precision, int tempSol) {
    
    double factor = 1;
    double ans = tempSol;

    for(int i=0; i<precision; i++) {
        factor = factor/10;

        for(double j=ans; j*j<n; j= j+factor ){
            ans = j;
        }
    }
    return ans;
}

int main() {
    int n;
    cout <<" Enter the number " << endl;
    cin >> n;

    int tempSol = sqrtInteger(n);
    cout <<" Answer is " << morePrecision(n, 3, tempSol) << endl;

    return 0;
}



// another method

class Solution {
public:
    int mySqrt(int x) {
        if(x < 2){
            return x;
        }

        int s = 1;
        int e = x/2;        // use end as x/2 as square root for x >=2 will be between 1 and x/2. It makes the algo fast
        int mid = s + (e-s)/2;
        int ans = 0;

        while(s <= e){
            if(mid <= x/mid){
                ans = mid;
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
            mid = s + (e-s)/2;
        }

        return ans;
    }
};

