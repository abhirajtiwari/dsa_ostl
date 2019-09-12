import java.util.Scanner;

interface Callable {
	void makeAudioCall(String cellNum);
	void makeVideoCall(String cellNum);
}

class Phone implements Callable {
	public String cellNum;
	public String brandName;
	public int memCap;
	Phone(String n, String bn, int mem) {
		if (n.length() != 10) System.out.println("Wrong Mobile number");
		this.cellNum = n;
		this.brandName = bn;
		this.memCap = mem; 
	}

	public void makeAudioCall(String cellNum) {
		System.out.println("Audio Calling: " + cellNum);
	}

	public void makeVideoCall(String cellNum) {
		System.out.println("Video Calling: " + cellNum);
	}
}

class SmartPhone extends Phone {
	SmartPhone(String cellNum, String brandName, int mem) {
		super(cellNum, brandName, mem);
	}
}

class BasicPhone extends Phone {
	BasicPhone(String cellNum, String brandName, int mem) {
		super(cellNum, brandName, mem);
	}

	@Override
	public void makeVideoCall(String cellNum) {
		System.out.println("Can't Video Call from a basic phone");
	}
}

class TestPhone {
	public static void main(String[] args) {
		Phone a = new SmartPhone("1234567890", "Samsung", 128);
		a.makeVideoCall("4561237890");
		a.makeAudioCall("7894561230");
		a = new BasicPhone("4354545452", "Nokia", 8);
		a.makeVideoCall("12345678989");
	}
}