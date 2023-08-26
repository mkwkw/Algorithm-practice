#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//모든 경우의 수로 붙여보고 그다음 정렬
vector<string> numberStr;
vector<bool> visited;
string tempStr;

void dfs(string temp){
    for(int i=0; i<visited.size(); i++){
        if(!visited[i]){
            temp += numberStr[i];
            visited[i] = true;
            dfs(temp);
            visited[i] = false;
        }
    }
    tempStr = temp;
}

string solution(vector<int> numbers) {
    string answer = "0";
    char firstNum;
    
    for(int i=0; i<numbers.size(); i++){
        numberStr.push_back(to_string(numbers[i]));    
    }
    
    sort(numberStr.begin(), numberStr.end(), greater<>());
    
    firstNum = numberStr[0][0];
    for(int i=0; i<numberStr.size(); i++){
        if(firstNum == numberStr[i][0]){
            visited.assign(numberStr.size(), false);
            
            visited[i] = true;
            dfs(numberStr[i]);
            cout<<tempStr<<'\n';
            if(tempStr>answer){
                answer = tempStr;
            }
        }            
    }
    
    return answer;
}

int main(){
    cout<<"ans "<<solution({6,10,2});
}