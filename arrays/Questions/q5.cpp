#include<iostream>
#include<vector>
using namespace std;

// https://www.naukri.com/code360/problems/sum-of-two-arrays_893186?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_4
// Add arrays
// L21 love babbar last question of the lecture

vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	vector<int> ans;
	int first = n-1;
	int second = m-1;
	int extra = 0;
	int sum = 0;

    // adding from back
	while(first >= 0 && second >= 0){
		sum = a[first] + b[second] + extra;
		int value = sum % 10;
		extra = sum / 10;
		ans.push_back(value);
		first--;
		second--;
	}

    // agar size are not same then this
	while(first >= 0){
		sum = a[first] + extra;
		int value = sum % 10;
		extra = sum / 10;
		ans.push_back(value);
		first--;
	}
	while(second >= 0){
		sum = b[second] + extra;
		int value = sum % 10;
		extra = sum / 10;
		ans.push_back(value);
		second--;
	}
    // agar extra carry bach gya then this is also very important
	while(extra != 0){
		sum = extra;
		extra = sum/10;
		int value = sum%10;
		ans.push_back(value);

	}

    // as we were pushing elements in the array so the reverse order was saved in it
	reverse(ans.begin(), ans.end());

	return ans;
}


