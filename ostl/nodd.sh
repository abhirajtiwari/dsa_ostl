#!/bin/bash
echo "Enter value for n: "
read n
i=0
while [ $i -le $n ]
do
if [ `expr $i % 2` != 0 ]
then
echo $i
fi
i=`expr $i + 1`
done
