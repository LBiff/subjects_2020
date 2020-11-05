#!/bin/bash
# 写一个 bash脚本以统计一个文本文件 nowcoder.txt中字母数小于8的单词。

awk '{for(i=1; i <= NF; i++) if(length($i) < 8) print $i}' nowcoder.txt
