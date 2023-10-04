#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

//항공권을 모두 써야함.
//백트래킹으로 풀어야할 듯 - bfs로 풀어도 가능할 듯? - 하지만 메모리 초과 가능
vector<string> answer;
void travel(string start, string to, map<string, vector<string>> &startTo, map<string, vector<bool>> visited){
    //visited[start].erase(to);
    answer.push_back(to);
    
    for(auto s : startTo[to]){
        //travel(to, s);
        break;
    }
}
vector<string> solution(vector<vector<string>> tickets) {
    map<string, vector<string>> startTo;
    map<string, vector<bool>> visited;
    
    for(int i=0; i<tickets.size(); i++){
        startTo[tickets[i][0]].push_back(tickets[i][1]);
        visited[tickets[i][0]].push_back(false);
    }
    
    for(auto m : startTo){
        sort(m.second.begin(), m.second.end());
    }
    
    for(int i=0; i<startTo["ICN"].size(); i++){
        //answer.push_back("ICN");
        travel("ICN", startTo["ICN"][i], startTo, visited);

    }
    
    return answer;
}