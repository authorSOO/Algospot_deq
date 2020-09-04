#include <cstdio>
#include <iostream>
#include <deque>
using namespace std;
int a[555][555];
int dist[555][555];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%1d",&a[i][j]);
			dist[i][j]=-1;
		}
	}
	deque<pair<int,int>> q;
	q.push_back(make_pair(0,0));
	dist[0][0]=0;
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		q.pop_front();
		for(int k=0;k<4;k++){
			int nx = x+dx[k];
			int ny = y+dy[k];
			if(nx>=0 && nx <n && ny<m && ny>=0){
				if(dist[nx][ny]==-1){
					if(a[nx][ny]==0){
						dist[nx][ny]=dist[x][y];
						q.push_front(make_pair(nx,ny));
					}
					else{
						dist[nx][ny]=dist[x][y]+1;
						q.push_back(make_pair(nx,ny));						
					}
				}			
			}
		}			
	}	
	cout<<dist[n-1][m-1]<<endl;
	return 0;
}
