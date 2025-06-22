#include <stdio.h>
//on = nth operand
double sum(double o1,double o2){
    
    return o1+o2;
    
}
double subt(double o1,double o2){
    
    return o1-o2;
    
}
double mul(double o1,double o2){
    
    return o1*o2;
    
}
double div(double o1,double o2){
    
    return o1/o2;
    
}


/* ******************************
Fn Power fn
*/
double pwer(double base,int power)
{
    double out=1.0;//if power =0 itll auto return 1
    if(power>0){
    for(int i=1;i<=power;i++){
        
        out*=base;
        
    }
    }
    if(power<0){
        
        for(int i=1;i<=(-power);i++)
        {
            
            out*=(1/base);
            
        }
        
    }
    
return out;    
}
/* *********** */

/*
Func for power of any number
**************************** */
double upow(double base, char power[])//terminate karna padayga with \0 end of array
{
 int lengofint=0,lengofdeci=0,encdecimal=0,k=0;
 char array[100];
 for(int i=0;power[i]!='\0';i++)
 {
     
     if(power[i]=='.'){encdecimal=1;}
     else if(encdecimal==0){lengofint++;array[k]=power[i];k++;}
     else{lengofdeci++;array[k]=power[i];k++;}
 }
 
 array[lengofdeci+lengofint]='\0';
// printf("\n array strores %s\n",array);
 
 int power1=0,temp=0;
 for(int i =0;i<lengofdeci+lengofint;i++)
 {
     temp=(int)array[i]-48;
     //printf("\ntemp = %d\n",temp);
     power1+=temp*pwer(10,lengofdeci+lengofint-i-1);//power would after this loop store how many times the subseq loop runs
     //printf("\npower1 = %d\n",power1);
 }
 
temp=pwer(10,lengofdeci);//= a^1/1000...

double number=0.0;

while(pwer(number+1,temp)<base){  number+=1;  }
while(pwer(number+0.001,temp)<base){  number+=0.001;  }
while(pwer(number+0.00001,temp)<base){  number+=0.00001;  }
while(pwer(number+0.0000001,temp)<base){  number+=0.0000001;  }
while(pwer(number+0.000000001,temp)<base){  number+=0.000000001;  }

while(pwer(number+0.00000000001,temp)<base){  number+=0.00000000001;  }


double output=1;
for(int i=0;i<power1;i++)
{
    
    output*=number;
    
}
return output;
}

/* *************************** */


/* **************************
Fn for sqrt of any number
*/
double sqroot(double x)
{
    double out=0;
    if(x>0){
    int nooftimesallloospran=0;
//    printf("\n%d",nooftimesallloospran);

for(int i=0;((out+i)*(out+i))<=x;i++)    
{
out=i;  
nooftimesallloospran++;
}

for(double i=0.001;((out+i)*(out+i))<=x;i+=0.001)
{
    
    out+=i;
    nooftimesallloospran++;
}

for(double i=0.00001;((out+i)*(out+i))<=x;i+=0.00001){
    
    out+=i;
nooftimesallloospran++;
}

for(double i=0.000000001;((out+i)*(out+i))<=x;i+=0.000000001){
    
    out+=i;
nooftimesallloospran++;
}

for(double i=0.0000000000001;((out+i)*(out+i))<=x;i+=0.0000000000001){
    
    out+=i;
nooftimesallloospran++;
}
}
//printf("\n%d",nooftimesallloospran);
return out;
}
/* ******************* */

/*
Fn to convert any binary number stored in a char array into decimal reqs power fn
********************************************************************************* */

