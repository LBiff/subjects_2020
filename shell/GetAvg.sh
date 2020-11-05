#!/bin/sh

# 写一个bash脚本以实现一个需求，求输入的一个的数组的平均值

# 第1行为输入的数组长度N
# 第2~N行为数组的元素，如以下为:

read N
S=0
C=0
while [ $C -lt $N ]; do
    read A
    S=$(($S+$A))
    C=$(($C+1))
done
 
printf "%.3f" $(echo "$S / $N" | bc -l)



