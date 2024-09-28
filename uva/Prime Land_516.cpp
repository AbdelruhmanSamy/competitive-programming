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

    const ll MOD =  1e9;
    const double PI = acos(-1.0);

    vi primes;
    void sieve(){
        bool isPrime[MAX];
        memset(isPrime , 1  , sizeof(isPrime));
        isPrime[0] = 0;
        isPrime[1] = 0;

        for(int i = 2 ; i*i <=MAX ; i++){
            if(isPrime[i]){
                for(int j = 2*i ; j<=MAX ; j+=i)
                    isPrime[j] = 0;
            }
        }

        lp(i , 2 , MAX-1){
            if(isPrime[i])
                primes.push_back(i);
        }
    }

    vector<pii> getFactors(ll n){
        vector<pii> factors;

        for(int i = 0 ; i<primes.size() && primes[i]*primes[i] <=n ; i++){
            if(n%primes[i] == 0){
                int c = 0;
                while(n%primes[i] == 0){
                    n/=primes[i];
                    c++;
                }

                factors.push_back({primes[i] , c});
            }
        }

        if(n>1)
            factors.push_back({n, 1});

        return factors;
    }

    void problem1(){
        sieve();
        string s;
        while(getline(cin , s)) {
            stringstream ss(s);
            ll x, p;
            ss >> x;
            if (!x)

                ss >> p;

            ll val = 1;
            val *= pow(x, p);
            while (!ss.eof()) {
                ss >> x >> p;
                val *= pow(x, p);
            }

            vector<pii > factors = getFactors(val - 1);
            sort(all(factors), greater<pii >());

            bool f = 0;
            veclp(factors) {
                if (!f)
                    f = 1;
                else
                    cout << " ";
                cout << it->first << " " << it->second;
            }
            cout << "\n";
        }
    }

    void YallaSolve() {
        problem1();
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