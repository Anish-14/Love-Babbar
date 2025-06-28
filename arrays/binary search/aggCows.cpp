#include<iostream>
using namespace std;

// Aggressive cows
// https://www.naukri.com/code360/problems/aggressive-cows_1082559?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2

bool isPossible(vector<int> &stalls, int k, int mid, int n) {
    
    int cowCount = 1;
    int lastPos = stalls[0];
    // first pe cow ko baitha diya, because you want to maximize the minimum distance so 
    // first index per to cow baithegi hi

    for(int i=1; i<n; i++ ){
        // agar next cow ko baithne ki jagah mil gyi then bitha do
        if(stalls[i]-lastPos >= mid){
            cowCount++;
            if(cowCount==k)
            {
                return true;
            }
            // cow baith gyi hai so the previous cow place will get updated
            lastPos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
   	int s = 0;
    int n = stalls.size();
    int e=stalls[n-1] - stalls[0];      // max possible distance
    int ans = -1;
    int mid = s + (e-s)/2;
    
    // we are applying binary search on s - e range which is 0 - max distance between cows
    // we will try to fit them between it peacefully

    while(s<=e) {
        if(isPossible(stalls, k, mid, n)) {
            ans = mid;
            // ans mil gya hai lekin kya pta isse bada gap bhi mil jaaye isliye we'll find it on the right
            s = mid + 1;
        }
        else{// we will find on the left side, i.e. for some smaller gap
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}



