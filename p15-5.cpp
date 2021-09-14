#include <iostream>

using namespace std;

string compact(string words){
    int wl = words.length();
    char result[10001];
    int cnt=0;
    int index=0;
    string ans="";

    if(words[0]=='1') {
        result[0] = '1';
        index++;
    }
    for(int i=1; i<wl; i++){
        if(words[i-1]==words[i])
            cnt++;
        else{
            result[index] = cnt + 65;
            index++;
            cnt=0;
        }
    }
    result[index]=cnt + 65;

    ans=result;

    return ans;
}

int main(){
    string words;

    cin>>words;

    string answer = compact(words);

    cout<<answer;
}