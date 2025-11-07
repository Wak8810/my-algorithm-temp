#include <iostream>
#include <vector>
#include <utility>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<typename T> using vc = vector<T>;
template<typename T> using vv = vc<vc<T>>;
using vi = vc<int>;using vl = vc<ll>;using vb = vc<bool>;using vpii = vc<pair<int,int>>;
using vvi = vv<int>;using vvl = vv<ll>;using vvb = vv<bool>;

void dfs(const vvi &G,int v,vb &seen){
    seen[v] = true;//見る
    for(auto nv:G[v]){//行ける場所を見る
        if(seen[nv]) continue;//見てあったらcontinue
        dfs(G,nv,seen);//探索
    }
}
//seenの中身を出力するだけ
void print_seen(int n,vb &seen){
    for(int i=1;i<=n;i++){
        if(seen[i]) cout << "True" << " ";
        else cout << "False" << " ";
    }
    cout << endl;
}

int main(){
    int n = 5;
    vvi A(n+1);
    vb seen(n+1,false);
    A[1].push_back(2);
    A[2].push_back(3);
    A[3].push_back(4);
    A[4].push_back(5);
    print_seen(n,seen);

    dfs(A,1,seen);//繋がっているところを全部探索するため、seenが全てtrueに
    print_seen(n,seen);
}