#!/bin/bash

#################################################################
# lastrace.sh
#    Trace system calls and signals on program passed as argument
# anthony.legrand
# 02 May 2022
#################################################################

SYSCALLS="read,write,clone,execve,wait4,waitpid,pipe,kill,alarm,sigaction,sigsuspend,sigprocmask,shmget,semget,socket,poll"
REGEX='^|\bread\b|write|clone|exec|wait4|waitpid|pipe|kill|alarm|sigaction|sigsuspend|sigprocmask|shmget|semget|socket|poll'
FILENAME=.lastrace.out

if [ $# -eq 0 ]; then
    echo $0 Error: executable file should be provided >&2
    exit 1
fi

if [ ! -x "$1" ]; then
    echo $0 Error: $1 is not an executable file >&2
    exit 1
fi

prog="$1"
if [[ ! "$1" =~ ^(\./|/) ]]; then
    prog="./"$1
fi

i=1
args=($*)
str=""
while [ $i -lt $# ]; do
    str=$str" ${args[i]}"
    ((i++))
done

# Execute program $prog and trace syscalls
strace -f -o $FILENAME -e trace=$SYSCALLS "$prog" $str

# Print tracing results
YELLOW='\033[1;36m'
NC='\033[0m' # No Color
echo -e "\n${YELLOW}Traced syscalls and signals on $prog:${NC}\n"

cat $FILENAME | awk '{$1="[PID="$1"]"}1' | egrep --color -E $REGEX
echo

rm $FILENAME
