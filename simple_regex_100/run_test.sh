program_name='simple_regex';
if gcc -Wall -Werror -O "$program_name.c" -o "$program_name.op"; then
  for f in tests/*.in
  do
    outputf=`echo "$f" | sed 's/in$/out/'`;
    expected_output=`cat "$outputf"`;
    my_output=`"./$program_name.op" < $f`;
    if [[ $my_output == $expected_output ]]; then
      echo "passed test: $f";
    else
      echo "Failed test: $f";
      echo "Your output: $my_output";
      echo "Expected output: $expected_output";
      echo "You can perform the test by running: \"./$program_name.op\" < $f";
      exit 1;
    fi
  done;
  echo "All test passed, you are awesome!";
else
  echo 'Compilation failed!';
  exit 1;
fi
