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

    void solveD(){
        ll n;
        cin>>n;

        vll p(n+1);
        lp(i , 1 , n)
            cin>>p[i];

        string s;
        cin>>s;

        vi vis(n+2);
        vi ans(n+2);
        lp(i , 1 , n){
            vi arr;
            int val = i;
            while(!vis[val]){
                vis[val] = 1;
                val = p[val];
                arr.push_back(val);
            }

            int c = 0;
            veclp(arr){
                if(s[*it-1] == '0')
                    c++;
            }

            veclp(arr){
                ans[*it] = c;
            }
        }

        lp(i , 1 , n){
            cout<<ans[p[i]]<<" ";
        }
    }

    void YallaSolve() {
        solveD();
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
