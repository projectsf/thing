#!/bin/bash
#========================================================================
#        FILE: flac2mp3.sh
#
#       USAGE: flac2mp3.sh
#
# DESCRIPTION: Converts flac files to mp3 file.  Execute in directory
#              containing flac files.  mp3 files are written in same directory.
#
#
#  ARGUMENTS:
#
#      AUTHOR: Scott Maroney
#
#============================================================================
for a in *.flac

do
OUTF=`echo "$a" | sed s/\.flac$/.mp3/g`

ARTIST=`metaflac "$a" --show-tag=ARTIST | sed s/.*=//g`
TITLE=`metaflac "$a" --show-tag=TITLE | sed s/.*=//g`
ALBUM=`metaflac "$a" --show-tag=ALBUM | sed s/.*=//g`
GENRE=`metaflac "$a" --show-tag=GENRE | sed s/.*=//g`
TRACKNUMBER=`metaflac "$a" --show-tag=TRACKNUMBER | sed s/.*=//g`
DATE=`metaflac "$a" --show-tag=DATE | sed s/.*=//g`

flac -c -d "$a" | lame --preset cbr 320 - --tt "$TITLE" --tn "${TRACKNUMBER:-0}" --ta "$ARTIST" --tl "$ALBUM" --ty "$DATE" --tg "${GENRE:-12}" "$OUTF"

done