int btd(int positive,char input[])//Input is an 1d array that contains the binary values
{
int i =0,k=0,sm=0;
int length=0;


        char a[32];
    for(int j=0;input[j]!='\0';j++){
        
        if(input[j]=='1'){a[k]='1';input[k]='1';}else if(input[j]=='0'){a[k]='0';input[k]='0';}else{k--;}k++;//ab k mai len hogi
        
    }

    a[k]='\0';


for (int i =0;i<32;i++)
{
    if (positive == 1){
input[i]='0';    }else{input[i]='1';}
    
}
for(int i =k-1;i>=0;i--)
{
    
    input[32-k+i]=a[i];
    
}
input[32]='\0';
//printf("\n\ntest %s\n",input);


for(int i =0;i<=32;i++)
{
    
    a[i]=input[i];
    
}

//if the number is negative in nature then first take its compliment, eval that as int and then add 1
if(positive==0)
{
    
    for(int j =0;j<32;j++)
    {
        
        if(a[j]=='1')
        {
            
            a[j]='0';
            
        }
        else if(a[j]=='0')
        {
            
            a[j]='1';
            
        }
        
    }
    
}
k=0;
for(int i=31;i>=0;i--){
    
    if(a[i]=='1'){
    sm+=pwer(2,k);}
    k++;
}




if(positive==0)
{
    
    sm+=1;
    sm=-sm;
    
}
return sm;
}
/* ******************************* */


/* 
Function to display a 1d int array 
********************************** */
void dis1diarr(int size,int matrix[])
{

for(int l =0 ; l<size;l++){

printf("%d",matrix[l]);
   
}
}
/* ***************************** */


/*
Fn to remove all grabage inputs from 32 bitbinary char array and for proper termination
************************************************************************************* */
void binarr(char array[])
{
    int k=0;
    for (int i =0;i<32&&(array[i]!='\0');i++)
    {
        
        if(array[i]=='1'){array[k]='1';k++;}
        else if(array[i]=='0'){array[k]='0';k++;}
        
    }
    array[k]='\0';
}
/* ********************************************************************************** */

/*
FnTo convert any decimal number into 32bit binary int array
******************************************* */


int dtb(double decimal, int binary[32])// a decimal input and the array in which the binary would be returned
{
    
    int posi=0,remaindar=0,number=0,i=0;
    if(decimal>=0)
    {
        
        posi=1;
        number=decimal;
        
    }
    else
    {
        
        number=-decimal;
        number-=1;
        
    }
    
for(int j =0;j<32;j++)
{
    
    binary[j]=0;
    
}

int binary1[32];
for(int j =0;j<32;j++)
{
    
    binary1[j]=0;
    
}
    while(number!=0)
    {
        
        remaindar=number%2;
        binary1[i]=remaindar;
        number=(int) number/2;
        
        
        i++;
    }
   // printf("\nTest binary1 = ");
   // dis1diarr(32,binary1);
    


//Now reversing the array
int temp;
for(int j=0;j<16;j++)
{
    
    temp=binary1[31-j];
    binary1[31-j]=binary1[j];
    binary1[j]=temp;
    
}

   // printf("\nTest binary1 = ");
   // dis1diarr(32,binary1);

for(int j=0;j<32;j++)
{
    
    binary[j]=binary1[j];
    
}

if(posi==0)
{
    
    for(int i=0;i<32;i++)
    {
        
        binary[i]=!binary[i];
        
    }
    
}


}
/* **************************************** */


/*
FnTo convert any decimal number into 32bit binary int array
******************************************* */


int dtbc(int decimal, char binary[32])// a decimal input and the array in which the binary would be returned
{
    
    int posi=0,remaindar,number,i=0;
    if(decimal>0)
    {
        
        posi=1;
        number=decimal;
        
    }
    else
    {
        
        number=-decimal;
        number-=1;
        
    }
    
for(int i =0;i<32;i++)
{
    
    binary[i]='\0';
    
}


    while(number!=0)
    {
        
        remaindar=number%2;
        if(remaindar==1){        binary[i]='1';
}else{        binary[i]='0';
}
        number=(int) number/2;
        
        
        i++;
    }
    


//Now reversing the array
char temp;
for(int j=0;j<16;j++)
{
    
    temp=binary[31-j];
    binary[31-j]=binary[j];
    binary[j]=temp;
    
}

for(int j=0;binary[j]=='\0';j++)
{
    
    binary[j]='0';
    
}

if(posi==0)
{
    
    for(int i=0;i<32;i++)
    {
        if(binary[i]=='1'){binary[i]='0';}else{binary[i]='1';}
        //binary[i]=!binary[i];
        
    }
    
}


}
/* **************************************** */


