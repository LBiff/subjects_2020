#!/bin/bash

# 写一个 bash脚本以输出一个文本文件 nowcoder.txt 中第5行的内容。
# 知识点： sed
# sed在处理文本时是逐行读取文件内容，读到匹配的行就根据指令做操作，不匹配就跳过。
# 非交互流式文本编辑器，可以对文本文件进行增、删、改、查等操作，支持按行、按字段、
# 按正则匹配文本内容，灵活方便，特别适合于大文件的编辑

# sed [args] file 或者 sed [args] -f command_file file
# sed +选项  ‘指令’ 文件
sed -n '5p' nowcoder.txt;

