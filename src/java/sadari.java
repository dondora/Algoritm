import java.io.FileInputStream;
import java.util.Scanner;


public class Sadari {

	
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		System.setIn(new FileInputStream("sadari_input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int testcase = sc.nextInt();
		
		for(int t =0;t<testcase;t++)
		{
			int N = sc.nextInt();
			int boomber = sc.nextInt();
			int lineNum = sc.nextInt();			
			LINE line[] = new LINE[lineNum];
						
			for(int i=0;i<lineNum;i++)
			{	
				line[i] = new LINE();
				line[i].sy = sc.nextInt();
				line[i].sx = sc.nextInt();
				line[i].ey = sc.nextInt();
				line[i].ex = sc.nextInt();
			} 
			//algorithm
			// 폭탄의 위치에서 거꾸로 추적하자.
			int boomY, boomX;
			boomY = N;
			boomX = boomber;
			for(int y=boomY;y>=0;y--)
			{
				for(int l=0;l<lineNum;l++)
				{
					if((line[l].sy==y && line[l].sx==boomX) )							
					{
						boomX = line[l].ex;
						break;
					}
					else if((line[l].ey==y && line[l].ex==boomX))
					{
						boomX = line[l].sx;
						break;
					}											
				}				
			}
			
			System.out.println("#"+t+" "+boomX);			
		}		
		return ;
	}	

}

class LINE
{
	public int sx,sy, ex, ey;
};
