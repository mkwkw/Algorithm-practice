#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

int main(){
    vector<vector<int>> dist;
    int n, m;
    int s,d,w;

    cin>>n>>m;    

    dist.assign(n,vector<int>(n,INF));

    for(int i=0; i<m; i++){
        cin>>s>>d>>w;

        if(dist[s-1][d-1]>w){
            dist[s-1][d-1]=w;
        }
    }

    for(int i=0; i<n; i++){
        dist[i][i]=0;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                
                if(dist[j][k]>dist[j][i]+dist[i][k]){
                    dist[j][k]=dist[j][i]+dist[i][k];
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(dist[i][j]==INF){
                dist[i][j]=0;
            }
            cout<<dist[i][j]<<' ';
        }
        cout<<'\n';
    }

}

//플로이드 워셜 : 핵심 dist[출발지점][도착지점]>dist[출발지점][경유지점]+dist[경유지점][도착지점]
//for 경유지점
//  for 출발지점
//      for 도착지점
//경유지점, 출발지점, 도착지점을 모두 돌면서 모든 dist[출발지점][도착지점] 갱신