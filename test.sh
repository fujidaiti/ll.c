cd test
rm -f ./test.out
gcc -o test.out ./test.c ../src/ll.c
./test.out
cd ..