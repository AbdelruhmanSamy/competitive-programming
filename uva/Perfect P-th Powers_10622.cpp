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

    vll sieve(ll n){
        vector<bool> isPrime(n+1 , 1);
        vll primes;

        isPrime[0] = 0;
        isPrime[1] = 0;

        for(int i = 2 ; i*i<=n ; i++){
            if(isPrime[i]){
                for(int j = 2*i ; j<=n ; j+=i){
                    isPrime[j] = 0;
                }
            }
        }

        lp(i , 2 , n-1){
            if(isPrime[i])
                primes.push_back(i);
        }

        return primes;
    }


    vll getFactors(ll n , vll & primes){
        vll factors;
        for(int i = 0 ; i<primes.size() && primes[i]*primes[i]<=n ; i++){
            int count = 0;
            if(!(n%primes[i])){
                while(!(n%primes[i])){
                    n/=primes[i];
                    count++;
                }
                factors.push_back(count);
            }
        }

        if(n>1)
            factors.push_back(1);
        return factors;
    }

    ll gcd(ll  a , ll b){
        if(a == 0)
            return b;
        return gcd(b%a , a);
    }

    void YallaSolve() {
        ll n;
        vll primes = sieve(1e5);
        while(cin>>n && n){
            // There is a mistake in the problem statement, input range
            // is from -INT_MAX to INT_MAX except 0
            bool isNeg = 0;
            if(n<0) {
                n *= -1;
                isNeg = 1;
            }

            vll factors = getFactors(n , primes);
            ll val = factors[0];


            lp(i , 1, factors.size()-1){
                val = gcd(val , factors[i]);
            }

            if(isNeg && !(val&1)) {
                while(!(val&1))
                    val/=2;
            }
            cout<<val<<"\n";
        }
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