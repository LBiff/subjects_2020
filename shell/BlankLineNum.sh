#!/bin/bash
# 写一个 bash脚本以输出一个文本文件 nowcoder.txt中空行的行号,可能连续,从1开始
# 知识点： awk逐行正则匹配，打印行号NR
# awk '/^$/ {print NR}' nowcoder.txt