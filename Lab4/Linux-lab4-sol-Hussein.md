### 1- List the user commands and redirect the output to /tmp/commands.list
ls /usr/bin /usr/sbin > /tmp/commands.list

### 2-Count the number of user commands
wc -w /tmp/commands.list

### 3-Get all the users names whose first character in their login is ‘g’.
cut /etc/passwd -f1 -d: | grep '^g'

### 4-Get the logins name and full names (comment) of logins starts with “g”.
cut /etc/passwd -f1,5 -d: | grep '^g'

### 5-Save the output of the last command sorted by their full names in a file.
cut /etc/passwd -f1,5 -d: | grep '^g' | sort -k 2 -t: -o users-g.list

### 6-Write two commands: first: to search for all files on the system that named
### .bash_profile. Second: sorts the output of ls command on / recursively, Saving
### their output and error in 2 different files and sending them to the background.
### a-
sudo find / -name .bash_profile &
### b-
ls -R / > ls-output.list 2> ls-error.list &
// need sorting.

### 7-Display the number of users who is logged now to the system.
who | wc -l

### 8-Display lines 7 to line 10 of /etc/passwd file
head /etc/passwd | tail -4

### 9-What happens if you execute:
### - cat filename1 | cat filename2
### - ls | rm
### - ls /etc/passwd | wc –l
### a-
display filename2 only
### b-
rm: missing operand
Try 'rm --help' for more information.
### c-
displays 1 
because ls with a file gives only the file path.

### 10-Issue the command sleep 100.
sleep 100

### 11-Stop the last command.
// ctrl+z

### 12-Resume the last command in the background
bg %5

### 13-Issue the jobs command and see its output.
jobs

### 14-Send the sleep command to the foreground and send it again to the background.
fg %5
ctrl+z
bg %5

### 15-Kill the sleep command.
kill -SIGKILL %5

### 16-Display your processes only
ps -u

### 17-Display all processes except yours
ps aux | grep -v $(whoami)

### 18-Use the pgrep command to list your processes only
pgrep -lu $(whoami)

### 19-Kill your processes only.
pkill -u $(whoami)
