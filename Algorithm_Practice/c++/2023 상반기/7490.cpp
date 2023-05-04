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

        //하나의 항 만들기
        while(!strQ.empty()){
            char ch = strQ.front();
            if(ch=='+' || ch=='-'){ //새로운 항이 만들어짐
                strQ.pop();

                if(oneRes!="" && flag){
                    oneRes = "1"+oneRes;
                    res = stoi(oneRes);
                    flag = false; //flag 원래대로!! - 이 코드 없으면 1 이후에도 oneRes를 res로 해버리는 오류 발생
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
                //cout<<"op: "<<ch<<" oneRes: "<<oneRes<<'\n';
                if(ch=='+'){
                    //cout<<"beforeA: "<<res<<' ';
                    res = res + stoi(oneRes);
                    //cout<<"afterA: "<<res<<'\n';
                }
                else{
                    //cout<<"beforeM: "<<res<<' ';
                    //cout<<"minu: "<<stoi(oneRes)<<'\n';
                    res = res - stoi(oneRes);
                    //cout<<"afterM: "<<res<<'\n';
                }
                //cout<<"res: "<<res<<'\n';
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
        //cout<<"res: "<<res<<'\n';
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
    //시간 초과 주의!
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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