#!/bin/bash

PID=$(pgrep -f bash)

if [ -z "$PID" ]; then
    echo "minishell is not running."
    exit 1
fi

echo "Monitoring minishell (PID=$PID)..."

while ps -p "$PID" > /dev/null; do
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
    lsof -p $(pgrep -f bash) 
    sleep 1
done

echo "minishell (PID=$PID) has exited."