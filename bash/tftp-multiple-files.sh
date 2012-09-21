#!/bin/bash
#========================================================================
#        FILE: tftp-multiple-files.sh
#
#       USAGE: tftp-multiple-files.sh [tftp-server-ip]
#
# DESCRIPTION: Instructions:
#              o execute script with root priveleges in /tftpboot
#                $ sudo ./tftp-multiple-files.sh [tftp-server-ip]
#              o follow instructions
#
#  ARGUMENTS:
#              o tftp_sever_ip -- ip address of tftp server
#
#      AUTHOR: Scott Maroney
#
#============================================================================

if [ $# -ne 1 ]
then
	echo "Usage: 'tftp-multiple-files.sh [tftp-server-ip]' "
	exit
fi

tftp_server_ip=$1
input_file="ls-file-list.txt"

#--------------------
# create input file 
#---------------------
touch $input_file
chmod 777 $input_file

#----------------------------------
# prompt and wait for user
#-----------------------------------
echo "------------------------------------------------------"
echo "Execute on device:"
echo "  $ ls -l > $input_file"
echo "  $ tftp -p -r $input_file $tftp_server_ip "
echo "When complete press [ENTER]"
read 


#--------------------
# create file list 
#--------------------
if [ ! -f $input_file ]
then
	echo "$input_file not found"
	exit
fi
sed -e 's/^.\{56\}//' $input_file > file-list.txt

#--------------------
# touch files
#--------------------
while read file ; do
	touch $file
	chmod 777 $file
done < file-list.txt

#------------------------------------
# create tftp put file script
#------------------------------------
touch tftp-put-files.sh
chmod 777 tftp-put-files.sh
echo "#!/bin/sh" > tftp-put-files.sh
sed -e 's/^\(.*\)/tftp -p -r \1 '"$tftp_server_ip"'/' file-list.txt >> tftp-put-files.sh

#----------------------------------
# prompt and wait for user
#-----------------------------------
echo "------------------------------------------------------"
echo "Execute on device:"
echo "  $ tftp -g -r tftp-put-files.sh $tftp_server_ip"
echo "  $ chmod 700 tftp-put-files.sh"
echo "  $ ./tftp-put-files.sh"
echo "When complete press [ENTER]"
read 

#---------------------------------------
# generate archive from file list
#---------------------------------------
tar cjf reports.tar.bz2  --files-from file-list.txt

#--------------------
# cleanup
#--------------------
while read file ; do
	rm $file
done < file-list.txt
rm file-list.txt
rm tftp-put-files.sh

