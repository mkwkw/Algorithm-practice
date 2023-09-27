#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//그리디
//여벌 옷이 있는데 도난 당한 경우, 주의!!
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<bool> possible;
    
    possible.assign(n, true);
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    for(int i=0; i<lost.size(); i++){
        possible[lost[i]-1] = false;
    }
    
    for(int i=0; i<reserve.size(); i++){
        //여벌 옷이 있는데 도난 당한 경우 먼저 처리 - if lost:[4,5], reserve[3,4] -> 먼저 처리 안하면 reserve의 3이 lost의 4에게 체육복을 줘버림.
        if(!possible[reserve[i]-1]){
            possible[reserve[i]-1] = true;
            reserve[i] = -1; //그 어느것의 인덱스도 아닌 -1로 reserve의 원소를 바꿔버림.
        }
    }
    
    for(int i=0; i<reserve.size(); i++){
        if(reserve[i]==-1){ //여벌 옷 있는데 도난 당한 경우인 경우, 그냥 뛰어넘기
            continue;
        }
        
        if(reserve[i]==1){ //1번 학생
            if(!possible[1]){
                possible[1] = true;
                continue;
            }
        }
        else if(reserve[i]==n){ //n번 학생
            if(!possible[n-2]){
                possible[n-2] = true;
                continue;
            }
        }
        else{ //2번~n-1번 학생
            if(!possible[reserve[i]-2]){
                possible[reserve[i]-2] = true;
                continue;
            }
            if(!possible[reserve[i]]){
                possible[reserve[i]] = true;
                continue;
            }
        }
    }
    
    for(int i=0; i<n; i++){
        if(possible[i]){
            answer++;
        }
    }
    
    return answer;
}