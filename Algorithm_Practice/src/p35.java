//1753
//���ͽ�Ʈ�� �ִܰ��
import java.io.*;
import java.util.*;
public class p35 {
	static int V,E,k,INF=Integer.MAX_VALUE;
	static int dist[];
	static ArrayList<Point> arrList[];
	public static void main(String[] args) throws IOException{
		 BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	     String brr[] = br.readLine().split(" ");   
		 
	     V = Integer.parseInt(brr[0]); //���� ����
	     E = Integer.parseInt(brr[1]); //���� ����
	        
	     arrList = new ArrayList [V+1]; //��� ����� �� ǥ���ϱ� ���� ����
	     dist = new int [V+1]; //������ k������ �Ÿ� �迭
	     
	     for(int i=1; i<=V; i++) { //�� �迭�� ���Ҹ� ArrayList�� ����
	        arrList[i] = new ArrayList<>();
	     }
	     for(int i=1; i<=V; i++) { //�Ÿ��� INF�� �ʱ�ȭ
	        dist[i] = INF;
	     }
	     
	     k = Integer.parseInt(br.readLine()); //������
	     dist[k] = 0; //������������ �Ÿ��� 0���� ����
	        
	     //���� �� ����� ������ ����ġ ����
	     for(int i=0; i<E; i++) {
	        brr = br.readLine().split(" ");
	        int u = Integer.parseInt(brr[0]);
	        int v = Integer.parseInt(brr[1]);
	        int val = Integer.parseInt(brr[2]);
	        arrList[u].add(new Point(v, val)); //������ �迭����Ʈ�� Point��ü ����
	     }
	     
	     //�켱����ť
	     solve();
	     
	     //��¹�
	     for(int i=1; i<=V; i++) {
	        if(dist[i] == INF)
	            System.out.println("INF");
	        else
	            System.out.println(dist[i]);
	     }
	 }
	
	public static void solve() {
	
		//Point��ü�� ���� �ϴ� �켱����ť ����
		PriorityQueue<Point> pq = new PriorityQueue<>();
	        
	    // PriorityQueue = (Vertex, weight)
	    pq.add(new Point(k, 0));
	        
	    while(!pq.isEmpty()) {
	    
	    	Point point = pq.poll(); //�켱����ť���� poll�� point��ü
	            
	        // �����Ϸ��� �ϴ� �Ÿ� ���� PQ���� poll�� ����� ��(point)���� ���� �� ���� X
	        if(dist[point.vertex] < point.val)
	            continue;
	            
	        // ���� ��忡 ����� Vertex�� ���� �� ArrayList�� �ݺ����� ���� Ž���ϸ� �� ���� ������ ������ �� �ִٸ� �����ϸ鼭 PQ�� �־��ش�.
	        for(int i=0; i<arrList[point.vertex].size(); i++) {
	            int tmpIndex = arrList[point.vertex].get(i).vertex; //����� ���� ������
	            int tmpDist = point.val + arrList[point.vertex].get(i).val; //����� ������ val������ ���ݱ����� val ���ϱ�
	                
	            if(dist[tmpIndex] > tmpDist) { //���ϰ� �� ���� ������ ����
	                dist[tmpIndex] = tmpDist;
	                pq.add(new Point(tmpIndex, tmpDist));
	            }
	        }
	    }
	}
	    
	// �켱����ť�� ���ϰ� ����ϱ� ���� ���ı��� ����
	//Point ��ü
	public static class Point implements Comparable<Point>{ //Comparable<Point>�� ���ĵǵ����Ѵ�.
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
