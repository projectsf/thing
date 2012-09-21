#!/bin/sh
#========================================================================
#        FILE: convert-csv-to-wiki.sh
#
#       USAGE: convert-csv-to-wiki.sh <file-name>
#
# DESCRIPTION: Instructions:
#              o Converts a csv formatted file to a wiki formatted file
#
#  ARGUMENTS:
#              o file-name -- csv file name
#
#      AUTHOR: Scott Maroney
#
#============================================================================

file_name=$1

sed \
	-e 's/\"//g' \
	-e 's/\,,/||/g' \
	-e 's/\,/||/g' \
	-e 's/^/||/' \
	$file_name



