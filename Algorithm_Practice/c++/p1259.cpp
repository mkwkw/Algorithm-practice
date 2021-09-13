#include <iostream>

using namespace std;

string palindrome(string num){
    int cnt=0;

    for(int i=0; i<num.length()/2; i++){
        if(num[i]==num[num.length()-1-i])
            cnt++;
    }

    if(cnt == num.length()/2)
        return "yes";
    else
        return "no";

}

int main(){
    string stnum;
    string answer;

    while(true){
        cin>>stnum;

        if(stnum=="0")
            break;

        answer = palindrome(stnum);
        cout<<answer<<'\n';
    }


}
