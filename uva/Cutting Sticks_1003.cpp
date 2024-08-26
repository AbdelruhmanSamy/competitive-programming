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
    #define mp make_pair
    #define all(v) v.begin() , v. end()
    #define MAX 1e6
    #define rep(i, v) for(int i =0 ; i<v.size() ; i++)
    #define scn(v) for (auto& i : v)cin >> i;
    #define oo 1e18
    #define cond(flag) if(flag)cout<<"YES";else cout<<"NO";

    const ll MOD =  1e9 + 7;
    const double PI = acos(-1.0);

    vll cuts;
    vvll memo;

    ll dp(int l , int r){
        if(r-l <= 1)
            return 0;

        ll* ret = &memo[l][r];

        if(*ret!= -1)
            return *ret;

        *ret = 1e18;
        lp(k ,l+1 , r-1){
            ll val = (cuts[r] - cuts[l]) + dp(l , k) + dp(k , r);
            *ret = min(*ret, val);
        }

        return *ret;
    }

    void YallaSolve() {
        int n;
        while(cin>>n &&  n){
            ll x;
            cin>>x;
            cuts.resize(x+2);
            cuts[0] = 0;
            lp(i , 1 , x)
                cin>>cuts[i];

            cuts[x+1] = n;

            memo.resize(x+5 , vll(x+5 , -1));


            ll ans = dp(0 , x+1);
            cout<<"The minimum cutting is "<<ans<<".\n";

            memo.clear();
            cuts.clear();
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
