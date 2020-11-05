#!/bin/bash
# 写一个 bash脚本以去掉一个文本文件 nowcoder.txt中的空行/

sed '/^$/d' nowcoder.txt
