#!/bin/bash
# 给定一个 nowcoder.txt文件，其中有3列信息，如下实例，编写一个sheel脚本来检查文件第二列是否有重复，且有几个重复，
# 并提取出重复的行的第二列信息：
awk '{print $2}' nowcoder.txt | sort | uniq -cd |sort

# uniq -c统计重复次数 -d打印重复行