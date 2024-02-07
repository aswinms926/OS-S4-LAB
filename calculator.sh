echo "Enter two numbers "
read a
read b

echo "Enter 1)add 2) substrct 3) mutiply 4) Divide "
read op
 case $op in 
 1) rs=$(($a+$b))
 echo "sum is : $rs ";;
 2) rs=$(($a-$b))
 echo "difference is : $rs ";;
 3) rs=$(($a*$b))
 echo "result is : $rs ";;
 4) rs=$(($a/$b))
 echo "result is : $rs ";;
 *)
 echo "wrong command ";;
 esac

