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



    bool Compare(pair<string , ll>& a , pair<string , ll>& b){
        return (a.second > b.second) || (a.second == b.second && a.first < b.first);
    }

    map<string , ll >add = {{"posted" , 15} , {"commented" , 10} , {"likes" , 5}};
    void YallaSolve() {
        string name;
        cin>>name;
        ll n;
        cin>>n;

        map<string , ll> m;
        string s;
        getline(cin , s);
        while(n--){
            getline(cin , s);
            stringstream ss(s);
            string  a , b , c;
            ss>>a;
            ss>>b;
            if(b == "likes")
                ss>>c;
            else
                ss>>c>>c;
            c = c.substr(0 , c.length()-2);


            if(a == name || c == name){
                if(c == name)
                    swap(a , c);

                m[c]+=add[b];
            }
            else{
                m[a]+=0;
                m[c]+=0;
            }
        }

        vector<pair<string , ll>> ans;

        veclp(m){
            ans.push_back(*it);
        }

        sort(all(ans) , Compare);


        veclp(ans)
            cout<<it->first<<"\n";
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
