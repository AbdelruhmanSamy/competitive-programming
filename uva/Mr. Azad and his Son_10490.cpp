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

    vll calculatePowersOf2(){
        ll val = 1;
        vll ans;
        lp(i , 0 , 62){
            ans.push_back(val);
            val*=2;
        }

        return ans;
    }

    bool isPrime[MAX];
    vll primes;
    void Sieve(){
        memset(isPrime , 1 , sizeof(isPrime));
        isPrime[0] = 0;
        isPrime[1] = 0;

        for(int i = 2 ; i*i<=MAX ; i++){
            if(isPrime[i]) {
                for (int j = 2 * i; j <= MAX; j += i) {
                    isPrime[j] =  0;
                }
            }
        }

        lp(i , 0 , MAX)
            if(isPrime[i])
                primes.push_back(i);

    }

    vector<pair<ll , ll>> getPrimeFactors(ll n ){
        vector<pair<ll , ll>> primeFactors;

        for(int i = 0 ; i<primes.size() && primes[i]*primes[i]<=n ; i++){
            ll count = 0;
            while(n%primes[i] == 0){
                n/=primes[i];
                count++;
            }
            if(count)
                primeFactors.push_back({primes[i] , count});
        }

        if(n>1)
            primeFactors.push_back({n , 1});

        return primeFactors;
    }

    ll sumOfFactors = 0;
    void FactorsSum(vector<pair<ll , ll>> & arr , int count , ll currFactor){
        if(count >= arr.size()) {
            sumOfFactors +=currFactor;
            return;
        }

        ll val = 1;
        lp(i , 0 , arr[count].second){
            FactorsSum(arr , count+1 , currFactor*val);
            val*=arr[count].first;
        }

    }



    void YallaSolve() {
        ll n;
        vll twoPowers = calculatePowersOf2();
        Sieve();
        while(cin>>n && n){
            vector<pair<ll, ll>> factors = getPrimeFactors((twoPowers[n] - 1));

            if (factors[0].first == 2)
                factors[0].second += (n - 1);
            else
                factors.push_back({2, n - 1});

            FactorsSum(factors, 0, 1);

            ll temp =  (twoPowers[n - 1] * (twoPowers[n] - 1));
    //            cout<<sumOfFactors<<" "<<temp<<"\n";
            if (sumOfFactors/2 == temp)
                cout << "Perfect: " << temp << "!\n";
            else if(isPrime[n])
                cout<<"Given number is prime. But, NO perfect number is available.\n";
            else
                cout << "Given number is NOT prime! NO perfect number is available.\n";

            sumOfFactors = 0;
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
