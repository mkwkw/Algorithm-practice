#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

//map
//"시간 -> 분"으로 변환, 각각 시간에 대한 주차 요금X, 누적 시간에 대한 주차 요금!
//carAndTime - key: 차 번호, value: 입출차 시간 (vector 크기가 짝수가 아니면 23:59에 해당하는 1439 추가) 
//누적 시간 계산
//carAndPay - key: 차 번호, value: 누적 시간
//map은 key값 기준으로 자동 정렬되므로 carAndPay돌면서 계산한 요금을 순서대로 answer에 넣으면 됨.
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, vector<int>> carAndTime;
    map<string, int> carAndPay;
    
    for(int i=0; i<records.size(); i++){
        string hourStr = records[i].substr(0,2);
        string minuteStr = records[i].substr(3,2);
        string carNum = records[i].substr(6,4);
        
        int time = stoi(hourStr)*60 + stoi(minuteStr);
        carAndTime[carNum].push_back(time);
    }
    
    for(auto car : carAndTime){
        int totalTime = 0;
        
        if(car.second.size()%2!=0){
            car.second.push_back(1439);
        }
        
        for(int i=0; i<car.second.size()-1; i+=2){
            totalTime += car.second[i+1] - car.second[i];
        }
        
        carAndPay[car.first] = totalTime;
    }
    
    for(auto car : carAndPay){
        int price = 0;
        
        //일단 시간
        if(0<car.second && car.second<=fees[0]){
            price = fees[1];
        }
        else if(fees[0]<car.second){
            //기본 요금 + 추가 요금
            //cout<<ceil((car.second-fees[0])/fees[2])<<'\n';
            price = fees[1] + ceil((double)(car.second-fees[0])/fees[2])*fees[3];
        }
        
        //carAndPay[car.first] = price;
        answer.push_back(price);
    }
    
    return answer;
}