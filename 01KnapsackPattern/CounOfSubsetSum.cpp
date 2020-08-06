//  Created by Pradeep Singh on 06/08/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.


// Given a set of positive numbers, find the total number of subsets whose sum is equal to a given number ‘S’.


#include<bits/stdc++.h>
using namespace std;


// recursive solution. memoise it.
int CountOfSubsetSum(vector<int>&v, int currsum, int requiredsum, int currindex, vector<vector<int>>&dp) {
	if (currsum == requiredsum) {
		return 1;
	}
	if (currsum > requiredsum || currindex >= v.size())
		return 0;
	if (dp[currindex][currsum] != -1) return dp[currindex][currsum];
	int count = 0;
	count += CountOfSubsetSum(v, currsum + v[currindex], requiredsum, currindex + 1, dp);
	count += CountOfSubsetSum(v, currsum , requiredsum, currindex + 1, dp);
	return dp[currindex][currsum] = count;
}


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
	vector<vector<int> > dp(n, vector<int>(s + 1, -1));
	cerr << CountOfSubsetSum(v, 0, s, 0, dp) << endl;

}