#!/bin/bash
# 写一个 bash脚本以输出一个文本文件 nowcoder.txt中的行数
# 知识点: wc -l（行数）c（字节数）w（字数）， 语法 wc [args] file1, file2...



wc -l nowcode.txt  会输出: 9 nowcode.txt, 只需要检出行数
wc -l nowcode.txt | awk '{print $1}'
wc -l < nowcode.txt
