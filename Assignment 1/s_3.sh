#! /bin/sh
output=$((echo $1; echo $2; echo $3) | ./s_1.sh);
res=$((echo $output) | ./s_2.sh);
echo $res;
