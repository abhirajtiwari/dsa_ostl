#include <stdio.h>
#include <stdlib.h>

typedef struct {
	float re;
	float im;
} COMPLEX;

COMPLEX add(COMPLEX a, COMPLEX b) {
	COMPLEX answer;
	answer.re = a.re + b.re;
	answer.im = a.im + b.im;
	return answer;
}

COMPLEX subtract(COMPLEX a, COMPLEX b) {
	COMPLEX answer;
	answer.re = a.re - b.re;
	answer.im = a.im - b.im;
	return answer;
}

COMPLEX multiply(COMPLEX a, COMPLEX b) {
	COMPLEX answer;
	answer.re = (a.re*b.re) - (a.im*b.im);
	answer.im = (a.re*b.im) + (a.im*b.re);
	return answer;
}

int main() {

}