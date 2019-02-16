echo '0'
bison -d -y 1505080.y

echo '1'
g++ -w -c -o y.o y.tab.c
#g++ -w -c -o y.o y.tab.c -g

echo '2'
flex 1505080.l

echo '3'
g++ -fpermissive -w -c -o l.o lex.yy.c
#g++ -fpermissive -w -c -o l.o lex.yy.c -g

# if the above command doesn't work try g++ -fpermissive -w -c -o l.o lex.yy.c

echo '4'
g++ -o a.out y.o l.o -lfl -ly
#g++ -o a.out y.o l.o -lfl -ly

echo '5'
./a.out input.c
#gdb ./a.out
