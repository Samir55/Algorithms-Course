#! /bin/sh
if [ "$#" = 3 ];
then
output=$((echo $1; echo $2; echo $3) | ./s_1.sh);
res=$((echo $output) | ./s_2.sh);
echo $res;
else
  echo "Error: Arguments count mismatch. use \"./s_3.sh op val1 val2\"";
fi
