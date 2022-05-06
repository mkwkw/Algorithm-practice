#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, firstSize, secondSize, negativeSum=0, positiveSum=0, maxSum=0;
    vector<int> negativeAndZero;
    vector<int> positive;

    cin>>n;

    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        if(num<=0){
            negativeAndZero.push_back(num);
        }
        else{
            positive.push_back(num);
        }
    }

    sort(negativeAndZero.begin(), negativeAndZero.end());
    sort(positive.begin(), positive.end(), greater<>());

    firstSize = negativeAndZero.size();
    secondSize = positive.size();
   
    for(int i=0; i+1<firstSize && firstSize>1; i+=2){
        if(negativeAndZero[i]*negativeAndZero[i+1]>negativeAndZero[i]+negativeAndZero[i+1]){
            negativeSum += negativeAndZero[i]*negativeAndZero[i+1];
        }
        else{
            negativeSum += negativeAndZero[i]+negativeAndZero[i+1];
        }
    }

    for(int i=0; i+1<secondSize && secondSize>1; i+=2){
        if(positive[i]*positive[i+1]>positive[i]+positive[i+1]){
            positiveSum += positive[i]*positive[i+1];
        }
        else{
            positiveSum += positive[i]+positive[i+1];
        }
    }
    

    if(firstSize%2!=0){
        negativeSum += negativeAndZero[firstSize-1];
    }

    if(secondSize%2!=0){
        positiveSum += positive[secondSize-1];
    }

    maxSum = negativeSum + positiveSum;

    cout<<maxSum;
}

//0이하의 숫자가 들어갈 배열과 1이상의 숫자가 들어갈 배열을 따로 둔다.
//0이하의 숫자가 들어갈 배열은 오름차순으로 정렬하고
//1이상의 숫자가 들어갈 배열은 내림차순으로 정렬한다.
//인덱스 0부터 2개씩 묶는다. for의 i는 2씩 증가시키는데 조건에 i+1<해당 배열의 크기를 두어야 올바르게 계산이 된다.
