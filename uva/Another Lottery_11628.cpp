#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define lp(i, j, n) for (int i = j; i <= n; i++)
#define vi vector<int>
#define popcnt(a) __builtin_popcount(a)
#define vvi vector<vector<int>>
#define vll vector<ll>
#define vch vector<char>
#define vvll vector<vector<ll>>
#define vvch vector<vector<char>>
#define vpi vector<pii>
#define veclp(n) for(auto it=n.begin() ; it!=n.end();it++)
#define pi 3.141592654
#define mp make_pair
#define all(v) v.begin() , v. end()
#define MAX 1e6
#define rep(i, v) for(int i =0 ; i<v.size() ; i++)
#define oo 1e18

ll gcd(ll a , ll b){
    if(!a)
        return b;

    return gcd(b%a , a);
}

void YallaSolve() {
    int n, k;
    cin >> n >> k;
    while (n && k) {

        ll tot = 0;
        vll arr(n);
        ll temp;
        lp(i, 0, n - 1) {
            lp(j, 0, k - 1) {
                cin >> temp;
                if(j == k-1) {
                    tot += temp;
                    arr[i] = temp;
                }
            }
        }


        lp(i, 0, n - 1) {
            int g = gcd(arr[i] , tot);
            cout<<arr[i]/g<<" / "<<tot/g<<"\n";
        }

        cin >> n >> k;
    }
}

void LotsOfTests() {
    int t;
    cin >> t;
    while (t--) {
        YallaSolve();
        cout << "\n";
    }
}

void PLAY() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cout << fixed << setprecision(10);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    PLAY();
//        LotsOfTests();
    YallaSolve();
}
