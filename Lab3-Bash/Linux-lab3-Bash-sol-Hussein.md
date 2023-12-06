# Lab 3
### 1. Write a script called mycase, using the case utility to checks the type of character
### entered by a user:
### a. Upper Case.
### b. Lower Case.
### c. Number.
### d. Nothing.

<br> #! /usr/bin/bash
<br> shopt -s extglob
<br> export LC_COLLAT=C
<br> read -p "Enter Input : " var 
case <br> $var in
<br> [a-z] ) echo "lower case" ;;
<br> [A-Z] ) echo "upper case" ;;
<br> [0-9] ) echo "integer" ;;
<br> *) echo "nothing"
<br> esac

![shell-lab3 q1](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/e4c1ec14-4030-4e19-a97d-a6894e866070)

### 2. Enhanced the previous script, by checking the type of string entered by a user:
### a. Upper Cases.
### b. Lower Cases.
### c. Numbers.
### d. Mix.
### e. Nothing.

<br> #! /usr/bin/bash
<br> shopt -s extglob
<br> export LC_COLLAT=C
<br> read -p "Enter Input : " var 
<br> case $var in
<br> +([a-z]) ) echo "lower case" ;;
<br> +([A-Z]) ) echo "upper case" ;;
<br> +([0-9]) ) echo "number" ;;
<br> +([a-zA-Z0-9]) ) echo "mix" ;;
<br> *) echo "nothing"
<br> esac

![shell-lab3 q2](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/56904628-80bf-402d-a56f-ee6bf6085f21)

### 3. Write a script called mychmod using for utility to give execute permission to all files and
### directories in your home directory.

