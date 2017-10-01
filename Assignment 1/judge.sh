#! /bin/sh

# Compile the file to be in $1 variable.
program_to_be_judged="temp";
compile_result=$(g++ $1 -o $program_to_be_judged);

# Compile the test generator cpp.
test_cases_generator_source="TestCasesGenerator.cpp";
test_cases_generator_exec_name="test_cases_generator";
g++ $test_cases_generator_source -o $test_cases_generator_exec_name

# Run the program_to_be_judged exe for each input. Remove program_to_be_judged_output file if found.
test_cases_input="testcases.in";
program_to_be_judged_output="output.out"
rm $program_to_be_judged_output;
while read in; do echo $in | ./$program_to_be_judged >> $program_to_be_judged_output; done < $test_cases_input;

# Check result and print number of different lines.
test_cases_output="testcases.out";
diffs_count=$(diff -U 0 $test_cases_output $program_to_be_judged_output | grep ^@ | wc -l);

echo Diffs count is $diffs_count;
