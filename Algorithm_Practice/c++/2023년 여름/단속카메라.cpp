#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//정렬
//나간 지점 기준 정렬 - 나간 지점 기준으로 카메라를 설치해야 최소 개수의 카메라 설치 가능
bool comp(vector<int> &a, vector<int> &b){
    return a[1]<b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 1, camera; //카메라 위치
    
    sort(routes.begin(), routes.end(), comp);
    
    camera = routes[0][1]; //처음 카메라 위치
    
    for(int i=0; i<routes.size(); i++){
        //카메라 위치가 다음 차의 경로 범위 안에 들어와있으면 그대로 그 카메라 사용
        if(routes[i][0]<=camera && camera<=routes[i][1]){
            continue;
        }
        else{ //카메라 위치 이후에 차량이 진입하면 카메라 새로 설치(해당 차량 나간 지점에)
            camera = routes[i][1];
            answer++;
        }
    }
    
    return answer;
}