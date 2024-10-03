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
    #define MAX (1<<8)
    #define rep(i, v) for(int i =0 ; i<v.size() ; i++)
    #define scn(v) for (auto& i : v)cin >> i;
    #define oo 1e18
    #define cond(flag) if(flag)cout<<"YES";else cout<<"NO";

    const ll MOD = 1e9;
    const double PI = acos(-1.0);

    void YallaSolve() {
        ll n;
        cin>>n;

        vector<string> s(3);
        scn(s);

        vector<string> names({"Kuro", "Shiro", "Katie"});

        vvll rp(3 , vll(52));

        lp(i , 0 , 2){
            lp(j , 0 , s[i].size()-1){
                char c = s[i][j];
                if(islower(c))
                    rp[i][c - 'a']++;
                else
                    rp[i][c - 'A' + 26]++;
            }
        }

        lp(i , 0 , 2)
            sort(all(rp[i]) , greater<>());

        ll l = s[0].size();
        vector<pair<ll , ll>> ans(3);

        lp(i , 0 , 2){
            ans[i] = {rp[i][0] , i};
            if(n == 1 && rp[i][0] == l)
                ans[i].first--;
            else
                ans[i].first = min(ans[i].first + n , l);
        }

        sort(all(ans) , greater<>());
        if(ans[0].first == ans[1].first )
            cout<<"Draw";
        else
            cout<<names[ans[0].second];

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