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
Fn to convert any binary number into decimal reqs power fn
********************************************* */
int btd(int positive,char a[])//Input is an 1d array that contains the binary values
{
int i =0,k=0,sm=0;

int length=0;
    while((a[i]!= '\0'))
    {   
        if(((a[i]=='1')||(a[i]=='0')))//The condition is so because via some user err some chars in the array may be invalid those arent counted
        {
        length++;//Evaluates the length of binary number
        }
        i++;
    }
//printf("%d",length); //working as it should

int b[length];
//if the number is negative in nature then first take its compliment, eval that as int and then add 1
if(positive==0)
{
    
    for(int j =0;j<i;j++)
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
   

for (int j = 0;j<i;j++)//total elements in binary array =i and we have to check all of em irrespective of wether they are valid or not
{
    if (a[i-1-j]=='1')//but to store well check wether the inputs are valid or not i-1 is the last elem of array
    {
    b[k]=1;
    }
    else if(a[i-1-j]=='0')
    {
        b[k]=0;
    }
    else{k--;}//now if the value stored in bin array were to be invalid then the cell of B in which we r storing shouldnt change
    k++;
}


for(int j=0;j<i;j++){
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


int main() {
    int mode;
    double o1,o2;
    char opera='a',a[100];
    char bin2[100];
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
        scanf("%s",a);
        printf("\nIs %s to be treated as positive(1) or negative(0), Enter 1 or 0: ",a);
        scanf("%d",&posi);
        o1= btd(posi,a);
        printf("\n Operations:\nc - Conversion to decimal\n+ - addition\n- - subtraction\n* - multiplication\n^ - exponentiation\n| - titration\n");

    
        printf("Input operation: c, +, -, \n");
        scanf(" %c",&opera);
    
    
    while(opera!='='){

        printf("\n %s %c ",a,opera);
    
    switch(opera){

        case 'c':


        printf("%d\n",(int)o1);
        break;
        
        case '+':
        printf("\nEnter next Binary operand:\n");
        scanf("%s",bin2);
        
        printf("\nIs %s to be treated as positive(1) or negative(0), Enter 1 or 0: ",bin2);
        scanf("%d",&posi);
        o2=btd(posi,bin2);
        
        o1+=o2;
        
        printf("%lf\n",o1);
        break;
        
        default :
        printf("Enter valid operation");
        break;

    }
//to display output the code is to written indivisually
        
        printf("\n%s %c %s: ",a,opera,bin2);// the string here dosent change so well 
        printf("%lf\n",o1);
        printf("Input Next operation\n");
        scanf(" %c",&opera);
    
    
    }
    
    printf("%lf",o1);
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
    //

    //Initialization of the array
for (int i = 0; i < r; i++)
{
for(int j=0 ; j< c;j++){

Matrix1[i][j]=0;

}
}
//

//To input elements in the array and simultaneously show them
for (int i = 0; i < r; i++)
{
for(int j=0;j<c;j++){

for (int k = 0; k < r; k++)
{
for(int l=0;l<c;l++){
if (!l)//if L not equal 0
{
printf("| ");}

printf(" %d ",Matrix1[k][l]);
if (l==c-1)
{
printf(" |");}

}printf("\n");}


scanf("%d",&Matrix1[i][j]);

}}
//

//final display of M
printf("\nThe matrix A = \n");
for (int k = 0; k < r; k++)
{
for(int l=0;l<c;l++){
if (!l)//if L not equal 0
{
printf("| ");}

printf(" %d ",Matrix1[k][l]);
if (l==c-1)
{
printf(" |");}

}printf("\n");}
//

    while(opera!='='){

        printf("\n A %c ",opera);

        int Matrix2[r][c];
    //

    //Initialization of the array
for (int i = 0; i < r; i++)
{
for(int j=0 ; j< c;j++){

Matrix2[i][j]=0;

}
}
//

//To input elements in the array and simultaneously show them
for (int i = 0; i < r; i++)
{
for(int j=0;j<c;j++){

for (int k = 0; k < r; k++)
{
for(int l=0;l<c;l++){
if (!l)//if L not equal 0
{
printf("| ");}

printf(" %d ",Matrix2[k][l]);
if (l==c-1)
{
printf(" |");}

}printf("\n");}


scanf("%d",&Matrix2[i][j]);

}}
//

//final display of M
printf("\nThe matrix A = \n");
for (int k = 0; k < r; k++)
{
for(int l=0;l<c;l++){
if (!l)//if L not equal 0
{
printf("| ");}

printf(" %d ",Matrix2[k][l]);
if (l==c-1)
{
printf(" |");}

}printf("\n");}
//    
    switch(opera){

        
        default :
        printf("Enter valid operation");

    }
        printf("Input operation\n");
        scanf(" %c",&opera);
    
    
    }
    
    printf("%lf",o1);
break;





}//ye switch mode ka bracket
    return 0;
}
