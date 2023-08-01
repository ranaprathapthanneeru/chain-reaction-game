//code for chain reaction game

#include<simplecpp>
#include<cmath>
int getX(int a){
int x=a/65536;
return x;}
//it gives the x coordinate

int getY(int a){
int y=a%65536;
return y;}
//it gives the y coordinate

int geti(int a){
int i=getY(a)/100;
return i;}
//it specifies the row of the grid in which mouseclick is done

int getj(int a){
int j=getX(a)/100;
return j;}
//it specifies the coloumn of the grid in which mouseclick is done

struct cell{
int cellval;
int ncircles;
Circle c1,c2,c3,c4;};

int score(cell A[8][8]){
int sum=0;
for ( int i=0;i<8;i++){
  for(int j=0;j<8;j++){
    sum+=A[i][j].cellval;
  }}
  return sum;}




void scan(cell A[8][8]);



main_program{
/*initCanvas("chain reaction",1000,800);
//creates a window of size 800x600 with title chain reaction

Text name(500,400,"CHAIN REACTION");
name.scale(3);
//creates text -chain reaction -centred at (500,400)
wait(5);
//makes the window visible for 5 seconds
*/
/*initCanvas("menu",1000,800);
 Rectangle r1(500,250,400,200);
Rectangle r2(500,550,400,200);
//creates two rectangles r1,r2 with centres at (500,300),(500,500)

Text t1(500,250,"PLAY");
Text t2(500,550,"INSTRUCTIONS");
//creates texts PLAY and INSTRUCTIONS in the rectangular tabs

int clickpos=getClick();

if(((300<getX(clickpos))&&(getX(clickpos)<700))&&(150<getY(clickpos))&&(getY(clickpos)<350)){
*/
{int clickpos;
initCanvas("chain reaction",1000,800);
Line l1(100,0,900,0);
Line l2(100,100,900,100);
Line l3(100,200,900,200);
Line l4(100,300,900,300);
Line l5(100,400,900,400);
Line l6(100,500,900,500);
Line l7(100,600,900,600);
Line l8(100,700,900,700);
Line l9(100,800,900,800);

Line l10(100,0,100,800);
Line l11(200,0,200,800);
Line l12(300,0,300,800);
Line l13(400,0,400,800);
Line l14(500,0,500,800);
Line l15(600,0,600,800);
Line l16(700,0,700,800);
Line l17(800,0,800,800);
Line l18(900,0,900,800);

int k,m,n;
cell A[8][8];

for(m=0;m<8;m++){
    for(n=0;n<8;n++){
    A[m][n].ncircles=0;
    A[m][n].cellval=0;
    }}

for(k=1; ;k++){
clickpos=getClick();
int j=geti(clickpos);
int i=getj(clickpos);//test
cout<<i<<j;
  if((k%2!=0)&&(A[i][j].cellval>=0)){
    switch(A[i][j].ncircles){
    case 0: A[i][j].c1.reset(50+100*i,50+100*j,20);
            A[i][j].c1.setFill(true);
            A[i][j].c1.setColor(COLOR("green"));

            A[i][j].ncircles++;
            A[i][j].cellval=1;
            break;
    case 1: A[i][j].c2.reset(50-20*sqrt(2)+100*i,50+20*sqrt(2)+100*j,20);
            A[i][j].c2.setFill(true);
            A[i][j].c2.setColor(COLOR("green"));
            A[i][j].ncircles++;
            A[i][j].cellval=2;
            break;
    case 2: A[i][j].c3.reset(50+20*sqrt(2)+100*i,50-20*sqrt(2)+100*j,20);
            A[i][j].c3.setFill(true);
            A[i][j].c3.setColor(COLOR("green"));
            A[i][j].ncircles++;
            A[i][j].cellval=3;
            break;
    case 3: A[i][j].c4.reset(50+100*i,50+100*j,20);
            A[i][j].c4.setFill(true);
            A[i][j].c4.setColor(COLOR("green"));
            A[i][j].ncircles++;
            A[i][j].cellval=4;
            break;}}
   if((k%2==0)&&((A[i][j].cellval)<=0)){
     switch(A[i][j].ncircles){
    case 0: A[i][j].c1.reset(50+100*i,50+100*j,20);
            A[i][j].c1.setFill(true);
            A[i][j].c1.setColor(COLOR("blue"));
            A[i][j].ncircles++;
            A[i][j].cellval=1;
            break;
    case 1: A[i][j].c2.reset(50-20*sqrt(2)+100*i,50+20*sqrt(2)+100*j,20);
            A[i][j].c2.setFill(true);
            A[i][j].c2.setColor(COLOR("blue"));
            A[i][j].ncircles++;
            A[i][j].cellval=2;
            break;
    case 2: A[i][j].c3.reset(50+20*sqrt(2)+100*i,50-20*sqrt(2)+100*j,20);
            A[i][j].c3.setFill(true);
            A[i][j].c3.setColor(COLOR("blue"));
            A[i][j].ncircles++;
            A[i][j].cellval=3;
            break;
    case 3: A[i][j].c4.reset(50+100*i,50+100*j,20);
            A[i][j].c4.setFill(true);
            A[i][j].c4.setColor(COLOR("blue"));
            A[i][j].ncircles++;
            A[i][j].cellval=4;
            break;}}







       int p=0,q=0;cout<<p<<q;
       scan (&(&A[0])[0]);


for(i=0;i<8;i++){
    for(j=0;j<8;j++){
    if(A[i][j].cellval>=0){p++;}
    if(A[i][j].cellval<=0){q--;}
    if(p==64){Text t1(500,250,"GREEN WINS");
              Text t2(400,550,"SCORE:");
              Text t3(600,550,score(A));break;}
    if(q==-64){Text t4(500,250,"BLUE WINS");
              Text t5(400,550,"SCORE:");
              Text t6(600,550,score(A));break;}}}cout<<"man";

}//for loop ends
}//if
}
//closeCanvas();}main ends
void scan(cell A[8][8]){

if((A[0][0].ncircles)==2){
    switch(A[0][1].ncircles){
    case 0: A[0][1].c1.reset(50+100*0,50+100*1,20);
            A[0][1].c1.setFill(true);//huhuh
            if(A[0][0].cellval>0){A[0][1].c1.setColor(COLOR("green"));A[0][1].cellval=1;}
            else{A[0][1].c1.setColor(COLOR("blue"));A[0][1].cellval=-1;}
            A[0][1].ncircles++;
            break;
    case 1: A[0][1].c2.reset(50-20*sqrt(2)+100*0,50+20*sqrt(2)+100*1,20);
            A[0][1].c2.setFill(true);
            A[0][1].c1.setFill(true);
           if(A[0][0].cellval>0){A[0][1].c2.setColor(COLOR("green"));A[0][1].c1.setColor(COLOR("green"));A[0][1].cellval=2;}
           else{A[0][1].c2.setColor(COLOR("blue"));A[0][1].c1.setColor(COLOR("blue"));A[0][1].cellval=-2;}
            A[0][1].ncircles++;
            break;
    case 2: A[0][1].c3.reset(50+20*sqrt(2)+100*0,50+20*sqrt(2)+100*1,20);
            A[0][1].c3.setFill(true); A[0][1].c2.setFill(true);A[0][1].c1.setFill(true);
            if(A[0][0].cellval>0){A[0][1].c3.setColor(COLOR("green"));
            A[0][1].c2.setColor(COLOR("green"));
            A[0][1].c1.setColor(COLOR("green"));
            A[0][1].cellval=3;}
            else{A[0][1].c3.setColor(COLOR("blue"));
            A[0][1].c2.setColor(COLOR("blue"));
            A[0][1].c1.setColor(COLOR("blue"));
            A[0][1].cellval=-3;}
            A[0][1].ncircles++;
            break;}

    switch(A[1][0].ncircles){
    case 0: A[1][0].c1.reset(50+100*1,50+100*0,20);
            A[1][0].c1.setFill(true);
            if(A[0][0].cellval>0){A[1][0].c1.setColor(COLOR("green"));A[1][0].cellval=1;}
            else{A[1][0].c1.setColor(COLOR("blue"));A[1][0].cellval=-1;}
            A[1][0].ncircles++;
            break;
    case 1: A[1][0].c2.reset(50-20*sqrt(2)+100*1,50+20*sqrt(2)+100*0,20);
            A[1][0].c2.setFill(true);
            A[1][0].c1.setFill(true);
           if(A[0][0].cellval>0){A[1][0].c2.setColor(COLOR("green"));A[1][0].c1.setColor(COLOR("green"));A[1][0].cellval=2;}
           else{A[1][0].c2.setColor(COLOR("blue"));A[1][0].c1.setColor(COLOR("blue"));A[1][0].cellval=-2;}
            A[1][0].ncircles++;
            break;
    case 2: A[1][0].c3.reset(50+20*sqrt(2)+100*1,50+20*sqrt(2)+100*0,20);
            A[1][0].c3.setFill(true); A[1][0].c2.setFill(true);A[1][0].c1.setFill(true);
            if(A[0][0].cellval>0){A[1][0].c3.setColor(COLOR("green"));
            A[1][0].c2.setColor(COLOR("green"));
            A[1][0].c1.setColor(COLOR("green"));
            A[1][0].cellval=3;}
            else{A[1][0].c3.setColor(COLOR("blue"));
            A[1][0].c2.setColor(COLOR("blue"));
            A[1][0].c1.setColor(COLOR("blue"));
            A[1][0].cellval=-3;}
            A[1][0].ncircles++;
            break;}


A[0][0].c1.reset(50+100*0,50+100*0,0);
A[0][0].c2.reset(50-20*sqrt(2)+100*0,50+20*sqrt(2)+100*0,0);
   A[0][0].ncircles=0;
   A[0][0].cellval=0;}


 if(A[7][0].ncircles==2){
    switch(A[7][1].ncircles){
    case 0: A[7][1].c1.reset(50+100*7,50+100*1,20);
            A[7][1].c1.setFill(true);
            if(A[7][0].cellval>0){A[7][1].c1.setColor(COLOR("green"));A[7][1].cellval=1;}
            else{A[7][1].c1.setColor(COLOR("blue"));A[7][1].cellval=-1;}
            A[7][1].ncircles++;
            break;
    case 1: A[7][1].c2.reset(50-20*sqrt(2)+100*7,50+20*sqrt(2)+100*1,20);
            A[7][1].c2.setFill(true);
            A[7][1].c1.setFill(true);
           if(A[7][0].cellval>0){A[7][1].c2.setColor(COLOR("green"));A[7][1].c1.setColor(COLOR("green"));A[7][1].cellval=2;}
           else{A[7][1].c2.setColor(COLOR("blue"));A[7][1].c1.setColor(COLOR("blue"));A[7][1].cellval=-2;}
            A[7][1].ncircles++;
            break;
    case 2: A[7][1].c3.reset(50+20*sqrt(2)+100*7,50+20*sqrt(2)+100*1,20);
            A[7][1].c3.setFill(true); A[7][1].c2.setFill(true);A[7][1].c1.setFill(true);
            if(A[7][0].cellval>0){A[7][1].c3.setColor(COLOR("green"));
            A[7][1].c2.setColor(COLOR("green"));
            A[7][1].c1.setColor(COLOR("green"));
            A[7][1].cellval=3;}
            else{A[7][1].c3.setColor(COLOR("blue"));
            A[7][1].c2.setColor(COLOR("blue"));
            A[7][1].c1.setColor(COLOR("blue"));
            A[7][1].cellval=-3;}
            A[7][1].ncircles++;
            break;}
    switch(A[6][0].ncircles){
    case 0: A[6][0].c1.reset(50+10061,50+100*0,20);
            A[6][0].c1.setFill(true);
            if(A[7][0].cellval>0){A[6][0].c1.setColor(COLOR("green"));A[6][0].cellval=1;}
            else{A[6][0].c1.setColor(COLOR("blue"));A[6][0].cellval=-1;}
            A[6][0].ncircles++;
            break;
    case 1: A[6][0].c2.reset(50-20*sqrt(2)+100*6,50+20*sqrt(2)+100*0,20);
            A[6][0].c2.setFill(true);
            A[6][0].c1.setFill(true);
           if(A[7][0].cellval>0){A[6][0].c2.setColor(COLOR("green"));A[6][0].c1.setColor(COLOR("green"));A[6][0].cellval=2;}
           else{A[6][0].c2.setColor(COLOR("blue"));A[6][0].c1.setColor(COLOR("blue"));A[6][0].cellval=-2;}
            A[6][0].ncircles++;
            break;
    case 2: A[6][0].c3.reset(50+20*sqrt(2)+100*6,50+20*sqrt(2)+100*0,20);
            A[6][0].c3.setFill(true); A[6][0].c2.setFill(true);A[6][0].c1.setFill(true);
            if(A[7][0].cellval>0){A[6][0].c3.setColor(COLOR("green"));
            A[6][0].c2.setColor(COLOR("green"));
            A[6][0].c1.setColor(COLOR("green"));
            A[6][0].cellval=3;}
            else{A[6][0].c3.setColor(COLOR("blue"));
            A[6][0].c2.setColor(COLOR("blue"));
            A[6][0].c1.setColor(COLOR("blue"));
            A[6][0].cellval=-3;}
            A[6][0].ncircles++;
            break;}


A[7][0].c1.reset(50+100*7,50+100*0,0);
A[7][0].c2.reset(50-20*sqrt(2)+100*7,50+20*sqrt(2)+100*0,0);
   A[7][0].ncircles=0;
   A[7][0].cellval=0;}

   if(A[0][7].ncircles==2){
    switch(A[0][6].ncircles){
    case 0: A[0][6].c1.reset(50+100*0,50+100*6,20);
            A[0][6].c1.setFill(true);
            if(A[0][7].cellval>0){A[0][6].c1.setColor(COLOR("green"));A[0][6].cellval=1;}
            else{A[0][6].c1.setColor(COLOR("blue"));A[0][6].cellval=-1;}
            A[0][6].ncircles++;
            break;
    case 1: A[0][6].c2.reset(50-20*sqrt(2)+100*0,50+20*sqrt(2)+100*6,20);
            A[0][6].c2.setFill(true);
            A[0][6].c1.setFill(true);
           if(A[0][7].cellval>0){A[0][6].c2.setColor(COLOR("green"));A[0][6].c1.setColor(COLOR("green"));A[0][6].cellval=2;}
           else{A[0][6].c2.setColor(COLOR("blue"));A[0][6].c1.setColor(COLOR("blue"));A[0][6].cellval=-2;}
            A[0][6].ncircles++;
            break;
    case 2: A[0][6].c3.reset(50+20*sqrt(2)+100*0,50+20*sqrt(2)+100*6,20);
            A[0][6].c3.setFill(true); A[0][6].c2.setFill(true);A[0][6].c1.setFill(true);
            if(A[0][7].cellval>0){A[0][6].c3.setColor(COLOR("green"));
            A[0][6].c2.setColor(COLOR("green"));
            A[0][6].c1.setColor(COLOR("green"));
            A[0][6].cellval=3;}
            else{A[0][6].c3.setColor(COLOR("blue"));
            A[0][6].c2.setColor(COLOR("blue"));
            A[0][6].c1.setColor(COLOR("blue"));
            A[0][6].cellval=-3;}
            A[0][6].ncircles++;
            break;}


    switch(A[1][7].ncircles){
     case 0: A[1][7].c1.reset(50+100*1,50+100*7,20);
            A[1][7].c1.setFill(true);
            if(A[0][7].cellval>0){A[1][7].c1.setColor(COLOR("green"));A[1][7].cellval=1;}
            else{A[1][7].c1.setColor(COLOR("blue"));A[1][7].cellval=-1;}
            A[1][7].ncircles++;
            break;
    case 1: A[1][7].c2.reset(50-20*sqrt(2)+100*1,50+20*sqrt(2)+100*7,20);
            A[1][7].c2.setFill(true);
            A[1][7].c1.setFill(true);
           if(A[0][7].cellval>0){A[1][7].c2.setColor(COLOR("green"));A[1][7].c1.setColor(COLOR("green"));A[1][7].cellval=2;}
           else{A[1][7].c2.setColor(COLOR("blue"));A[1][7].c1.setColor(COLOR("blue"));A[1][7].cellval=-2;}
            A[1][7].ncircles++;
            break;
    case 2: A[1][7].c3.reset(50+20*sqrt(2)+100*1,50+20*sqrt(2)+100*7,20);
            A[1][7].c3.setFill(true); A[1][7].c2.setFill(true);A[1][7].c1.setFill(true);
            if(A[0][7].cellval>0){A[1][7].c3.setColor(COLOR("green"));
            A[1][7].c2.setColor(COLOR("green"));
            A[1][7].c1.setColor(COLOR("green"));
            A[1][7].cellval=3;}
            else{A[1][7].c3.setColor(COLOR("blue"));
            A[1][7].c2.setColor(COLOR("blue"));
            A[1][7].c1.setColor(COLOR("blue"));
            A[1][7].cellval=-3;}
            A[1][7].ncircles++;
            break;}

A[0][7].c1.reset(50+100*0,50+100*7,0);
A[0][7].c2.reset(50-20*sqrt(2)+100*0,50+20*sqrt(2)+100*7,0);
   A[0][7].ncircles=0;
   A[0][7].cellval=0;}


   if(A[7][7].ncircles==2){
    switch(A[7][6].ncircles){
      case 0: A[7][6].c1.reset(50+100*7,50+100*6,20);
            A[7][6].c1.setFill(true);
            if(A[7][7].cellval>0){A[7][6].c1.setColor(COLOR("green"));A[7][6].cellval=1;}
            else{A[7][6].c1.setColor(COLOR("blue"));A[7][6].cellval=-1;}
            A[7][6].ncircles++;
            break;
    case 1: A[7][6].c2.reset(50-20*sqrt(2)+100*7,50+20*sqrt(2)+100*6,20);
            A[7][6].c2.setFill(true);
            A[7][6].c1.setFill(true);
           if(A[7][7].cellval>0){A[7][6].c2.setColor(COLOR("green"));A[7][6].c1.setColor(COLOR("green"));A[7][6].cellval=2;}
           else{A[7][6].c2.setColor(COLOR("blue"));A[7][6].c1.setColor(COLOR("blue"));A[7][6].cellval=-2;}
            A[7][6].ncircles++;
            break;
    case 2: A[7][6].c3.reset(50+20*sqrt(2)+100*7,50+20*sqrt(2)+100*6,20);
            A[7][6].c3.setFill(true); A[7][6].c2.setFill(true);A[7][6].c1.setFill(true);
            if(A[7][7].cellval>0){A[7][6].c3.setColor(COLOR("green"));
            A[7][6].c2.setColor(COLOR("green"));
            A[7][6].c1.setColor(COLOR("green"));
            A[7][6].cellval=3;}
            else{A[7][6].c3.setColor(COLOR("blue"));
            A[7][6].c2.setColor(COLOR("blue"));
            A[7][6].c1.setColor(COLOR("blue"));
            A[7][6].cellval=-3;}
            A[7][6].ncircles++;
            break;}
    switch(A[6][7].ncircles){
    case 0: A[6][7].c1.reset(50+100*6,50+100*7,20);
            A[6][7].c1.setFill(true);
            if(A[7][7].cellval>0){A[6][7].c1.setColor(COLOR("green"));A[6][7].cellval=1;}
            else{A[6][7].c1.setColor(COLOR("blue"));A[6][7].cellval=-1;}
            A[6][7].ncircles++;
            break;
    case 1: A[6][7].c2.reset(50-20*sqrt(2)+100*6,50+20*sqrt(2)+100*7,20);
            A[6][7].c2.setFill(true);
            A[6][7].c1.setFill(true);
           if(A[7][7].cellval>0){A[6][7].c2.setColor(COLOR("green"));A[6][7].c1.setColor(COLOR("green"));A[6][7].cellval=2;}
           else{A[6][7].c2.setColor(COLOR("blue"));A[6][7].c1.setColor(COLOR("blue"));A[6][7].cellval=-2;}
            A[6][7].ncircles++;
            break;
    case 2: A[6][7].c3.reset(50+20*sqrt(2)+100*6,50+20*sqrt(2)+100*7,20);
            A[6][7].c3.setFill(true); A[6][7].c2.setFill(true);A[6][7].c1.setFill(true);
            if(A[7][7].cellval>0){A[6][7].c3.setColor(COLOR("green"));
            A[6][7].c2.setColor(COLOR("green"));
            A[6][7].c1.setColor(COLOR("green"));
            A[6][7].cellval=3;}
            else{A[6][7].c3.setColor(COLOR("blue"));
            A[6][7].c2.setColor(COLOR("blue"));
            A[6][7].c1.setColor(COLOR("blue"));
            A[6][7].cellval=-3;}
            A[6][7].ncircles++;
            break;}
A[7][7].c1.reset(50+100*7,50+100*7,0);
A[7][7].c2.reset(50-20*sqrt(2)+100*7,50+20*sqrt(2)+100*7,0);
   A[7][7].ncircles=0;
   A[7][7].cellval=0;}










for(int n=1;n<7;n++){
    if(A[0][n].ncircles==3){
    switch(A[1][n].ncircles){
    case 0: A[1][n].c1.reset(50+100*1,50+100*n,20);
            A[1][n].c1.setFill(true);
            if(A[0][n].cellval>0){A[1][n].c1.setColor(COLOR("green"));A[1][n].cellval=1;}
            else{A[1][n].c1.setColor(COLOR("blue"));A[1][n].cellval=-1;}
            A[1][n].ncircles++;
            break;
    case 1: A[1][n].c2.reset(50-20*sqrt(2)+100*1,50+20*sqrt(2)+100*n,20);
            A[1][n].c2.setFill(true);
            A[1][n].c1.setFill(true);
           if(A[0][n].cellval>0){A[1][n].c2.setColor(COLOR("green"));A[1][n].c1.setColor(COLOR("green"));A[1][n].cellval=2;}
           else{A[1][n].c2.setColor(COLOR("blue"));A[1][n].c1.setColor(COLOR("blue"));A[1][n].cellval=-2;}
            A[1][n].ncircles++;
            break;
    case 2: A[1][n].c3.reset(50+20*sqrt(2)+100*1,50+20*sqrt(2)+100*n,20);
            A[1][n].c3.setFill(true); A[1][n].c2.setFill(true);A[1][n].c1.setFill(true);
            if(A[0][n].cellval>0){A[1][n].c3.setColor(COLOR("green"));
            A[1][n].c2.setColor(COLOR("green"));
            A[1][n].c1.setColor(COLOR("green"));
            A[1][n].cellval=3;}
            else{A[1][n].c3.setColor(COLOR("blue"));
            A[1][n].c2.setColor(COLOR("blue"));
            A[1][n].c1.setColor(COLOR("blue"));
            A[1][n].cellval=-3;}
            A[1][n].ncircles++;
            break;


     case 3: A[1][n].c4.reset(50+20*sqrt(2)+100*1,50+20*sqrt(2)+100*n,20);
            A[1][n].c4.setFill(true); A[1][n].c3.setFill(true);   A[1][n].c2.setFill(true);  A[1][n].c1.setFill(true);
           if((A[0][n].cellval)>0){ A[1][n].c4.setColor(COLOR("green"));
            A[1][n].c3.setColor(COLOR("green"));
            A[1][n].c2.setColor(COLOR("green"));
            A[1][n].c1.setColor(COLOR("green"));
            A[1][n].cellval=4;}
            else{A[1][n].c4.setColor(COLOR("blue"));
            A[1][n].c3.setColor(COLOR("blue"));
            A[1][n].c2.setColor(COLOR("blue"));
            A[1][n].c1.setColor(COLOR("blue"));
            A[1][n].cellval=-4;}
            A[1][n].ncircles++;
            break;}

    switch(A[0][n-1].ncircles){
    case 0: A[0][n-1].c1.reset(50+100*0,50+100*(n-1),20);
            A[0][n-1].c1.setFill(true);
            if(A[0][n-1].cellval>0){A[0][n-1].c1.setColor(COLOR("green"));A[0][n-1].cellval=1;}
            else{A[0][n-1].c1.setColor(COLOR("blue"));A[0][n-1].cellval=-1;}
            A[0][n-1].ncircles++;
            break;
    case 1: A[0][n-1].c2.reset(50-20*sqrt(2)+100*0,50+20*sqrt(2)+100*(n-1),20);
            A[0][n-1].c2.setFill(true);
            A[0][n-1].c1.setFill(true);
           if(A[0][n-1].cellval>0){A[0][n-1].c2.setColor(COLOR("green"));A[0][n-1].c1.setColor(COLOR("green"));A[0][n-1].cellval=2;}
           else{A[0][n-1].c2.setColor(COLOR("blue"));A[0][n-1].c1.setColor(COLOR("blue"));A[0][n-1].cellval=-2;}
            A[0][n-1].ncircles++;
            break;
    case 2: A[0][n-1].c3.reset(50+20*sqrt(2)+100*0,50+20*sqrt(2)+100*(n-1),20);
            A[0][n-1].c3.setFill(true); A[0][n-1].c2.setFill(true);A[0][n-1].c1.setFill(true);
            if(A[0][n-1].cellval>0){A[0][n-1].c3.setColor(COLOR("green"));
            A[0][n-1].c2.setColor(COLOR("green"));
            A[0][n-1].c1.setColor(COLOR("green"));
            A[0][n-1].cellval=3;}
            else{A[0][n-1].c3.setColor(COLOR("blue"));
            A[0][n-1].c2.setColor(COLOR("blue"));
            A[0][n-1].c1.setColor(COLOR("blue"));
            A[0][n-1].cellval=-3;}
            A[0][n-1].ncircles++;
            break;}

   switch(A[0][n+1].ncircles){
     case 0: A[0][n+1].c1.reset(50+100*0,50+100*(n+1),20);
            A[0][n+1].c1.setFill(true);
            if(A[0][n+1].cellval>0){A[0][n+1].c1.setColor(COLOR("green"));A[0][n+1].cellval=1;}
            else{A[0][n+1].c1.setColor(COLOR("blue"));A[0][n+1].cellval=-1;}
            A[0][n+1].ncircles++;
            break;
    case 1: A[0][n+1].c2.reset(50-20*sqrt(2)+100*0,50+20*sqrt(2)+100*(n+1),20);
            A[0][n+1].c2.setFill(true);
            A[0][n+1].c1.setFill(true);
           if(A[0][n+1].cellval>0){A[0][n-1].c2.setColor(COLOR("green"));A[0][n+1].c1.setColor(COLOR("green"));A[0][n+1].cellval=2;}
           else{A[0][n+1].c2.setColor(COLOR("blue"));A[0][n+1].c1.setColor(COLOR("blue"));A[0][n+1].cellval=-2;}
            A[0][n+1].ncircles++;
            break;
    case 2: A[0][n+1].c3.reset(50+20*sqrt(2)+100*0,50+20*sqrt(2)+100*(n+1),20);
            A[0][n+1].c3.setFill(true); A[0][n+1].c2.setFill(true);A[0][n+1].c1.setFill(true);
            if(A[0][n+1].cellval>0){A[0][n+1].c3.setColor(COLOR("green"));
            A[0][n+1].c2.setColor(COLOR("green"));
            A[0][n+1].c1.setColor(COLOR("green"));
            A[0][n+1].cellval=3;}
            else{A[0][n+1].c3.setColor(COLOR("blue"));
            A[0][n+1].c2.setColor(COLOR("blue"));
            A[0][n+1].c1.setColor(COLOR("blue"));
            A[0][n+1].cellval=-3;}
            A[0][n+1].ncircles++;
            break;}


A[0][n].c1.reset(50+100*0,50+100*n,0);
A[0][n].c2.reset(50-20*sqrt(2)+100*0,50+20*sqrt(2)+100*n,0);
A[0][n].c3.reset(50+20*sqrt(2)+100*0,50-20*sqrt(2)+100*n,0);
   A[0][n].ncircles=0;
   A[0][n].cellval=0;}

 if(A[7][n].ncircles==3){
    switch(A[6][n].ncircles){
       case 0: A[6][n].c1.reset(50+100*6,50+100*n,20);
            A[6][n].c1.setFill(true);
            if(A[7][n].cellval>0){A[6][n].c1.setColor(COLOR("green"));A[6][n].cellval=1;}
            else{A[6][n].c1.setColor(COLOR("blue"));A[6][n].cellval=-1;}
            A[6][n].ncircles++;
            break;
    case 1: A[6][n].c2.reset(50-20*sqrt(2)+100*6,50+20*sqrt(2)+100*n,20);
            A[6][n].c2.setFill(true);
            A[6][n].c1.setFill(true);
           if(A[7][n].cellval>0){A[6][n].c2.setColor(COLOR("green"));A[6][n].c1.setColor(COLOR("green"));A[6][n].cellval=2;}
           else{A[6][n].c2.setColor(COLOR("blue"));A[6][n].c1.setColor(COLOR("blue"));A[6][n].cellval=-2;}
            A[6][n].ncircles++;
            break;
    case 2: A[6][n].c3.reset(50+20*sqrt(2)+100*6,50+20*sqrt(2)+100*n,20);
            A[6][n].c3.setFill(true); A[6][n].c2.setFill(true);A[6][n].c1.setFill(true);
            if(A[7][n].cellval>0){A[6][n].c3.setColor(COLOR("green"));
            A[6][n].c2.setColor(COLOR("green"));
            A[6][n].c1.setColor(COLOR("green"));
            A[6][n].cellval=3;}
            else{A[6][n].c3.setColor(COLOR("blue"));
            A[6][n].c2.setColor(COLOR("blue"));
            A[6][n].c1.setColor(COLOR("blue"));
            A[6][n].cellval=-3;}
            A[6][n].ncircles++;
            break;


     case 3: A[6][n].c4.reset(50+20*sqrt(2)+100*6,50+20*sqrt(2)+100*n,20);
            A[6][n].c4.setFill(true); A[1][n].c3.setFill(true);A[6][n].c2.setFill(true);  A[6][n].c1.setFill(true);
           if((A[7][n].cellval)>0){ A[6][n].c4.setColor(COLOR("green"));
            A[6][n].c3.setColor(COLOR("green"));
            A[6][n].c2.setColor(COLOR("green"));
            A[6][n].c1.setColor(COLOR("green"));
            A[6][n].cellval=4;}
            else{A[6][n].c4.setColor(COLOR("blue"));
            A[6][n].c3.setColor(COLOR("blue"));
            A[6][n].c2.setColor(COLOR("blue"));
            A[6][n].c1.setColor(COLOR("blue"));
            A[6][n].cellval=-4;}
            A[6][n].ncircles++;
            break;}



    switch(A[7][n-1].ncircles){
     case 0: A[7][n-1].c1.reset(50+100*7,50+100*(n-1),20);
            A[7][n-1].c1.setFill(true);
            if(A[7][n].cellval>0){A[7][n-1].c1.setColor(COLOR("green"));A[7][n-1].cellval=1;}
            else{A[7][n-1].c1.setColor(COLOR("blue"));A[7][n-1].cellval=-1;}
            A[7][n-1].ncircles++;
            break;
    case 1: A[7][n-1].c2.reset(50-20*sqrt(2)+100*7,50+20*sqrt(2)+100*(n-1),20);
            A[7][n-1].c2.setFill(true);
            A[7][n-1].c1.setFill(true);
           if(A[7][n].cellval>0){A[7][n-1].c2.setColor(COLOR("green"));A[7][n-1].c1.setColor(COLOR("green"));A[7][n-1].cellval=2;}
           else{A[7][n-1].c2.setColor(COLOR("blue"));A[7][n-1].c1.setColor(COLOR("blue"));A[7][n-1].cellval=-2;}
            A[7][n-1].ncircles++;
            break;
    case 2: A[7][n-1].c3.reset(50+20*sqrt(2)+100*7,50+20*sqrt(2)+100*(n-1),20);
            A[7][n-1].c3.setFill(true); A[7][n-1].c2.setFill(true);A[7][n-1].c1.setFill(true);
            if(A[7][n].cellval>0){A[7][n-1].c3.setColor(COLOR("green"));
            A[7][n-1].c2.setColor(COLOR("green"));
            A[7][n-1].c1.setColor(COLOR("green"));
            A[7][n-1].cellval=3;}
            else{A[7][n-1].c3.setColor(COLOR("blue"));
            A[7][n-1].c2.setColor(COLOR("blue"));
            A[7][n-1].c1.setColor(COLOR("blue"));
            A[7][n-1].cellval=-3;}
            A[7][n-1].ncircles++;
            break;}



   switch(A[7][n+1].ncircles){
    case 0: A[7][n+1].c1.reset(50+100*0,50+100*(n+1),20);
            A[7][n+1].c1.setFill(true);
            if(A[7][n].cellval>0){A[7][n+1].c1.setColor(COLOR("green"));A[7][n+1].cellval=1;}
            else{A[7][n+1].c1.setColor(COLOR("blue"));A[7][n+1].cellval=-1;}
            A[7][n+1].ncircles++;
            break;
    case 1: A[7][n+1].c2.reset(50-20*sqrt(2)+100*0,50+20*sqrt(2)+100*(n+1),20);
            A[7][n+1].c2.setFill(true);
            A[7][n+1].c1.setFill(true);
           if(A[7][n].cellval>0){A[7][n+1].c2.setColor(COLOR("green"));A[7][n+1].c1.setColor(COLOR("green"));A[7][n+1].cellval=2;}
           else{A[7][n+1].c2.setColor(COLOR("blue"));A[7][n+1].c1.setColor(COLOR("blue"));A[7][n+1].cellval=-2;}
            A[7][n+1].ncircles++;
            break;
    case 2: A[7][n+1].c3.reset(50+20*sqrt(2)+100*7,50+20*sqrt(2)+100*(n+1),20);
            A[7][n+1].c3.setFill(true); A[7][n+1].c2.setFill(true);A[7][n+1].c1.setFill(true);
            if(A[7][n].cellval>0){A[7][n+1].c3.setColor(COLOR("green"));
            A[7][n+1].c2.setColor(COLOR("green"));
            A[7][n+1].c1.setColor(COLOR("green"));
            A[7][n+1].cellval=3;}
            else{A[7][n+1].c3.setColor(COLOR("blue"));
            A[7][n+1].c2.setColor(COLOR("blue"));
            A[7][n+1].c1.setColor(COLOR("blue"));
            A[7][n+1].cellval=-3;}
            A[7][n+1].ncircles++;
            break;}


A[7][n].c1.reset(50+100*7,50+100*n,0);
A[7][n].c2.reset(50-20*sqrt(2)+100*7,50+20*sqrt(2)+100*n,0);
A[7][n].c3.reset(50+20*sqrt(2)+100*7,50-20*sqrt(2)+100*n,0);
   A[7][n].ncircles=0;
   A[7][n].cellval=0;}

if(A[n][0].ncircles==3){
    switch(A[n][1].ncircles){
      case 0: A[n][1].c1.reset(50+100*n,50+100*1,20);
            A[n][1].c1.setFill(true);
            if(A[n][0].cellval>0){A[n][1].c1.setColor(COLOR("green"));A[n][1].cellval=1;}
            else{A[n][1].c1.setColor(COLOR("blue"));A[n][1].cellval=-1;}
            A[n][1].ncircles++;
            break;
    case 1: A[n][1].c2.reset(50-20*sqrt(2)+100*n,50+20*sqrt(2)+100*1,20);
            A[n][1].c2.setFill(true);
            A[n][1].c1.setFill(true);
           if(A[n][0].cellval>0){A[n][1].c2.setColor(COLOR("green"));A[n][1].c1.setColor(COLOR("green"));A[n][1].cellval=2;}
           else{A[n][1].c2.setColor(COLOR("blue"));A[n][1].c1.setColor(COLOR("blue"));A[n][1].cellval=-2;}
            A[n][1].ncircles++;
            break;
    case 2: A[n][1].c3.reset(50+20*sqrt(2)+100*n,50+20*sqrt(2)+100*1,20);
            A[n][1].c3.setFill(true); A[n][1].c2.setFill(true);A[n][1].c1.setFill(true);
            if(A[n][0].cellval>0){A[n][1].c3.setColor(COLOR("green"));
            A[n][1].c2.setColor(COLOR("green"));
            A[n][1].c1.setColor(COLOR("green"));
            A[n][1].cellval=3;}
            else{A[n][1].c3.setColor(COLOR("blue"));
            A[n][1].c2.setColor(COLOR("blue"));
            A[n][1].c1.setColor(COLOR("blue"));
            A[n][1].cellval=-3;}
            A[n][1].ncircles++;
            break;


     case 3: A[n][1].c4.reset(50+20*sqrt(2)+100*n,50+20*sqrt(2)+100*1,20);
            A[n][1].c4.setFill(true); A[n][1].c3.setFill(true);A[n][1].c2.setFill(true);  A[n][1].c1.setFill(true);
           if((A[n][0].cellval)>0){ A[n][1].c4.setColor(COLOR("green"));
            A[n][1].c3.setColor(COLOR("green"));
            A[n][1].c2.setColor(COLOR("green"));
            A[n][1].c1.setColor(COLOR("green"));
            A[n][1].cellval=4;}
            else{A[n][1].c4.setColor(COLOR("blue"));
            A[n][1].c3.setColor(COLOR("blue"));
            A[n][1].c2.setColor(COLOR("blue"));
            A[n][1].c1.setColor(COLOR("blue"));
            A[n][1].cellval=-4;}
            A[n][1].ncircles++;
            break;}
    switch(A[n-1][0].ncircles){
    case 0: A[n-1][0].c1.reset(50+100*(n-1),50+100*0,20);
            A[n-1][0].c1.setFill(true);
            if(A[n][0].cellval>0){A[n-1][0].c1.setColor(COLOR("green"));A[n-1][0].cellval=1;}
            else{A[n-1][0].c1.setColor(COLOR("blue"));A[n-1][0].cellval=-1;}
            A[n-1][0].ncircles++;
            break;
    case 1: A[n-1][0].c2.reset(50-20*sqrt(2)+100*(n-1),50+20*sqrt(2)+100*0,20);
            A[n-1][0].c2.setFill(true);
            A[n-1][0].c1.setFill(true);
           if(A[n][0].cellval>0){A[n-1][0].c2.setColor(COLOR("green"));A[n-1][0].c1.setColor(COLOR("green"));A[n-1][0].cellval=2;}
           else{A[n-1][0].c2.setColor(COLOR("blue"));A[n-1][0].c1.setColor(COLOR("blue"));A[n-1][0].cellval=-2;}
            A[n][1].ncircles++;
            break;
    case 2: A[n-1][0].c3.reset(50+20*sqrt(2)+100*(n-1),50+20*sqrt(2)+100*0,20);
            A[n-1][0].c3.setFill(true); A[n-1][0].c2.setFill(true);A[n-1][0].c1.setFill(true);
            if(A[n][0].cellval>0){A[n-1][0].c3.setColor(COLOR("green"));
            A[n-1][0].c2.setColor(COLOR("green"));
            A[n-1][0].c1.setColor(COLOR("green"));
            A[n-1][0].cellval=3;}
            else{A[n-1][0].c3.setColor(COLOR("blue"));
            A[n-1][0].c2.setColor(COLOR("blue"));
            A[n-1][0].c1.setColor(COLOR("blue"));
            A[n-1][0].cellval=-3;}
            A[n-1][0].ncircles++;
            break;}

    switch(A[n+1][0].ncircles){
     case 0: A[n+1][0].c1.reset(50+100*(n+1),50+100*0,20);
            A[n+1][0].c1.setFill(true);
            if(A[n][0].cellval>0){A[n+1][0].c1.setColor(COLOR("green"));A[n+1][0].cellval=1;}
            else{A[n+1][0].c1.setColor(COLOR("blue"));A[n+1][0].cellval=-1;}
            A[n+1][0].ncircles++;
            break;
    case 1: A[n+1][0].c2.reset(50-20*sqrt(2)+100*(n+1),50+20*sqrt(2)+100*0,20);
            A[n+1][0].c2.setFill(true);
            A[n+1][0].c1.setFill(true);
           if(A[n][0].cellval>0){A[n+1][0].c2.setColor(COLOR("green"));A[n+1][0].c1.setColor(COLOR("green"));A[n+1][0].cellval=2;}
           else{A[n+1][0].c2.setColor(COLOR("blue"));A[n+1][0].c1.setColor(COLOR("blue"));A[n+1][0].cellval=-2;}
            A[n+1][0].ncircles++;
            break;
    case 2: A[n+1][0].c3.reset(50+20*sqrt(2)+100*(n+1),50+20*sqrt(2)+100*0,20);
            A[n+1][0].c3.setFill(true); A[n+1][0].c2.setFill(true);A[n+1][0].c1.setFill(true);
            if(A[n][0].cellval>0){A[n+1][0].c3.setColor(COLOR("green"));
            A[n+1][0].c2.setColor(COLOR("green"));
            A[n+1][0].c1.setColor(COLOR("green"));
            A[n+1][0].cellval=3;}
            else{A[n+1][0].c3.setColor(COLOR("blue"));
            A[n+1][0].c2.setColor(COLOR("blue"));
            A[n+1][0].c1.setColor(COLOR("blue"));
            A[n+1][0].cellval=-3;}
            A[n+1][0].ncircles++;
            break;}

A[n][0].c1.reset(50+100*n,50+100*0,0);
A[n][0].c2.reset(50-20*sqrt(2)+100*n,50+20*sqrt(2)+100*0,0);
A[n][0].c3.reset(50+20*sqrt(2)+100*n,50-20*sqrt(2)+100*0,0);
   A[n][0].ncircles=0;
   A[n][0].cellval=0;}



   if(A[n][7].ncircles==3){
    switch(A[n][6].ncircles){
    case 0: A[n][6].c1.reset(50+100*n,50+100*6,20);
            A[n][6].c1.setFill(true);
            if(A[n][7].cellval>0){A[n][6].c1.setColor(COLOR("green"));A[n][6].cellval=1;}
            else{A[n][6].c1.setColor(COLOR("blue"));A[n][6].cellval=-1;}
            A[n][6].ncircles++;
            break;
    case 1: A[n][6].c2.reset(50-20*sqrt(2)+100*n,50+20*sqrt(2)+100*6,20);
            A[n][6].c2.setFill(true);
            A[n][6].c1.setFill(true);
           if(A[n][7].cellval>0){A[n][6].c2.setColor(COLOR("green"));A[n][6].c1.setColor(COLOR("green"));A[n][6].cellval=2;}
           else{A[n][6].c2.setColor(COLOR("blue"));A[n][6].c1.setColor(COLOR("blue"));A[n][6].cellval=-2;}
            A[n][6].ncircles++;
            break;
    case 2: A[n][6].c3.reset(50+20*sqrt(2)+100*n,50+20*sqrt(2)+100*6,20);
            A[n][6].c3.setFill(true); A[n][6].c2.setFill(true);A[n][6].c1.setFill(true);
            if(A[n][7].cellval>0){A[n][6].c3.setColor(COLOR("green"));
            A[n][6].c2.setColor(COLOR("green"));
            A[n][6].c1.setColor(COLOR("green"));
            A[n][6].cellval=3;}
            else{A[n][6].c3.setColor(COLOR("blue"));
            A[n][6].c2.setColor(COLOR("blue"));
            A[n][6].c1.setColor(COLOR("blue"));
            A[n][6].cellval=-3;}
            A[n][6].ncircles++;
            break;


     case 3: A[n][6].c4.reset(50+20*sqrt(2)+100*n,50+20*sqrt(2)+100*6,20);
            A[n][6].c4.setFill(true); A[n][6].c3.setFill(true);A[n][6].c2.setFill(true);  A[n][6].c1.setFill(true);
           if((A[n][7].cellval)>0){ A[n][6].c4.setColor(COLOR("green"));
            A[n][6].c3.setColor(COLOR("green"));
            A[n][6].c2.setColor(COLOR("green"));
            A[n][6].c1.setColor(COLOR("green"));
            A[n][6].cellval=4;}
            else{A[n][6].c4.setColor(COLOR("blue"));
            A[n][6].c3.setColor(COLOR("blue"));
            A[n][6].c2.setColor(COLOR("blue"));
            A[n][6].c1.setColor(COLOR("blue"));
            A[n][6].cellval=-4;}
            A[n][6].ncircles++;
            break;}
    switch(A[n-1][7].ncircles){
     case 0: A[n-1][7].c1.reset(50+100*(n-1),50+100*7,20);
            A[n-1][7].c1.setFill(true);
            if(A[n][7].cellval>0){A[n-1][7].c1.setColor(COLOR("green"));A[n-1][7].cellval=1;}
            else{A[n-1][7].c1.setColor(COLOR("blue"));A[n-1][7].cellval=-1;}
            A[n-1][7].ncircles++;
            break;
    case 1: A[n-1][7].c2.reset(50-20*sqrt(2)+100*(n-1),50+20*sqrt(2)+100*0,20);
            A[n-1][7].c2.setFill(true);
            A[n-1][7].c1.setFill(true);
           if(A[n][7].cellval>0){A[n-1][7].c2.setColor(COLOR("green"));A[n-1][7].c1.setColor(COLOR("green"));A[n-1][7].cellval=2;}
           else{A[n-1][7].c2.setColor(COLOR("blue"));A[n-1][7].c1.setColor(COLOR("blue"));A[n-1][7].cellval=-2;}
            A[n-1][7].ncircles++;
            break;
    case 2: A[n-1][7].c3.reset(50+20*sqrt(2)+100*(n-1),50+20*sqrt(2)+100*7,20);
            A[n-1][7].c3.setFill(true); A[n-1][7].c2.setFill(true);A[n-1][7].c1.setFill(true);
            if(A[n][7].cellval>0){A[n-1][7].c3.setColor(COLOR("green"));
            A[n-1][7].c2.setColor(COLOR("green"));
            A[n-1][7].c1.setColor(COLOR("green"));
            A[n-1][7].cellval=3;}
            else{A[n-1][7].c3.setColor(COLOR("blue"));
            A[n-1][7].c2.setColor(COLOR("blue"));
            A[n-1][7].c1.setColor(COLOR("blue"));
            A[n-1][7].cellval=-3;}
            A[n-1][7].ncircles++;
            break;}
    switch(A[n+1][7].ncircles){
     case 0: A[n+1][7].c1.reset(50+100*(n+1),50+100*7,20);
            A[n+1][7].c1.setFill(true);
            if(A[n][7].cellval>0){A[n+1][7].c1.setColor(COLOR("green"));A[n+1][7].cellval=1;}
            else{A[n+1][7].c1.setColor(COLOR("blue"));A[n+1][7].cellval=-1;}
            A[n+1][7].ncircles++;
            break;
    case 1: A[n+1][7].c2.reset(50-20*sqrt(2)+100*(n-1),50+20*sqrt(2)+100*0,20);
            A[n+1][7].c2.setFill(true);
            A[n+1][7].c1.setFill(true);
           if(A[n][7].cellval>0){A[n+1][7].c2.setColor(COLOR("green"));A[n+1][7].c1.setColor(COLOR("green"));A[n+1][7].cellval=2;}
           else{A[n+1][7].c2.setColor(COLOR("blue"));A[n+1][7].c1.setColor(COLOR("blue"));A[n+1][7].cellval=-2;}
            A[n+1][7].ncircles++;
            break;
    case 2: A[n+1][7].c3.reset(50+20*sqrt(2)+100*(n+1),50+20*sqrt(2)+100*7,20);
            A[n+1][7].c3.setFill(true); A[n+1][7].c2.setFill(true);A[n+1][7].c1.setFill(true);
            if(A[n][7].cellval>0){A[n+1][7].c3.setColor(COLOR("green"));
            A[n+1][7].c2.setColor(COLOR("green"));
            A[n+1][7].c1.setColor(COLOR("green"));
            A[n+1][7].cellval=3;}
            else{A[n+1][7].c3.setColor(COLOR("blue"));
            A[n+1][7].c2.setColor(COLOR("blue"));
            A[n+1][7].c1.setColor(COLOR("blue"));
            A[n+1][7].cellval=-3;}
            A[n+1][7].ncircles++;
            break;}

A[n][7].c1.reset(50+100*n,50+100*7,0);
A[n][7].c2.reset(50-20*sqrt(2)+100*n,50+20*sqrt(2)+100*7,0);
A[n][7].c3.reset(50+20*sqrt(2)+100*n,50-20*sqrt(2)+100*7,0);
   A[n][7].ncircles=0;
   A[n][7].cellval=0;}


   for(int m=1;m<7;m++){
    if(A[m][n].ncircles==4){
    switch(A[m-1][n].ncircles){
   case 0: A[m-1][n].c1.reset(50+100*(m-1),50+100*n,20);
            A[m-1][n].c1.setFill(true);
            if(A[m][n].cellval>0){A[m-1][n].c1.setColor(COLOR("green"));A[m-1][n].cellval=1;}
            else{A[m-1][n].c1.setColor(COLOR("blue"));A[m-1][n].cellval=-1;}
            A[m-1][n].ncircles++;
            break;
    case 1: A[m-1][n].c2.reset(50-20*sqrt(2)+100*(m-1),50+20*sqrt(2)+100*n,20);
            A[m-1][n].c2.setFill(true);
            A[m-1][n].c1.setFill(true);
           if(A[m][n].cellval>0){A[m-1][n].c2.setColor(COLOR("green"));A[m-1][n].c1.setColor(COLOR("green"));A[m-1][n].cellval=2;}
           else{A[m-1][n].c2.setColor(COLOR("blue"));A[m-1][n].c1.setColor(COLOR("blue"));A[m-1][n].cellval=-2;}
            A[m-1][n].ncircles++;
            break;
    case 2: A[m-1][n].c3.reset(50+20*sqrt(2)+100*(m-1),50+20*sqrt(2)+100*n,20);
            A[m-1][n].c3.setFill(true); A[m-1][n].c2.setFill(true);A[m-1][n].c1.setFill(true);
            if(A[m][n].cellval>0){A[m-1][n].c3.setColor(COLOR("green"));
            A[m-1][n].c2.setColor(COLOR("green"));
            A[m-1][n].c1.setColor(COLOR("green"));
            A[m-1][n].cellval=3;}
            else{A[m-1][n].c3.setColor(COLOR("blue"));
            A[m-1][n].c2.setColor(COLOR("blue"));
            A[m-1][n].c1.setColor(COLOR("blue"));
            A[m-1][n].cellval=-3;}
            A[m-1][n].ncircles++;
            break;


     case 3: A[m-1][n].c4.reset(50+20*sqrt(2)+100*(m-1),50+20*sqrt(2)+100*n,20);
            A[m-1][n].c4.setFill(true); A[m-1][n].c3.setFill(true);A[m-1][n].c2.setFill(true);  A[m-1][n].c1.setFill(true);
           if((A[m][n].cellval)>0){ A[m-1][n].c4.setColor(COLOR("green"));
            A[m-1][n].c3.setColor(COLOR("green"));
            A[m-1][n].c2.setColor(COLOR("green"));
            A[m-1][n].c1.setColor(COLOR("green"));
            A[m-1][n].cellval=4;}
            else{A[m-1][n].c4.setColor(COLOR("blue"));
            A[m-1][n].c3.setColor(COLOR("blue"));
            A[m-1][n].c2.setColor(COLOR("blue"));
            A[m-1][n].c1.setColor(COLOR("blue"));
            A[m-1][n].cellval=-4;}
            A[m-1][n].ncircles++;
            break;}

    switch(A[m+1][n].ncircles){
   case 0: A[m+1][n].c1.reset(50+100*(m+1),50+100*n,20);
            A[m+1][n].c1.setFill(true);
            if(A[m][n].cellval>0){A[m+1][n].c1.setColor(COLOR("green"));A[m+1][n].cellval=1;}
            else{A[m+1][n].c1.setColor(COLOR("blue"));A[m+1][n].cellval=-1;}
            A[m+1][n].ncircles++;
            break;
    case 1: A[m+1][n].c2.reset(50-20*sqrt(2)+100*(m+1),50+20*sqrt(2)+100*n,20);
            A[m+1][n].c2.setFill(true);
            A[m+1][n].c1.setFill(true);
           if(A[m][n].cellval>0){A[m+1][n].c2.setColor(COLOR("green"));A[m+1][n].c1.setColor(COLOR("green"));A[m+1][n].cellval=2;}
           else{A[m+1][n].c2.setColor(COLOR("blue"));A[m+1][n].c1.setColor(COLOR("blue"));A[m+1][n].cellval=-2;}
            A[m+1][n].ncircles++;
            break;
    case 2: A[m+1][n].c3.reset(50+20*sqrt(2)+100*(m+1),50+20*sqrt(2)+100*n,20);
            A[m+1][n].c3.setFill(true); A[m+1][n].c2.setFill(true);A[m+1][n].c1.setFill(true);
            if(A[m][n].cellval>0){A[m+1][n].c3.setColor(COLOR("green"));
            A[m+1][n].c2.setColor(COLOR("green"));
            A[m+1][n].c1.setColor(COLOR("green"));
            A[m+1][n].cellval=3;}
            else{A[m+1][n].c3.setColor(COLOR("blue"));
            A[m+1][n].c2.setColor(COLOR("blue"));
            A[m+1][n].c1.setColor(COLOR("blue"));
            A[m+1][n].cellval=-3;}
            A[m+1][n].ncircles++;
            break;


     case 3: A[m+1][n].c4.reset(50+20*sqrt(2)+100*(m+1),50+20*sqrt(2)+100*n,20);
            A[m+1][n].c4.setFill(true); A[m+1][n].c3.setFill(true);A[m+1][n].c2.setFill(true);  A[m+1][n].c1.setFill(true);
           if((A[m][n].cellval)>0){ A[m+1][n].c4.setColor(COLOR("green"));
            A[m+1][n].c3.setColor(COLOR("green"));
            A[m+1][n].c2.setColor(COLOR("green"));
            A[m+1][n].c1.setColor(COLOR("green"));
            A[m+1][n].cellval=4;}
            else{A[m+1][n].c4.setColor(COLOR("blue"));
            A[m+1][n].c3.setColor(COLOR("blue"));
            A[m+1][n].c2.setColor(COLOR("blue"));
            A[m+1][n].c1.setColor(COLOR("blue"));
            A[m+1][n].cellval=-4;}
            A[m+1][n].ncircles++;
            break;}
    switch(A[m][n-1].ncircles){
    case 0: A[m][n-1].c1.reset(50+100*m,50+100*(n-1),20);
            A[m][n-1].c1.setFill(true);
            if(A[m][n].cellval>0){A[m][n-1].c1.setColor(COLOR("green"));A[m][n-1].cellval=1;}
            else{A[m][n-1].c1.setColor(COLOR("blue"));A[m][n-1].cellval=-1;}
            A[m][n-1].ncircles++;
            break;
    case 1: A[m][n-1].c2.reset(50-20*sqrt(2)+100*m,50+20*sqrt(2)+100*(n-1),20);
            A[m][n-1].c2.setFill(true);
            A[m][n-1].c1.setFill(true);
           if(A[m][n].cellval>0){A[m][n-1].c2.setColor(COLOR("green"));A[m][n-1].c1.setColor(COLOR("green"));A[m][n-1].cellval=2;}
           else{A[m][n-1].c2.setColor(COLOR("blue"));A[m][n-1].c1.setColor(COLOR("blue"));A[m][n-1].cellval=-2;}
            A[m][n-1].ncircles++;
            break;
    case 2: A[m][n-1].c3.reset(50+20*sqrt(2)+100*m,50+20*sqrt(2)+100*(n-1),20);
            A[m][n-1].c3.setFill(true); A[m][n-1].c2.setFill(true);A[m][n-1].c1.setFill(true);
            if(A[m][n].cellval>0){A[m][n-1].c3.setColor(COLOR("green"));
            A[m][n-1].c2.setColor(COLOR("green"));
            A[m][n-1].c1.setColor(COLOR("green"));
            A[m][n-1].cellval=3;}
            else{A[m][n-1].c3.setColor(COLOR("blue"));
            A[m][n-1].c2.setColor(COLOR("blue"));
            A[m][n-1].c1.setColor(COLOR("blue"));
            A[m][n-1].cellval=-3;}
            A[m][n-1].ncircles++;
            break;


     case 3: A[m][n-1].c4.reset((50+20*sqrt(2)+100*m),50+20*sqrt(2)+100*(n-1),20);
            A[m][n-1].c4.setFill(true); A[m][n-1].c3.setFill(true);A[m][n-1].c2.setFill(true);  A[m][n-1].c1.setFill(true);
           if((A[m][n].cellval)>0){ A[m][n-1].c4.setColor(COLOR("green"));
            A[m][n-1].c3.setColor(COLOR("green"));
            A[m][n-1].c2.setColor(COLOR("green"));
            A[m][n-1].c1.setColor(COLOR("green"));
            A[m][n-1].cellval=4;}
            else{A[m][n-1].c4.setColor(COLOR("blue"));
            A[m][n-1].c3.setColor(COLOR("blue"));
            A[m][n-1].c2.setColor(COLOR("blue"));
            A[m][n-1].c1.setColor(COLOR("blue"));
            A[m][n-1].cellval=-4;}
            A[m][n-1].ncircles++;
            break;}
    switch(A[m][n+1].ncircles){
     case 0: A[m][n+1].c1.reset(50+100*m,50+100*(n+1),20);
            A[m][n+1].c1.setFill(true);
            if(A[m][n].cellval>0){A[m][n+1].c1.setColor(COLOR("green"));A[m][n+1].cellval=1;}
            else{A[m][n+1].c1.setColor(COLOR("blue"));A[m][n+1].cellval=-1;}
            A[m][n+1].ncircles++;
            break;
    case 1: A[m][n+1].c2.reset(50-20*sqrt(2)+100*m,50+20*sqrt(2)+100*(n+1),20);
            A[m][n+1].c2.setFill(true);
            A[m][n+1].c1.setFill(true);
           if(A[m][n].cellval>0){A[m][n+1].c2.setColor(COLOR("green"));A[m][n+1].c1.setColor(COLOR("green"));A[m][n+1].cellval=2;}
           else{A[m][n+1].c2.setColor(COLOR("blue"));A[m][n+1].c1.setColor(COLOR("blue"));A[m][n+1].cellval=-2;}
            A[m][n+1].ncircles++;
            break;
    case 2: A[m][n+1].c3.reset(50+20*sqrt(2)+100*m,50+20*sqrt(2)+100*(n+1),20);
            A[m][n+1].c3.setFill(true); A[m][n+1].c2.setFill(true);A[m][n+1].c1.setFill(true);
            if(A[m][n].cellval>0){A[m][n+1].c3.setColor(COLOR("green"));
            A[m][n+1].c2.setColor(COLOR("green"));
            A[m][n+1].c1.setColor(COLOR("green"));
            A[m][n+1].cellval=3;}
            else{A[m][n+1].c3.setColor(COLOR("blue"));
            A[m][n+1].c2.setColor(COLOR("blue"));
            A[m][n+1].c1.setColor(COLOR("blue"));
            A[m][n+1].cellval=-3;}
            A[m][n+1].ncircles++;
            break;


     case 3: A[m][n+1].c4.reset((50+20*sqrt(2)+100*m),50+20*sqrt(2)+100*(n+1),20);
            A[m][n+1].c4.setFill(true); A[m][n+1].c3.setFill(true);A[m][n+1].c2.setFill(true);  A[m][n+1].c1.setFill(true);
           if((A[m][n].cellval)>0){ A[m][n+1].c4.setColor(COLOR("green"));
            A[m][n+1].c3.setColor(COLOR("green"));
            A[m][n+1].c2.setColor(COLOR("green"));
            A[m][n+1].c1.setColor(COLOR("green"));
            A[m][n+1].cellval=4;}
            else{A[m][n+1].c4.setColor(COLOR("blue"));
            A[m][n+1].c3.setColor(COLOR("blue"));
            A[m][n+1].c2.setColor(COLOR("blue"));
            A[m][n+1].c1.setColor(COLOR("blue"));
            A[m][n+1].cellval=-4;}
            A[m][n+1].ncircles++;
            break;}
A[m][n].c1.reset(50+100*m,50+100*n,0);
A[m][n].c2.reset(50-20*sqrt(2)+100*m,50+20*sqrt(2)+100*n,0);
A[m][n].c3.reset(50+20*sqrt(2)+100*m,50-20*sqrt(2)+100*n,0);
A[m][n].c4.reset(50+100*m,50+100*n,0);
   A[m][n].ncircles=0;
   A[m][n].cellval=0;}}}
   int m,n;
 for(m=1;m<7;m++){
    for(n=1;n<7;n++){
    if((A[0][0].ncircles<2)&&(A[7][0].ncircles<2)&&(A[7][7].ncircles<2)&&(A[0][7].ncircles<2)&&(A[0][n].ncircles<3)&&
       (A[7][n].ncircles<3)&&(A[n][0].ncircles<3)&&(A[n][7].ncircles<3)&&(A[m][n].ncircles<4)){return;}
       else{scan(A);}}}}//scan ends




















