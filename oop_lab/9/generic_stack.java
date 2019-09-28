import java.util.*;	

class StackUnderflowError extends Exception {}
class StackDSOverflowError extends Exception {}

class Stack<T> {
	private T[] st;
	private int top = -1;
	private int max;

	Stack(T[] input) {
		this.max = input.length;
		st = input;
	}

	public void pushStack(T ele) throws StackDSOverflowError {
		if (this.isFull())
			throw new StackDSOverflowError();
		st[++top] = ele;
	}

	public T popStack() throws StackUnderflowError {
		if (this.isEmpty())
			throw new StackUnderflowError();
		T temp = this.st[top];
		this.st[top--] = null;
		return temp;
	}

	public T getElementAt(int i) {
		return this.st[i];
	}

	public T peekStack() {
		return this.st[this.top];
	}

	public void printStack() {
		System.out.println();
		for (int i = this.top; i >= 0; --i) {
			System.out.println(st[i].toString());
		}
		System.out.println();
	}

	public boolean isEmpty() {
		return (top == -1) ? true : false;
	}

	public boolean isFull() {
		return (top == max-1) ? true : false;
	}
}

class Student {
	String name;
	Student(String name) {this.name = name;}
	@Override
	public String toString() {
		return name;
	}
}

class Employee {
	String name;
	Employee(String name) {this.name = "e_" + name;}
	@Override
	public String toString() {
		return name;
	}
}

class StackTester {
	public static void main(String[] args) {
		Student[] stuarr = new Student[5];
		Employee[] emparr = new Employee[5];
		Stack<Student> stustack = new Stack<Student>(stuarr);
		Stack<Employee> empstack = new Stack<Employee>(emparr);
		try {
			System.out.println("----------Student Test----------");
			stustack.pushStack(new Student("Abhiraj"));
			stustack.pushStack(new Student("abc"));
			stustack.pushStack(new Student("xyz"));
			stustack.printStack();
			System.out.println("Element popped: " + stustack.popStack().toString());
			stustack.printStack();

			System.out.println("----------Employee Test----------");
			empstack.pushStack(new Employee("Abhiraj"));
			empstack.pushStack(new Employee("abc"));
			empstack.pushStack(new Employee("xyz"));
			empstack.printStack();
			System.out.println("Element popped: " + empstack.popStack().toString());
			empstack.printStack();
			for (; ; )
				stustack.pushStack(new Student("hi"));
		}
		catch (Exception e) {e.printStackTrace();}
	}
}	
