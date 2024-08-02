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
#define oo 1e18
const int MOD = (int) 1e9 + 7;
const double PI = acos(-1.0);


ll memo[300005][2][2];
ll n;
vll up , down;
ll up_m , d_m;
ll up_ind , d_ind;

ll dp(int i , int j , bool canAddUp , bool canAddDown){

    if(memo[max(i , j)][canAddUp][canAddDown] != -1)
        return memo[max(i , j)][canAddUp][canAddDown];

    //base case
    if(i == n-1 || j == n-1){
        ll val= 0 ;
        if(canAddUp && canAddDown){
            val += abs(up_m - d_m);
        }
        else if(canAddUp){
            val+=abs(up_m - down[j]);
        }
        else if(canAddDown){
            val+=abs(d_m - up[i]);
        }
        else
            val+=abs(down[j] - up[i]);

        return memo[max(i , j)][canAddUp][canAddDown] = val;
    }


    ll ans1 = abs(up[i] - down[j]) + dp(i+1 ,  j+1 , canAddUp , canAddDown);

    ll ans2 = -1;
    ll ans3 = -1;

    if(canAddUp){
        ans2 = abs(up_m - down[j]) + dp(i , j+1 , 0 , canAddDown);
    }
    if(canAddDown){
        ans3 = abs(d_m - up[i]) + dp(i+1 , j , canAddUp , 0);
    }


    return memo[max(i , j)][canAddUp][canAddDown] = max(ans1 , max(ans2 , ans3));

}

vll upArr , dArr;
void buildDP(int i , int j , bool canAddUp , bool canAddDown){

    //base case
    if(i == n-1 || j == n-1){
        if(canAddUp && canAddDown){
            upArr.push_back(up_m);
            dArr.push_back(d_m);
        }
        else if(canAddUp){
            upArr.push_back(up_m);
            dArr.push_back(down[j]);
        }
        else if(canAddDown){
            upArr.push_back(up[i]);
            dArr.push_back(d_m);
        }
        else {
            upArr.push_back(up[i]);
            dArr.push_back(down[j]);
        }
        return ;
    }


    // getting all solutions

    ll ans1 = abs(up[i] - down[j]) + dp(i+1 ,  j+1 , canAddUp , canAddDown);
    ll ans2 = -1;
    ll ans3 = -1;

    if(canAddUp){
        ans2 = abs(up_m - down[j]) + dp(i , j+1 , 0 , canAddDown);
    }
    if(canAddDown){
        ans3 = abs(d_m - up[i]) + dp(i+1 , j , canAddUp , 0);
    }

    // get optimal sol
    ll opt = dp(i , j , canAddUp , canAddDown);

    //comparing solutions with the optimal sol
    if(opt == ans1){
        upArr.push_back(up[i]);
        dArr.push_back(down[j]);
        buildDP(i+1, j+1 , canAddUp , canAddDown);
    }
    else if(opt == ans2){
        upArr.push_back(up_m);
        dArr.push_back(down[j]);
        buildDP(i, j+1 , 0 , canAddDown);
    }
    else if(opt == ans3){
        upArr.push_back(up[i]);
        dArr.push_back(d_m);
        buildDP(i+1, j , canAddUp , 0);
    }

}

void YallaSolve() {
    memset(memo , -1 , sizeof(memo));
    cin>>n;
    up.resize(n);
    down.resize(n);

    up_ind = n-1;
    d_ind = n-1;

    unordered_set<ll> s;
    lp(i ,  0 , n-2) {
        cin >> up[i];
        s.insert(up[i]);
    }

    lp(i , 1 , n){
        if(s.find(i) == s.end()){
            up_m = i;
            break;
        }
    }

    s.clear();

    lp(i ,  0 , n-2) {
        cin >> down[i];
        s.insert(down[i]);
    }

    lp(i , 1 , n){
        if(s.find(i) == s.end()){
            d_m = i;
            break;
        }
    }
    cout<<dp(0 , 0 , 1 ,  1)<<"\n";

    buildDP(0 , 0 , 1 , 1);

    lp(i , 0 , n-1)cout<<upArr[i]<<" ";
    cout<<"\n";

    lp(i , 0 , n-1)cout<<dArr[i]<<" ";


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
//        LotsOfTests();
    YallaSolve();
}