#include <string>
#include <vector>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//정렬, 문자열
//struct 정렬 기준 커스텀!
//substr 사용하기 애매하거나 복잡할 때는
//그냥 while문 써서 기준에 맞는동안 쭉 +=으로 붙이는 방법도 좋다!
struct FileInfo{
    string head;
    int number;
    int originalIdx;
};

bool comp(const FileInfo &a, const FileInfo &b){
    
    if(a.head==b.head){
        if(a.number == b.number){
            return a.originalIdx<b.originalIdx;
        }
        
        return a.number<b.number;
    }
    
    return a.head<b.head;
}

bool verifyNum(char ch){
    if('0'<=ch && ch<='9'){
        return true;
    }
    return false;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<FileInfo> fileInfo;
    string head, numberStr;
    int number;
    
    //숫자(number) 기준으로 앞은 head, 뒤는 tail
    for(int i=0; i<files.size(); i++){
        int idx = 0;
        string smallFileStr = "";
        for(int j=0; j<files[i].length(); j++){
            smallFileStr += tolower(files[i][j]);
        }
        
        head = "";
        numberStr = "";
        //head 구하기
        while(idx<files[i].length()){
            if(!verifyNum(smallFileStr[idx])){
                head += smallFileStr[idx];
                idx += 1;
            }
            else{
                break;
            }
        }
        
        //numberStr 구하기
        while(idx<files[i].length()){
            if(verifyNum(smallFileStr[idx])){
                numberStr += smallFileStr[idx];
                idx += 1;
            }
            else{
                break;
            }
        }
        
        number = stoi(numberStr);
        
        fileInfo.push_back({head, number, i});
        
    }
    
    sort(fileInfo.begin(), fileInfo.end(), comp);
    
    for(int i=0; i<fileInfo.size(); i++){
        // cout<<"head "<<fileInfo[i].head<<'\n';
        // cout<<"number "<<fileInfo[i].number<<'\n';
        // cout<<"idx "<<fileInfo[i].originalIdx<<'\n';
        answer.push_back(files[fileInfo[i].originalIdx]);
    }
    
    return answer;
}