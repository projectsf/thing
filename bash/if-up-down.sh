#!/bin/sh
#========================================================================
#        FILE: if-up-down.sh
#
#       USAGE: if-up-down [IF-DOWNTIME] [IF-UPTIME]
#
# DESCRIPTION: Uses iptables to bring an interface up and down
#              at times controlled by input parameters
#
#  ARGUMENTS:
#              o IF-DOWNTIME -- Time in seconds that the IF is held down
#              o IF-UPTIME -- Time in seconds that the IF is help up 
#
#     AUTHOR: Scott Maroney
#
#============================================================================

if [ $# -ne 2 ]
then
	echo "Usage: 'if-up-down [IF-DOWNTIME] [IF-UPTIME]' "
	exit
fi

if_downtime=$1
if_uptime=$2

while [ 1 ]
do
  echo "Bringing down interface for $if_downtime seconds"
  iptables -A INPUT -i wan0  -j DROP
  sleep $if_downtime
  echo "Bringing up interface for $if_uptime seconds"
  iptables -D INPUT -i wan0  -j DROP
  sleep $if_uptime
done
