#!/bin/sh
#========================================================================
#        FILE: duplicate-reports.sh
#
#       USAGE: duplicate-reports.sh [number-reports] [reference-report-name]
#
# DESCRIPTION: 
#              o generates number-report duplicates of a reference-report-name
#              o reference-report-name is expected to follow the following convention
#                -- $i + '-' + $j + '-' + $k, where $i, $j and $k are unsigned integral values
#              o duplicates will be named with the following convention
#                -- $i + '-' + $j + '-' + $index, where index is an increment unsigned integral value from 1..number-reports
#
#  ARGUMENTS:
#              o number-reports -- number of duplicates to create
#              o reference-report-name -- name of reference report that is duplicated 
#
#      AUTHOR: Scott Maroney
#
#============================================================================

if [ $# -ne 2 ]
then
	echo "Usage: 'duplicate-reports.sh [number-reports] [reference-report-name]' "
	exit
fi

number_reports=$1
reference_report_name=$2;

######################################
# strip off field following last '-'
######################################
base_report_name=$(echo $reference_report_name | sed 's/\([[:digit:]]*\)-\([[:digit:]]*\)-\([[:digit:]]*\)/\1-\2-/')

##################################################
# generate duplicate files from reference file
#################################################
for (( ii = 0; ii < $number_reports; ii++ ))
do
	file=$base_report_name$ii;
	cp $reference_report_name $file;
done


