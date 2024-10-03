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
        ll n , x;
        cin>>n>>x;

        ll ans = LLONG_MAX;

        map<int , vector<pll>> dur;
        map<pll , ll> vouch;

        lp(i ,0  , n-1){
            ll l , r , c;
            cin>>l>>r>>c;


            pll p = {l , r-l+1};
            if(vouch.find(p) == vouch.end()) {
                vouch[p] = c;
                dur[r-l+1].push_back({l , c});
            }
            else {
                vouch[p] = min(vouch[p], c);
            }
        }


        veclp(dur){
            vector<pll> & arr = it->second;
            sort(all(arr));
            ll x = arr.size()-1;
            arr[x].second  = vouch[{arr[x].first , it->first}];
            ll mn = arr[x].second;
            for(int i = arr.size()-2 ; i>=0 ; i--){
                ll c = vouch[{arr[i].first , it->first}];
                mn = min(c , mn);
                arr[i].second = mn;
            }
        }

        veclp(vouch){
            ll l = it->first.first;
            ll d = it->first.second;
            ll c = it->second;

            int remD = x - d;
            if(remD > 0 && dur.find(remD)!=dur.end()) {
                pll temp = {l + d - 1 , LLONG_MAX};
                int ind = upper_bound(all(dur[remD]), temp) - dur[remD].begin();
                if (ind != dur[remD].size()) {
                    ans = min(ans, c + dur[remD][ind].second);
                }
            }
        }

        if(ans == LLONG_MAX)
            cout<<-1;
        else
            cout<<ans;
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