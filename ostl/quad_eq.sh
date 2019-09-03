#!/bin/bash
echo "Enter a, b and c: "
read a
read b
read c
d=`expr $b \* $b - 4 \* $a \* $c`

if [ $d -ge 0 ]
then 
quad="r"
else
quad="i"
fi

case $quad in
"r")
r1=$(echo "(-1*$b+sqrt($d))/(2*$a)" | bc -l)
r2=$(echo "(-1*$b-sqrt($d))/(2*$a)" | bc -l)
echo "Root1: $r1	Root2: $r2"
;;
"i")
re=$(echo "(-1*$b)/(2*$a)" | bc -l)
im=$(echo "sqrt(-1*$d)/2*$a" | bc -l)
echo "Root1: $re + i$im	Root2: $re - i$im"
;;
esac
