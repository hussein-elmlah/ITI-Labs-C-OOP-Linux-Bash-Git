1- Install CentOS /RHEL
//  RHEL installation done.
2- What is the difference between cat and more command?
//  cat: display all file.  more:display file page by page.
3- What is the difference between rm and rmdir using man?
//  rm for dir can't remove not-empty directory but rmdir can remove it.
4-Create the following hierarchy under your home directory:
a. Remove dir11 in one-step. What did you notice? And how did you overcome that?
b. Then remove dir12 using rmdir –p command. State what happened to the
hierarchy (Note: you are in your home directory).
c. The output of the command pwd was /home/user. Write the absolute
and relative path for the file mycv

mkdir dir1
cd ./dir1
mkdir dir11 dir12
cd dir11
touch file1
cd
touch mycv

a-
rmdir ~/dir1/dir11
//  failed to remove when directory not empty.
rm -r ~/dir1/dir11
//  remove directory whatever empty or not.

b-
rmdir -p dir1/dir12
//  remove directory and it's ancestors when ancestors empty.(removed dir1 also).

c-
absolute path: ~/docs/mycv
relative path: docs/mycv

5- Copy the /etc/passwd file to your home directory making its name is mypasswd.
cp /etc/passwd ~/mypasswd

6- Rename this new file to be oldpasswd.
mv ~/mypasswd ~/oldpasswd

7-You are in /usr/bin, list four ways to go to your home directory
cd
cd ~
cd /home/hussein
cd ../../home/hussen

![lab1 q1-q7](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/5ce50b3c-7d74-4fcb-86ac-a74f85e10c6b)


8-List Linux commands in /usr/bin that start with letter w
cd /usr/bin
ls w*

9-Display the first 4 lines of /etc/passwd
head -4 /etc/passwd

10-Display the last 7 lines of /etc/passwd
tail -7 /etc/passwd

![lab1 q8-q10](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/89a57a16-f7c0-4633-8e80-7e6ff8dace11)


11-Display the man pages of passwd the command and the file sequentially in one command.
man passwd file

12-Display the man page of the passwd file.
man -s 5 passwd

###13-Display a list of all the commands that contain the keyword passwd in their man page.
man -K passwd

![lab1 q11-q13](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/39ae59b3-9f93-4a9e-8717-0db75d4f5afc)


