#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

//tempStr: ������� ����, tempNum: ���� ����(1~n), op: '+', '-', ' '
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
        int res = 1; //������� ������ ��
        string oneRes = ""; //�� ���� ��
        bool flag = false; //1 �ٷ� �ڿ� ' '�� �ִ���
        for(int i=1; i<tempStr.length(); i++){
            strQ.push(tempStr[i]);
        }

        while(!strQ.empty()){
            char ch = strQ.front();
            if(ch=='+' || ch=='-'){ //���ο� ���� �������
                strQ.pop();

                if(oneRes!="" && flag){
                    oneRes = "1"+oneRes;
                    res = stoi(oneRes);
                }

                oneRes = "";
                char nextCh = strQ.front();
                while(('0'<nextCh && nextCh<='9') || nextCh==' '){//' '�� �ƴ� ���� ���� ������ ���ڸ� �� �ٿ�����.
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
            else if(ch==' '){//1 �ٷ� ������ ' '�� ������ ��� - ' '�� �ƴ� ���� ���� ������ ���ڸ� �� �ٿ�����.
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

    //���� �ڿ� �����ڸ� �ϳ��� ���̴� ���
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