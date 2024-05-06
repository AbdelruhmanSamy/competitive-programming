#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define lp(i, j, n) for (int i = j; i <= n; i++)
#define vi vector<int>
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
#define MAX 10000000

void Seive(vi& primeNumbers){
    vector<bool> primes(MAX+1 , true);

    primes[0]=0; primes[1]=0;

    for(int i=2 ; i*i<=MAX ; i++){
        if(primes[i]){
            for(int j = i*i; j<=MAX ; j+=i){
                primes[j]=0;
            }
        }
    }

    lp(i , 2 , MAX){
        if(primes[i]){
            primeNumbers.push_back(i);
        }
    }

}

int getPrevPrime(vi& primeNumbers , int val){
    int ind = lower_bound(all(primeNumbers) ,val ) - primeNumbers.begin();

    if(primeNumbers[ind]  == val)
        return val;

    return primeNumbers[ind-1];
}

void YallaSolve() {
    vi primeNumbers;
    Seive(primeNumbers);

    string s;
    getline(cin ,s);
    while(s!=""){
        int n;
        n=stoi(s);

        int i = 4;
        vector<int> ans;
        if(n< 8)
        {
            cout<<"Impossible.\n";
        }
        else{
            while(i){
                int val = getPrevPrime(primeNumbers, n-2*(i-1));
                ans.push_back(val);
                n-=val;
                i--;
            }
            lp(j ,  0 , 3)
                cout<<ans[j]<<" ";
            cout<<'\n';
        }

        getline(cin,s);
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
    //LotsOfTests();
}

