#!/bin/bash


# 以上内容是通过ps aux | grep -v 'RSS TTY' 命令输出到nowcoder.txt文件下面的
# 请你写一个脚本计算一下所有进程占用内存大小的和:
# USER       PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
# root         1  0.0  0.0   8936   308 ?        Ssl  11:52   0:00 /init
# root         9  0.0  0.0   8936   216 tty1     Ss   11:52   0:00 /init
# biff        10  0.0  0.0  16784  3384 tty1     S    11:52   0:00 -bash
# biff        39  0.0  0.0  17384  1920 tty1     R    11:58   0:00 ps aux

awk '{sum = sum + $6}; END {print sum}' nowcoder.txt