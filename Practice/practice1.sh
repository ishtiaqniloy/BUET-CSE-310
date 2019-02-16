echo '1'
flex -o practice1.cpp 1505080.l
echo '2'
g++ practice1.cpp -lfl -o practice1.out
echo '3'
./practice1.out practice2.txt
echo '4'
