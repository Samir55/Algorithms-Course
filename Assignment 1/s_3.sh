#! /bin/sh
output=$(./s_1.sh);
echo $output;
$res=$(./s_2.sh <<< "$output");
echo $res;
