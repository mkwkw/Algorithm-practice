//1753
//���ͽ�Ʈ�� �ִܰ��
import java.io.*;
import java.util.*;
public class p35 {
	
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String brr[] = br.readLine().split(" ");
		int v = Integer.parseInt(brr[0]); //���� ����
		int e = Integer.parseInt(brr[1]); //���� ����
		String brr1[] = br.readLine().split(" ");
		int k = Integer.parseInt(brr1[0]); //���� ���
		int dis[] = new int [v+1]; //���� �������� �Ÿ� ���
		Arrays.fill(dis, Integer.MAX_VALUE);
		boolean visited[] = new boolean [v+1]; //������ �湮�ߴ°�-INF�Ǻ�
		
		ArrayList<Node>[] graph = new ArrayList[v+1];  //�迭 ������ ArrayList
		//�迭�� �� ���Ұ� Node����
		
		for(int i=0; i<v+1; i++) {
			graph[i] = new ArrayList<Node>(); 
		}
		Arrays.fill(dis, Integer.MAX_VALUE);
		
		for(int i=0; i<e; i++) {
			brr= br.readLine().split(" ");
			//graph[Integer.parseInt(brr[0])].add(new Node(Integer.parseInt(brr[1]),Integer.parseInt(brr[2])));
		}
		
		PriorityQueue<Integer> pque = new PriorityQueue<Integer>();
		pque.add(k);
		while(!pque.isEmpty()) {
			int current = pque.poll();
			visited[current] = true;
			
			for(int i=0; i<graph[current].size(); i++) {
				
				int next = graph[current].get(i).end;
				int value = graph[current].get(i).weight;
				
				if(dis[next]>dis[current]+value) {
					dis[next] = Math.min(dis[next], dis[current]+value);
					pque.add(next);
				}
				
				
			}
		}
		
		for(int i=1; i<=v; i++) {
					if(visited[i])
						System.out.println(dis[i]);
					else
						System.out.println("INF");
				}

	}
	
	class Node {
		int end;
		int weight;
		Node(int end, int weight){
			this.end = end;
			this.weight = weight;
		}
	}

}
