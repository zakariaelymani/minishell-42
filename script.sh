#!/bin/bash

<<<<<<< HEAD
PID=$(pgrep -f ./minishell)
=======
PID=$(pgrep -f bash)
>>>>>>> merged

if [ -z "$PID" ]; then
    echo "minishell is not running."
    exit 1
fi

echo "Monitoring minishell (PID=$PID)..."

<<<<<<< HEAD
while ps "$PID" > /dev/null; do
=======
while ps -p "$PID" > /dev/null; do
>>>>>>> merged
    echo "=============================="
    echo "Time: $(date)"
    echo "PID: $PID"

    echo "CPU and MEM:"
    ps -p "$PID" -o pid,%cpu,%mem,command

    echo -n "Open files: "
    lsof -p "$PID" | wc -l

    echo -n "Memory usage (RSS KB): "
    ps -p "$PID" -o rss=

    sleep 9
    echo -n "FD Count: "
<<<<<<< HEAD
    lsof -p $(pgrep -f ./minishell) 
=======
    lsof -p $(pgrep -f bash) 
>>>>>>> merged
    sleep 1
done

echo "minishell (PID=$PID) has exited."