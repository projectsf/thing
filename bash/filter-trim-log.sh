#!/bin/sh
#========================================================================
#        FILE: filter-trim-log.sh
#
#       USAGE: filter-trim-log.sh <log-file-name> <severity-level> <output-length>
#
# DESCRIPTION: Instructions:
#              o Provides a filtered and fixed length transform of an input log file
#
#  ARGUMENTS:
#              o log-file-name  -- log file name
#              o severity-level -- desired severity level of log messages captures
#                               -- (error || warning || info || debug)
#              o output-length  -- output length in bytes
#
#      AUTHOR: Scott Maroney
#
#============================================================================

log_file_name=$1
severity_level=$2
output_length=$3

cat $log_file_name | grep -i $severity_level | tail -c $output_length

