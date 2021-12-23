#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1; //카메라 개수
    
    sort(routes.begin(), routes.end()); //진입지점 작은 순서대로 정렬
    
    int pos = routes[0][1]; //진입 지점 가장 작은 차량의 나가는 지점에 카메라 설치 가정
    
    for(int i=0; i<routes.size(); i++){
        if(pos<routes[i][0]){ //카메라 위치가 i번째 차량 진입 지점보다 앞에 있으므로 카메라 추가 설치 필요
            answer++; //카메라 하나 추가
            pos = routes[i][1]; //현재 카메라 위치
        }
        if(pos>=routes[i][1]){ //카메라 위치가 i번째 차량 나가는 지점과 같거나 더 뒤에 있다면 = 현재 차보다 뒤차가 먼저 나가면
            pos=routes[i][1]; //뒤 차 나가는 지점으로 카메라 위치 변경 
        }

    }
    return answer;
}

