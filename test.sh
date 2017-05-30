dcc test_stack.c stack.c -o stack &&

dcc history.c test_history.c stack.c -o history &&

./history < testinput > tmpoutput &&

diff tmpoutput testoutput;

rm tmpoutput;
