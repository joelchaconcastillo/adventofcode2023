#include <bits/stdc++.h>
using namespace std;
void up(vector<string> &gd){
    int n = gd.size(), m=gd.front().size();
    for(int j = 0; j < m; j++){
        priority_queue<int> pq;
        for(int i = 0; i < n; i++){
            if(gd[i][j] == '.')pq.push(-i);
            else if(gd[i][j]=='O' && !pq.empty()){
                    auto ii = -pq.top(); pq.pop();
                    gd[i][j] = '.', pq.push(-i), gd[ii][j]='O';
            }else if(gd[i][j] == '#') pq=priority_queue<int>();
        }
    }
}
void left(vector<string> &gd){
    int n = gd.size(), m=gd.front().size();
    for(int i = 0; i < n; i++){
        priority_queue<int> pq;
        for(int j = 0; j < m; j++){
            if(gd[i][j] == '.')pq.push(-j);
            else if(gd[i][j]=='O' && !pq.empty()){
                    auto ii = -pq.top(); pq.pop();
                    gd[i][j] = '.', pq.push(-j), gd[i][ii]='O';
            }else if(gd[i][j] == '#') pq=priority_queue<int>();
        }
    }
}
void down(vector<string> &gd){
    int n = gd.size(), m=gd.front().size();
    for(int j = 0; j < m; j++){
        priority_queue<int> pq;
        for(int i = n-1; i >= 0; i--){
            if(gd[i][j] == '.')pq.push(i);
            else if(gd[i][j]=='O' && !pq.empty()){
                    auto ii = pq.top(); pq.pop();
                    gd[i][j] = '.', pq.push(i), gd[ii][j]='O';
            }else if(gd[i][j] == '#') pq=priority_queue<int>();
        }
    }
}
void right(vector<string> &gd){
    int n = gd.size(), m=gd.front().size();
    for(int i = 0; i < n; i++){
        priority_queue<int> pq;
        for(int j = m-1; j >=0; j--){
            if(gd[i][j] == '.')pq.push(j);
            else if(gd[i][j]=='O' && !pq.empty()){
                    auto ii = pq.top(); pq.pop();
                    gd[i][j] = '.', pq.push(j), gd[i][ii]='O';
            }else if(gd[i][j] == '#') pq=priority_queue<int>();
        }
    }
}
long long evaluate(vector<string> &gd){
    long long res=0;
    int n = gd.size(), m=gd.front().size();
        for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(gd[i][j] == 'O') res += (n-i);
        }
    }
    return res;
}
vector<string> f(vector<string> gd){
    up(gd);left(gd); down(gd); right(gd);
    return gd;
}
pair<int, int> floyd(vector<string> &gd){
    auto tortoise=f(gd), hare=f(f(gd));
    //find k*mu
    while(tortoise != hare) tortoise=f(tortoise), hare=f(f(hare));
    //find mu
    int mu=0; hare=gd;
    while(tortoise!=hare)tortoise=f(tortoise), hare=f(hare), mu++;
    //find lamda
    int lam=1; hare=f(tortoise);
    while(tortoise!=hare)hare=f(hare), lam++;
    return make_pair(mu, lam);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string line;
    vector<string> gd;    
    while(cin>>line)
        gd.push_back(line);
    auto pp = floyd(gd);
    for(int i = 0; i < pp.first; i++) gd=f(gd);
    long long K = 1000000000-pp.first;
    for(int i = 0; i < K%pp.second; i++)gd=f(gd);
    auto res = evaluate(gd);
    cout << res <<endl;
    return 0;
}