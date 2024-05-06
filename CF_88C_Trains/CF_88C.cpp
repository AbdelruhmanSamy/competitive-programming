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
#define MAX 10000000

int gcd(ll n , ll m){
    return (n==0)?m: gcd(m%n , n);
}

void YallaSolve() {
    ll n, m;
    cin>>n>>m;

    ll lcm = n*m/gcd(n, m);

    vll arr(2);

    arr[0]= lcm/n;
    arr[1] = lcm/m;

    if(!(lcm%n || lcm%m))
        (n<m)?arr[0]--:arr[1]--;

    if(arr[0] > arr[1])
        cout<<"Dasha";
    else if(arr[0]== arr[1])
        cout<<"Equal";
    else
        cout<<"Masha";
}

void LotsOfTests() {
    int t;
    cin >> t;
    while (t--) {
        YallaSolve();
        cout << "\n";
    }
}

void uvaLotsOfTests(){
    string s;
    getline(cin , s);
    while(s!=""){
        stringstream ss(s);
        ll n , m;
        ss>>n;
        ss>>m;
//        YallaSolve(n , m);
        getline(cin , s);
        getline(cin , s);
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);
    YallaSolve();
    //LotsOfTests();
    // uvaLotsOfTests();
}