<br> #! /usr/bin/bash
<br> if [ $# -gt 0 ]
<br> then
<br> for var in ls $1/*
<br> do
<br> chmod u+x $var
<br> #echo $var
<br> done
<br> echo "changed sucessfully"
<br> else
<br> echo "no directory entered"
<br> fi

![shell-lab3 q3](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/25572492-e8cc-4034-82ad-cfa3a18fa538)

### 4. Write a script called mybackup using for utility to create a backup of only files in your home directory.

<br> #!/bin/bash
<br> # Define the source directory to check
<br> source_dir="$HOME/"
<br> <br> # List of files to include in the backup
<br> file_array=()
<br> # Iterate over the contents of the source directory
<br> for file in "$source_dir"/*; do
  <br> # Check if it is a regular file (not a directory)
  <br> if [ -f "$file" ]; then
    <br> # Add the file name to the array
    <br> file_array+=("$file")
  <br> fi
<br> done
<br> # Check if there are files to backup
<br> if [ ${#file_array[@]} -eq 0 ]; then
  <br> echo "No files found to backup."
  <br> exit 1
<br> fi
<br> # Define the backup destination directory
<br> backup_dir="$HOME/"
<br> # Create a filename with the current date
<br> backup_filename="backup_$(date +'%Y%m%d').tar.gz"
<br> # Create the backup using tar with the files from the array
<br> tar -czvf "$backup_dir/$backup_filename" "${file_array[@]}"
<br> # Check if the backup was successful
<br> if [ $? -eq 0 ]; then
  <br> echo "Backup completed successfully. Backup file: $backup_dir/$backup_filename"
<br> else
  <br> echo "Backup failed. Please check for errors."
<br> fi

![shell-lab3 q4](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/c23d02bf-ae41-4046-977c-33e1b8610112)

### 5. Write a script called mymail using for utility to send a mail to all users in the system.
### Note: write the mail body in a file called mtemplate.

<br> #! /usr/bin/bash
<br> temp_file="mtemplate"
<br> for var in cut -f1 -d: /etc/passwd
<br> do mail -s "greeting" $var <$temp_file
<br> done
<br> echo "mails sent"

![shell-lab3 q5](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/658bd354-a756-4394-82c2-659d1e2ccc35)

### 6. Write a script called chkmail to check for new mails every 10 seconds. Note: mails are saved in /var/mail/username.

<br> #!/bin/bash
<br> # Define the username for which you want to check mail
<br> username="$(whoami)"
<br> # Define the mail spool directory
<br> mail_dir="/var/mail/$username"
<br> # Initialize the last check time
<br> last_check_time=$(date +%s)
<br> # Function to check for new mails
<br> check_mail() {
  <br> new_mail_count=$(find "$mail_dir" -type f -newermt "@$last_check_time" 2>/dev/null | wc -l)
  <br> echo "New mails for $username: $new_mail_count"
<br> }
<br> # Continuously check for new mails every 10 seconds
<br> while true; do
  <br> check_mail
  <br> last_check_time=$(date +%s)
  <br> sleep 10
<br> done

![shell-lab3 q6](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/da10879e-aafe-4dc9-8980-e02afaffd089)

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

![shell-lab3 q7](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/b3c24c29-18c0-42a1-b54b-ace6fa37b363)

### 8. Create the following menu:
### a. Press 1 to ls
### b. Press 2 to ls –a
### c. Press 3 to exit
### Using select utility then while utility.

<br> #!/bin/bash
 <br> let flag=0
 <br> get_choice() {
   <br> select choice in "ls" "ls -a" "exit"; do
    <br> case $choice in
      <br> "ls")
        <br> echo "Executing ls"
        <br> ls
        <br> ;;
      <br> "ls -a")
        <br> echo "Executing ls -a"
        <br> ls -a
        <br> ;;
      <br> "exit")
        <br> echo "Exiting the script."
        <br> let flag=1
        <br> ;;
      <br> *)
        <br> echo "Invalid choice. Please enter a number between 1 and 3."
        <br> ;;
    <br> esac
    <br> break
  <br> done
<br> }
 <br> while [ $flag -eq 0 ]; do
 <br> echo "make a choice : "
 <br> get_choice
 <br> done
 
![shell-lab3 q8](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/6d7b5538-2d1e-4c76-bcb7-17167d21b2e7)

### 9. Write a script called myarr that ask a user how many elements he wants to enter in an
### array, fill the array and then print it.

<br> #!/bin/bash
<br> # Ask the user for the number of elements
<br> read -p "Enter the number of elements in the array: " num_elements
<br> # Check if the input is a positive integer
<br> if [[ ! $num_elements =~ ^[1-9][0-9]*$ ]]; then
  <br> echo "Invalid input. Please enter a positive integer."
<br> else
<br> # Declare an array
<br> declare -a my_array
<br> # Fill the array with user input
<br> for ((i = 0; i < num_elements; i++)); do
  <br> read -p "Enter element $((i + 1)): " element
  <br> my_array[i]=$element
<br> done
<br> # Print the array
<br> echo "Array elements:"
<br> for element in "${my_array[@]}"; do
  <br> echo "$element"
<br> done
<br> fi

![shell-lab3 q9](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/41d37944-dd96-40b6-805a-a8a123ccfa25)

### 10.Write a script called myavg that calculate average of all numbers entered by a user.
### Note: use arrays

<br> #!/bin/bash
<br> # Ask the user for the number of elements
<br> read -p "Enter the number of elements in the array: " num_elements
<br> # Check if the input is a positive integer
<br> if [[ ! $num_elements =~ ^[1-9][0-9]*$ ]]; then
  <br> echo "Invalid input. Please enter a positive integer."
<br> else
<br> # Declare an array
<br> declare -a my_array
<br> sum=0
<br> # Fill the array with user input
<br> for ((i = 0; i < num_elements; i++)); do
  <br> read -p "Enter element $((i + 1)): " element
  <br> my_array[i]=$element
<br>   sum=$((sum + element))
<br> done
<br> # Print the avg
<br> echo "Array avg:"
<br> avg=$(echo "scale=2; $sum / $num_elements" | bc)
<br> echo "array average = $avg"
<br> fi

![shell-lab3 q10](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/73cfa733-e0e0-4fc9-b4d9-799530f564a0)

### 11.Write a function called mysq that calculate square if its argument.

<br> #!/bin/bash
<br> # Define the mysq function
<br> mysq() {
  <br> local num=$1
  <br> local result=$((num * num))
  <br> echo "Square of $num is $result"
<br> }
<br> # Ask the user for a number
<br> read -p "Enter a number: " user_input
<br> # Check if the input is a valid number
<br> if [[ "$user_input" =~ ^[0-9]+$ ]]; then
  <br> # Call the mysq function with the user's input
  <br> mysq "$user_input"
<br> else
  <br> echo "Invalid input. Please enter a valid number."
<br> fi

![shell-lab3 q11](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/56fb07b7-be30-487b-bba3-1229b10ed920)


