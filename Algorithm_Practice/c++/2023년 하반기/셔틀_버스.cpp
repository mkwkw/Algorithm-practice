#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    priority_queue<int, vector<int>, greater<>> pq; //오름차순 정렬
    string answer = "";
    
    //1. timetable 시간 -> 분으로 다 바꾸어서 pq에 넣기
    for(int i=0; i<timetable.size(); i++){
        int hh = stoi(timetable[i].substr(0,2));
        int mm = stoi(timetable[i].substr(3,2));
        
        int time = hh*60+mm;
        pq.push(time);
    }
    
    //2. 셔틀버스 배차
    int cnt, lastCrew;
    for(int i=0; i<n; i++){
        //9시부터 시작
        int bus = 540 + i*t;
        cnt = 0; //셔틀 버스 탄 사람 수
        lastCrew = 0; //마지막에 탄 사람 시간
        while(!pq.empty() && pq.top()<=bus && cnt<m){
            lastCrew = pq.top();
            pq.pop();
            ++cnt;
        }
        //cout<<lastCrew<<' '<<cnt<<'\n';
    }
    
    //마지막 차량에 탄 사람 수가 m보다 작다면, 마지막 셔틀버스 시간에 맞춰서 오면 됨.
    //마지막 차량에 탄 사람 수가 m보다 크거나 같다면, 마지막 셔틀버스에 탄 마지막 m번째 사람보다 1분 먼저 오면 됨. 
    //- m번째 사람과 같은 시간에 오면, 확실하게 탑승한다고 장담할 수 없음.
    int answerTime;
    if(cnt<m){
        answerTime = 540 + (n-1)*t;
    }
    else{
        answerTime = lastCrew-1;
    }
    
    //분 -> 시간
    //리턴 형식에 맞추기
    int hh = answerTime/60;
    int mm = answerTime%60;
    string hStr = to_string(hh);
    string mStr = to_string(mm);
    
    if(hStr.length()==1){
        hStr = "0"+hStr;
    }
    if(mStr.length()==1){
        mStr = "0"+mStr;
    }
    
    answer = hStr+":"+mStr;
    
    return answer;
}