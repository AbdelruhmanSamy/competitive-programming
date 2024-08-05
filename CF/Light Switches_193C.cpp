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
#define MAX 1e6
#define rep(i, v) for(int i =0 ; i<v.size() ; i++)
#define scn(v) for (auto& i : v)cin >> i;

#define oo 1e18
const int MOD = (int) 1e9 + 7;
const double PI = acos(-1.0);



void solveC(){
    ll n , k;
    cin>>n>>k;

    vll arr(n);
    scn(arr);

    sort(all(arr));

    ll lst = arr[n-1];

    vll vec;
    vec.push_back(lst);

    lp(i ,  0  , n-2){
        ll val = (lst - arr[i])/k;
        if(val & 1){
            val++;
        }
        vec.push_back(arr[i] + k*val);
    }

    sort(all(vec));

    if(vec[0]+k > vec[n-1])
        cout<<vec[n-1];
    else
        cout<<-1;

}

void YallaSolve() {
    solveC();
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
//       YallaSolve();
}
