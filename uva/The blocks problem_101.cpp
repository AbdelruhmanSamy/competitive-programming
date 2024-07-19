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

vector<list<int>> arr;
map<int, int> m;

void move(int listNo , int val){
    int top =arr[listNo].back();
    while(top!=val){
        arr[listNo].pop_back();
        arr[top].push_back(top);
        m[top] = top;
        top =arr[listNo].back();
    }
}

void pile(int list1 , int list2  , int val){
    stack<int> s;
    int top =arr[list1].back();
    while(top!=val){
        s.push((top));
        arr[list1].pop_back();
        top =arr[list1].back();
    }

    s.push(top);
    arr[list1].pop_back();

    while(s.size()){
        top = s.top();
        s.pop();
        arr[list2].push_back(top);
        m[top] = list2;
    }

}

void moveOver(int a , int b){
    move(m[a] , a);
    arr[m[a]].pop_back();
    arr[m[b]].push_back(a);
    m[a] = m[b];
}

void moveOnto(int a, int b){
    move(m[a] , a);
    move(m[b] , b);
    arr[m[a]].pop_back();
    arr[m[b]].push_back(a);
    m[a] = m[b] ;
}

void pileOver(int a , int b){
    pile(m[a] , m[b] , a);
}

void pileOnto(int a , int b){
    move(m[b] , b);
    pile(m[a] , m[b] , a);
}



void YallaSolve() {
    int n;
    cin >> n;
    arr.resize(n);
    lp(i, 0, n-1) {
        arr[i].push_back(i);
        m[i] = i;
    }

    string s1, s2;
    int a, b;
    cin>>s1;
    while(s1!="quit"){
        cin>>a>>s2>>b;
        if(a == b || m[a] == m[b]) {
            cin>>s1;
            continue;
        }
        else if(s1 == "move" && s2 == "over")
            moveOver(a , b);
        else if(s1 == "move" && s2 == "onto")
            moveOnto(a , b);
        else if(s1 == "pile" && s2 == "over")
            pileOver(a , b);
        else if(s1 == "pile" && s2 == "onto")
            pileOnto(a , b);
        cin>>s1;
    }

    lp(i , 0 , n-1){
        cout<<i<<":";
        veclp(arr[i])
            cout<<" "<<*it;
        cout<<"\n";
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
