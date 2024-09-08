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
        ll n , m;
        cin>>n>>m;

        vector<string> v(n);
        scn(v);

        ll ans = 0;

        vvi arr(m+1 , vi(n , 1));
        int ptr = 0;

        lp(i, 0, m - 1) {
            bool f = 0 , x = 0;
            lp(j , 1 , n-1) {
                if(arr[ptr][j] && v[j][i] < v[j-1][i]){
                    ans++;
                    f=1;
                    x = 1;
                    break;
                }
                else if(arr[ptr][j] && v[j][i] == v[j-1][i]) {
                    f = 1;
                }
                else{
                    arr[i+1][j] = 0;
                }
            }

            if(!x)
                ptr = i+1;

            if(!f)
                break;

        }

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