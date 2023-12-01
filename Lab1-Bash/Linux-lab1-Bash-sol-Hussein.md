### Using sed utility
### 1. Display the lines that contain the word “lp” in /etc/passwd file.
sed -n '/lp/p' /etc/passwd
![lab6 q1](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/ab838d23-0edb-4eab-b97f-624e520d980a)

### 2. Display /etc/passwd file except the third line.
sed '3d' /etc/passwd
![lab6 q2](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/3aec32a6-4f04-46f5-8180-849669410c26)

### 3. Display /etc/passwd file except the last line.
sed '$d' /etc/passwd
![lab6 q3](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/a5bf0fbd-f8d7-4283-9f75-d9615e717a8c)

### 4. Display /etc/passwd file except the lines that contain the word “lp”.
sed '/lp/d' /etc/passwd
![lab6 q4](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/f0428458-e139-41cc-9113-9d5aa7bb1e6a)

### 5. Substitute all the words that contain “lp” with “mylp” in /etc/passwd
sed -n 's/lp/mylp/gp' /etc/passwd
![lab6 q5](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/265de89e-48b1-4ec9-9027-be3bf7cde267)

### Using awk utility
### 1. Print full name (comment) of all users in the system.
awk -F: '{print $5}' /etc/passwd
![lab06 awk q1](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/33faf343-3343-49e8-9528-ef11369ab803)


### 2. Print login, full name (comment) and home directory of all users. (Print each line preceded by a line number)
awk -F: '{print NR,$1,$5,$6}' /etc/passwd
![lab06 awk q2](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/921cbc93-f531-49d0-828d-23102d84d0aa)


### 3. Print login, uid and full name (comment) of those uid is greater than 500
awk -F: '{if($3>500) {print $1,$3,$5}}' /etc/passwd
![lab06 awk q3](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/ee97258a-7b6c-4a59-b80b-a949667ad893)


### 4. Print login, uid and full name (comment) of those uid is exactly 500
awk -F: '{if($3==500) {print $1,$3,$5}}' /etc/passwd
![lab06 awk q4](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/7869f37d-5bfd-4d55-9274-6e4a065cf8f8)


### 5. Print line from 5 to 15 from /etc/passwd
awk -n '{ if(NR>=5 && NR<=15){print $0}}' /etc/passwd
![lab06 awk q5](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/351c5958-28da-4742-b17f-6582d26e7f68)


### 6. Change lp to mylp
awk -F: '{for(i=1;i<8;i++){if($i=="lp"){$i="mylp"}} print $0}' /etc/passwd
![lab06 awk q6](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/824ea46f-7562-4852-bcc8-a18cb7ffb255)


### 7. Print all information about greatest uid.
awk -F: 'BEGIN{max=0;content=0}{if(max<$3){max=$3;content=$0}} END{print content}' /etc/passwd
![lab06 awk q7](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/eab854a8-9cc4-4694-b658-003b9ccf45b6)

### 8. Get the sum of all accounts id’s.
awk -F: 'BEGIN{sum=0}{sum=sum+$3} END{print sum}' /etc/passwd
![lab06 awk q8](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/a97edf83-fddc-4a41-bb84-36a4ed7bbcf3)

