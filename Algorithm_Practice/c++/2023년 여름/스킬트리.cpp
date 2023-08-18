#include <string>
#include <vector>
#include <iostream>

using namespace std;

//구현
//skill에 해당하는 문자가 skill_trees[i]에 아예 없을 때도 통과!!
int solution(string skill, vector<string> skill_trees) {
    vector<int> idx;
    int answer = 0, endValidIdx;
    string result;
    
    for(int i=0; i<skill_trees.size(); i++){
        result = "";
        idx.assign(skill.length(), -1);
        
        for(int j=0; j<skill_trees[i].length(); j++){
            if(skill.find(skill_trees[i][j])!=string::npos){
                //chQ.push(skill_trees[i][j]);
                result += skill_trees[i][j];
            }
        }
        /*
        while(!chQ.empty()){
            result += chQ.front();
            chQ.pop();
        }
        */
        //cout<<result<<'\n';
        if((skill.find(result)!=string::npos && result[0]==skill[0]) || result == ""){ //skill에 해당하는 문자가 있을 때 || skill에 해당하는 문자가 아예 없을 때
            answer++;
        }
    }
    return answer;
}