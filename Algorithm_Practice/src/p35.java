//1753
//다익스트라 최단경로
import java.io.*;
import java.util.*;
public class p35 {
	static int V,E,k,INF=Integer.MAX_VALUE;
	static int dist[];
	static ArrayList<Point> arrList[];
	public static void main(String[] args) throws IOException{
		 BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	     String brr[] = br.readLine().split(" ");   
		 
	     V = Integer.parseInt(brr[0]); //정점 개수
	     E = Integer.parseInt(brr[1]); //간선 개수
	        
	     arrList = new ArrayList [V+1]; //노드 연결된 것 표현하기 위해 생성
	     dist = new int [V+1]; //시작점 k에서의 거리 배열
	     
	     for(int i=1; i<=V; i++) { //각 배열의 원소를 ArrayList로 지정
	        arrList[i] = new ArrayList<>();
	     }
	     for(int i=1; i<=V; i++) { //거리를 INF로 초기화
	        dist[i] = INF;
	     }
	     
	     k = Integer.parseInt(br.readLine()); //시작점
	     dist[k] = 0; //시작점에서의 거리는 0으로 설정
	        
	     //정점 간 연결된 간선의 가중치 저장
	     for(int i=0; i<E; i++) {
	        brr = br.readLine().split(" ");
	        int u = Integer.parseInt(brr[0]);
	        int v = Integer.parseInt(brr[1]);
	        int val = Integer.parseInt(brr[2]);
	        arrList[u].add(new Point(v, val)); //시작점 배열리스트에 Point객체 저장
	     }
	     
	     //우선순위큐
	     solve();
	     
	     //출력문
	     for(int i=1; i<=V; i++) {
	        if(dist[i] == INF)
	            System.out.println("INF");
	        else
	            System.out.println(dist[i]);
	     }
	 }
	
	public static void solve() {
	
		//Point객체를 노드로 하는 우선순위큐 생성
		PriorityQueue<Point> pq = new PriorityQueue<>();
	        
	    // PriorityQueue = (Vertex, weight)
	    pq.add(new Point(k, 0));
	        
	    while(!pq.isEmpty()) {
	    
	    	Point point = pq.poll(); //우선순위큐에서 poll한 point객체
	            
	        // 갱신하려고 하는 거리 값이 PQ에서 poll한 노드의 값(point)보다 작을 땐 갱신 X
	        if(dist[point.vertex] < point.val)
	            continue;
	            
	        // 현재 노드에 연결된 Vertex가 저장 된 ArrayList를 반복문을 통해 탐색하며 더 작은 값으로 갱신할 수 있다면 갱신하면서 PQ에 넣어준다.
	        for(int i=0; i<arrList[point.vertex].size(); i++) {
	            int tmpIndex = arrList[point.vertex].get(i).vertex; //연결된 정점 꺼내기
	            int tmpDist = point.val + arrList[point.vertex].get(i).val; //연결된 정점의 val꺼내고 지금까지의 val 더하기
	                
	            if(dist[tmpIndex] > tmpDist) { //비교하고 더 작은 값으로 갱신
	                dist[tmpIndex] = tmpDist;
	                pq.add(new Point(tmpIndex, tmpDist));
	            }
	        }
	    }
	}
	    
	// 우선순위큐를 편하게 사용하기 위해 정렬기준 변경
	//Point 객체
	public static class Point implements Comparable<Point>{ //Comparable<Point>로 정렬되도록한다.
	     int vertex;
	     int val;
	     public Point(int v, int val) {
	        this.vertex=v;
	        this.val=val;
	     }
	     @Override
	     public int compareTo(Point o) {
	        if(this.val > o.val)
	            return 1;
	        // TODO Auto-generated method stub
	        return 0;
	     }
	        
	}
	
	
}