/*
Fn to input a 1d int binary array into a 1d char binary array
*********************************************** */

void swap1dinttochar(int size,int imatrix[size],char carray[size])
{
    char temp;
    for(int i =0;i<size;i++)
    {
        if(imatrix[i]==1)
        {
            
        carray[i]='1';    
            
        }
        else
        {
            
            carray[i]='0';
            
        }
        
        
    }
}

/* ******************************************** */


/*
Function to initialise and simultaneously show the matrix
*********************************************************** */
int imatrix(int r,int c,int matrix[r][c]){//Parameters of the matrix are rows, columns and an output matrix
//initialise with 0s
for (int i = 0; i < r; i++)
{
for(int j =0; j<c; j++){

matrix[i][j]=0;

}}
//
//Simulateneous input and display of array 
for (int i = 0; i < r; i++)
{
for(int j =0; j<c; j++){

    for (int k = 0; k < r; k++)
    {
for(int l =0 ; l<c;l++){

if (l==0){  printf("| ");    } 

printf("%d ",matrix[k][l]);

if (l==c-1){    printf("|");   }


}  printf("\n");  }
    
scanf("%d",&matrix[i][j]);
}}
//

// print entire stored matrix
printf("\n");
for (int k = 0; k < r; k++)
    {
for(int l =0 ; l<c;l++){

    if (l==0)
    {
printf("| ");    }

    
printf("%d ",matrix[k][l]);
if (l==c-1)
{
printf("|");}


}  printf("\n");  }
    return 0;
}
/* ********************************* */



/* 
Function for determinant of 2x2 3x3 int matrix
******************************************* */
int det(int rows,int array[rows][rows])
{
int det=0;
    
    if(rows==2)
    {
        
    det=array[0][0]*array[1][1]-array[0][1]*array[1][0]; 
        
    }
    
    else if(rows==3)
    {
        
    det=array[0][0]*array[1][1]*array[2][2]+array[0][1]*array[1][2]*array[2][0]+array[0][2]*array[1][0]*array[2][1]-array[0][2]*array[1][1]*array[2][0]-array[0][1]*array[1][0]*array[2][2]-array[0][0]*array[1][2]*array[2][1];
        
    }
    else
    {
        
        printf("Invalid input");
        
    }
    return det;
}
/* ******************************** */
/* 
Function to display a matrix
**************************** */
void disimat(int rows,int columns,int matrix[][columns])
{//No of rows and columns of a matrix to print
        // print entire stored matrix
printf("\n\n");
for (int k = 0; k < rows; k++)
    {
for(int l =0 ; l<columns;l++){

    if (l==0)
    {
printf("| ");    }

    
printf("%d ",matrix[k][l]);
if (l==columns-1)
{
printf("|");}


}  printf("\n");  }
printf("\n");   
}
/* ******************************** */

/* 
Function for trace of int matrix
******************************************* */
int trace(int rows,int array[rows][rows])
{

int trace=0;
for(int i =0;i<rows;i++)//total no of elems to add = t no of rows
{
    
 trace+=array[i][i];   
    
}

    return trace;
}
/* ******************************** */


/*
Fn For sum of two integer matricies
*********************************** */
void matsum(int rows,int columns,int matrix1[rows][columns],int matrix2[rows][columns]){//would save the sum in the matrix1 itself
    
    for(int i =0;i<rows;i++){
        
        for(int j=0; j<columns;j++){
            
            matrix1[i][j]+=matrix2[i][j];
            
        }}}
