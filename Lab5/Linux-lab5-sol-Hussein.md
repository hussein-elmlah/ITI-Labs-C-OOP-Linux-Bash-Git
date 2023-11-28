### 1- Compress a file by compress, gzip, zip commands and decompress it again. State the
### differences between compress and gzip commands.

compress filetest3
uncompress filetest3
gzip filetest3
gunzip filetest3
zip filetest3.tar  filetest3
unzip filetest3.tar 

In general Compress will run faster and use less memory, but gzip will generally reach significantly higher levels of compression.

### 2- What is the command used to view the content of a compressed file.
zcat

### 3- Backup /etc directory using tar utility.

sudo tar -cvf etcBackup.tar /etc

### 4- Starting from your home directory, find all files that were modified in the last two day.

find ~ -type f -mtime -2

### 5- Starting from /etc, find files owned by root user.

find /etc -type f -user root

### 6- Find all directories in your home directory.

find ~ -type d

### 7- Write a command to search for all files on the system that, its name is “.profile”. (???)

find / -type f -name .profile

### 8- Identify the file types of the following: /etc/passwd, /dev/pts/0, /etc, /dev/sda

file /etc/passwd    ->  file
file /dev/pts/0    ->  Character special file
file /etc    ->  directory
file /dev/sda    ->  Block special file
//or using  ls -l filePath

### 9- List the inode numbers of /, /etc, /etc/hosts.

ls -id /   : 128
ls -id /etc   : 100663425
ls -id /etc/hosts   : 100666287

### 10- Copy /etc/passwd to your home directory, use the commands diff and cmp, and Edit in the
### file you copied, and then use these commands again, and check the output.

cp /etc/passwd ~
Befor Editing:
diff passwd /etc/passwd
cmp passwd /etc/passwd
no output as the 2 files is identical
After Editing :
diff passwd /etc/passwd
output-> 2d1 as edit to make files identical
cmp passwd /etc/passwd
output-> passwd /etc/passwd differ: byte 33, line 2

### 11- Create a symbolic link of /etc/passwd in /boot.

sudo ln -s /etc/passwd /boot/passwdsoftlink

### 12- Create a hard link of /etc/passwd in /boot. Could you? Why?

sudo ln /etc/passwd /boot/passwdhardlink
No I couldn’t > Different Partitions (Invalid cross-device link)

