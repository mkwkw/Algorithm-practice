#include <iostream>
#include <vector>

using namespace std;

//출력할 때 '.' 주의!

int main(){
    string str;
    bool flag;

    while(cin>>str){
        flag = true;

        if(str=="end"){
            break;
        }

        //세 번째 조건
        for(int i=0; i<str.length()-1; i++){
            if(str[i]==str[i+1] && (str[i]!='e' && str[i]!='o')){
                //cout<<"ee oo else\n";
                flag = false;
                break;
            }

        }

        if(!flag){
            cout<<"<"<<str<<"> is not acceptable.\n";
            continue;
        }

        //두 번째 조건
        if(str.length()>=3){
            for(int i=0; i<=str.length()-3; i++){
                if(((str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u') && (str[i+1]=='a' || str[i+1]=='e' || str[i+1]=='i' || str[i+1]=='o' || str[i+1]=='u') && (str[i+2]=='a' || str[i+2]=='e' || str[i+2]=='i' || str[i+2]=='o' || str[i+2]=='u')) ||
                ((str[i]!='a' && str[i]!='e' && str[i]!='i' && str[i]!='o' && str[i]!='u') && (str[i+1]!='a' && str[i+1]!='e' && str[i+1]!='i' && str[i+1]!='o' && str[i+1]!='u') && (str[i+2]!='a' && str[i+2]!='e' && str[i+2]!='i' && str[i+2]!='o' && str[i+2]!='u'))){
                    //cout<<"3 row\n";
                    flag = false;
                    break;
                }
            }
            if(!flag){
                cout<<"<"<<str<<"> is not acceptable.\n";
                continue;
            }
        }

        

        //첫 번째 조건
        flag = false;
        for(int i=0; i<str.length(); i++){
            if((str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u')){
                flag = true;
                break;
            }
        }

        if(flag){
            cout<<"<"<<str<<"> is acceptable.\n";
        }
        else{
            cout<<"<"<<str<<"> is not acceptable.\n";

        }
    }
}