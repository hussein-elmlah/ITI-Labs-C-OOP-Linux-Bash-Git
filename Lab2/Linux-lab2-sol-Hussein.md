### 1. Create a user account with the following attribute
### • username: islam
### • Fullname/comment: Islam Askar
### • Password: islam

sudo useradd -c "Islam Askar" -md /home/islam islam

### 2. Create a user account with the following attribute
### • Username: baduser
### • Full name/comment: Bad User
### • Password: baduser

sudo useradd -c "Bad User" -md /home/baduser baduser
sudo passwd baduser

### 3. Create a supplementary (Secondary) group called pgroup with group ID of 30000

sudo groupadd -g 3000 pgroup

### 4. Create a supplementary group called badgroup:

sudo groupadd badgroup

### 5. Add islam user to the pgroup group as a supplementary group

sudo usermod -G pgroup islam

### 6. Modify the password of islam's account to password

sudo passwd islam

### 7. Modify islam's account so the password expires after 30 days

sudo chage -M 30 islam
or
sudo passwd -x 30 islam

### 8. Lock bad user account so he can't log in

sudo passwd -l baduser

### 9. Delete bad user account

sudo userdel -r baduser

### 10. Delete the supplementary group called badgroup.

sudo groupdel badgroup


### 13-Create a folder called myteam in your home directory and change its permissions to
read only for the owner.

mkdir myteam
ls -ld myteam
chmod u=r myteam
ls -ld myteam

### 14-Log out and log in by another user

su - islam

### 15-Try to access (by cd command) the folder (myteam)
cd /home/hussein/myteam
//  permission denied

### 16-Using the command Line
### a-Change the permissions of oldpasswd file to give owner read and write
### permissions and for group write and execute and execute only for the others
### (using chmod in 2 different ways)

su - hussein
// method1
chmod u=rw,g=wx,o=x oldpasswd
// method2
chmod 631 oldpasswd

### b-Change your default permissions to be as above.

// method1
umask 146
// method2
umask -S u=rw,g=wx,o=x 

### c-What is the maximum permission a file can have, by default when it is just
### created? And what is that for directory.

file max default 666
dir max default 777

### d- Change your default permissions to be no permission to everyone then create a
### directory and a file to verify.

umask 777
mkdir dirtest1
touch filetest1

### 17-What are the minimum permission needed for:
### a- Copy a directory (permission for source directory and permissions for target
### parent directory)

if not Empty:
source_dir:r-x    target_parent_dir:-wx
If Empty Directory: 
source_dir:r--    target_parent_dir:-wx

### b- Copy a file (permission for source file and and permission for target parent
directory)

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

-w- permission only using echo (write only editors)
rw- permission to modify with nano, vim (interactive editors)

### 18. Create a file with permission 444. Try to edit in it and to remove it? Note what
Happened.

touch filetest
chmod 444 filetest

readonly file is unwritable
readonly file can be deleted

### 19. What is the difference between the “x” permission for a file and for a
directory?

For a file : to run the file(execute the codes inside the file)
for a directory : to enter the directory with cd
