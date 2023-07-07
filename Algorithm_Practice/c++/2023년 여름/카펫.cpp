#include <string>
#include <vector>
#include <cmath>

using namespace std;

//가로:x, 세로:y 
//x*y = brown+yellow
//(x-2)*(y-2) = yellow
//식 이용
vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total = brown + yellow; //xy
    
    for(int y=2; y<=(int)sqrt(total); y++){
        if(total%y!=0){
            continue;
        }
        
        int x = total/y;
        
        if(x+y == (total+4-yellow)/2){
            answer.push_back(x);
            answer.push_back(y);
            break;
        }
    }
    return answer;
}