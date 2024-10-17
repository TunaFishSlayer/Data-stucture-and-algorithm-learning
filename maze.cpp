#include<bits/stdc++.h>
using namespace std;
int const maxN = 1000;
int n,m,r,c;
int maze[maxN][maxN],step[maxN][maxN];
queue<pair<int, int> > qe;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int solve(){
    qe.push({r,c});
    step[r][c]=0;
    maze[r][c]=1;
    while (!qe.empty()){
        pair<int,int> index = qe.front();
        qe.pop();
        for (int i=0;i<4;i++){
            int x = dx[i] + index.first;
            int y = dy[i] + index.second;
            if (x<1 || x>n || y<1 || y>m) return step[index.first][index.second] + 1;
            if (maze[x][y] == 0){
                maze[x][y] = 1;
                step[x][y] = step[index.first][index.second] + 1;
                qe.push({x,y});
            }
        }
    }
    return -1;
}


int main(){
    cin >> n >> m >> r >> c;
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=m;j++){
            cin >> maze[i][j];
        }
    }
    int kq = solve();
    cout << kq;
}