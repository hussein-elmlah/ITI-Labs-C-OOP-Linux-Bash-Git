# Lab 2
### 1. Create a script that asks for user name then send a greeting to him.

#!/usr/bin/bash
echo Enter your username :
read username
echo Welcome $username

### 2. Create a script called s1 that calls another script s2 where:
#### a. In s1 there is a variable called x, it's value 5
#### b. Try to print the value of x in s2 by two different ways.

Way1:
script1:
#!/usr/bin/bash
echo script1 started 
export x=5
./script2.sh
script2:
#!/usr/bin/bash
echo script2 started 
echo x = $x

Way2:
script1:
#!/usr/bin/bash
echo script1 started 
x=5
. ./script2.sh
script2:
#!/usr/bin/bash
echo script2 started 
echo x = $x

### 3. Create a script called mycp where:
#### a. It copies a file to another
#!/usr/bin/bash
cp file1 file2
#### b. It copies multiple files to a directory.
#!/usr/bin/bash
cp file1 file2 dir1

### 4. Create a script called mycd where:
#### a. It changed directory to the user home directory, if it is called without arguments.
#### b. Otherwise, it change directory to the given directory.
#!/usr/bin/bash
if [ $# -gt 0 ]
then
cd $1
echo $1
else
cd
echo $HOME
fi

### 5. Create a script called myls where:
#### a. It lists the current directory, if it is called without arguments.
#### b. Otherwise, it lists the given directory.
#!/usr/bin/bash
if [ $# -gt 0 ]
then
ls $1
else
ls
fi

### 6. Enhance the above script to support the following options individually:
#### a. –l: list in long format
#### b. –a: list all entries including the hiding files.
#### c. –d: if an argument is a directory, list only its name
#### d. –i: print inode number
#### e. –R: recursively list subdirectories
#!/usr/bin/bash
if [ $# -gt 1 ]
then
ls $2 $1
elif [ $# -gt 0 ]
then
ls $1
else
ls
fi

### 7. Create a script called mytest where:
#### a. It check the type of the given argument (file/directory)
#### b. It check the permissions of the given argument (read/write/execute)
#!/usr/bin/bash
if [ $# -gt 0 ]
then
if [ -f $1 ]
then
echo "it's a file"
elif [ -d $1 ]
then
echo "it's a dir"
else
echo "error"
fi
if [ -r $1 ]
then
echo "readable"
fi
if [ -w $1 ]
then
echo "writable"
fi
if [ -x $1 ]
then
echo "excutable"
fi
fi

### 8. Create a script called myinfo where:
#### a. It asks the user about his/her logname.
#### b. It print full info about files and directories in his/her home directory
#### c. Copy his/her files and directories as much as you can in /tmp directory.
#### d. Gets his current processes status.
#!/usr/bin/bash
echo Enter your Login name :
read loginName
echo you Entered $loginName
ls -l /home/$loginName
cp -a /home/$loginName/. /tmp/$loginName
ps -u $loginName