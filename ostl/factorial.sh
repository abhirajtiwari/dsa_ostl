#!/bin/bash
echo "Enter a number to find the factorial: "
read n
prod=1
while [ $n -ge 1 ]
do
prod=`expr $n \* $prod`
n=`expr $n - 1`
done
echo Factorial is $prod
