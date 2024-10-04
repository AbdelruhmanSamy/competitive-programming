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
    #define vpl vector<pll>
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

    bool isValid(ll x , ll y){
        return (x>=0 && x<=100 && y>=0 && y<=100);
    }

    ll help(ll (*arr)[101][11] ,  int i ,int j  , int k){
        ll a = isValid(i-1 , j) ? arr[i-1][j][k] : 0;
        ll b = isValid(i , j-1) ? arr[i][j-1][k] : 0;
        ll c = isValid(i-1 , j-1) ? arr[i-1][j-1][k]: 0;
        return (a + b - c);
    }

    ll calc(ll (*arr)[101][11] , int t , int x1 , int y1 , int x2 , int y2){
        ll ans = 0;
        ans += isValid(x2 , y2)? arr[x2][y2][t]: 0;
        ans -=isValid(x1-1 , y2)? arr[x1-1][y2][t] : 0;
        ans -=isValid(x2 , y1-1)? arr[x2][y1-1][t] : 0;
        ans +=isValid(x1-1 , y1-1)? arr[x1-1][y1-1][t] : 0;

        return ans;
    }

    void YallaSolve() {
        ll n ,q , c;
        cin>>n>>q>>c;

        c++;
        map<pll , vll> br;
        lp(i , 0 , n-1){
            ll x , y , s;
            cin>>x>>y>>s;

            pll coord = {x , y};
            br[coord].push_back(s);
        }

        ll memo[101][101][11];

        lp(i , 0 , 100){
            lp(j , 0 , 100){
                lp(k , 0 , c-1) {
                    pll coord = {i, j};
                    auto it = br.find(coord);
                    ll curr = 0;
                    if (it != br.end()) {
                        vll & temp = it->second;
                        lp(f, 0 , temp.size()-1) {
                            curr += (temp[f] + k)%c;
                        }
                    }

                    memo[i][j][k] = help(memo, i, j , k) + curr;
                }
            }
        }

        while(q--){
            ll t , x1,y1, x2 , y2;
            cin>>t >> x1>>y1>> x2 >> y2;

            cout<<calc(memo  , t%c , x1 , y1 , x2 , y2)<<    "\n";

        }
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
    //        LotsOfTests();
        YallaSolve();
    }