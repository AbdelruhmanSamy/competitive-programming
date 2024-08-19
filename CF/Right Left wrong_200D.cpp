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
#define MAX 1e6
#define rep(i, v) for(int i =0 ; i<v.size() ; i++)
#define scn(v) for (auto& i : v)cin >> i;
#define oo 1e18
const ll MOD =  1e9 + 7;
const double PI = acos(-1.0);



void solveA(){
    ll n;
    cin>>n;


    ll v = n%10;
    n/=10;
    ll val = v;
    ll ind = 10;
    while(n && (n%10 || !v)){
        v = n%10;
        n/=10;

        val=v*ind+val;
        ind*=10;
    }


    if(val >=2 && n==10)
        cout<<"YES";
    else
        cout<<"NO";
}

void solveB(){
    ll n;
    cin>>n;

    vll arr(n);
    scn(arr);

    vll vis(n+2 , 0);
    vis[arr[0]]=1;
    lp(i , 1 , n-1){
        if(arr[i]>n){
            cout<<"NO";
            return;
        }
        if(vis[arr[i]-1] || vis[arr[i]+1])
            vis[arr[i]]=1;
        else
        {
            cout<<"NO";
            return;
        }

    }

    cout<<"YES";
}

void solveC(){
    ll n;
    cin>>n;

    vll arr(n);
    scn(arr);

    ll k;
    cin>>k;

    string s;
    while(k--){
        unordered_map<char , ll>m;
        unordered_map<ll , char>m2;
        cin>>s;

        if(s.size()!=n){
            cout<<"NO\n";
            continue;
        }

        bool f=1;
        lp(i , 0 , s.size()-1){
            if(m.find(s[i])==m.end() && m2.find(arr[i])==m2.end()) {
                m[s[i]] = arr[i];
                m2[arr[i]] = s[i];
            }
            else if(m.find(s[i])==m.end() && m2.find(arr[i]) != m2.end() || m.find(s[i])!=m.end() && m2.find(arr[i])==m2.end() || m[s[i]]!=arr[i] || m2[arr[i]]!=s[i]){
                cout<<"NO\n";
                f=0;
                break;
            }
        }

        if(f)
            cout<<"YES\n";
    }
}

void solveD(){
    ll n;
    cin>>n;

    vll arr(n);
    scn(arr);

    vll preSum(n+2);
    preSum[0] = arr[0];
    lp(i , 1 , n-1){
        preSum[i] = preSum[i-1]+arr[i];
    }

    string s;
    cin>>s;

    vll r , l;

    lp(i , 0 , n-1){
        if(s[i] == 'L')
            l.push_back(i);
        else
            r.push_back(i);
    }

    ll ans = 0 , rind =r.size()-1 , lind = 0;

    while(rind>=0 && lind<l.size()){
        if(r[rind] > l[lind]) {
            ans += preSum[r[rind]] - (l[lind] == 0 ? 0 : preSum[l[lind] - 1]);
            rind--;
            lind++;
        }
        else{
            break;
        }
    }

    cout<<ans;
}

void solveE(){
    ll n , m , k;
    cin>>n>>m>>k;

    ll w;
    cin>>w;

    vll arr(w);
    scn(arr);
    sort(all(arr), greater<>());

    ll ans = 0;

    vll vec;
    lp(i , 0 , n-1){
        lp(j, 0  , m-1){
            ll x = min({int(i+1) , int(k) , int(n-k+1), int(n-i)});
            ll y = min({int(j+1) , int(k) , int(m-k+1), int(m-j)});

            vec.push_back(x*y);
        }
    }

    sort(all(vec) , greater<>());

    lp(i , 0 , w-1)
        ans+=vec[i]*arr[i];

    cout<<ans;
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
}
