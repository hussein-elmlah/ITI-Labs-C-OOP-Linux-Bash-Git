### 1. Using vi write your CV in the file mycv. Your CV should include your name, age,
### school,college, experience,…

![lab3 q1](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/546c1513-c9ca-4eae-9e5c-14f93d91893d)


### 2. Open mycv file using vi command then: Without using arrows state how to:
### a. Move the cursor down one line at time.

In Command mode using ‘j’

### b. Move the cursor up one line at time.

In Command mode using ‘k’

### c. Search for word age

In Command mode using ‘?age’

### d. Step to line 5 (assuming that you are in line 1 and file is more than 5 lines).

In Command mode using ‘:5’

### e. Delete the line you are on and line 5.

In Command mode using dd then :5 dd

### f. How to step to the end of line and change to writing mode in one-step.

In Command mode using ‘A’

### 3. List the available shells in your system.
<br> Cat /etc/shells
<br> chsh -l

### 4. List the environment variables in your current shell.
<br> Printenv
<br> env

### 5. List all of the environment variables for the bash shell.(?؟؟)

set

### 6. What are the commands that list the value of a specific variable?
<br> printenv VARIABLE
<br> echo $VARIABLE

### 7. Display your current shell name.
<br> printenv SHELL
<br> echo $SHELL

### 8. State the initialization files of: sh, ksh, bash.
<br> cat ~/.bash_profile
<br> cat ~/.bashrc

<br> cat /etc/bash_profile
<br> cat /etc/bashrc


### 9. Edit in your profile to display date at login and change your prompt permanently.
<br> vi ~/.bashrc
<br> // add 
<br> PS1="\d"

![lab3 q9 p1](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/5b7ac454-aac2-4281-b727-72b75c37a2e9)



### 10. Execute the following command :
### echo \ then press enter
### What is the purpose of \ ?

<br> escape character allowing special chars to be written

<br> Notice the prompt ”>” what is that? and how can you change it from “>” to “:”.

<br> vim ~/.bashrc
<br> // add 
<br> PS2=”:”

### 11. Create a Bash shell alias named ls for the “ls –l” command

alias LS ='ls -l'
