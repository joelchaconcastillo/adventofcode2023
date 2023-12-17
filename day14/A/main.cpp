#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string line;
    long long res = 0;
    vector<string> gd;    
    while(cin>>line){
        gd.push_back(line);
    }
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
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(gd[i][j] == 'O') res += (n-i);
        }
    }
    cout << res <<endl;
    return 0;
}