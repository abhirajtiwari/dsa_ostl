#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    int rollno;
    double cgpa;
} STUDENT;

STUDENT* getStudent () {
    STUDENT* p = (STUDENT *)malloc(sizeof(STUDENT));

    printf("Enter the name of the student: ");
    scanf("%s", p->name);

    printf("Enter roll number: ");
    scanf("%d", &p->rollno);

    printf("Enter cgpa: ");
    scanf("%lf", &p->cgpa);
    printf("\n---------------\n\n");
    return p;
}

void printStudent (STUDENT* p) {
    printf("Name:\t%s\n", p->name);
    printf("Roll No.:%d\n", p->rollno);
    printf("CGPA:\t%lf\n", p->cgpa);
    printf("\n---------------\n\n");
}

void sortStudent (STUDENT** p, int s) {
	STUDENT* temp;
	int swapped = 1;
	for (int i = 0; i<s-1 && swapped==1; ++i) {
		swapped=0;
		if (((*(p+i))->rollno) > ((*(p+i+1))->rollno)) {
			temp=*(p+i);
			*(p+i)=*(p+i+1);
			*(p+i+1)=temp;
			swapped=1;
		}
	}
}

int main() {
    STUDENT** stu_arr;
    printf("Enter number of students: ");
    int n;
    scanf("%d", &n);
    stu_arr = (STUDENT **)calloc(n, sizeof(STUDENT *));
    for (int i = 0; i < n; ++i) *(stu_arr+i) = getStudent();
    printf("Sorted list of students is:\n");
    sortStudent(stu_arr, n);
    for (int i = 0; i < n; ++i)	printStudent(*(stu_arr+i));
}
