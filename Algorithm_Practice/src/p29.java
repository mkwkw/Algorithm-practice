//백준 1021
//회전하는 큐
//덱
import java.io.*;
import java.util.*;
public class p29 {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String brr[] = br.readLine().split(" ");
		int n = Integer.parseInt(brr[0]);
		int m = Integer.parseInt(brr[1]);
		int num[] = new int [m];
		
		brr = br.readLine().split(" ");
		for(int i=0; i<m; i++) {
			num[i] = Integer.parseInt(brr[i]);
		}
		
		//연결리스트로 덱 생성
		LinkedList<Integer> deq = new LinkedList<Integer>();
		for(int i=1; i<=n; i++) {
			deq.add(i);
		}
		
		int count = 0; //횟수 저장
		int mid = 0; //중간지점
		for(int i=0; i<m; i++) {
			
			if(deq.size()%2==0)
				mid = deq.size()/2 -1;
			else
				mid = deq.size()/2;
		
			int idxq = 0; //덱에서의 인덱스
			for(int j=0; j<deq.size(); j++) {
				if(deq.get(j) == num[i]) { //덱에 지정한 숫자가 있다면 idxq에 해당 숫자인덱스 저장
					idxq=j;
					break;
				}
			}
			
			if(mid-idxq >= 0) { //해당 숫자가 중간보다 앞에 있을 때나 중간에 위치할 때
				for(int j=0; j<idxq; j++) { //해당 숫자 앞의 숫자까지 2번 작업 수행
					int first = deq.pollFirst();
					deq.addLast(first);
					count++;
				}
				deq.poll(); //해당 숫자는 poll
			}
			else { //해당 숫자가 중간보다 뒤에 있을 떼
				for(int j=0; j<deq.size()-idxq; j++) { //해당 숫자 뒤의 숫자까지 3번 작업 수행
					int last = deq.pollLast();
					deq.addFirst(last);
					count++;
				}
				deq.poll(); //해당 숫자는 poll
			}
		}
		System.out.println(count);

	}

}
