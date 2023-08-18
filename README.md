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

### Usage Examples

## Contributing
You can contribute with this shell adding some buil-int functions, feel free to make pull request.

## Autors
- [Gabriel Castro](https://github.com/ThatFireBoi)
- [Omar Velez](https://github.com/Natzu83)
