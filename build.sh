rm -rf ./dist
mkdir dist
cd dist
gcc -c ../src/ll.c
ar rc libll.a ll.o
rm *.o
cp ../src/*.h .
cd ..