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
#define MAX 10000000

ll gcd(ll a , ll b){
    return (a==0)?b:gcd(b%a , a);
}

ll Lcm(ll a , ll b){
    return a*b/gcd(a , b);
}

void YallaSolve(int n, int m) {
    vll arr(n);
    lp(i , 0 , n-1)
        cin>>arr[i];

    while(m--){
        ll val;
        cin>>val;

        ll mnlen = 0 , mxlen = (1<<30);
        lp(i1 , 0 , n-4) {
            lp(i2 , i1+1 , n-3){
                lp(i3 , i2+1 , n-2){
                    lp(i4 , i3+1 , n-1){
                        ll res_a , res_b;
                        ll lcm = Lcm(arr[i1] , arr[i2]);
                        lcm = Lcm(lcm , arr[i3]);
                        lcm = Lcm(lcm , arr[i4]);

                        res_a = val/lcm * lcm;
                        if(res_a!=val)
                            res_b = (val/lcm +1)*lcm;
                        else
                            res_b = val;

                        mnlen = max(mnlen , res_a);
                        mxlen = min(mxlen , res_b);
                    }
                }
            }
        }
        cout<<mnlen<<" "<<mxlen<<"\n";
    }
}

void LotsOfTests() {
    int t;
    cin >> t;
    while (t--) {
//        YallaSolve();
        cout << "\n";
    }
}

void uvaLotsOfTests() {
    ll n , m;
    cin>>n>>m;
    while (n&&m) {
        YallaSolve(n, m);
        cin>>n>>m;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);
    //YallaSolve();
    //LotsOfTests();
    uvaLotsOfTests();
}
