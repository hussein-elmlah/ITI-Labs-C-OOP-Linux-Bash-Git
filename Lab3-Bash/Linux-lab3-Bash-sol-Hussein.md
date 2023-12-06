# Lab 3
### 1. Write a script called mycase, using the case utility to checks the type of character
### entered by a user:
### a. Upper Case.
### b. Lower Case.
### c. Number.
### d. Nothing.

#! /usr/bin/bash
shopt -s extglob
export LC_COLLAT=C
read -p "Enter Input : " var 
case $var in
[a-z] ) echo "lower case" ;;
[A-Z] ) echo "upper case" ;;
[0-9] ) echo "integer" ;;
*) echo "nothing"
esac

### 2. Enhanced the previous script, by checking the type of string entered by a user:
### a. Upper Cases.
### b. Lower Cases.
### c. Numbers.
### d. Mix.
### e. Nothing.

#! /usr/bin/bash
shopt -s extglob
export LC_COLLAT=C
read -p "Enter Input : " var 
case $var in
+([a-z]) ) echo "lower case" ;;
+([A-Z]) ) echo "upper case" ;;
+([0-9]) ) echo "number" ;;
+([a-zA-Z0-9]) ) echo "mix" ;;
*) echo "nothing"
esac

### 3. Write a script called mychmod using for utility to give execute permission to all files and
### directories in your home directory.

#! /usr/bin/bash
if [ $# -gt 0 ]
then
for var in ls $1/*
do
chmod u+x $var
#echo $var
done
echo "changed sucessfully"
else
echo "no directory entered"
fi

### 4. Write a script called mybackup using for utility to create a backup of only files in your home directory.

#!/bin/bash
# Define the source directory to check
source_dir="$HOME/"
# List of files to include in the backup
file_array=()
# Iterate over the contents of the source directory
for file in "$source_dir"/*; do
  # Check if it is a regular file (not a directory)
  if [ -f "$file" ]; then
    # Add the file name to the array
    file_array+=("$file")
  fi
done
# Check if there are files to backup
if [ ${#file_array[@]} -eq 0 ]; then
  echo "No files found to backup."
  exit 1
fi
# Define the backup destination directory
backup_dir="$HOME/"
# Create a filename with the current date
backup_filename="backup_$(date +'%Y%m%d').tar.gz"
# Create the backup using tar with the files from the array
tar -czvf "$backup_dir/$backup_filename" "${file_array[@]}"
# Check if the backup was successful
if [ $? -eq 0 ]; then
  echo "Backup completed successfully. Backup file: $backup_dir/$backup_filename"
else
  echo "Backup failed. Please check for errors."
fi

### 5. Write a script called mymail using for utility to send a mail to all users in the system.
### Note: write the mail body in a file called mtemplate.

#! /usr/bin/bash
temp_file="mtemplate"
for var in cut -f1 -d: /etc/passwd
do mail -s "greeting" $var <$temp_file
done
echo "mails sent"

### 6. Write a script called chkmail to check for new mails every 10 seconds. Note: mails are saved in /var/mail/username.

#!/bin/bash
# Define the username for which you want to check mail
username="$(whoami)"
# Define the mail spool directory
mail_dir="/var/mail/$username"
# Initialize the last check time
last_check_time=$(date +%s)
# Function to check for new mails
check_mail() {
  new_mail_count=$(find "$mail_dir" -type f -newermt "@$last_check_time" 2>/dev/null | wc -l)
  echo "New mails for $username: $new_mail_count"
}
# Continuously check for new mails every 10 seconds
while true; do
  check_mail
  last_check_time=$(date +%s)
  sleep 10
done

### Bonus:
### Open a talk session to a certain user when she/he logs into the system.



### 7. What is the output of the following script
### typeset –i n1
### typeset –i n2
### n1=1
### n2=1
### ### while test $n1 –eq $n2
### do
### n2=$n2+1
### print $n1
### if [ $n1 –gt $n2 ]
### then
### break
### else
### continue
### fi
### n1=$n1+1
### print $n2
### done

it will print 1 .

### 8. Create the following menu:
### a. Press 1 to ls
### b. Press 2 to ls –a
### c. Press 3 to exit
### Using select utility then while utility.

#!/bin/bash
 let flag=0
 get_choice() {
   select choice in "ls" "ls -a" "exit"; do
    case $choice in
      "ls")
        echo "Executing ls"
        ls
        ;;
      "ls -a")
        echo "Executing ls -a"
        ls -a
        ;;
      "exit")
        echo "Exiting the script."
        let flag=1
        ;;
      *)
        echo "Invalid choice. Please enter a number between 1 and 3."
        ;;
    esac
    break
  done
}
 while [ $flag -eq 0 ]; do
 echo "make a choice : "
 get_choice
 done

### 9. Write a script called myarr that ask a user how many elements he wants to enter in an
### array, fill the array and then print it.

#!/bin/bash
# Ask the user for the number of elements
read -p "Enter the number of elements in the array: " num_elements
# Check if the input is a positive integer
if [[ ! $num_elements =~ ^[1-9][0-9]*$ ]]; then
  echo "Invalid input. Please enter a positive integer."
else
# Declare an array
declare -a my_array
# Fill the array with user input
for ((i = 0; i < num_elements; i++)); do
  read -p "Enter element $((i + 1)): " element
  my_array[i]=$element
done
# Print the array
echo "Array elements:"
for element in "${my_array[@]}"; do
  echo "$element"
done
fi

### 10.Write a script called myavg that calculate average of all numbers entered by a user.
### Note: use arrays

#!/bin/bash
# Ask the user for the number of elements
read -p "Enter the number of elements in the array: " num_elements
# Check if the input is a positive integer
if [[ ! $num_elements =~ ^[1-9][0-9]*$ ]]; then
  echo "Invalid input. Please enter a positive integer."
else
# Declare an array
declare -a my_array
sum=0
# Fill the array with user input
for ((i = 0; i < num_elements; i++)); do
  read -p "Enter element $((i + 1)): " element
  my_array[i]=$element
  sum=$((sum + element))
done
# Print the avg
echo "Array avg:"
avg=$(echo "scale=2; $sum / $num_elements" | bc)
echo "array average = $avg"
fi

### 11.Write a function called mysq that calculate square if its argument.

#!/bin/bash
# Define the mysq function
mysq() {
  local num=$1
  local result=$((num * num))
  echo "Square of $num is $result"
}
# Ask the user for a number
read -p "Enter a number: " user_input
# Check if the input is a valid number
if [[ "$user_input" =~ ^[0-9]+$ ]]; then
  # Call the mysq function with the user's input
  mysq "$user_input"
else
  echo "Invalid input. Please enter a valid number."
fi