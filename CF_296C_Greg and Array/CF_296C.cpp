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


//problem's Category: Prefix Sum

void YallaSolve() {
    int x;
    cin>>x;

    for(int i = ceil(sqrt(x)); i>=0 ; i--){
        if(x%i == 0){
            cout<< i*(x/i -1);
        }
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
    //YallaSolve();
    LotsOfTests();
}

