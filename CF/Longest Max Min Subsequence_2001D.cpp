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
    const ll MOD =  1e9 + 7;
    const double PI = acos(-1.0);

    vi ans(3e5 + 5);

    bool better(int a, int ind){
        return ((ind&1 && a < ans[ind]) || (!(ind&1) && a > ans[ind]));
    }

    void solveD(){
        ll n;
        cin>>n;

        vll arr(n);
        scn(arr);

        ans.resize(n+5);

        vi in(n+1) , cnt(n+1) ;

        lp(i , 0 , n-1)
            cnt[arr[i]]++;

        ll ptr = 0;

        lp(i , 0 , n-1){
            cnt[arr[i]]--;

            if(!ptr)
                ans[ptr++] = arr[i], in[arr[i]] = 1;
            else{
                if(in[arr[i]])
                    continue;

                while(ptr && cnt[ans[ptr-1]] && better(arr[i] , ptr-1) || ptr>=2 && cnt[ans[ptr-1]] && cnt[ans[ptr-2]] && better(arr[i] , ptr-2)){

                    if(ptr && cnt[ans[ptr-1]] && better(arr[i] , ptr-1)){
                        in[ans[ptr-1]] = 0;
                        ptr--;
                    }else{
                        in[ans[ptr-1]] = 0;
                        in[ans[ptr-2]] = 0;
                        ptr-=2;
                    }
                }

                ans[ptr++] = arr[i];
                in[arr[i]] = 1;

            }

        }

        cout<<ptr<<"\n";
        lp(i , 0 , ptr-1)cout<<ans[i]<<" ";
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
    }
