# Lab 2
### 1. Create a script that asks for user name then send a greeting to him.

#!/usr/bin/bash
echo Enter your username :
read username
echo Welcome $username

![shell-lab2 q1](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/8bdda705-0b04-4e8f-8845-fbde14aa8ea7)

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

![shell-lab2 q2-a](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/8d62da2e-cdb2-45bb-9aa0-fc7006c13266)

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

![shell-lab2 q2-b](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/ac6bf346-7259-44e7-83e3-6d90d5e849d5)

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

![shell-lab2 q4](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/324e7b79-9396-4f4e-8a37-0a118f4eb6b7)

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

![shell-lab2 q5](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/aa01ad68-f58d-4813-aff8-a690414d08bc)

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

![shell-lab2 q6](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/9f179bf8-fd37-4afb-afe7-b9244c12410a)

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

![shell-lab2 q7](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/729866e8-3cda-4f78-b1ad-1196d53fa2ff)

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

![shell-lab2 q8](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/a285bac0-f745-4300-a825-fb20c954cd8a)

