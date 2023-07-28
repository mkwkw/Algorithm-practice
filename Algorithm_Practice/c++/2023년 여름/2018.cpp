#include <iostream>
#include <vector>

using namespace std;

//투 포인터
//합이 크면 left를 오른쪽으로
//합이 작으면 right를 오른쪽으로
int main(){
    int num, answer = 1, left, right, partSum;

    cin>>num;

    left = 1;
    right = 1;
    partSum = 1;

    while(right<num && left<=right){
        //cout<<left<<' '<<right<<' '<<partSum<<'\n';
        if(partSum==num){
            answer++;
            partSum -= left;
            ++left; 
        }
        else if(partSum<num){
            ++right;
            partSum += right;
        }
        else{
            partSum -= left;
            ++left;    
        }
    }   

    cout<<answer;
}