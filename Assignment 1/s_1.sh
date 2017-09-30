#! /bin/sh
read op
read  val1
read  val2
if [ "$op" -eq 0 ]
then
	echo $(expr $val1 + $val2);
elif [ "$op" -eq 1 ]
then
	echo $(expr $val1 \* $val2);
elif [ "$op" -eq 2 ]
then
	echo $(expr $val1 / $val2 );
fi
