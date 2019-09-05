import java.util.Scanner;

class Time {
	int h;
	int m;
	int s;

	Time() {
		h = 0;
		m = 0;
		s = 0;
	}

	Time(int hour, int minute, int sec) {
		h = (hour+(minute+(sec/60))/60)%24;
		m = (minute+(sec/60))%60;
		s = sec%60;
	}

	void print() {
		System.out.println(h+":"+m+":"+s);
	}

	Time addTime(Time a) {
		Time ans = new Time(0,0,0);
		ans.h = ((this.h+a.h)+(this.m+a.m+((this.s+a.s)/60))/60)%24;
		ans.m = (this.m+a.m+((this.s+a.s)/60))%60;
		ans.s = (this.s+a.s)%60;
		return ans;
	}

	Time subTime(Time a) {
		Time ans = new Time(0,0,0);
		//seconds
		if (this.s>a.s) {
			ans.s = this.s-a.s;
		}
		else {
			ans.s = this.s+60-a.s;
			this.m--;
		}

		//minutes
		if (this.m>a.m) {
			ans.m = this.m-a.m;
		}
		else {
			ans.m = this.m+60-a.m;
			this.h--;
		}

		//hours
		ans.h = this.h-a.h;

		return ans;
	}

	int compareTime(Time a) {
		//if the function returns 1 then the object that calls this is larger.
		int totala = (a.h*60)+(a.m*60)+a.s;
		int totalthis = (this.h*60)+(this.m*60)+this.s;
		if (totala == totalthis) return 0;
		else if (totala > totalthis) return -1;
		else return 1;
	}
}

class TimeTest {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		System.out.println("Enter a time: ");
		Time a = new Time(sc.nextInt(), sc.nextInt(), sc.nextInt());
		a.print();
		System.out.println("Enter another time: ");
		Time b = new Time(sc.nextInt(), sc.nextInt(), sc.nextInt());
		b.print();

		System.out.println("\nAdded Time:");
		a.addTime(b).print();

		System.out.println("\nDifference is:");
		a.subTime(b).print();

		System.out.println(a.compareTime(b));
	}
}