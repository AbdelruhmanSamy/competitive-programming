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
    #define MAX 1e4+5
    #define rep(i, v) for(int i =0 ; i<v.size() ; i++)
    #define scn(v) for (auto& i : v)cin >> i;
    #define oo 1e18
    #define cond(flag) if(flag)cout<<"YES";else cout<<"NO";

    const ll MOD =  1e9 + 7;
    const double PI = acos(-1.0);


    ll powerMod(ll a , ll b){
        if(b == 0)
            return 1;

        ll p = powerMod(a , b/2) %MOD;
        p = (p*p)%MOD;

        return (b&1)? (a%MOD*p)% MOD:p;
    }

    ll invMod(ll a){
        return powerMod(a , MOD-2);
    }

    void solveF(){
        ll n;
        cin>>n;
        vi arr(n);
        scn(arr);

        ll sum = 0;
        lp(i , 0 , n-1)
            sum+=arr[i];

        ll val = 0;
        lp(i , 0 , n-1){
            sum-=arr[i];
            val+=(sum % MOD*arr[i])%MOD;
        }

        ll y = (n*(n-1))/2;
        cout<<(val%MOD*invMod(y)%MOD)%MOD;
    }

    void YallaSolve() {
        solveF();
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
        cout << fixed << setprecision(10);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }

    int main() {
        PLAY();
        LotsOfTests();
    //        YallaSolve();
    }
