//  Created by Pradeep Singh on 06/08/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.

/*
Given a set of positive numbers, find if we can partition it into two subsets such
that the sum of elements in both subsets is equal.
*/


#include<bits/stdc++.h>
using namespace std;


bool CanPartition(vector<int>&v, int requiredsum, int currindex, vector<vector<int> >&dp) {
	if (requiredsum == 0)
		return true;
	if (currindex >= v.size()) 	// if required sum!=0 and currindex exceeded n.
		return false;
	if (dp[currindex][requiredsum] != -1)
		return dp[currindex][requiredsum];
	bool flag1 = false, flag2 = false;
	if (v[currindex] <= requiredsum)
		flag1 = CanPartition(v, requiredsum - v[currindex], currindex + 1, dp);
	flag2 = CanPartition(v, requiredsum, currindex + 1, dp);
	return dp[currindex][requiredsum] = (flag1 || flag2);
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
	if (sum % 2 != 0) {
		cout << "False" << endl;
		return 0;
	}
	vector<vector<int> > dp(n, vector<int>(sum + 1, -1));
	if (CanPartition(v, sum / 2, 0, dp))	cout << "True" << endl;
	else cout << "False" << endl;

}