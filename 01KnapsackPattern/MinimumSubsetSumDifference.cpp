//  Created by Pradeep Singh on 06/08/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.


// Given a set of positive numbers, partition the set into two subsets with minimum difference between their subset sums.





#include<bits/stdc++.h>
using namespace std;

int MinimumSubsetSumDifference(vector<int>&v, int sum1, int currindex, int sum, vector<vector<int> >&dp) {
	if (currindex == v.size()) {
		int sum2 = sum - sum1;
		return abs(sum2 - sum1);
	}
	if (dp[currindex][sum1] != -1)
		return dp[currindex][sum1];
	int diff1 = MinimumSubsetSumDifference(v, sum1 + v[currindex], currindex + 1, sum, dp);
	int diff2 = MinimumSubsetSumDifference(v, sum1, currindex + 1, sum, dp);
	return dp[currindex][sum1] = min(diff1, diff2);
}



int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; cin >> n;
	vector<int> v(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
	}
	vector<vector<int> > dp(n, vector<int>(sum + 1, -1));
	cerr << MinimumSubsetSumDifference(v, 0, 0, sum, dp) << endl;

}