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


void YallaSolve() {
    ll n , m , k;
    cin>>n>>m>>k;
    vll arr(n), op_count(m+2 ,  0),added_val(n+2 , 0) , l(m)  , r(m) , d(m);

    lp(i , 0 , n-1){
        cin>>arr[i];
    }

    lp(i , 0 , m-1){
        cin>>l[i]>>r[i]>>d[i];
    }

    lp(i , 0 , k-1){
        ll x , y;
        cin>>x>>y;
        op_count[x]++;
        op_count[y+1]--;
    }

    lp(i , 1 , m){
        op_count[i]+=op_count[i-1];
        d[i-1] *=op_count[i];
    }

    lp(i , 0 , m-1){
        added_val[l[i]]+=d[i];
        added_val[r[i]+1]-=d[i];
    }


    lp(i , 1 , n){
        added_val[i]+=added_val[i-1];
        arr[i-1]+=added_val[i];
    }

    lp(i , 0 , n-1)
        cout<<arr[i]<<" ";


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