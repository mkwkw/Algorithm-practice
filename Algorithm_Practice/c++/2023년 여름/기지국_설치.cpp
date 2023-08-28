#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//수학 문제
//전파가 닿지 않는 공간에 기지국이 최소 몇 개가 필요한가? 
//굳이 하나하나 세울 수 있나없나 탐색x
//전파가 닿지 않는 각 영역의 크기 구하기 
//반올림
int solution(int n, vector<int> stations, int w)
{
    vector<int> apartments;
    int answer = 0;
    
    //현재 기지국 전파 도달하지 못하는 부분 구하기 - stations가 오름차순으로 주어지므로 순차 탐색으로 가능
    int start = 0, end = 0;
    
    for(int i=0; i<stations.size(); i++){
        //1부터 시작하는 영역 (1부터 시작하는 영역이 없으면 음수가 됨.)
        if(i==0){
            start = 1;
            end = stations[i]-w-1;
        }
        else{
            start = stations[i-1]+w+1;
            end = stations[i]-w-1;
        }
        apartments.push_back(end-start+1);
    }
    
    //n으로 끝나는 영역(n으로 끝나는 영역이 없으면 음수가 됨.)
    start = stations[stations.size() - 1] + w + 1;
    end = n;
    apartments.push_back(end-start+1);
    
    
    for(int i=0; i<apartments.size(); i++){
        if(apartments[i]<=0){
            continue;
        }
        
        if(apartments[i]%(1+2*w)==0){
            answer += apartments[i]/(1+2*w);
        }
        else{
            answer += apartments[i]/(1+2*w)+1;
        }
    }
    
    return answer;
}