//���� 1021
//ȸ���ϴ� ť
//��
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
		
		//���Ḯ��Ʈ�� �� ����
		LinkedList<Integer> deq = new LinkedList<Integer>();
		for(int i=1; i<=n; i++) {
			deq.add(i);
		}
		
		int count = 0; //Ƚ�� ����
		int mid = 0; //�߰�����
		for(int i=0; i<m; i++) {
			
			if(deq.size()%2==0)
				mid = deq.size()/2 -1;
			else
				mid = deq.size()/2;
		
			int idxq = 0; //�������� �ε���
			for(int j=0; j<deq.size(); j++) {
				if(deq.get(j) == num[i]) { //���� ������ ���ڰ� �ִٸ� idxq�� �ش� �����ε��� ����
					idxq=j;
					break;
				}
			}
			
			if(mid-idxq >= 0) { //�ش� ���ڰ� �߰����� �տ� ���� ���� �߰��� ��ġ�� ��
				for(int j=0; j<idxq; j++) { //�ش� ���� ���� ���ڱ��� 2�� �۾� ����
					int first = deq.pollFirst();
					deq.addLast(first);
					count++;
				}
				deq.poll(); //�ش� ���ڴ� poll
			}
			else { //�ش� ���ڰ� �߰����� �ڿ� ���� ��
				for(int j=0; j<deq.size()-idxq; j++) { //�ش� ���� ���� ���ڱ��� 3�� �۾� ����
					int last = deq.pollLast();
					deq.addFirst(last);
					count++;
				}
				deq.poll(); //�ش� ���ڴ� poll
			}
		}
		System.out.println(count);

	}

}
