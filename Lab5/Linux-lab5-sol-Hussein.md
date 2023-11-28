### 1- Compress a file by compress, gzip, zip commands and decompress it again. State the
### differences between compress and gzip commands.
<br> compress filetest3
<br> uncompress filetest3
<br> gzip filetest3
<br> gunzip filetest3
<br> zip filetest3.tar  filetest3
<br> unzip filetest3.tar 

In general Compress will run faster and use less memory, but gzip will generally reach significantly higher levels of compression.

### 2- What is the command used to view the content of a compressed file.
zcat

### 3- Backup /etc directory using tar utility.
sudo tar -cvf etcBackup.tar /etc

![lab5 q1-3](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/cc4f6261-5a88-4f3a-ae4a-7700abaef41d)


### 4- Starting from your home directory, find all files that were modified in the last two day.
find ~ -type f -mtime -2

### 5- Starting from /etc, find files owned by root user.

find /etc -type f -user root

### 6- Find all directories in your home directory.
find ~ -type d

### 7- Write a command to search for all files on the system that, its name is “.profile”. (???)
find / -type f -name .profile

### 8- Identify the file types of the following: /etc/passwd, /dev/pts/0, /etc, /dev/sda
<br> file /etc/passwd    ->  file
<br> file /dev/pts/0    ->  Character special file
<br> file /etc    ->  directory
<br> file /dev/sda    ->  Block special file
<br> //or using  ls -l filePath

![lab5 q8](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/e6286185-87d1-4d8b-847a-ae63557a8a5f)


### 9- List the inode numbers of /, /etc, /etc/hosts.
<br> ls -id /   : 128
<br> ls -id /etc   : 100663425
<br> ls -id /etc/hosts   : 100666287

### 10- Copy /etc/passwd to your home directory, use the commands diff and cmp, and Edit in the
### file you copied, and then use these commands again, and check the output.
<br> cp /etc/passwd ~
<br> Before Editing:
<br> diff passwd /etc/passwd
<br> cmp passwd /etc/passwd
<br> no output as the 2 files is identical
<br> After Editing :
<br> diff passwd /etc/passwd
<br> output-> 2d1 as edit to make files identical
<br> cmp passwd /etc/passwd
<br> output-> passwd /etc/passwd differ: byte 33, line 2

### 11- Create a symbolic link of /etc/passwd in /boot.
sudo ln -s /etc/passwd /boot/passwdsoftlink

### 12- Create a hard link of /etc/passwd in /boot. Could you? Why?
<br> sudo ln /etc/passwd /boot/passwdhardlink
<br> No I couldn’t > Different Partitions (Invalid cross-device link)

![lab5 q9-12](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/a243cabf-ca8c-46e2-9a87-ab1b2ca553d8)
