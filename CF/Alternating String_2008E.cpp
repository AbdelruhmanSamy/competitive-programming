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

    void solveE(){
        ll n;
        string s;
        cin>>n>>s;

        vvi odd(30) , even(30);

        lp(i , 0 , n-1){
            if(i&1)
                odd[s[i]-'a'].push_back(i);
            else
                even[s[i]-'a'].push_back(i);
        }

        int even_f = 0 , odd_f = 0 , val=0;
        if(s.size() & 1){
            lp(i, 0 , n-1){
                even_f = 0 , odd_f = 0;
                lp(j , 0 , 25){
                    int a = lower_bound(all(even[j]) , i) - even[j].begin();
                    int b = lower_bound(all(odd[j]) , i+1) - odd[j].begin();
                    b = odd[j].size()-b;

                    even_f = max(even_f , a+b);

                    a = lower_bound(all(odd[j]) , i) - odd[j].begin();
                    b = lower_bound(all(even[j]) , i+1) - even[j].begin();
                    b = even[j].size()-b;

                    odd_f = max(odd_f , a+b);
                }
                val = max(val , even_f+odd_f);
            }
            cout<<n - val;
        }
        else{
            lp(i ,0 , 25){
                even_f = max(even_f , (int)even[i].size());
                odd_f = max(odd_f , (int)odd[i].size());
            }
            cout<<n - even_f - odd_f;
        }
    }

    void YallaSolve() {
        solveE();
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
