#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> one={1,2,3,4,5};
    vector<int> two={2,1,2,3,2,4,2,5};
    vector<int> thr={3,3,1,1,2,2,4,4,5,5};
    vector<int> res={0,0,0};
    int maxNum=0;
    
    for(int i=0; i<answers.size(); i++){
        if(answers[i]==one[i%one.size()]){
            res[0]++;
        }
        if(answers[i]==two[i%two.size()]){
            res[1]++;
        }
        if(answers[i]==thr[i%thr.size()]){
            res[2]++;
        }
        
        maxNum = max(res[0], res[1]);
        maxNum = max(maxNum, res[2]);
    }
    
    for(int i=0; i<3; i++){
        if(maxNum == res[i]){
            answer.push_back(i+1);
        }
    }
    
    return answer;
}

/*
각 수포자가 쓸 답을 벡터로 만든다.
for문을 돌리는데 %를 사용한다.
최대 정답자가 여러명인 경우 오름차순으로 다 표시해야하므로 최대 정답 수를 저장해서
for문으로 모든 수포자를 순회해서 해당 정답 수인 사람을 answer벡터에 push_back한다.
*/