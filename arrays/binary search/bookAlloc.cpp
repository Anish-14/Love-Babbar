#include<iostream>
using namespace std;

// Book allocation problem
// https://www.naukri.com/code360/problems/ayush-and-ninja-test_1097574?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2


// brute force code
long long ayushGivesNinjatest(int n, int m, vector<int> time)
{

    long long sum = 0;

    int maxTime = INT_MIN;

    // We will iterate through all the chapters and calculate the sum and maximum time.
    for (int i = 0; i < m; i++)
    {
        sum += time[i];
        maxTime = max(maxTime , time[i]);
    }

    // We will iterate through all the possible values of answer.
    for (int i = maxTime; i <= sum; i++)
    {
        
        long long days = 1;
        long long currentTime = 0;

        for (int j = 0; j < m; j++)
        {
            currentTime += time[j];
            if (currentTime > i)
            {
                days++;
                currentTime = time[j];
            }

        }

        // If the days required to study all the chaptes is less than or equal to n than answer is possible and we will return it.
        if (days <= n)
        {
            return i;
        }

    }

    return -1;
}



// optimal code  binary search
long long ayushGivesNinjatest(int n, int m, vector<int> time)
{

    long long sum = 0;

    int maxTime = INT_MIN;

    // We will iterate through all the chapters and calculate the sum.
    for (int i = 0; i < m; i++)
    {
        sum += time[i];
        maxTime = max(maxTime , time[i]);
    }

    // We will initialize the lower limit of binary search l with maxTime and the upper limit of binary search with sum.
    long long l = maxTime, r = sum, answer = sum;

    while (l <= r)
    {
        
        long long mid = (l + r) / 2;
        long days = 1;
        long long currentTime = 0;

        for (int i = 0; i < m; i++)
        {
            currentTime += time[i];
            if (currentTime > mid)
            {
                days++;
                currentTime = time[i];
            }

        }

        /*
            If the days required to study all the chaptes is greater than n than answer is not possible
            and we want more time to study in a given day so we will compress the range to the right hand side.
            Else we can study all the chapters and we will update the answer with mid.
        */

        // less than ke sign per bhi hum answer update kar rhe hai because the question states that
        // we have to minimize the maximum time and it should be completed within n days
        // now let's suppose we got a solution where he is taking less than n days but for 
        // a value less than out answer it takes more than n days (that can happen), so we
        // want that our less than solution also get included
        if (days <= n)
        {
            answer = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }

    }

    // We will return the final answer.
    return answer;
}




// this is love babbar's code, I think there's some change in the question
// to understand the code mentioned below I guess you've to watch the love's lecture

bool isPossible(vector<int> arr, int n, int m, int mid) {
    int studentCount = 1;
    int pageSum = 0;
    //cout << "checking for mid "<< mid <<endl;
    
    for(int i = 0; i<n; i++) {
        if(pageSum + arr[i] <= mid) {
            pageSum += arr[i];
        }
        else
        {
            studentCount++;
            if(studentCount > m || arr[i] > mid ) {
            return false;
        }
            pageSum = arr[i];
        }
        if(studentCount > m) {
            return false;
        }
        //cout << " for i " << i << " Student "<< studentCount << " pageSum " << pageSum << endl;
    }
    return true;
}

int allocateBooks(vector<int> arr, int n, int m) {
    int s = 0;
    int sum = 0;
    
    for(int i = 0; i<n; i++) {
        sum += arr[i];
    }
    int e = sum;
    int ans = -1;
    int mid = s + (e-s)/2;
    
    while(s<=e)
    {
        if(isPossible(arr,n,m,mid)) {
            //cout<<" Mid returned TRUE" << endl;
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

