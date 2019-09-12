import java.util.Scanner;

class InvalidMonthException extends Exception {
	private int value;
	public InvalidMonthException (int value) {
		this.value = value;
	}
	public int getMonth() {
		return this.value;
	}
}

class InvalidDayException extends Exception {
	private int value;
	public InvalidDayException (int value) {
		this.value = value;
	}
	public int getDay() {
		return this.value;
	}
}

class CurrentDate {
	int day;
	int month;
	int year;

	public int createDate(int day, int month, int year) throws InvalidDayException, InvalidMonthException {
		try {
			if (month > 12 || month < 1) throw new InvalidMonthException(month);	
			boolean d31 = false;
			for (int i : new int[] {1, 3, 5, 7, 8, 10, 12}) {
				if (month == i) {
					d31 = true;
					if (day != 31) throw new InvalidDayException(day);
					break;
				}	
			}
			if (!d31) {
				if (day==30) throw new InvalidDayException(day);
				else this.day = day;
			}	
			else this.day = day;
			this.year = year;
			return 8;
		}
		catch (InvalidMonthException me) {
			System.out.println("Invalid Month: " + me.getMonth());
			me.printStackTrace();
		}
		catch (InvalidDayException de) {
			System.out.println("Invalid date for the given month " + de.getDay());
			de.printStackTrace();
		}	
	}
}