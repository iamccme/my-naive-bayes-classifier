#!/bin/sh

FILES=`ls */* |grep [0-9]`

for FF in $FILES
do
    iconv -f GB2312 -t utf-8 $FF > $FF.utf-8
done

rm -rf */*.txt
