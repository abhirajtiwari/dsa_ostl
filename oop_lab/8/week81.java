import java.util.*;
class Mul{
	synchronized void multi (int n)
	{
		for(int i=0;i<11;i++)
         System.out.println(n+"*"+i+"="+(n*i));
	}
}
class multhrd extends Thread
{
	
	int n;
	Mul m;
	multhrd(Mul m1,int n1)
	{
		
		m=m1;
		n=n1;
		start();
	}
	public void run()
	{
		m.multi(n);
	}
}
class week81
{
	public static void main(String args[])
	{
		Mul m=new Mul(); 
		multhrd mt1=new multhrd(m,5);
		multhrd mt2=new multhrd(m,7);
	}
}










