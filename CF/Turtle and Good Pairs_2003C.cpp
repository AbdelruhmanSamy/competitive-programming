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
    #define MAX 1e6
    #define rep(i, v) for(int i =0 ; i<v.size() ; i++)
    #define scn(v) for (auto& i : v)cin >> i;
    #define oo 1e18
    #define cond(flag) if(flag)cout<<"YES";else cout<<"NO";

    const ll MOD =  1e9 + 7;
    const double PI = acos(-1.0);

    bool cmp(pair<char , ll>& a , pair<char , ll>& b){
        return a.second > b.second;
    }

    void solveC(){
        ll n;
        cin>>n;
        string s;
        cin>>s;f


        map<char , ll> m;

        lp(i , 0 , s.size()-1)
            m[s[i]]++;

        vector<pair<char , ll>> v;
        veclp(m){
            v.push_back({it->first , it->second});
        }

        sort(all(v) , cmp);

        int i = 0 , j=1;
        bool who = 0;

        while(n--) {
            if(!who && i<v.size() || (who && j>=v.size())){
                cout<<v[i].first;
                v[i].second--;
                if(!v[i].second)
                    i = max(i , j)+1;
            }
            else if(who && j<v.size() || (!who && i>=v.size())){
                cout<<v[j].first;
                v[j].second--;
                if(!v[j].second)
                    j = max(i , j)+1;
            }

            who = !who;
        }
    }

    void YallaSolve() {
        solveC();
    }

    void LotsOfTests() {
        int t;
        cin >> t;
        while (t--) {
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
