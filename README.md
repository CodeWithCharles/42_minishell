# Minishell

## Introduction

Minishell is an assignement given by the 42 school.
The main purpose of this project is to create a rather simple shell.
Feature list below.

## Features

### Mandatory

- [ ] Display a prompt when waiting for a new command
- [ ] Have a working history
- [ ] Search and launch the right executable (base on the PATH variable or using a relative or an absolute path)
- [ ] Avoid using more than one global variable to indicate a received signal.
- [ ] Not interpret unclosed quotes or special characters which are not required by the subject such as \ or ;
- [ ] Handle single-quote '
- [ ] Handle double-quote "

- [ ] Implement redirections
    - [ ] < should redirect input.
    - [ ] > should redirect output.
    - [ ] << should be given a delimiter, then read the input until a line containing the delimiter is seen. It doesn't have to update the history.
    - [ ] >> should redirect output in append mode.

- [ ] Implement pipes ( | ). The output of each command in the pipeline is connected to the input of the next command via pipe.
- [ ] Handle environment variables ($ followed by a sequence of characters) which should expand to their values.
- [ ] Handle $? which should expand to the exit status of the most recently executed foreground pipeline.
- [ ] Handle ctrl-C, ctrl-D, and ctrl-\ which should behave like in bash.

- [ ] Your shell must implement the following builtins :
    - [ ] echo with option -n 
    - [ ] cd with only a relative or absolute path 
    - [ ] pwd with no options
    - [ ] export with no options
    - [ ] unset with no options
    - [ ] env with no options or arguments
    - [ ] exit with no options

### Bonus part

- [ ] You must implement && and || along with parenthesis priorities.
- [ ] Wildcards ( * ) should work for the current directory.


