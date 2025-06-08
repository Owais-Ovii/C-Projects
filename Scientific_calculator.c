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
Fn to convert any binary number stored in a char array into decimal reqs power fn
********************************************************************************* */

int btd(int positive,char input[])//Input is an 1d array that contains the binary values
{
int i =0,k=0,sm=0;
int length=0;
    while((input[i]!= '\0'))
    {   
        if(((input[i]=='1')||(input[i]=='0')))//The condition is so because via some user err some chars in the array may be invalid those arent counted
        {
        length++;//Evaluates the length of binary number
        }
        i++;//total chars in arr inc garbage values
    }
    char a[length];
    a[length]='\0';

    for(int j=0;j<i;j++){
        
        if(input[j]=='1'){a[k]='1';input[k]='1';}else if(input[j]=='0'){a[k]='0';input[k]='0';}else{k--;}k++;
        
    }
k=0;
input[length]='\0';
int b[length];
//if the number is negative in nature then first take its compliment, eval that as int and then add 1
if(positive==0)
{
    
    for(int j =0;j<length;j++)
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


for (int j = 0;j<length;j++)//total elements in binary array =i and we have to check all of em irrespective of wether they are valid or not
{
    if (a[i-1-j]=='1')//but to store well check wether the inputs are valid or not i-1 is the last elem of array
    {
    b[k]=1;
    }
    else if(a[length-1-j]=='0')
    {
        b[k]=0;
    }
    else{k--;}//now if the value stored in bin array were to be invalid then the cell of B in which we r storing shouldnt change
    k++;
}


for(int j=0;j<length;j++){
    if (b[j])
    {
    sm+=pwer(2,j);
    }


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
    for (int i =0;i<32;i++)
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


int dtb(int decimal, int binary[32])// a decimal input and the array in which the binary would be returned
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
    
    binary[i]=-2147483648;
    
}


    while(number!=0)
    {
        
        remaindar=number%2;
        binary[i]=remaindar;
        number=(int) number/2;
        
        
        i++;
    }
    


//Now reversing the array
int temp;
for(int j=0;j<16;j++)
{
    
    temp=binary[31-j];
    binary[31-j]=binary[j];
    binary[j]=temp;
    
}

for(int j=0;binary[j]==-2147483648;j++)
{
    
    binary[j]=0;
    
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
   return; 
}

/* ******************************************** */


int main() {
    int mode;
    double o1,o2;
    char opera='a',bin1[50],bin2[50];
    int posi;
    
  //  printf("\nEnter operand:\n");
//    scanf("%lf",o1);
    
    printf("Enter mode: \n 1) Decimal \n 2) Binary \n 3)  Matricies \n 4) Exit\n");
    scanf("%d",&mode);
        
    switch(mode){
        case 1:
    
    printf("Input operand:\n");
    scanf(" %lf",&o1);
        
    printf("\n Operations:\n+ - addition\n/ - division\n- - subtraction\n* - multiplication\n^ - exponentiation\n| - titration\n");
    

    
    printf("Input operation: +, -, *, /, ^, |\n");
    scanf(" %c",&opera);
    
    
    while(opera!='='){

    printf("\n%lf %c :",o1,opera);
    scanf("%lf",&o2);
    
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
        
       /* case '|':
        o1= tetr(o1,o2);
        break;  */
        
        case 'a':
        break;
        default :
        printf("Enter valid operation");

    }
        printf("%lf\n",o1);
        printf("Input operation: +, -, *, /, ^, | or = : \n");
        scanf(" %c",&opera);
    
    
    }
    
    printf("%lf",o1);
    break;
    
    case 2:
        


        printf("\nEnter a Binary number:\n");
        scanf("%s",bin1);
        binarr(bin1);
        
        printf("\nIs %s to be treated as positive(1) or negative(0), Enter 1 or 0: ",bin1);
        scanf("%d",&posi);
        o1= btd(posi,bin1);
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

        o1=btd(posi,bin1);
        dtb(o1,output);
        
        break;
        
        case '+':
        scanf("%s",bin2);
        binarr(bin2);
        
        printf("Is %s to be treated as positive(1) or negative(0), Enter 1 or 0: ",bin2);
        scanf("%d",&posi);
        
        o2=btd(posi,bin2);
        
        o1+=o2;
        
        break;
        
        case'-':
        scanf("%s",bin2);
        binarr(bin2);
        
        printf("\nIs %s to be treated as positive(1) or negative(0), Enter 1 or 0: ",bin2);
        scanf("%d",&posi);
        
        o2=btd(posi,bin2);
        
        o1-=o2;
        break;
        
        case '*':
        scanf("%s",bin2);
        binarr(bin2);
            
        printf("\nIs %s to be treated as positive(1) or negative(0), Enter 1 or 0: ",bin2);
        scanf("%d",&posi);
        
        o2=btd(posi,bin2);
        
        o1*=o2;
        break;
        
        case '/':
        scanf("%s",bin2);
        binarr(bin2);
        
        printf("\nIs %s to be treated as positive(1) or negative(0), Enter 1 or 0: ",bin2);
        scanf("%d",&posi);
        
        o2=btd(posi,bin2);
        
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
        
        o1=(int)o1 & (int)o2;
        
        break;
        
        
        case '|':
        
        scanf("%s",bin2);
        binarr(bin2);
              
        printf("\nIs %s to be treated as positive(1) or negative(0), Enter 1 or 0: ",bin2);
        scanf("%d",&posi);
        o2=btd(posi,bin2);
        
        o1=(int)o1 | (int)o2;
        
        break;
        
        
        case '^':
        
        scanf("%s",bin2);
        binarr(bin2);
                
        printf("\nIs %s to be treated as positive(1) or negative(0), Enter 1 or 0: ",bin2);
        scanf("%d",&posi);
        o2=btd(posi,bin2);
        
        o1=(int)o1 ^ (int)o2;
        
        break;
        
        default :
        printf("Enter valid operation");
        break;

    }

// The section of code below just 
        dtb(o1,output);//inputs int value from o1 to output why cause o1 is the variable containg the output of the opeartion
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

        printf("\n%s %c %s: ",bin1,opera,bin2);
        

        swap1dinttochar(32,output,bin1);


        dis1diarr(32,output);
        
        if(bin1[0]=='1'){posi=0;}else{posi=1;}
        printf(" (%d)",btd(posi,bin1));
        

        printf("\n\nInput Next operation: c, +, -, !, or =. \n");
        scanf(" %c",&opera);

    }
    
    printf("\n%s (%lf)",bin1,o1);
    break;

case 3:    
          //List of all avalible Operations for Matricies
    printf("\n Operations:\n+ - addition\n/ - division\n- - subtraction\n* - multiplication\n^ - exponentiation\n| - titration\n");
    //
    
    //For decleration of any user defined Array total number of rows and columns are needed
        printf("For a matrix of size r x c, Enter value of r:\n");
        int r,c;
        scanf("%d",&r);

        printf("Enter value of c:\n");
        scanf("%d",&c);

        int Matrix1[r][c];
        printf("\nthe size of matrix = %d\n",sizeof(Matrix1)/sizeof(Matrix1[0][0]));

    switch(opera){

        
        default :
        printf("Enter valid operation");

    
        printf("Input operation\n");
        scanf(" %c",&opera);
    
    
    
    
    printf("%lf",o1);
break;




}
}//ye switch mode ka bracket
    return 0;
}
