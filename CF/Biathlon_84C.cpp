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

    struct Shoot{
        ll x;
        ll y;
        ll ind;
        Shoot(ll X, ll Y , ll I){
            x=X;
            y=Y;
            ind=I;
        }
    };

    void YallaSolve() {
        ll n;
        cin>>n;

        vector<pii> targets;
        vector<vector<vi>> index(2 , vector<vi>(2e4 + 5 , {0 , 0}));
        lp(i , 1  , n){
            pii a;
            cin>>a.first>>a.second;
            targets.push_back(a);

            lp(j , a.first - a.second , a.first + a.second){
                index[j<0?0:1][abs(j)].push_back(i);
            }
        }

        ll m;
        cin>>m;
        vector<vector<Shoot>> shoots(n+1);
        lp(i , 1 , m){
            ll x , y;
            cin>>x>>y;
            vi ind = index[x<0?0:1][abs(x)];
            lp(j , 0 , ind.size()-1){
                Shoot s(x , y , i);
                shoots[ind[j]].push_back(s);
            }
        }

        vi ans(n);
        ll count = 0;
        lp(i , 1 , n){
            bool found = 0;
            if(!shoots[i].empty()) {
                lp(j, 0, shoots[i].size() - 1) {
                    Shoot val = shoots[i][j];
                    ll a = targets[i-1].first;
                    ll r = targets[i-1].second;
                    ll x = val.x;
                    ll y = val.y;
                    ll ind = val.ind;
                    if ((x-a)*(x-a) + y*y <= r*r ){
                        ans[i-1] = ind;
                        found = 1;
                        count++;
                        break;
                    }
                }
            }
            if(!found)
                ans[i-1] = -1;
        }

        cout<<count<<"\n";
        veclp(ans)
            cout<<*it<<" ";

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