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

    void solveB(){
        ll n;
        cin>>n;
        string s;
        cin>>s;

        bool can = 1;

        int val = sqrt(n);
        if(val * val !=n )
            can = 0;
        else{
            lp(i , 0 , val-1){
                lp(j , 0 , val-1){
                    if(i == 0 || j==0 || i==val-1 || j==val-1){
                        if(s[i*val + j]!='1'){
                            can = 0;
                            break;
                        }
                    }
                    else if(s[i*val +j]!='0'){
                        can = 0;
                        break;
                    }
                }
                if(!can)
                    break;
            }

        }

        cond(can);
    }


    void YallaSolve() {
        solveB();
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
