#!/bin/bash
# 写一个 bash脚本以实现一个需求，去掉输入中含有this的语句，把不含this的语句输出
sed '/this/d'
grep -vwi this; #-v反向匹配（不匹配）， -w(精确搜索，*表示*不是任意字符的意思), -i 显示匹配行

