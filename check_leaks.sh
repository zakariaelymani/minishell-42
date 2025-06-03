#!/bin/bash

# Compile Minishell with debugging flags
echo "Compiling Minishell with -g flag for Valgrind..."
make re CFLAGS="-g -fsanitize=address"

# Clear the screen
clear

# Path to your Minishell binary
MINISHELL=./minishell

# Run Valgrind with leak check
echo "Running Minishell under Valgrind..."
<<<<<<< HEAD
valgrind --leak-check=full  --track-origins=yes --log-file=valgrind_report.txt $MINISHELL

echo "Done. Check valgrind_report.txt for detailed leak info."--leak-ckeck=full
=======
valgrind --leak-check=full --track-origins=yes --log-file=valgrind_report.txt $MINISHELL

echo "Done. Check valgrind_report.txt for detailed leak info."

>>>>>>> refs/remotes/origin/merged
