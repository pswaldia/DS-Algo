//  Created by Pradeep Singh on 06/08/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.

/*
Given a set of positive numbers, determine if a subset exists whose sum is equal to a given number ‘S’.
*/




#include<bits/stdc++.h>
using namespace std;


bool SubsetSumPossibe(vector<int>&v, int requiredsum, int currindex, vector<vector<int> >&dp) {
	if (requiredsum == 0)
		return true;
	if (currindex >= v.size()) 	// if required sum!=0 and currindex exceeded n.
		return false;
	if (dp[currindex][requiredsum] != -1)
		return dp[currindex][requiredsum];
	bool flag1 = false, flag2 = false;
	if (v[currindex] <= requiredsum)
		flag1 = SubsetSumPossibe(v, requiredsum - v[currindex], currindex + 1, dp);
	flag2 = SubsetSumPossibe(v, requiredsum, currindex + 1, dp);
	return dp[currindex][requiredsum] = (flag1 || flag2);
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, sum; cin >> n >> sum;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<vector<int> > dp(n, vector<int>(sum + 1, -1));
	if (SubsetSumPossibe(v, sum, 0, dp))	cout << "True" << endl;
	else cout << "False" << endl;

}