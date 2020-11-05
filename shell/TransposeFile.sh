#!/bin/bash
# 转置文件
# 假设 nowcoder.txt 内容如下：
# job salary
# c++ 13
# java 14
# php 12

# 你的脚本应当输出（以词频升序排列）：
# job c++ java php
# salary 13 14 12

awk '{
    for (i=1;i<=NF;i++){
        if (NR==1){
            res[i]=$i
        }
        else{
            res[i]=res[i]" "$i
        }
    }
}END{
    for(j=1;j<=NF;j++){
        print res[j]
    }
}' nowcoder.txt

