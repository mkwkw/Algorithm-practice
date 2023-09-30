#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

//구현, 문자열

//C# 같은 것을 두 글자로 읽으면 안되고, 한 글자로 읽어야함. -> #붙은 것을 소문자로 바꾸기 (C# -> c)
string removeSharp(string score){
    stack<char> st;
    string str = "";
    
    for(int i=0; i<score.length(); i++){
        if(score[i]=='#'){
            char ch = st.top();
            st.pop();
            st.push(tolower(ch));
        }
        else{
            st.push(score[i]);
        }
    }
    
    while(!st.empty()){
        str += st.top();
        st.pop();
    }
    
    reverse(str.begin(), str.end());
    
    return str;
}

string solution(string m, vector<string> musicinfos) {
    string answer = ""; //정답 후보
    int playTime = 0;  //정답 후보의 재생 시간
    
    for(int i=0; i<musicinfos.size(); i++){
        stringstream ss(musicinfos[i]); //ss(나눌 문자열)
        string token;
        vector<string> tokens;
        
        //',' 기준으로 분리
        while(getline(ss, token, ',')){
            tokens.push_back(token);
        }
        
        //HH:MM -> 총 몇 분인지 환산 (HH*60 + MM)
        int startTimeH = stoi(tokens[0].substr(0,2));
        int startTimeM = stoi(tokens[0].substr(3,2));
        int endTimeH = stoi(tokens[1].substr(0,2));
        int endTimeM = stoi(tokens[1].substr(3,2));
        int startTime = startTimeH*60 + startTimeM;
        int endTime = endTimeH*60 + endTimeM;
        
        int time = endTime - startTime; //총 재생 시간
        //cout<<time<<'\n';
        string title = tokens[2]; //음악 제목
        string score = removeSharp(tokens[3]); //#없앤 악보
        string totalScore = "";
        
        //재생 시간에 따른 총 악보 구하기
        if(score.length()<time){
            for(int j=0; j<time/score.length(); j++){
                totalScore += score;
            }
            totalScore += score.substr(0,time%score.length());
            //cout<<totalScore<<'\n';
        }
        else if(score.length()>time){
            totalScore = score.substr(0, time);
        }
        else{
            totalScore = score;
        }

        //m이 totalScore에 포함되는가
        if(totalScore.find(removeSharp(m)) != string::npos){
            //순차적으로 탐색하므로, 입력 순서는 따지지 않고
            //재생 시간 기준으로만 정답 따지기
            if(time > playTime){
                answer = title;
                playTime = time;
            }
        }        
    }
    
    //맞는 곡이 없을 때
    if(answer == ""){
        answer = "(None)";
    }
    
    return answer;
}