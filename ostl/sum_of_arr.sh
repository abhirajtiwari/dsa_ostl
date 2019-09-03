#!/bin/bash
echo "Enter the numnber of numbers to enter: "
read n
declare -a nums

echo "Enter the numbers: "
i=0
while [ $i -lt $n ]
do
read nums[$i]
i=$(( $i + 1 ))
done

sum=0
for i in ${nums[*]}
do
sum=$(( $sum + $i ))
done

echo "Sum is $sum"
