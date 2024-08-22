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


    vvll memo;
    vll arr , open , clse;
    ll rec(int i , int j){
        if(i == j || i>j)
            return 0;

        ll* ret = &memo[i][j];
        if(*ret!=-1)
            return *ret;

        *ret = 1e18;

        lp(k , i , j){
            *ret = min(*ret , rec(i , k)+rec(k+1 , j)+arr[i]*arr[k+1]*arr[j+1]);
        }

        return *ret;
    }

    void buildOutput(int i , int j){
        if(i == j || i>j)
            return;
        open[i]++;
        clse[j]++;

        ll ans = rec(i , j);

        ll curr;

        lp(k , i , j){
            curr = rec(i , k)+rec(k+1 , j)+arr[i]*arr[k+1]*arr[j+1];
            if(curr == ans) {
                buildOutput(i , k);
                buildOutput(k+1 , j);
                break;
            }
        }

    }

    void YallaSolve() {
        ll n;
        cin>>n;
        ll cnt = 1;
        while(n){
            arr.clear();
            arr.resize(n+2);

            cin>>arr[1]>>arr[2];
            memo.clear();
            memo.resize(n+5 , vll(n+5 , -1));
            open.clear();
            open.resize(20 , 0);
            clse.clear();
            clse.resize(20 , 0);

            lp(i ,  3 , n+1) {
                cin>>arr[i]>>arr[i];
            }

            rec(1 , n);

            buildOutput(1 , n);

            cout<<"Case "<<cnt<<": ";
            lp(i , 1 , n){
                while(open[i])
                    cout<<"(" , open[i]--;
                cout<<"A"<<i;
                while(clse[i])
                    cout<<")" , clse[i]--;
                if(i!=n)
                    cout<<" x ";
            }
            cout<<"\n";
            cin>>n;
            cnt++;
        }
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
    //        LotsOfTests();
        YallaSolve();
    }
