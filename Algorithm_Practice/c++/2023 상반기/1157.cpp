#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    vector<int> alphabet;
    string str;
    int maxCnt = 0;
    char answer;
    bool flag = true; //�������� true�̸� �ߺ�X, false�̸� �ߺ� �ִٴ� ��
    cin>>str;

    alphabet.assign(26, 0);

    for(int i=0; i<str.length(); i++){
        str[i] = toupper(str[i]);
        alphabet[str[i]-'A'] += 1;
        //cout<<str[i]-'A'<<' ';
    }

    for(int i=0; i<26; i++){
        if(alphabet[i]>maxCnt){
            maxCnt = alphabet[i];
            answer = (char)i+'A';
        }

    }

    for(int i=0; i<26; i++){
        if(maxCnt == alphabet[i] && answer!=(char)i+'A'){
            flag = false;
            break;
        }
    }

    if(flag){
        cout<<answer;
    }
    else{
        cout<<'?';
    }
}