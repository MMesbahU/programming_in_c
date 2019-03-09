#!/bin/bash
## bash test.sh 
isprmC=$1
isprmB=$2
for i in 1.4 a {-1..200}; 
do 
	echo $i
	a=`$isprmC $i`
 	b=`$isprmB $i`
	if [ "$a" != "$b" ]; then 
		echo "value not equal: $a $b "
		exit 1
	fi

done


