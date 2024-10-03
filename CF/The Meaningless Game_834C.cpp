    #include<bits/stdc++.h>

    using namespace std;

    typedef long long ll;
    #define pii pair<int , int>
    #define pll pair<ll , ll>
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
    #define mp make_pair
    #define all(v) v.begin() , v. end()
    #define MAX (1<<8)
    #define rep(i, v) for(int i =0 ; i<v.size() ; i++)
    #define scn(v) for (auto& i : v)cin >> i;
    #define oo 1e18
    #define cond(flag) if(flag)cout<<"YES";else cout<<"NO";

    const ll MOD = 1e9;
    const double PI = acos(-1.0);

    ll getCube(ll n){
        ll l = 0 , r = 1000005;
        while(l!=r){
            ll m = (l+r+1)/2;
            if(m*m*m > n)
                r = m-1;
            else
                l = m;
        }
        return l;
    }

    void YallaSolve() {
        ll a , b;
        cin>>a>>b;
        ll val = getCube( a*b);

        if(val * val * val != a*b)
            cout<<"NO";
        else if(a%val == 0 && b%val == 0)
            cout<<"YES";
        else
            cout<<"NO";
    }


    void LotsOfTests() {
        int t;
        cin >> t;
        lp(i, 1, t) {
            YallaSolve();
            cout << "\n";
        }
    }

    void PLAY() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
        cout << fixed << setprecision(0);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }

    int main() {
        PLAY();
        LotsOfTests();
        //            YallaSolve();
    }