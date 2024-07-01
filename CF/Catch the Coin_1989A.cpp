    //
    // Created by abdelruhman on 6/28/24.
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
    #define rep(i ,v) for(int i =0 ; i<v.size() ; i++)

    ll mod = 1e9+7;


    void YallaSolve() {
        ll n;
        cin>>n;

        while(n--){
            int x, y;
            cin>>x>>y;
            if(y<-1)
                cout<<"NO\n";
            else
                cout<<"YES\n";
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

    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        std::cout.tie(NULL);
        YallaSolve();
    //        LotsOfTests();
    }
