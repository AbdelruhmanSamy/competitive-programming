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
    #define MAX (1<<17)
    #define rep(i, v) for(int i =0 ; i<v.size() ; i++)
    #define scn(v) for (auto& i : v)cin >> i;
    #define oo 1e18
    #define cond(flag) if(flag)cout<<"YES";else cout<<"NO";

    const ll MOD =  1e9;
    const double PI = acos(-1.0);

    ll n , h;
    bool rec(ll l , ll r  , ll& ans ,  bool dir, ll currH){
        ans++;
        if(l == r){
            if(l == n)
                return 1;
            return 0;
        }

        bool isLeft = (n>=l && n<= r - (r-l+1)/2);
        if((dir && !isLeft) || (!dir && isLeft)) {
            ans += pow(2 , h - currH) -1;
        }
        if(isLeft)
            return rec(l , r-(r-l+1)/2 , ans , 0 , currH+1);

        return rec( l+ (r-l+1)/2 , r,ans , 1, currH+1);
    }

    void YallaSolve() {
        cin>>h>>n;
        ll ans = -1;
        rec(1 , pow(2 , h) , ans , 1 , 0);

        cout<<ans;
    }


    void LotsOfTests() {
        int t;
        cin >> t;
        lp(i , 1 , t) {
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
    //        LotsOfTests();
        YallaSolve();
    }