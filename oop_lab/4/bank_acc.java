import java.util.Scanner;

class BankAccount {
	String name;
	int account_number;
	String type_of_account;
	double balance;
	static double roi = 5;

	BankAccount() {
		name = "Unknown account user";
		account_number = 0;
		type_of_account = "savings";
		balance = 0;
	}

	BankAccount(String name, int account_number, String type_of_account, double balance, double roi) {
		this.name = name;
		this.account_number = account_number;
		if (type_of_account.equals("savings") || type_of_account.equals("current")) this.type_of_account = type_of_account;
		else {
			System.out.println("Invalid type for account");
			return;
		}
		this.balance = balance;
		this.roi = roi;
	}

	void depositAmount(double amt) {
		this.balance += amt;
	}

	void withdrawAmount(double amt) {
		if (this.balance < amt) {
			System.out.println("Not enough money in the account.");
			return;
		}
		this.balance -= amt;
	}

	void display() {
		System.out.println("Name: " + this.name);
		System.out.println("Account number: " + this.account_number);
		System.out.println("Type of account: " + this.type_of_account);
		System.out.println("Balance: Rs. " + this.balance);
		System.out.println("Rate of interest: " + this.roi);
		System.out.println();
	}

	static void getROI() {
		System.out.println(roi);
	}
}

class BATester {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		BankAccount a = new BankAccount();
		a.display();

		System.out.println("Enter details for a new bank account: ");
		String name_temp = sc.nextLine();
		int acc_num = sc.nextInt();
		sc.nextLine();
		String type = sc.nextLine();
		double amt = sc.nextDouble();
		double roi_temp = sc.nextDouble();
		BankAccount b = new BankAccount(name_temp, acc_num, type, amt, roi_temp);
		b.display();

		System.out.println("Enter an amount to deposit in b: ");
		b.depositAmount(sc.nextDouble());
		b.display();
		System.out.println("Enter an amoun to withdraw from b: ");
		b.withdrawAmount(sc.nextDouble());
		b.display();
		System.out.println("Enter an amount to withdraw from a: ");
		a.withdrawAmount(sc.nextDouble());
		a.display();

		System.out.println("ROI of bank is: " + BankAccount.roi);
		BankAccount.getROI();
	}
}
	