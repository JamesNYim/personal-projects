# Totally Safe And Not A Ransomware

## Description
This program goes through all the files in the directory and encrypts the contents using RSA. If the key file is
present in the directory then the files will be decrypted.

## Usage
Ensure that the 'rsa' folder is in the same folder as the executable. In terminal use the command './JamNJelly' 
or click on the executable 'JamNJelly' using a GUI. 

## Encrypting
This program will encrypt all the files in the current directory. This program is not able to encrypt outside the
current directory. It will also not be able to encrypt into directories. It uses the rsa encryption algorithim.

## Decrypting
To decrpyt files make a file with the name 'Jam.paid' and run the program. The program will only decrypt files with the
prefix 'Jelly.'. It will then delete the file 'Jam.paid'.

## Credit
UCSC CSE13s: Assignment 5
GeeksForGeeks
