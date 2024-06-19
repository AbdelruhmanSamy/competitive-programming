//
// Created by abdelruhman on 6/19/24.
//

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
#define MAX 5e4

const vector<pii> moves ={
        {-1, 0} , {-1 , -1} ,
        {0 , -1}, {1  , -1} ,
        {1 , 0} , {1  , 1} ,
        {0 , 1} , {-1 , 1}
};

struct node{
    int i , j , ans ;
    node(int a , int b , int c){
        i=a; j=b; ans = c;
    }
};

bool isValid(int i , int j , int n , int m){
    return (i>=0 && i<n && j>=0 && j<m);
}

void YallaSolve() {
    int n , m;
    cin>>n>>m;

    int r , c , rf , cf;
    vvch arr(n , vch(m));
    lp(i , 0 , n-1){
        lp(j ,0 , m-1){
            cin>>arr[i][j];
            if(arr[i][j] == 'S'){
                r = i;
                c = j;
            }
            else if(arr[i][j] == 'F'){
                rf = i;
                cf = j;
            }
        }
    }
    vvi flag(n , vi(m));
    flag[0][0] = 0;
    queue<node> q;
    q.push(node(r , c , 0 ));
    while(!q.empty()){
        node cell  = q.front();
        q.pop();

        if(cell.i == rf && cell.j == cf){
            cout<<cell.ans;
            return;
        }
        else{
            int d = 0;
            veclp(moves){
                int i = cell.i+it->first, j = cell.j+it->second;
                while(isValid(i , j , n , m) && arr[i][j]!='X'){
                    if(flag[i][j] & (1 << d))
                        break;
                    else if(!flag[i][j])
                        q.push(node(i , j ,  (flag[cell.i][cell.j] & (1 << d))? cell.ans: cell.ans+1));

                    flag[i][j] |= (1 << d);

                    i+=it->first;
                    j+=it->second;
                }
                d++;
            }
        }
    }
    cout<<-1;
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