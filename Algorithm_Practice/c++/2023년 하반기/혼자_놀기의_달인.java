import java.util.*;

class Solution {
    
    private boolean[] visited;
    
    private int dfs(int idx, int[] cards, int cnt){
        
        if(!visited[cards[idx]]){
            visited[cards[idx]] = true;
            return dfs(cards[idx], cards, cnt+1);
        }
        else{
            return cnt;
        }
        
    }
    public int solution(int[] cards) {
        List<Integer> temp = new ArrayList<>();
        int answer = 0;
        
        int[] cards1 = new int[cards.length+1];
        for(int i=1; i<=cards.length; i++){
            cards1[i] = cards[i-1];
        }
        visited = new boolean[cards.length+1];
        Arrays.fill(visited, false);
        
        for(int i=1; i<cards1.length; i++){
            if(!visited[i]){
                visited[i] = true;
                temp.add(dfs(i, cards1, 1));
            }
        }
        
        temp.sort(Collections.reverseOrder());
        
        if(temp.get(0)==cards.length){
            answer = 0;
        }
        else{
            answer = temp.get(0)*temp.get(1);
        }
        
        return answer;
    }
}