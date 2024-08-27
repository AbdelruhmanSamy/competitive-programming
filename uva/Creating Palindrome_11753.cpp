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

    vll arr;
    map<pair<int , int > , ll >memo;
    ll dp(int i , int j , ll k){
        if(i>=j)
            return 0;

        // pruning
        if(k<0)
            return 1e18;

        if(memo.find({i, j}) != memo.end())
            return memo[{i , j}];


        ll ans;
        if(arr[i] == arr[j])
            ans = dp(i+1 , j-1, k);
        else
            ans = 1 + min(dp(i , j-1 , k-1) , dp(i+1 , j , k-1));

        // if  the value returned is just indicating that this time
        // i got out of Ks, i shouldn't record this in my memo in order
        // to retry the path in the future, which may not exceed K
        if(ans >= 1e18)
            return ans;

        return memo[{i , j}] = ans;
    }

    void YallaSolve(int t) {
        ll n , k;
        cin>>n>>k;

        arr.resize(n);
        scn(arr);

        ll ans = dp(0 , n-1, k);

        cout<<"Case "<<t<<": ";
        if(!ans)
            cout<<"Too easy";
        else if(ans > k)
            cout<<"Too difficult";
        else
            cout<<ans;

        memo.clear();
    }

    void LotsOfTests() {
        int t;
        cin >> t;
        lp(i , 1 , t) {
            YallaSolve(i);
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
