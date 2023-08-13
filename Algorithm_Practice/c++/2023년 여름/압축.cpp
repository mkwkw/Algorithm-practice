#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

//map
//문자열.substr(시작 인덱스, 개수)
vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> wordAndIdx;
    
    for(int i=0; i<26; i++){
        char ch = (char)(i+'A');
        string str;
        str += ch;
        wordAndIdx[str] = i+1;
    }
    
    for(int i=0; i<msg.length();){
        int len = 1;
        string str;
        int idx = wordAndIdx[str+msg[i]];
        
        while(i+len-1<msg.length() && (wordAndIdx.find(msg.substr(i, len))!=wordAndIdx.end())){
            idx = wordAndIdx[msg.substr(i, len)];
            len += 1; 
        }
        
            //cout<<msg.substr(i, len)<<' '<<wordAndIdx.size()+1<<'\n';
            wordAndIdx[msg.substr(i, len)] = wordAndIdx.size()+1;
        
        answer.push_back(idx);
        i += len-1;
        //cout<<"i: "<<i<<'\n';
    }
    return answer;
}