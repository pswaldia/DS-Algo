#include <vector>
#include <list>
#include <unordered_map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;

#define str(a) to_string(a)
#define int long long
#define pb push_back
#define mp make_pair
#define SORT(c) sort(c.begin(),c.end())
#define max_heap priority_queue<int>
#define min_heap priority_queue< int,vector<int>, greater<int> >
#define mod 1000000007
#define setbits(x) __builtin_popcount(x)
#define ps(x,y) fixed<<setprecision(y)<<x
#define start(t) int x;cin>>x;while(x--)
#define MAX 10000001
#define sync ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void fast_io() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
}
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }



int power(int x, int y, int p)
{
    x = x % mod;
    int res = 1;
    while (y > 0)
    {
        if (y & 1)
        {
            res = (res * x) % mod;
        }
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}
int inverse(int x, int p)
{
    return power(x, p - 2, p);
}

int32_t main()
{
    sync;
    int cases;
    cin >> cases;
    while (cases--)
    {
        int N;
        cin >> N;
        int arr[N + 1];
        for (int i = 1; i < N + 1; i++)
            cin >> arr[i];
        int f1 = 0, f2 = 0;
        int ans = 0;
        for (int i = 1; i < N + 1; i++)
        {
            if (arr[i] % 2) //if no. is odd then check the
            {
                ans += i - f1;
                if (f1 != 0)
                {
                    if (arr[f1] % 4 == 0)
                    {
                        ans += f1;
                    }
                    else
                    {
                        ans += f2;
                    }
                }
            }
            else
            {
                f2 = f1;
                f1 = i;
                if (arr[i] % 4 == 0)
                {
                    ans += i;
                }
                else
                {
                    ans += f2;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
