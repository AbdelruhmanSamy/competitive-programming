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

    void solveD(){
        ll  n ,m;
        cin>>n>>m;

        ll best = 0;
        lp(k, 0 , n-1){
            ll sz;
            cin>>sz;

            vll arr(sz);
            scn(arr);
            sort(all(arr));
            ll cnt = 2;
            ll val = 0;

            int j = 0;
            while(j<sz){
                if(val < arr[j]) {
                    cnt--;
                    if(!cnt)
                        break;
                    val++;
                }
                else if(val > arr[j])
                    val = arr[j];
                else{
                    j++;
                    val++;
                }
            }

            if(cnt == 2)
                val++;

            best = max(best , val);
        }


        ll ans = (min(m , best)+1) *best;

        if(best < m)
            ans+= ((m+(best+1))*(m+1-(best+1)))/2;

        cout<<ans;
    }

    void YallaSolve() {
        solveD();
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
