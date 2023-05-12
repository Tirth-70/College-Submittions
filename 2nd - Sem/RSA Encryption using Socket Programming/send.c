#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include <arpa/inet.h>
#define SIZE 1024

int pub_key,rece_key,priv_key;
int i,a;
int c[1000];
char e_str[1000],str[1000],temp[100];
time_t t1;

void sending()
{
    printf("\n\n*-*\n\tEnter your message : ");
    fgets(str, 1000, stdin);


    printf("\n*-*\n\tEncrypted Message in integer to share : ");

    c[0] = priv_key+str[0];
    sprintf(e_str, "%d", c[0]);  //it converts the integer to string.
    
    for(i=1;i<strlen(str);i++)
    {
        c[i]=priv_key+str[i];//Encrpyting the message using private key with the help of ASCII value...
        sprintf(temp, "%d", c[i]);//it converts the integer to string.
        strcat(e_str,temp);
        printf("%d",c[i]);//Gives the user a number which is Encrypted and the number gets shared later using socket programing..
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

    int sockfd, new_sock;
    struct sockaddr_in server_addr, new_addr;
    socklen_t addr_size;
    char buffer[SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("[-]Error in socket");
        exit(1);
    }
    printf("[+]Server socket created successfully.\n");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = port;
    server_addr.sin_addr.s_addr = inet_addr(ip);

    e = bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if(e < 0) {
        perror("[-]Error in bind");
        exit(1);
    }
    printf("[+]Binding successfull.\n");

    if(listen(sockfd, 10) == 0){
        printf("[+]Listening....\n");
    }else{
        perror("[-]Error in listening");
    exit(1);
    }

    addr_size = sizeof(new_addr);
    new_sock = accept(sockfd, (struct sockaddr*)&new_addr, &addr_size);
    /* Connection has successfully establised here... */


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
    sprintf(s_pub_key, "%d", pub_key);//converts integer to string for sending purpose..

    send(new_sock, s_pub_key, sizeof(s_pub_key), 0);

    /* Getting the Private Key */
    recv(new_sock, s_rece_key, sizeof(s_rece_key), 0);

    rece_key = atoi(s_rece_key); //It will convert the string to an integer if there is any...


    pub_key=pow(rece_key,a);
    priv_key=pub_key%13;

    printf("\n*-*\n\n-->\tYour private key is %d",priv_key);

    //RSA logic Ends here...

    //so this function basically encrypts the data and stores to an variable named 'e_str' .....
    sending(); 

    send(new_sock, e_str, sizeof(str), 0);//just sending it to the other side...

    printf("\n\n\n\n*---*--*--  ^_^ THANK YOU FOR USING OUR SERVICE ^_^  --*--*---*\n\n");
    return 0;
}