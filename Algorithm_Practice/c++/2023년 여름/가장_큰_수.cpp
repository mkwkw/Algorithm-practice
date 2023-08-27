#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

//정렬
//같은 숫자로 시작하는 수만 정렬
//0만 들어왔을 때 체크!! - 예외처리!
bool comp(const string &a, const string &b){
    //a와 b를 붙였을 때, b와 a를 붙였을 때 어느것이 큰가 비교
    return stoi(a+b)>stoi(b+a);
    
}

string solution(vector<int> numbers) {
    vector<string> numberStr;
    string answer = "";
    map<char, vector<string>> firstChAndNum;
    
    for(int i=0; i<numbers.size(); i++){
        numberStr.push_back(to_string(numbers[i]));
        firstChAndNum[numberStr[i][0]].push_back(numberStr[i]);
    }
        
    //0만 들어왔을 때 판단 필요!
    bool zeroflag = true;
    
    for(int i=9; i>=0; i--){
        if(!firstChAndNum[i+'0'].empty()){
            if(i+'0' != '0'){
                zeroflag = false;
            }
            
            if(firstChAndNum[i+'0'].size()==1){
                answer += firstChAndNum[i+'0'][0];
            }
            else{ //같은 숫자로 시작하는 숫자 - 정렬 필요
                string temp = "";
                sort(firstChAndNum[i+'0'].begin(), firstChAndNum[i+'0'].end(), comp);
                for(int j=0; j<firstChAndNum[i+'0'].size(); j++){
                    //cout<<firstChAndNum[i+'0'][j]<<'\n';
                    temp += firstChAndNum[i+'0'][j];
                }
                answer += temp;
            }
        }
    }
    
    if(zeroflag){ //0만 있다면 "0000" -> "0"
        answer = "0";
    }
    
    return answer;
}