gcc ex1.c -o ex1
a=0
while [ "$a" -lt 10 ]   
do
   ./ex1
   a=`expr $a + 1`
done


