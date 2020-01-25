
int a;
int f(int a){
    return 2*a;
    println(-1);
    a=9;
}

int g(int a, int b){
    int x;
    x=f(a)+a+b;
    return x;
}


void h();


int main(){
    
    int a, b, x;

    a = 5;
    b = 7;

    x = g(a, b);
    println(x); //22


    println(a+b);   //12
    println(a-b);   //-2
    println(a*b);   //35
    println(a/b);   //0
    println(a%b);   //5

    b=0;

    println(a&&b);  //0
    println(a||b);  //1

    int c[5];
    c[2] = 4;



    println(f(c[2]));   //8


    c[2]++;

    c[1] = 6;

    println(c[2]*c[1]); //30
    println( !(c[2]>c[1]) ); //1

    println(!c[2]); //0

    for(b = 0; b<=c[2]; b++)
        println(b); //0, 1, 2, 3, 4, 5


    h();    //-2

    b = 0;
    while(b<c[2]){
        println(b);
        b=b+2;  //0, 2, 4
    }

    if(c[2]>=6){
        println(1);
    }
    else{
        println(2); //2
    }

    for(b=0; b < c[2]; b++){
        x = 0;
        while(x<2){
            println(b*x);   //0, 0, 0, 1, 0, 2, 0, 3, 0, 4 
            x++;
        }
    }


    //return 0; //does not work


}


void h(){
    int x;
    x = 2;
    println(-x);
}
