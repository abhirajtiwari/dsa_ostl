#!/bin/bash
echo "Enter a string to check if it is palindrome: "
read input
n=`expr length $input`
i=1
palindrome=true
while [ $i -le `expr $n / 2` ]
do 
if [ `expr substr $input $i 1` != `expr substr $input $(( $n + 1 - $i )) 1` ]
then 
palindrome=false
fi
i=`expr $i + 1`
done
if $palindrome
then
echo "The string is a palindrome"
else
echo "The string is not a palindrome"
fi
