#include <string>
#include <vector>
#include <set>

using namespace std;

//중복 없이 -> set
//원형 큐
int solution(vector<int> elements) {
    set<int> partSum; //수의 범위<=int
    int answer = 0;
    
    for(int i=1; i<=elements.size(); i++){ //길이
        for(int j=0; j<elements.size(); j++){ //시작 인덱스
            int sum = 0;
            for(int k=0; k<i; k++){
                sum += elements[(j+k)%elements.size()]; //원형 큐 인덱스 특성 사용 -> [(j+k)%elements.size()]
            }
            partSum.insert(sum);
        }
    }
    
    answer = partSum.size();
    return answer;
}