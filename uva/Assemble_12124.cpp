    //
    // Created by abdelruhman on 7/5/24.
    //

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
    #define pi 3.141592654
    #define mp make_pair
    #define all(v) v.begin() , v. end()
    #define MAX 1e9
    #define rep(i, v) for(int i =0 ; i<v.size() ; i++)

    class Compare {
    public:
        bool operator()(pii l, pii r) {
            return (l.first < r.first || ((l.first == r.first) && (l.second < r.second)));
        }
    };

    void YallaSolve() {
        int n, budget;
        cin >> n >> budget;

        string s1, s2;
        int q, p;

        map<string, int> m;
        vector<vector<pii>> arr;
        int curr  = 1;

        while (n--) {
            cin >> s1 >> s2 >> p >> q;
            if (!m[s1]) {
                m[s1] = curr;
                curr++;
                arr.push_back(vector<pii >());
            }
            int ind = m[s1]-1;
            arr[ind].push_back({q, p});
        }

        int ans = MAX;
        rep(i, arr) {
            sort(all(arr[i]), [](pii l, pii r) {
                return (l.first < r.first || ((l.first == r.first) && (l.second > r.second)));
            });

            pii val = arr[i][arr[i].size() - 1];
            ans = min(ans, val.first);

            vector<pii> temp;
            temp.push_back(val);
            int k = arr[i].size()-1;
            for (int j = arr[i].size() - 2; j >= 0; j--) {
                if (arr[i][j].second < arr[i][k].second) {
                    temp.push_back(arr[i][j]);
                    k=j;
                }
            }

            arr[i].clear();
            for (int j = temp.size() - 1; j >= 0; j--) {
                arr[i].push_back(temp[j]);
            }

        }

        ll currPrice = 0;
        priority_queue<pii, vector<pii >, Compare> queue;
        lp(i, 0, arr.size() - 1) {
            int j = lower_bound(all(arr[i]), mp(ans, 0), [](pii l , pii r){
                return (l.first < r.first );
            }) - arr[i].begin();
            currPrice += arr[i][j].second;


            lp(k, 1, j) {
                queue.push(mp(arr[i][k - 1].first, arr[i][k].second - arr[i][k - 1].second));
            }
        }

        while (currPrice > budget) {
            pii pair = queue.top();
            queue.pop();
            currPrice -= pair.second;
            ans = min(ans, pair.first);
        }

        cout << ans;
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
        //            YallaSolve();
    }
