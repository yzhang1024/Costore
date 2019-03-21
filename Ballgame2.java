
import java.awt.*;
import javax.swing.*;

public class Ballgame2 extends JFrame{
	
	Image ball=Toolkit.getDefaultToolkit().getImage("images/ball.png");
	Image desk=Toolkit.getDefaultToolkit().getImage("images/desk.JPEG");
	
	double x=100; //小球的横坐标
	double y=100; //小球的纵坐标
	double degree=3.14/3; //弧度，60度
	
	//画窗口的方法
	public void paint(Graphics g) {
		System.out.println("窗口被画了一次！");
		g.drawImage(desk, 0, 0, null);
		g.drawImage(ball,(int)x,(int)y,null);
       
		x=x+10*Math.cos(degree);
		y=y+10*Math.sin(degree);
		
		if(y>500-40-30 || y<40+40) {
			degree=-degree;
		}
		if(x<40 || x>856-40-30) {
			degree=3.14-degree;
		}
		
	}
		
		void launchFrame(){
			setSize(856,500);
			setLocation(50,50);
			setVisible(true);
			
			//重画窗口
			while(true) {
				repaint(); 
				try {
					Thread.sleep(40); //40ms
				}catch(Exception e) {
					e.printStackTrace();
				}
			}
			
		}


		//main方法是程序执行的入口
		public static void main(String[] args) {
			System.out.println("A frame.");
			Ballgame2 game=new Ballgame2();
			game.launchFrame();
			
		}
	}
		
		

