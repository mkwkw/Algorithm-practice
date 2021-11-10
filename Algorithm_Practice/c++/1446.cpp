#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//D킬로미터
//단방향
//운전해야 하는 거리의 최솟값 구하기
typedef struct Road{ //구조체로 시작점, 끝점, 거리 저장하기
    int start;
    int end;
    int distance;
}Road;

bool cmp(const Road &a, const Road &b){ //시작점->도착점->거리 - 오름차순 정렬 필요
    if(a.start<b.start){
        return true;
    }
    else if(a.start==b.start){
        if(a.end<b.end){
            return true;
        }
        else if(a.end==b.end){
            if(a.distance<b.distance){
                return true;
            }
        }
    }
    return false;
}

int shortcut(vector<Road> &v, int d){ //최소 거리 구하기
    int dist=0; //현재 위치
    int idx=0; //0부터 시작하는 인덱스(현재 위치)
    int road[10001]={0}; //d까지의 최소 거리 저장- 0으로 초기화
    
    while(dist!=d){
        if(v[idx].start == dist){ //지름길의 시작점이 현재 위치와 같다면
            if(v[idx].end <= d){ //그리고 지름길의 끝점이 전체 거리 내에 있다면
                //최소 거리로 갱신
                if(road[v[idx].end]!=0){
                    road[v[idx].end]=min(road[dist]+v[idx].distance, road[v[idx].end]);
                }
                else{
                    road[v[idx].end]=road[dist]+v[idx].distance;
                }
            }
            idx++; //다음 지름길로 이동
        }
        else{ //지름길의 시작점이 현재 위치와 다르다면
            //다음 위치까지의 거리 조사
            if(road[dist+1]!=0){ 
                road[dist+1]=min(road[dist+1], road[dist]+1);
            }
            else{
                road[dist+1]=road[dist]+1;
            }
            dist++; //현재 위치도 하나 이동
        }
    }
    return road[d]; 
}

int main(){
    vector<Road> v(10001);
    int n, d;
    int answer;

    cin>>n>>d;
    
    for(int i=0; i<n; i++){
        int s,e,dist;
        cin>>s>>e>>dist;
        
        v[i]={s,e,dist};
    }

    sort(v.begin(),v.end(), cmp);

    answer = shortcut(v,d);
    cout<<answer;
}