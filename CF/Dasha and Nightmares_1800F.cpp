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


    int getBit(int num , int ind){
        return ((num >> ind)&1);
    }

    int setBit(int num , int ind){
        return (num | (1<<ind));
    }

    int clearBit(int num , int ind){
        return (num & ~(1<<ind));
    }

    void printNumber(int n , int len){
        if(!len)
            return;

        printNumber(n >> 1 , len-1);
        cout<<(n&1);
    }


    void YallaSolve(){
        ll n;
        cin>>n;

        vector<string> arr(n);
        scn(arr);

        map<pii , int> mask;
        map<pii , int> m;       // {mask , index of zeros in foundMask} = count
        lp(i , 0 , n-1){
            vi count(26);
            lp(j , 1 , arr[i].size()){
                count[arr[i][j-1] - 'a']++;
            }

            int currMask = 0;
            int foundMask = 0;
            lp(j , 0  , 25){
                if(count[j]&1)
                    currMask = setBit(currMask , j);
                if(count[j])
                    foundMask = setBit(foundMask , j);
            }

            auto iter = mask.find({currMask , foundMask});
            if(iter == mask.end()) {
                mask[{currMask, foundMask}] = 1;
            }
            else {
                mask[{currMask , foundMask}]++;
            }
            lp(j , 0 , 25){
                if(!(foundMask & (1<<j))) {
                    m[{currMask , j}]++;
                }
            }

        }


        ll ans = 0;
        veclp(mask){
            int currMask = it->first.first;
            int foundMask = it->first.second;
            int notMask = currMask^((1<<26) -1);
            ll count = it->second;
            lp(i, 0, 25) {
                if (notMask & (1 << i) && !(foundMask & (1<<i))) {
                    int temp = clearBit(notMask, i);
                    auto it2 = m.find({temp , i});
                    if (it2 != mask.end()) {
                        ans+=count * m[{temp , i}];
                    }
                }
            }
        }

        cout<<ans/2;

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