//  Created by Pradeep Singh on 06/08/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.



/*
You are given a set of positive numbers and a target sum ‘S’. Each number should be assigned either a ‘+’ or ‘-’ sign.
We need to find the total ways to assign symbols to make the sum of the numbers equal to the target ‘S’.
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	// recursive solution. memoise it.
	int TargetSum(vector<int>&v, int currsum, int requiredsum, int currindex, vector<vector<int> > &dp) {
		// cerr << currsum << endl;
		if (currindex == v.size() && currsum == requiredsum)
			return 1;
		if (currindex >= v.size())
			return 0;
		int cnt = 0;
		if (dp[currindex][currsum + 1000] != -1) return dp[currindex][currsum + 1000];
		cnt += TargetSum(v, currsum + (-1 * v[currindex]), requiredsum, currindex + 1, dp);
		cnt += TargetSum(v, currsum + v[currindex], requiredsum, currindex + 1, dp);
		return dp[currindex][currsum + 1000] = cnt;
	}

	int findTargetSumWays(vector<int>& v, int s) {
		int n = v.size();
		int sum = 0;
		for (int x : v)	sum += x;
		vector<vector<int> > dp(n, vector<int>(sum + 1000 + 1, -1));  // 1000 has been added so that the currsum being negative would not impact the solution
		return TargetSum(v, 0, s, 0, dp);

	}
};


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, s; cin >> n >> s;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	Solution t;
	cerr << t.findTargetSumWays(v, s) << endl;

}