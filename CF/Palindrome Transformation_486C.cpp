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


    void YallaSolve() {
        ll n , k;
        cin>>n>>k;

        string s;
        cin>>s;

        ll ans = 0;

        bool f = 0;

        ll st = n/2 , end = 0;
        lp(i , 0 , n/2 -1){
            if(s[i] != s[n-i-1]){
                if(!f)
                    st = i , f=1;
                end = i;
                ans+=min(abs(s[i] - s[n-i-1]) , 26 - abs(s[i] - s[n-i-1]));
            }

        }


        if(k>n/2)
            k = n-k;
        else
            k--;

        ans+= max(0LL , 2*min(k-st , end - k));
        ans+=max(0LL , max(k-st , end-k));

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
