#include <string>
#include <vector>
#include <map>
#include <stack>
#include <iostream>

using namespace std;

//stack, map, 구현
//1. 연산자와 피연산자 나누기
//2. stack 4개로 연산 구현
//3. 같은 부호일 때는 앞에서부터 계산하므로 tempOpStack의 top이 해당 연산자일 때 계산
//4. 우선순위 순서대로 연산자를 찾아서 처음부터 끝까지 계산 반복 
//5. 절댓값 씌우는 것 잊지 말기!
long long solution(string expression) {
    long long answer = 0, result;
    map<char, vector<int>> opAndPriority;
    map<char, int> opCnt;
    vector<long long> num;
    vector<char> op;
        
    //연산자와 가능한 우선순위
    opAndPriority['*'] = {1,1,2,2,3,3};
    opAndPriority['+'] = {2,3,1,3,1,2};
    opAndPriority['-'] = {3,2,3,1,2,1};
    
    //연산자와 피연산자 나누기
    int opPos = -1;
    for(int i=0; i<expression.length(); i++){
        if(expression[i]=='*' || expression[i]=='+' || expression[i]=='-'){
            opCnt[expression[i]]++;
            
            string numStr = expression.substr(opPos+1, i-opPos+1);
            num.push_back(stol(numStr));
            op.push_back(expression[i]);
            opPos = i;
        }
    }
    string numStr = expression.substr(opPos+1);
    num.push_back(stol(numStr));
    
    result = 0;
    for(int i=0; i<6; i++){
        stack<long long> numSt, tempNumSt;
        stack<char> opSt, tempOpSt;
        
        for(int j=0; j<num.size(); j++){
            numSt.push(num[j]);
        }
        for(int j=0; j<op.size(); j++){
            opSt.push(op[j]);
        }
        
        map<char, int> tempOpCnt(opCnt);
        vector<char> opCh(3);
        opCh[opAndPriority['*'][i]-1] = '*';
        opCh[opAndPriority['+'][i]-1] = '+';
        opCh[opAndPriority['-'][i]-1] = '-';
        
        // for(int i=0; i<3; i++){
        //     cout<<opCh[i]<<' ';
        // }
        
        for(int i=0; i<3; i++){
            
            while(tempOpCnt[opCh[i]]>0){
                if(opSt.top()==opCh[i]){
                    tempOpCnt[opCh[i]]--;
                }
                
                tempNumSt.push(numSt.top());
                tempOpSt.push(opSt.top());
                numSt.pop();
                opSt.pop();
                
            }
            
            while(!tempOpSt.empty()){
                if(tempOpSt.top() == opCh[i]){
                    long long temp;
                    if(tempOpSt.top()=='*'){
                        temp = numSt.top()*tempNumSt.top();
                    }
                    else if(tempOpSt.top()=='+'){
                        temp = numSt.top()+tempNumSt.top();
                    }
                    else{
                        temp = numSt.top()-tempNumSt.top();
                    }
                    
                    numSt.pop();
                    tempOpSt.pop();
                    tempNumSt.pop();
                    //cout<<"temp "<<temp<<'\n';
                    numSt.push(temp);
                }
                else{
                    numSt.push(tempNumSt.top());
                    opSt.push(tempOpSt.top());
                    tempOpSt.pop();
                    tempNumSt.pop();
                }
                
            }
            
            while(!tempNumSt.empty()){
                numSt.push(tempNumSt.top());
                tempNumSt.pop();
            }
        }
        //cout<<abs(numSt.top())<<'\n';
        answer = max(answer, abs(numSt.top()));
    }
    
    return answer;
}