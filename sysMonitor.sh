#!/bin/bash
echo "****** HOSTNAME INFORMATION ********"
hostnamectl
echo "****** FILE DISK SPACE USAGE *******"
df -h
echo "****** FREE AND USED MEMORY ********"
free
echo "****** SYSTEM UPTIME AND LOAD ******"
uptime
echo "****** CURRENTLY LOGGED IN USERS *****"
who
echo "**** TOP 5 MEMORY CONSUMER PROCESSES ****"
ps -e0 %mem,%cpu,comm --sort=%mem | head -n 6
echo ""