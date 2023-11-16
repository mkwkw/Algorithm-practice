import java.util.*;

//투 포인터, 맵
//투 포인터: 보석 인덱스 범위
//맵: 보석 이름, 보석 개수 - 보석 개수로 중복 확인, 최소 개수 1이상 이어야하는데 이것도 체크
//start를 어떻게 이동시키는가 - gem[start]의 개수가 2개 이상인 경우 - 이동
class Solution {
    public int[] solution(String[] gems) {
        int kind = new HashSet<>(Arrays.asList(gems)).size();
 
        int[] answer = new int[2];
        int length = Integer.MAX_VALUE, start = 0;
               
        Map<String, Integer> map = new HashMap<>(); //보석 이름, 보석의 개수
        
        for (int end = 0; end < gems.length; end++) {
            map.put(gems[end], map.getOrDefault(gems[end], 0) + 1);
 
            //start번째 보석의 개수가 2개 이상이면 보석의 개수를 하나 줄이고 start를 +1
            while (map.get(gems[start]) > 1) {
                map.put(gems[start], map.get(gems[start]) - 1);
                start++;
            }
 
            if (map.size() == kind && length > (end - start)) {
                length = end - start;
                answer[0] = start + 1;
                answer[1] = end + 1;
            }
        }
 
        return answer;
    }
}