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
        ll n;
        cin>>n;
        string s;
        cin>>s;

        char pre = s[0] , who = s[0];
        bool counting = 0;
        ll count = 1 , mxFlip = 0, currFlip = 0;

        lp(i , 1 , n-1){
            if(s[i] == pre){
                if(counting){
                    counting=!counting;
                    mxFlip = max(mxFlip , currFlip);
                    currFlip = 0;
                }
                else{
                    currFlip++;
                    counting = 1;
                }
            }
            if(s[i]!=who){
                count++;
                who = s[i];
            }
            pre = s[i];
        }

        ll ans = count;
        if(mxFlip)
            ans+=2;
        else if(!mxFlip && currFlip)
            ans++;

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