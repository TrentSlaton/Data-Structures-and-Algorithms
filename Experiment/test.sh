#!/bin/sh
# I'm a newbie shell scripter, so this could be done 1000 times better I'm sure


# MERGE SORT
i=0
while [ $i -lt 100 ]
do
	./a.out -mt 1000000 >> mergeresults
	i=$((i+1))
done

awk -F ':' '{
	for(i=1; i<100; i++) {sum+=$i; sumsq+=$i^2}
	printf("Mean: %f\tStddev: %f\n", sum/100, sqrt((sumsq-sum^2/100)/100))
}' mergeresults > tmp

echo "Merge Sort: 1M random integers, 100 iterations." >> results
tail -1 tmp >> results
echo "" >> results

rm tmp
rm mergeresults


# QUICK SORT
i=0
while [ $i -lt 100 ]
do
	./a.out -qt 1000000 >> quickresults
	i=$((i+1))
done

awk -F ':' '{
	for(i=1; i<100; i++) {sum+=$i; sumsq+=$i^2}
	printf("Mean: %f\tStddev: %f\n", sum/100, sqrt((sumsq-sum^2/100)/100))
}' quickresults > tmp

echo "Quick Sort: 1M random integers, 100 iterations." >> results
tail -1 tmp >> results
echo "" >> results

rm tmp
rm quickresults


# INSERTION SORT
i=0
while [ $i -lt 100 ]
do
	./a.out -it 10000 >> insertionresults
	i=$((i+1))
done

awk -F ':' '{
	for(i=1; i<100; i++) {sum+=$i; sumsq+=$i^2}
	printf("Mean: %f\tStddev: %f\n", sum/100, sqrt((sumsq-sum^2/100)/100))
}' insertionresults > tmp

echo "Insertion Sort: 1M random integers, 100 iterations." >> results
tail -1 tmp >> results
echo "" >> results

rm tmp
rm insertionresults


# SELECTION SORT
i=0
while [ $i -lt 100 ]
do
	./a.out -qt 10000 >> selectionresults
	i=$((i+1))
done

awk -F ':' '{
	for(i=1; i<100; i++) {sum+=$i; sumsq+=$i^2}
	printf("Mean: %f\tStddev: %f\n", sum/100, sqrt((sumsq-sum^2/100)/100))
}' selectionresults > tmp

echo "Selection Sort: 1M random integers, 100 iterations." >> results
tail -1 tmp >> results
echo "" >> results

rm tmp
rm selectionresults


# BUBBLE SORT
i=0
while [ $i -lt 100 ]
do
	./a.out -bt 10000 >> bubbleresults
	i=$((i+1))
done

awk -F ':' '{
	for(i=1; i<100; i++) {sum+=$i; sumsq+=$i^2}
	printf("Mean: %f\tStddev: %f\n", sum/100, sqrt((sumsq-sum^2/100)/100))
}' bubbleresults > tmp

echo "Bubble Sort: 1M random integers, 100 iterations." >> results
tail -1 tmp >> results

rm tmp
rm bubbleresults
