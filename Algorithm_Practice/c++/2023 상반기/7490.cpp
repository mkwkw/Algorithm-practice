#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

//tempStr: 현재까지 수식, tempNum: 현재 숫자(1~n), op: '+', '-', ' '
void backtracking(int n, string tempStr, int tempNum, char op){
    //cout<<"tempStr: "<<tempStr<<" tempNum: "<<tempNum<<' '<<op<<'\n';

    tempNum += 1;

    if(op=='+'){
        tempStr += "+"+to_string(tempNum);
    }
    else if(op=='-'){
        tempStr += "-"+to_string(tempNum);
    }
    else{ 
        tempStr += ' '+to_string(tempNum);
    }

    if(tempNum==n){
        //cout<<tempStr<<'\n';
        
        queue<char> strQ;
        int res = 1; //만들어진 수식의 값
        string oneRes = ""; //한 항의 값
        bool flag = false; //1 바로 뒤에 ' '가 있느냐
        for(int i=1; i<tempStr.length(); i++){
            strQ.push(tempStr[i]);
        }

        while(!strQ.empty()){
            char ch = strQ.front();
            if(ch=='+' || ch=='-'){ //새로운 항이 만들어짐
                strQ.pop();

                if(oneRes!="" && flag){
                    oneRes = "1"+oneRes;
                    res = stoi(oneRes);
                }

                oneRes = "";
                char nextCh = strQ.front();
                while(('0'<nextCh && nextCh<='9') || nextCh==' '){//' '가 아닌 연산 나올 때까지 숫자를 다 붙여야함.
                    if('0'<nextCh && nextCh<='9'){
                        oneRes += nextCh;
                    }
                    strQ.pop();
                    nextCh = strQ.front();
                }

                if(ch=='+'){
                    res += stoi(oneRes);
                }
                else{
                    res -= stoi(oneRes);
                }
            }
            else if(ch==' '){//1 바로 다음에 ' '가 나오는 경우 - ' '가 아닌 연산 나올 때까지 숫자를 다 붙여야함.
                strQ.pop();
                flag = true;
                char nextCh = strQ.front();
                while(('0'<nextCh && nextCh<='9') || nextCh==' '){
                    if('0'<nextCh && nextCh<='9'){
                        oneRes += nextCh;
                    }
                    strQ.pop();
                    nextCh = strQ.front();
                }
            }
        }

        if(res==0){
            cout<<tempStr<<'\n';
        }
        return;
    }

    //숫자 뒤에 연산자를 하나씩 붙이는 방식
    backtracking(n, tempStr, tempNum, ' ');
    backtracking(n, tempStr, tempNum, '+');
    backtracking(n, tempStr, tempNum, '-');
    
}

int main(){
    int t, n;
    cin>>t;

    for(int i=0; i<t; i++){
        cin>>n;

        backtracking(n, "1", 1, ' ');
        backtracking(n, "1", 1, '+');
        backtracking(n, "1", 1, '-');
        
        if(i<t-1){
            cout<<'\n';
        }
    }
}