/* ****************************************** */


/*
Fn For difference of two integer matricies
****************************************** */
void matdiff(int rows,int columns,int matrix1[rows][columns],int matrix2[rows][columns]){//would save the sum in the matrix1 itself
    
    for(int i =0;i<rows;i++){
        
        for(int j=0; j<columns;j++){
            
            matrix1[i][j]-=matrix2[i][j];
            
        }}}
/* *************************************** */


/* **********************
Fn For matrix multiplication A * B
*/
int matmul(int rows1,int columns1,int mat1[rows1][columns1], int columns2,int mat2[columns1][columns2],int out[rows1][columns2])
{
    int o=0;
    for(int i =0;i<rows1;i++)//i = konsa row Matrix A ka select kiya hai
    {
        
        for(int j=0;j<columns2;j++)//j = selected column of B matrix
        {
            
        o=0;
                        
        
            for(int k=0;k<columns1;k++)//k = kitne baar mujhe product ko sum karna hai
            {
                
                o+=(mat1[i][k]*mat2[k][j]);
            }
            
            out[i][j]=o;
                            

        }
        
    }
    
    return 0;
}


/* **************** */



int main() {
    int mode;
    double o1,o2;
    char opera='a',bin1[50],bin2[50];
    int posi;
    
  //  printf("\nEnter operand:\n");
//    scanf("%lf",o1);
    
    printf("Enter mode number: \n 1) Decimal \n 2) Binary \n 3) Matricies \n 4) Exit\n");
    scanf("%d",&mode);
        
    switch(mode){
        case 1:
    
    printf("Input operand:\n");
    scanf(" %lf",&o1);
        
    printf("\n Operations:\n+ - addition\n/ - division\n- - subtraction\n* - multiplication\n^ - exponentiation\nr - raised to a float\n");
    

    
    printf("Input operation: +, -, *, /, ^, r\n");
    scanf(" %c",&opera);
    
    
    while(opera!='='){

    printf("\n%lf %c ",o1,opera);
    if(opera!='r'){
    scanf("%lf",&o2);}
    
    switch(opera){
        
        case '+':
        o1= sum(o1,o2);
        break;
        
        case '-':
        o1= subt(o1,o2);
        break;
        
        case '*':
        o1= mul(o1,o2);
        break;
        
        case '/':
        o1= div(o1,o2);
        break;
        
        case '^':
        o1= pwer(o1,o2);
        break;
        
        case 'r':
        char power[100];

        scanf(" %s",power);
        o1=upow(o1,power);
        break;
        
       /* case '|':
        o1= tetr(o1,o2);
        break;  */
        
        case 'a':
        break;
        default :
        printf("Enter valid operation");

    }
        printf("%lf\n",o1);
        printf("Input operation: +, -, *, /, ^, r or = : \n");
        scanf(" %c",&opera);
    
    
    }
    
    printf("%lf",o1);
    break;
    
    case 2:
        


        printf("\nEnter a Binary number:\n");
        scanf(" %s",bin1);
        binarr(bin1);
        
        printf("\nIs %s to be treated as positive(1) or negative(0), Enter 1 or 0: ",bin1);
        scanf("%d",&posi);
        o1= btd(posi,bin1);
       // printf("\n\ntETS: %s",bin1);
       // dtbc(o1,bin1);
         //       printf("\n\ntETS: %s",bin1);

        bin1[32]='\0';
        bin2[32]='\0';

        printf("\n Operations:\nc - Conversion to decimal\n+ - Binary addition\n- - Binary subtraction\n* - Binary multiplication\n! - Binary Not\n& - Binary And\n| - Binary Or\n^ - Binary XOR\n");

    
        printf("Input operation: c, +, -, *, /, !, &, |, ^ \n");
        scanf(" %c",&opera);
    
    int output[32],output1[32];// definition of int array is for the decimal to bin fn as it outputs in int array
    
    while(opera!='=')
    {

        printf("\n%s %c ",bin1,opera);

    switch(opera)
    {

        case 'c':
        bin2[0]='\0';//To display properly
        
        
        if(bin1[0]=='1'){posi=0;}else{posi=1;}
         // printf("\n test: bin1 = %s",bin1);
        o1=btd(posi,bin1);
    
                //printf("\n test: o1 = %lf",o1);

        dtb(o1,output);
       // printf("\n test: output array = ");
        //dis1diarr(32,output);
        
        
        break;
        
        case '+':
        scanf(" %s",bin2);
        binarr(bin2);
        
        printf("Is %s to be treated as positive(1) or negative(0), Enter 1 or 0: ",bin2);
        scanf(" %d",&posi);
        
        o2=btd(posi,bin2);
        //dtbc(o2,bin2);
        
        o1+=o2;
        
        break;
        
        case'-':
        scanf(" %s",bin2);
        binarr(bin2);
        
        printf("\nIs %s to be treated as positive(1) or negative(0), Enter 1 or 0: ",bin2);
        scanf(" %d",&posi);
        o2=btd(posi,bin2);
       // printf("\nTest o1 = %lf o2 = %lf",o1,o2);
        
                //dtbc(o2,bin2);

        o1-=o2;
              //  printf("\nTest o1 = %lf o2 = %lf",o1,o2);

        break;
        
        case '*':
        scanf("%s",bin2);
        binarr(bin2);
            
        printf("\nIs %s to be treated as positive(1) or negative(0), Enter 1 or 0: ",bin2);
        scanf("%d",&posi);
        
        o2=btd(posi,bin2);
            //dtbc(o2,bin2);
    
        o1*=o2;
        break;
        
        case '/':
        scanf("%s",bin2);
        binarr(bin2);
        
        printf("\nIs %s to be treated as positive(1) or negative(0), Enter 1 or 0: ",bin2);
        scanf("%d",&posi);
        
        o2=btd(posi,bin2);
                //dtbc(o2,bin2);

        o1/=o2;
        break;
        
        case '!':
        
        dtb(o1,output);// from ui to deci1 to o1 to output
        for(int i=0;i<32;i++)
        {
            
            output[i]=!output[i];

        }

        swap1dinttochar(32,output,bin2);

        if(bin2[0]=='1'){posi=0;}else{posi=1;}
        o1=btd(posi,bin2);//btd fn works for an char input
        bin2[0]='\0';//bin2 is of no use for this so 

        break;
        
        case '&':
        
        scanf("%s",bin2);
        binarr(bin2);
        
        printf("\nIs %s to be treated as positive(1) or negative(0), Enter 1 or 0: ",bin2);
        scanf("%d",&posi);
        o2=btd(posi,bin2);
                //dtbc(o2,bin2);

        o1=(int)o1 & (int)o2;
        
        break;
        
        
        case '|':
        
        scanf("%s",bin2);
        binarr(bin2);
              
        printf("\nIs %s to be treated as positive(1) or negative(0), Enter 1 or 0: ",bin2);
        scanf("%d",&posi);
        o2=btd(posi,bin2);
                //dtbc(o2,bin2);

        o1=(int)o1 | (int)o2;
        
        break;
        
        
        case '^':
        
        scanf("%s",bin2);
        binarr(bin2);
                
        printf("\nIs %s to be treated as positive(1) or negative(0), Enter 1 or 0: ",bin2);
        scanf("%d",&posi);
        o2=btd(posi,bin2);
                //dtbc(o2,bin2);

        o1=(int)o1 ^ (int)o2;
        
        break;
        
        default :
        printf("Enter valid operation");
        break;

    }

// The section of code below just 
        dtb(o1,output);//inputs int value from o1 to output why cause o1 is the variable containg the output of the opeartion
     //   printf("\nTest: %lf",o1);
      //  dis1diarr(32,output);
/*
All the operations follow this pattern
1 bin1 = ui and posi ui
2 o1 = int(posi,bin1)
3 any operation that is done should return the outcome as an int in o1
4 output = (bin)o1
5 print the equation bin1 opera bin2
6 bin1 =output
7 terminate bin1
8 then check wether the value stored in bin1 is posi or negi
*/

        printf("\n%s %c %s: \n",bin1,opera,bin2);
        

        swap1dinttochar(32,output,bin1);


        dis1diarr(32,output);
        
        if(bin1[0]=='1'){posi=0;}else{posi=1;}
        printf(" (%d)",btd(posi,bin1));
        

        printf("\n\nInput Next operation: c, +, -, !, &, |, ^ or =. \n");
        scanf(" %c",&opera);

    }
    
    printf("\n%s (%lf)",bin1,o1);
    break;

case 3:    

    
    //For decleration of any user defined Array total number of rows and columns are needed
        printf("For a matrix of size r x c, Enter value of r:\n");
        int r,c,r2,c2,ro,co;
        scanf("%d",&r);

        printf("Enter value of c:\n");
        scanf("%d",&c);

        int Matrix1[r][c];
        int Matrix2[r][c];
        int outmatrix[r][c];

imatrix(r,c,Matrix1);
//

          //List of all avalible Operations for Matricies
    printf("\n Operations:\n+ - addition\n- - subtraction\n* - multiplication\nD - Determinant\nT - Trace\n");
    //

printf("\nInput the operation: +, -, *, D, T ");
scanf(" %c",&opera);



while(opera!='=')
{


    switch(opera)
    {

        default :
        printf("\nEnter a valid operation: \n");
        break;
        
        case 'D':
        
        o1= det(r,Matrix1);
        printf("\nDet of");
        disimat(r,c,Matrix1);
        printf("= %lf\n",o1);

        break;
        
        case 'T':
        
        o1= trace(r,Matrix1);
        printf("\nTrace of");
        disimat(r,c,Matrix1);
        printf("= %lf\n",o1);

        break;
        
        case '+':
        
        r2=r;c2=c;
        imatrix(r2,c2,Matrix2);
    
    printf("\n---\t---\t---\t");
    disimat(r,c,Matrix1);
    printf("%c",opera);
    disimat(r2,c2,Matrix2);
    printf("---\t---\t---\t\n");
    
        matsum(r,c,Matrix1,Matrix2);//vaapas travi ye result in Matrix1
        printf("=");
        disimat(r,c,Matrix1);
        
        break;
        
        case '-':
        
        r2=r;c2=c;
        imatrix(r2,c2,Matrix2);
    
    printf("\n---\t---\t---\t");
    disimat(r,c,Matrix1);
    printf("%c",opera);
    disimat(r2,c2,Matrix2);
    printf("---\t---\t---\t\n");
        
        matdiff(r,c,Matrix1,Matrix2);
        printf("=");
        disimat(r,c,Matrix1);
        
        break;
        
        case '*':
        
    r2=c;    
    printf("\n For Next matrix of order %d x c, Enter the value of c :\n",r2);
    scanf("%d",&c2);
    
    imatrix(r2,c2,Matrix2);
    
    printf("\n---\t---\t---\t");
    disimat(r,c,Matrix1);
    printf("%c",opera);
    disimat(r2,c2,Matrix2);
    printf("---\t---\t---\t\n");

        matmul(r,c,Matrix1,c2,Matrix2,Matrix1);
        c=c2;
        

        
        printf("=");
        disimat(r,c,Matrix1);

        break;
        

    }    
printf("\nInput the next operation: +, -, *, D, T or =");
        scanf(" %c",&opera);

}




        
        
        
        
    }//ye switch mode ka bracket
    return 0;
}
