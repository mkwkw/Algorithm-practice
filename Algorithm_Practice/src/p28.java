//백준 1966
//프린터 큐
import java.io.*;
import java.util.*;
public class p28 {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine());
		
		int t[] = new int [test];
		for(int i=0; i<test; i++) {
			int answer = 0;
			String brr[] = br.readLine().split(" ");
			int n = Integer.parseInt(brr[0]);
			int m = Integer.parseInt(brr[1]);
			
			LinkedList<Integer> que = new LinkedList<Integer>();
			
			String arr[] = br.readLine().split(" ");
			int num[] = new int [n];
			
			
			for(int j=0; j<n; j++) {
				num[j] = Integer.parseInt(arr[j]);
				que.offer(num[j]);
			}
			int number = num[m];
			
			Arrays.sort(num);
			
			int importance[] = new int [n];
			for(int j=0; j<n; j++) {
				importance[j] = num[n-1-j];
			}
			
			while(!que.isEmpty()) {
				boolean important = true;
				
				for(int j=1; j<que.size(); j++) {
					if(que.peek()<que.get(j)) {
						important = false;
						break;
					}
				}
				if(important) {
					answer++;
					que.poll();
					
					if(m==0)
						break;
					else
						m--;
				}
				else {
					int p = que.poll();
					que.offer(p);
					m= (m==0)? que.size()-1: --m;
				}
			}
			
			t[i]=answer;
		}
		
		for(int i=0; i<test; i++) {
			System.out.println(t[i]);
		}
	}

}
