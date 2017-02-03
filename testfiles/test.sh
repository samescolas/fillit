echo "valid files: \n"
for FILE in ./v*
do
	echo "\nfile: $FILE"
	./fillit $FILE
done

echo "\n\ninvalid files: \n"
for FILE in ./i*
do
	./fillit $FILE
done
