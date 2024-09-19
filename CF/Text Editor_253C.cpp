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


    void YallaSolve() {
        ll n;
        cin>>n;
        vi arr(n+1);
        lp(i , 1 , n)
            cin>>arr[i];

        int a , b , x , y;
        cin>>a>>b>>x>>y;

        queue<pair<pii , int>> q;
        q.push({{a , b} , 0});
        vvi vis(n+1 , vi(1e5+2));
        int currAns = 0;
        vis[a][b] = 1;

        while(q.size()){
            pair<pii , int> curr = q.front();
            q.pop();

            pii currPt = curr.first;
            currAns = curr.second;

            if(curr.first == mp(x , y)){
                break;
            }

            int rn , cn;
            // up
            if(currPt.first > 1) {
                rn = currPt.first - 1;
                cn = min(arr[rn] + 1, currPt.second);

                if (!vis[rn][cn]) {
                    vis[rn][cn] = 1;
                    q.push({{rn, cn}, currAns + 1});
                }
            }
            // down
            if(currPt.first < n) {
                rn = currPt.first + 1;
                cn = min(arr[rn] + 1, currPt.second);

                if (!vis[rn][cn]) {
                    vis[rn][cn] = 1;
                    q.push({{rn, cn}, currAns + 1});
                }
            }
            //left
            if(currPt.second > 1){
                rn = currPt.first;
                cn = currPt.second-1;
                if (!vis[rn][cn]) {
                    vis[rn][cn] = 1;
                    q.push({{rn, cn}, currAns + 1});
                }
            }
            //right
            if(currPt.second <= arr[currPt.first]){
                rn = currPt.first;
                cn = currPt.second + 1;
                if (!vis[rn][cn]) {
                    vis[rn][cn] = 1;
                    q.push({{rn, cn}, currAns + 1});
                }
            }
        }

        cout<<currAns;
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
    //    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    //    #endif
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