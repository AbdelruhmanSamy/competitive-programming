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
        ll n,  m , q;
        cin>>n>>m>>q;

        vvi mat(n , vi(m));
        lp(i , 0 , n-1)
            lp(j , 0 , m-1)
                cin>>mat[i][j];

        vi r(n+1) , c(m+1);

        lp(i , 1 , n)
            r[i] = i;
        lp(i , 1 , m)
            c[i] = i;

        char ch;
        ll x , y;

        while(q--){
            cin>>ch>>x>>y;
            if(ch =='c'){
                ll temp = c[x];
                c[x] = c[y];
                c[y] = temp;
            }
            else if(ch == 'r'){
                ll temp = r[x];
                r[x] = r[y];
                r[y] = temp;
            }
            else{
                cout<<mat[r[x]-1][c[y]-1]<<"\n";
            }
        }
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
