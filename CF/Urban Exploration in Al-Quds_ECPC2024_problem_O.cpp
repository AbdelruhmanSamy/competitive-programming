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

vll lat;
vvll ch;
vll power(300005);

struct trieNode{
    trieNode *child[2];
    ll count;
    trieNode(){
        lp(i , 0 , 1)
            child[i] = nullptr;
        count = 0;
    }
};


struct trie{
    trieNode* root;

    trie(){
        root = new trieNode();
    }

    void insert(ll myLat){
        ll b = 60;
        trieNode* ptr = root;

        while(b>=0){
            bool bit = ((myLat>>b) & 1);
            if(!ptr->child[bit])
                ptr->child[bit] = new trieNode();

            ptr = ptr->child[bit];
            ptr->count++;
            b--;
        }
    }

    ll getPower(ll myLat){
        ll b = 60;
        ll val = (1LL<<b);
        ll ans = 0;
        trieNode* ptr = root;

        while(b>=0){
            bool bit = ((myLat>>b) & 1);

            if(ptr->child[bit])
                ptr = ptr->child[bit];
            else{
                ans+=val;
                ptr = ptr->child[!bit];
            }

            val>>=1;
            b--;
        }

        return ans;
    }


    void dlt(ll myLat){
        dltPrv(myLat , root , 60);
    }

private:

    trieNode* dltPrv(ll myLat , trieNode *ptr , ll b){
        if(!ptr){
            return nullptr;
        }

        bool bit = ((myLat>>b) & 1);
        ptr->child[bit] = dltPrv(myLat , ptr->child[bit] , b-1);

        if(ptr == root)
            return ptr;

        ptr->count--;
        if(ptr->count)
            return ptr;

        delete ptr;
        return nullptr;
    }
};




ll backTrack(ll val , trie& t){

    if(val!=1)
        power[val] = t.getPower(lat[val]);

    t.insert(lat[val]);

    veclp(ch[val]){
        power[val]= min(backTrack(*it , t) , power[val]);
    }

    t.dlt(lat[val]);

    return power[val];
}

void solveO(){
    ll n;
    cin>>n;


    ch.resize(n+2);
    lp(i , 2  , n) {
        ll a;cin>>a;
        ch[a].push_back(i);
    }

    lat.resize(n+2);
    lp(i , 1  , n) {
        cin>>lat[i];
    }


    trie t;
    backTrack(1 , t);

    ll q;
    cin>>q;

    while(q--){
        ll a;
        cin>>a;
        cout<<power[a]<<"\n";
    }
}

void YallaSolve() {
    solveO();
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