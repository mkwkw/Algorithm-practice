#include <string>
#include <vector>
#include <stack>

using namespace std;

//stack
//num.top().second<numbers[i]일 동안 pop
vector<int> solution(vector<int> numbers) {
    
    vector<int> answer;
    stack<pair<int,int>> num; //인덱스, 숫자
    
    answer.assign(numbers.size(),-1);
    
    for(int i=0; i<numbers.size(); i++){
        if(num.empty()){
            num.push({i,numbers[i]});
        }
        else{
            if(num.top().second<numbers[i]){
                while(!num.empty() && num.top().second<numbers[i]){
                    answer[num.top().first] = numbers[i];
                    num.pop();
                }
                
                //answer[num.top().first] = numbers[i];
                num.push({i, numbers[i]});
            }
            else{
                num.push({i, numbers[i]});
            }
        }
    }
    
    return answer;
}