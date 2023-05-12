#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include <unistd.h>
#include <arpa/inet.h>
#define SIZE 1024

int a,pub_key,rece_key,priv_key;
int i,x,y,o,j,count=0;
int c[1000],d[1000];
char str[1000];
time_t t1;


void receiving(int socketfd)
{
  recv(socketfd, str, sizeof(str), 0);

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


  printf("\n*-*\n\n\tYour Decrypted Message is : ");

  for(i=0;i<count-1;i++)
  {
    printf("%c",d[i]);//Finally It prints the Encrypted message...
  }
}



int main()
{
  /* Initializing Random Values to Variable 'a' */
  srand((unsigned) time (&t1));
  a=rand()%20 + 1;

  char *ip = "127.0.0.1";
  int port = 5555;
  int e;

  int sockfd;
  struct sockaddr_in server_addr;
  FILE *fp;
  char *filename = "/Users/jayswaminarayan/Desktop/Groupcn/test/test1.txt";

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd < 0) {
    perror("[-]Error in socket");
    exit(1);
  }
  printf("[+]Server socket created successfully.\n");

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = port;
  server_addr.sin_addr.s_addr = inet_addr(ip);

  e = connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
  if(e == -1) {
    perror("[-]Error in socket");
    exit(1);
  }
	printf("[+]Connected to Server.\n");


  //The method used below is call RSA(Rivest, Shamir, Adleman)...
  //This method uses a logic that can shared number securely via open network...


  /* Creating Public Key 
  Here 2 & 13 are random value
  and is default for program */
  pub_key=pow(2,a); 
  pub_key=pub_key%13;

  system("clear");
  printf("\n*-*\n\n-->\tThis is your public Key : %d\n",pub_key);

  char s_pub_key[100];
  char s_rece_key[100];
  sprintf(s_pub_key, "%d", pub_key);//it converts the integer to sending purposes..

  //sending and receiving the public key for common public key....
  recv(sockfd, s_rece_key, sizeof(s_rece_key), 0);
  send(sockfd, s_pub_key, sizeof(s_pub_key), 0);


  rece_key = atoi(s_rece_key);// it converts the string to an integer if there is any..

  pub_key=pow(rece_key,a);
  priv_key=pub_key%13;


  printf("\n*-*\n\n-->\tYour private key is %d\n",priv_key);

  //RSA logic Ends here...
  receiving(sockfd);

  printf("\n\n\n\n*---*--*--  ^_^ THANK YOU FOR USING OUR SERVICE ^_^  --*--*---*\n\n");
  return 0;
}