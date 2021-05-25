import java.util.*;
import java.io.*;
public class p18352 {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		int x = Integer.parseInt(st.nextToken());
		
		ArrayList<Integer> list[] = new ArrayList[n+1]; //노드 저장
		int distance[] = new int [300001];
		
		for(int i=1; i<n+1; i++) {
			list[i] = new ArrayList<>(); //각 노드와 연결된 노드들을 ArrayList로 저장하는 형태
			distance[i]=-1;
		}
		
		for(int i=0; i<m; i++) {
			st = new StringTokenizer(br.readLine());
			int s = Integer.parseInt(st.nextToken());
			int e = Integer.parseInt(st.nextToken());
			
			list[s].add(e); //list[s]라는 ArrayList에 e원소 추가
		}
		
		distance[x]=0; //x->x는 거리0
		
		//BFS
		Queue<Integer> q = new LinkedList<Integer>();
		q.add(x); //출발도시 x
		
		while(!q.isEmpty()) {
			int temp = q.poll();
			
			for(int i=0; i<list[temp].size(); i++) {
				int next = list[temp].get(i);
				
				//방문한 적 없으면
				if(distance[next]==-1) {
					distance[next]=distance[temp]+1; //출발도시에서 next도시까지 거리
					q.add(next);
				}
			}
		}
		
		boolean check = false;
		for(int i=0; i<n+1; i++) {
			if(distance[i]==k) {
				System.out.println(i);
				check = true;
			}
		}
		if(!check) System.out.println(-1);
		
		
	}
}


