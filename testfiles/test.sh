echo "generating fresh puzzles...\n"
for i in 1 2 3 4 5 6 7 8 9 10 11 12
do
	echo "\n\ntesting file v$i...\n"
	time ./fillit "v$i"
done

#echo "valid files: \n"
#for FILE in ./v*
#do
#	echo "\nfile: $FILE"
#	time ./fillit $FILE
#done

echo "\n\ninvalid files: \n"
for FILE in ./i*
do
	./fillit $FILE
done
