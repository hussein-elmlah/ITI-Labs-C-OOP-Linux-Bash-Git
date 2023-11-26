1. Using vi write your CV in the file mycv. Your CV should include your name, age,
school,college, experience,…







2. Open mycv file using vi command then: Without using arrows state how to:
a. Move the cursor down one line at time.

In Command mode using ‘j’

b. Move the cursor up one line at time.

In Command mode using ‘k’

c. Search for word age

In Command mode using ‘?age’

d. Step to line 5 (assuming that you are in line 1 and file is more than 5 lines).

In Command mode using ‘:5’

e. Delete the line you are on and line 5.

In Command mode using dd then :5 dd

f. How to step to the end of line and change to writing mode in one-step.

In Command mode using ‘A’

3. List the available shells in your system.

Cat /etc/shells
chsh -l

4. List the environment variables in your current shell.

Printenv
env

5. List all of the environment variables for the bash shell.(?)

set

6. What are the commands that list the value of a specific variable?

printenv VARIABLE
echo $VARIABLE

7. Display your current shell name.

printenv SHELL
echo $SHELL

8. State the initialization files of: sh, ksh, bash.

cat ~/.bash_profile
cat ~/.bashrc

cat /etc/bash_profile
cat /etc/bashrc


9. Edit in your profile to display date at login and change your prompt permanently.

vi ~/.bashrc
// add 
PS1="\d"




10. Execute the following command :
echo \ then press enter
What is the purpose of \ ?

escape character allowing special chars to be written

Notice the prompt ”>” what is that? and how can you change it from “>” to “:”.

vim ~/.bashrc
// add 
PS2=”:”

11. Create a Bash shell alias named ls for the “ls –l” command

alias LS ='ls -l'