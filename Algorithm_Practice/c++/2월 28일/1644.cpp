#include <iostream>
#include <vector>

using namespace std;

vector<int> find_prime(int n){ //소수 담을 배열 찾기
    vector<bool> num(n+1, true);
    vector<int> prime;
    num[0]=false;
    num[1]=false;
    for(int i=2; i*i<=n; i++){
        for(int j=i*i; j<=n; j+=i){
            num[j]=false;
        }
    }

    for(int i=2; i<=n; i++){
        if(num[i]){
            prime.push_back(i);
        }
    }

    return prime; //소수 배열 리턴
}

vector<int> add_prime(vector<int> &find_prime, int n){
    vector<int> prime_sum(find_prime.size()+1,0); //소수 누적합 저장할 배열;
    prime_sum[0]=0; //인덱스 0에 들어갈 숫자를 0으로 해야 누적합간의 빼기 연산할 때 좋음.

    //누적합 계산
    int num = prime_sum[0];
    for(int i=1; i<prime_sum.size(); i++){
        prime_sum[i]=find_prime[i-1]+ num;
        num = prime_sum[i];
    }

    return prime_sum;
}

//누적합 간의 차이가 n인 경우 찾기
int find_case(vector<int> &prime_sum, int n){
    int answer=0;
    int result=0;
    int left=0;
    int right=0;

    while(left<=right && right<prime_sum.size()){
        result = prime_sum[right]-prime_sum[left];
        //cout<<"left: "<<left<<" right: "<<right<<" result: "<<result<<" answer: "<<answer<<'\n';
        if(result >= n){
            if(result==n){
                answer++;
            }
            left++;
        }
        else{
            right++;
            if(right==prime_sum.size()){
                break;
            }
        }
    }

    return answer;    
}

int main(){
    vector<int> prime;
    int n, answer;
    cin>>n;

    prime = find_prime(n);
    prime = add_prime(prime, n);

    answer = find_case(prime, n);
    cout<<answer;
}

//n까지 소수 찾기
//소수의 누적합 계산하기
//조건 적용 및 투 포인터 이용하여 누적합 간의 차이가 n인 경우 찾기