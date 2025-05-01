#include <iostream>
#include <queue>
using namespace std;

int n,vy[4]={1,-1,0,0},vx[4]={0,0,1,-1},sector,CBsector;
bool chk[101][101],CBchk[101][101];
char area[101][101];

bool safe(int y,int x) {
    return y>=0 && y<n && x>=0 && x<n;
}

void bfs(int y,int x){
    char pin=area[y][x];
    chk[y][x]=true;
        queue<pair<int, int>> q;
    q.push(make_pair(y, x));
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        for(int i=0; i<4; i++)
            if(area[y+vy[i]][x+vx[i]]==pin && safe(y+vy[i],x+vx[i]) && !chk[y+vy[i]][x+vx[i]]){
                q.push(make_pair(y+vy[i],x+vx[i]));
                chk[y+vy[i]][x+vx[i]]=true;
            }
    }
    sector++;
}

void CBbfs(int y,int x){
    char pin=area[y][x],rg='X';
    CBchk[y][x]=true;
    if(pin=='R')  
        rg='G';
    else if(pin=='G')
        rg='R';
	queue<pair<int, int>> q;
    q.push(make_pair(y, x));
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        for(int i=0; i<4; i++)
            if((area[y+vy[i]][x+vx[i]]==pin || area[y+vy[i]][x+vx[i]]==rg) && safe(y+vy[i],x+vx[i]) && !CBchk[y+vy[i]][x+vx[i]]){
                q.push(make_pair(y+vy[i],x+vx[i]));
                CBchk[y+vy[i]][x+vx[i]]=true;
            }
    }
    CBsector++;
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<n; j++)
            area[i][j]=s[j];
    }
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(!chk[i][j])
                bfs(i,j);
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(!CBchk[i][j]) 
                CBbfs(i,j);

    cout << sector << ' ' << CBsector;
}
