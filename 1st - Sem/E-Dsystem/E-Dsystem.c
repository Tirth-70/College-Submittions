/*Here we go for Encryption and Decryption*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
void main()
{
  int a,pub_key,rece_key,priv_key;
  int n,i,x,y,o,j,count=0;
  int c[1000],d[1000];
  char str[1000];
  time_t t1;

  system("clear");

  printf("\t*****\t*****\t*****\t*****\t  ^_^ Feel safe to Encrypt/Decrypt Your Message ^_^\t*****\t*****\t*****\t*****");


  /* Initializing Random Values to Variable 'a' */
  srand((unsigned) time (&t1));
  a=rand()%20 + 1;

  //The method used below is call RSA(Rivest, Shamir, Adleman)...
  //This method uses a logic that can shared number securely via open network...


  /* Creating Public Key 
     Here 2 & 13 are random value
     and is default for program */
  pub_key=pow(2,a);
  printf("\n\n-->\tThis is your public Key : %d\n",pub_key%13);


  /* Getting the Private Key */
  printf("-->\tEnter Given Public Key  : ");
  scanf("%d",&rece_key);
  pub_key=pow(rece_key,a);
  priv_key=pub_key%13;
  printf("-->\tYour private key is %d",priv_key);

  //RSA logic Ends here...

  //Choose given...
  printf("\n\n\n*-*\tChoice from the following :\n\n-->\t1. Send Message.\n-->\t2. Receive Message.");
  printf("\n\n*-*\tEnter your choice(1 or 2) :");
  scanf("%d",&n);
  fflush(stdin);


  if(n==1)
  {
    system("clear");
    //For sending the message...
    //For encrypting message.... 

    fflush(stdin);
    printf("*-*\n\tEnter your message :");
    fgets(str, 1000, stdin);//Getting the message in strings upto 1000...

    printf("\n*-*\n\tEncrypted Message in integer to share : ");
    for(i=0;i<strlen(str);i++)
    {
      c[i]=priv_key+str[i];//Encrpyting the message using private key with the help of ASCII value...
      printf("%d",c[i]);//Gives the user a number which is Encrypted and user have to share that number without any worries😇...
    }
    printf("\n\n\n\n");
    printf("\t*****\t*****\t*****\t*****\t ^_^ THANK YOU FOR USING SERVICE ^_^ \t*****\t*****\t*****\t*****");
    printf("\n\n\n\t");
  }
  else if(n==2)
  {
    system("clear");
    //For receving the message...

    fflush(stdin);
    printf("*-*\n\tEnter the recieved message : ");
    fgets(str, 1000, stdin);//It gets the Encrypted message which is sended by the user... 


    //A little complex logic below...
    for(i=0,j=0;i<strlen(str);i=i+2,j++)
    {
      //below is logic which divides the number accordingly
      x=str[i]-48;
      y=str[i+1]-48;
      o=(x*10)+y;
      count++;

      if(o<=20 && o>=10)
      {
        o=((str[i]-48)*100)+((str[i+1]-48)*10)+str[i+2]-48;
        c[j]=o;//While dividing it stores the value in here..
        i++;
      }
      else{
        c[j]=o;//While dividing it stores the value in here too..
      }
    }


    for(j=0;j<count;j++)
    {
      d[j]=c[j]-priv_key;//Then the computer Decryptes it using his private key(Which we generated earlier)...
    }


    printf("\n*-*\n\tYour Decrypted Message is : ");

    for(i=0;i<count-1;i++)
    {
      printf("%c",d[i]);//Finally It prints the Encrypted message...
    }

    printf("\n\n\n\n");
    printf("\t*****\t*****\t*****\t*****\t ^_^ THANK YOU FOR USING SERVICE ^_^ \t*****\t*****\t*****\t*****");
    printf("\n\n\n\t");
  }
  else{ 
    system("clear");

    printf("\n*-*\n\tInvalid Entry!!\n\tPlease Try Again ^_^ ");
    printf("\n\n\n\t");
  }
}