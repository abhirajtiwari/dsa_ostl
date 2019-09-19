import java.util.*;
class Q
{
	int n;
	boolean valueset=false;
	synchronized int get()
	{
		while(!valueset)
			try
		{
			wait();
		}
		catch(InterruptedException e)
		{
			System.out.println("InterruptedException caught");
		}
		System.out.println("Got:"+n);
		valueset=false;
		notify();
		return n;
	}
	synchronized void put(int n)
	{
		while(valueset)
			try{
				wait();
			}
			catch(InterruptedException e)
			{
				System.out.println("InterruptedException caught");
			}
			this.n=n;
			valueset=true;
			System.out.println("Put:"+n);
			notify();
	}
}
class producer implements Runnable
{
	Q q;
	producer(Q q)
	{
		this.q=q;
		new Thread(this,"Producer").start();
	}
	public void run()
	{
		int i=0;
		while(true)
		{
			q.put(i++);
		}
	}
}
class consumer implements Runnable
{
	Q q;
	consumer(Q q)
	{
		this.q=q;
		new Thread(this,"Consumer").start();

	}
	public void run()
	{
		while(true)
		{
			q.get();
		}
	}
}
class week83
{
	public static void main(String args[])
	{
		Q q=new Q();
		new producer(q);
		new consumer(q);
		System.out.println("Press Control -c to stop");
	}
}
