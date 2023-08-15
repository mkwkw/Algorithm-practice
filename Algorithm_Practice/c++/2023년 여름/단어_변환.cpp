#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

//bfs, queue
//알파벳 하나씩 바꿔가면서 큐에 넣기
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    vector<bool> visited;
    queue<pair<string, int>> changedWordAndCnt;
    map<string, int> wordAndIdx;
    
    changedWordAndCnt.push({begin, 0});
    visited.assign(words.size(), false);
    
    for(int i=0; i<words.size(); i++){
        wordAndIdx[words[i]] = i;
    }
    
    while(!changedWordAndCnt.empty()){
        
        string frontWord = changedWordAndCnt.front().first;
        int cnt = changedWordAndCnt.front().second;
        //cout<<frontWord<<' '<<cnt<<'\n';
        //frontWord가 target과 동일한 경우
        // if(frontWord == target){
        //     answer = cnt;
        //     break;
        // }
        
        //frontWord가 target과 동일하지 않은 경우 - 알파벳 하나씩 바꿔보면서 words에 있는지 확인하고 큐에 넣기
        for(int i=0; i<frontWord.length(); i++){
            string temp = frontWord;
            for(int j=0; j<26; j++){
                char ch = 'a'+j;
                temp[i] = ch;
                //cout<<temp<<'\n';
                
                //알파벳 바꾼 단어가 words에 있다면
                if(find(words.begin(), words.end(), temp)!=words.end()){
                    
                    //알파벳 바꾼 단어가 target이랑 같다면
                    if(temp == target){
                        return cnt+1;
                    }

                    //알파벳 바꾼 단어가 target이랑 다르면
                    //중복, 시간 줄이기 위해 방문 체크
                    if(visited[wordAndIdx[temp]]){
                        continue;
                    }
                    else{
                        visited[wordAndIdx[temp]] = true;
                    }

                    changedWordAndCnt.push({temp, cnt+1});
                }
            }
            temp[i] = frontWord[i];
        }
        
        //target에 가지 못하는 경우: visited가 true인데 temp와 target이 맞지 않는 경우
        changedWordAndCnt.pop();
    }
    
    return answer;
}