echo "Enter the limit : "
read n
x=0
y=1
for((i=1;i<=$n;i++))
do
	echo $x
	t=$(($x+$y))
	x=$y
	y=$t
	
done

