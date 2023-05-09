#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //vector<vector<int>> path;
    vector<int> sxTime, xsTime;
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> posQ; //우선순위 큐가 일반 큐보다 속도가 빠르다.
    int n, m, x, answer = 0;

    cin>>n>>m>>x;

    vector<vector<pair<int, int>>> path(n+1); //[시작점] = {시간, 끝점}
    sxTime.assign(n+1, 1000000);
    xsTime.assign(n+1, 1000000);
    
    for(int i=0; i<m; i++){
        int s, e, t;
        cin>>s>>e>>t;
        path[s].push_back({t, e});
    }

    //i->x, sxTime 채우기
    for(int i=1; i<=n; i++){
        int start = i;

        posQ.push({0, start});

        while(!posQ.empty()){
            int now = posQ.top().second;
            int nowTime = posQ.top().first;
            posQ.pop();
            
            if(nowTime>sxTime[now]){
                continue;
            }
            
            for(int k=0; k<path[now].size(); k++){
                int next = path[now][k].second;
                int nextTime = nowTime + path[now][k].first;
                if(nextTime<sxTime[next]){
                    posQ.push({nextTime, next});
                }
            }
            
        }
    }

    //x->i, xsTime 채우기
    posQ.push({0,x});
    while(!posQ.empty()){
        int now = posQ.top().second;
        int nowTime = posQ.top().first;
        posQ.pop();
        
        if(nowTime>xsTime[now]){    
            continue;
        }
            
        for(int k=0; k<path[now].size(); k++){
            int next = path[now][k].second;
            int nextTime = nowTime + path[now][k].first;
            if(nextTime<xsTime[next]){
                xsTime[next] = nextTime;
                posQ.push({nextTime, next});
            }
        }
        
    }

    for(int i=1; i<=n; i++){
        if(i!=x){
            cout<<"sxTime: "<<sxTime[i]<<" xsTime: "<<xsTime[i]<<'\n';
            answer = max(answer, sxTime[i]+xsTime[i]);
        }
    }

    cout<<answer;
}

//시간 초과
/*  
    for(int i=1; i<=n; i++){
        path[i][i] = 0;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<path[i][j]<<' ';
        }
        cout<<'\n';
    }
*/
/*
    for(int i=1; i<=n; i++){
        int start = i;
        int iTime1 = 1000000;
        if(start==x){
            continue;
        }

        for(int j=1; j<=n; j++){
            if(path[i][j]>0){
                if(j==x){
                    iTime1 = min(iTime1, path[i][j]);
                }
                else{
                    posQ.push({i,j,path[i][j]});
                }
            }
        }
        //cout<<"posQ.size: "<<posQ.size()<<'\n';

        while(!posQ.empty()){
            int tempStart = posQ.front().start;
            int end = posQ.front().end;
            int time = posQ.front().time;
            if(start==end){
                posQ.pop();
                continue;
            }

            if(end==x){
                iTime1 = min(iTime1, time);
                //cout<<"i: "<<i<<" Time: "<<iTime1<<'\n';
            }
            else{
                
                if(path[start][end]>path[start][tempStart]+path[tempStart][end]){
                    path[start][end] = path[start][tempStart]+path[tempStart][end];
                    //cout<<"path["<<start<<"]["<<end<<"] "<<path[start][end]<<" : "<<"path["<<start<<"]["<<tempStart<<"] "<<path[start][tempStart]<<" + path["<<tempStart<<"]["<<end<<"] "<<path[tempStart][end]<<' '<<path[start][end]<<'\n';
                }
                
                if(time>=iTime1){
                    posQ.pop();
                    continue;
                }
                else{
                    for(int j=1; j<=n; j++){
                        if(path[end][j]>0 && time+path[end][j]<iTime1){
                            if(j!=x){
                                posQ.push({end, j, time+path[end][j]});
                            }
                            else{
                                iTime1 = min(iTime1, time+path[end][j]);
                            }
                        }
                    }
                }
            }

            posQ.pop();
        }
        sxTime[i] = iTime1;
    }

    for(int i=1; i<=n; i++){
        int end = i;
        int iTime2=100000;
        if(end==x){
            continue;
        }
        for(int j=1; j<=n; j++){
            if(path[x][j]>0){
                if(j==i){
                    iTime2 = min(iTime2, path[x][j]);
                }
                else{
                    posQ.push({x,j,path[x][j]});
                }
            }
        }
        

            while(!posQ.empty()){
                int tempStart = posQ.front().start;
                int end = posQ.front().end;
                int time = posQ.front().time;
                if(x==end){
                    posQ.pop();
                    continue;
                }

                if(end==i && iTime2>time){
                    iTime2 = time;
                    //cout<<"i:"<<i<<" Time2: "<<iTime2<<'\n';
                }
                else{
                    //cout<<"path["<<x<<"]["<<end<<"] "<<path[x][end]<<" : "<<"path["<<x<<"]["<<tempStart<<"] "<<path[x][tempStart]<<" + path["<<tempStart<<"]["<<end<<"] "<<path[tempStart][end]<<' '<<path[x][end]<<'\n';
                    //if(x!=tempStart){
                        if(path[x][end]>path[x][tempStart]+path[tempStart][end] || (path[x][end]<0 && path[x][tempStart]+path[tempStart][end]>0)){
                            path[x][end] = path[x][tempStart]+path[tempStart][end];
                        }
                    //}
                    //cout<<"path: "<<path[x][end]<<" iTime2: "<<iTime2<<'\n';
                    if(time>=iTime2 || path[x][end]<0){
                        posQ.pop();
                        continue;
                    }
                    else{
                        for(int k=1; k<=n; k++){
                            if(path[end][k]>0 && time+path[end][k]<iTime2){
                                if(k!=i){
                                    posQ.push({end, k, time+path[end][k]});
                                }
                                else{
                                    iTime2 = min(iTime2, time+path[end][k]);
                                }
                            }
                        }
                    }
                }

                posQ.pop();
            }
            xsTime[i] = iTime2;
            
    }    
*/        
    
    
/*
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<path[i][j]<<' ';
        }
        cout<<'\n';
    }
    */