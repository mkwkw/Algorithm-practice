#include <vector>
#include <map>

using namespace std;

int solution(vector<int> nums)
{
    map<int, int> pocketMonster;
    int answer = 0;
    
    for(int i=0; i<nums.size(); i++){
        pocketMonster[nums[i]]++;
    }
    
    //포켓몬이 n/2종류 이상이면 n/2 리턴
    //포켓몬이 n/2종류보다 적으면 해당 포켓몬 종류 리턴
    if(pocketMonster.size()>=nums.size()/2){
        answer = nums.size()/2;
    }
    else{
        answer = pocketMonster.size();
    }
    
    return answer;
}