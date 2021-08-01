rm -rf ./dist
mkdir dist
cd dist
gcc -c ../src/ll.c ../src/llfunc.c
ar rc libll.a ll.o llfunc.o
rm *.o
cp ../src/*.h .
cd ..