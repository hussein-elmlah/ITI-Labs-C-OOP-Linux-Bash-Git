### 1. Create a user account with the following attribute
### • username: islam
### • Fullname/comment: Islam Askar
### • Password: islam

sudo useradd -c "Islam Askar" -md /home/islam islam

### 2. Create a user account with the following attribute
### • Username: baduser
### • Full name/comment: Bad User
### • Password: baduser

<br> sudo useradd -c "Bad User" -md /home/baduser baduser
<br> sudo passwd baduser

### 3. Create a supplementary (Secondary) group called pgroup with group ID of 30000

sudo groupadd -g 3000 pgroup

### 4. Create a supplementary group called badgroup:

sudo groupadd badgroup

### 5. Add islam user to the pgroup group as a supplementary group

sudo usermod -G pgroup islam

### 6. Modify the password of islam's account to password

sudo passwd islam

### 7. Modify islam's account so the password expires after 30 days

<br> sudo chage -M 30 islam
<br> or
<br> sudo passwd -x 30 islam

### 8. Lock bad user account so he can't log in

sudo passwd -l baduser

### 9. Delete bad user account

sudo userdel -r baduser

### 10. Delete the supplementary group called badgroup.

sudo groupdel badgroup

![lab2 q1-q12](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/22abd11f-3fea-4fd4-a27f-13b82893799e)

### 13-Create a folder called myteam in your home directory and change its permissions to
<br> read only for the owner.

<br> mkdir myteam
<br> ls -ld myteam
<br> chmod u=r myteam
<br> ls -ld myteam

![lab2 q13-](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/2dea3b23-f51e-4a8c-b12d-a2bf5199da7b)


### 14-Log out and log in by another user

su - islam

### 15-Try to access (by cd command) the folder (myteam)
<br> cd /home/hussein/myteam
<br> //  permission denied

### 16-Using the command Line
### a-Change the permissions of oldpasswd file to give owner read and write
### permissions and for group write and execute and execute only for the others
### (using chmod in 2 different ways)

<br> su - hussein
<br> // method1
<br> chmod u=rw,g=wx,o=x oldpasswd
<br> // method2
<br> chmod 631 oldpasswd

### b-Change your default permissions to be as above.

<br> // method1
<br> umask 146
<br> // method2
<br> umask -S u=rw,g=wx,o=x 

### c-What is the maximum permission a file can have, by default when it is just
### created? And what is that for directory.

<br> file max default 666
<br> dir max default 777

### d- Change your default permissions to be no permission to everyone then create a
### directory and a file to verify.

<br> umask 777
<br> mkdir dirtest1
<br> touch filetest1

### 17-What are the minimum permission needed for:
### a- Copy a directory (permission for source directory and permissions for target
### parent directory)

<br> if not Empty:
<br> source_dir:r-x    target_parent_dir:-wx
<br> If Empty Directory: 
<br> source_dir:r--    target_parent_dir:-wx

### b- Copy a file (permission for source file and and permission for target parent directory)

source_dir:--x    target_parent_dir:--wx

### c- Delete a file

no permission - but only the owner and the root can delete files

### d- Change to a directory

--x

### e- List a directory content (ls command)

r--  , but for ls -l we need r-x

### f- View a file content (more/cat command)

r-- permission

### g- Modify a file conten

<br> -w- permission only using echo (write only editors)
<br> rw- permission to modify with nano, vim (interactive editors)

### 18. Create a file with permission 444. Try to edit in it and to remove it? Note what
<br> Happened.

<br> touch filetest
<br> chmod 444 filetest

<br> readonly file is unwritable
<br> readonly file can be deleted

### 19. What is the difference between the “x” permission for a file and for a directory?

<br> For a file : to run the file(execute the codes inside the file)
<br> for a directory : to enter the directory with cd
