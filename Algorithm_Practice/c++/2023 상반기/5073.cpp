#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int a, b, c;
    vector<int> num(3);

    //a<=b<=c로 순서 맞추기
    while(cin>>a>>b>>c){
        if(a==0 && b==0 && c==0){
            return 0;
        }

        num[0] = a;
        num[1] = b;
        num[2] = c;

        sort(num.begin(), num.end());

        if(num[0]+num[1]<=num[2]){
            cout<<"Invalid\n";
        }
        else{
            if(num[0]==num[1] && num[1]==num[2] && num[2]==num[0]){
                cout<<"Equilateral\n";
            }
            else if((num[0]==num[1] && num[1]!=num[2]) || (num[1]==num[2] && num[2]!=num[0]) || (num[0]==num[2] && num[2]!=num[1])){
                cout<<"Isosceles\n";
            }
            else{
                cout<<"Scalene\n";
            }
        }
    }
}