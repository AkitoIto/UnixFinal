#!/bin/bash
#X=0.0
#Y=0.0
counter=1
inCircle=0
until [ $counter -gt $1 ]
do
  #generate random x and y
  X=`awk -v seed=$RANDOM 'BEGIN{srand(seed);print rand()}'`
  Y=`awk -v seed=$RANDOM 'BEGIN{srand(seed);print rand()}'`
  distance1=$(echo "$X * $X" | bc)
  distance2=$(echo "$Y * $Y" | bc)
  #calculate distance
  distance=$(echo "sale=2;sqrt($distance1 + $distance2)" | bc)
  
  #check if it landed on circle or not
  check=$(echo $distance'>'1.0 | bc)

  #landed on circle
  if [ $check -eq 0 ]
  then
    ((inCircle++))
  fi
  
  ((counter++))
done

division=$(echo "$inCircle / $1" | bc -l)
pi=$(echo "4 * $division" | bc -l)
echo "Pi: $pi"