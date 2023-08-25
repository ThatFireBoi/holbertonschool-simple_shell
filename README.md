# Simple Shell Project
Creating our version of a command line interpreter: shell.

- This repository includes our version of the Shell: simple Unix command interpreter, replicates the basic functionalities of the simple shell (sh), here we will apply the knowledge that we have acquired during the learning of the programming language C, works with the system call of the Kernel.
- This project is requested by Holberton School.

---------------

## What is the shell?

A Unix shell is a command-line interpreter or shell that provides a command line user interface for Unix-like operating systems. The shell is both an interactive command language and a scripting language, and is used by the operating system to control the execution of the system using shell scripts.

- https://en.wikipedia.org/wiki/Unix_shell

This version of super simple shell support the next built-in

| Command             | Definition                                                                                |
| ------------------- | ----------------------------------------------------------------------------------------- |
| exit            | Exit the shell with the command exit.                                          |
| env                 | Print the environment.                                                                    |

## Difference between a function and a system call

A function is a self-contained block of code that performs a specific task or tasks, while system calls are a mechanism
by which a program can request services from the operating system. System calls provide an interface between user-level
programs and the kernel of the operating system.

## Installation

Use the [git clone](https://github.com/ThatFireBoi/holbertonschool-simple_shell.git) to install this super simple shell.

```bash
git clone https://github.com/ThatFireBoi/holbertonschool-simple_shell.git
```
## Compilation

Your code will be compiled this way:

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
This project works in two different modes, the interactive mode and the non interactive mode.

With the compilation create an executable file that can use to emulate the simple shell like this in interective mode:


```sh
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
And also you can emulate the simple shell like this in non-interactive mode:

```sh
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```
## Flowchart
![shelldraft copy](https://github.com/ThatFireBoi/holbertonschool-simple_shell/assets/130172504/f3f08136-113e-41dd-b26a-a7e27fc4fda4)

### Usage Examples

## Allowed Editors

VI, VIM, EMACS

## List of allowed functions and system calls+

- all functions from string.h
- access (man 2 access)
- chdir (man 2 chdir)
- close (man 2 close)
- closedir (man 3 closedir)
- execve (man 2 execve)
- exit (man 3 exit)
- _exit (man 2 _exit)
- fflush (man 3 fflush)
- fork (man 2 fork)
- free (man 3 free)
- getcwd (man 3 getcwd)
- getline (man 3 getline)
- getpid (man 2 getpid)
- isatty (man 3 isatty)
- kill (man 2 kill)
- malloc (man 3 malloc)
- open (man 2 open)
- opendir (man 3 opendir)
- perror (man 3 perror)
- printf (man 3 printf)
- fprintf (man 3 fprintf)
- vfprintf (man 3 vfprintf)
- sprintf (man 3 sprintf)
- putchar (man 3 putchar)
- read (man 2 read)
- readdir (man 3 readdir)
- signal (man 2 signal)
- stat (__xstat) (man 2 stat)
- lstat (__lxstat) (man 2 lstat)
- fstat (__fxstat) (man 2 fstat)
- strtok (man 3 strtok)
- wait (man 2 wait)
- waitpid (man 2 waitpid)
- wait3 (man 2 wait3)
- wait4 (man 2 wait4)
- write (man 2 write)

## Project Tasks

- Task 0: Provide a Man page, a README and a AUTHORS file for the project.
- Task 1: Write code that passes Betty checkers.
- Task 2: Write a UNIX command line interpreter.
- Task 3: Simple Shell 0.1-Handle command lines with arguments
- Task 4: Simple Shell 0.2-Handle the PATH;fork must not be called if the command does not exist.
- Task 5: Simple Shell 0.3-Implement the exit built-in, that exits the shell.
- Task 6: Simple Shell 0.4-Implement the env built-in, that prints the current environment.

## Contributing
You can contribute with this shell adding some buil-int functions, feel free to make pull request.

## Autors
- [Gabriel Castro](https://github.com/ThatFireBoi)
- [Omar Velez](https://github.com/Natzu83)
