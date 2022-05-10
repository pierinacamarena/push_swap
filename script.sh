#! /bin/bash

max=0
test_nb=300
value_nb=100
min_val=1
max_val=800
total=0
for i in `seq 1 $test_nb`
do
	arg=`shuf -i $min_val-$max_val -n $value_nb`
	arg=`echo $arg | sed 's/\n/ /g'`
	current=`./push_swap $arg | wc -l`
    total=`expr $total + $current`
	error=`./push_swap $arg | ./checker_linux $arg`
	if [ $error != "OK" ]
	then
		echo "$arg\n" >> error
	else
		echo "$error\n\n" >> ok
	fi

avg=`expr $total / $test_nb`
done
echo "for $test_nb different tests with $value_nb different random values between $min_val and $max_val:\naverage count of instructions is $avg"