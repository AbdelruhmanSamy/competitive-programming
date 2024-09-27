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

    void YallaSolve() {
        ll n, t;
        cin >> n >> t;
        string s1, s2;
        cin >> s1 >> s2;

        string ans;
        ll diff = 0;
        lp(i, 0, n - 1)diff += (s1[i] != s2[i]);

        if (t < ceil(diff / 2.0))
            cout << -1;
        else {
            ll fir = t ,  sec = t , rem = max(t-diff , ll(0));
            lp(i, 0, n - 1) {
                if(s1[i] == s2[i]){
                    if(rem){
                        ans+=(s1[i]=='a')?'b':'a';
                        rem--;
                    }
                    else
                        ans+=s1[i];
                }
                else{
                    if((fir + sec) <= diff){
                        (fir > sec) ? (ans+=s1[i], fir--):(ans+=s2[i] , sec--);
                    }
                    else{
                        ans+= (char(s1[i]+1) == s2[i])?(s1[i] == 'a'?'z':'a'):  ((s1[i]!='z')? char(s1[i]+1):(s2[i] == 'a'? 'b': 'a')) ;
                        fir--;
                        sec--;
                    }
                    diff--;
                }
            }

            cout<<ans;
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