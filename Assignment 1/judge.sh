#! /bin/sh
# Check if arguments are found.
if [ "$#" = 1 ];
then
# Compile the file to be in $1 variable.
program_to_be_judged="temp";
compile_result=$(g++ $1 -o $program_to_be_judged);

# Check if file compiled succesfully.
if [ "$?" = 0 ];
then
# Compile and run the test generator cpp.
test_cases_generator_source="TestCasesGenerator.cpp";
test_cases_generator_exec_name="test_cases_generator";
g++ $test_cases_generator_source -o $test_cases_generator_exec_name;
./$test_cases_generator_exec_name; # Execute the test generator exe to get testcases.in and testcases.out files.

# Run the program_to_be_judged for each input.
test_cases_input="testcases.in";
program_to_be_judged_output="output.out"
while read in; do echo $in | ./$program_to_be_judged >> $program_to_be_judged_output; done < $test_cases_input; # Pass each line(test case) to the program and write output in it's output file.

# Check result and print number of different lines.
test_cases_output="testcases.out";
judge_output_array=($(cat $test_cases_output));
program_output_array=($(cat $program_to_be_judged_output));
i=0;
matched_count=0;
while [ $i -lt 100 ]; do
  if [ ${judge_output_array[i]} = ${program_output_array[i]} ]; then
    let matched_count+=1;
  fi
  let i+=1;
done

# Remove any created files.
$(unlink $test_cases_generator_exec_name);
$(unlink $program_to_be_judged);
$(unlink $test_cases_input);
$(unlink $test_cases_output);
$(unlink $program_to_be_judged_output);

# Print verdict.
if [ $matched_count -eq 100 ]; then
  echo "VERDICT: Accepted"
  echo "Number of matches " $matched_count;
else
  echo "VERDICT: Wrong answer"
  echo "user output:" $matched_count "expected: 100";
  echo "Number of mismatches " $(expr 100 - $matched_count);
fi

else
  echo "VERDICT: Compilation error"
fi

else
  echo "Error: Arguments count mismatch. use \"./judge.sh source_code_to_be_checked\"";
fi
