#include <stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <time.h>

int main()
{    
        printf("Welcome to Lottery ticket Scheduling \n\n");
        printf("**Press ENTER key to Continue**\n");  
        getchar(); 
        int z,i,j,k,yoyo;
        char process[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
        int arrival[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
        bool insert = false;
        int p = 0;
        int q=0;
        int highestticket = 0;
        int ticket[10][10];
        char temp[10];
        srand ( time(NULL) );
        for (z = 0; z < 10; z++) {
        	  
            int digit = rand()%30;
            arrival[z] = digit;
        }


        for (i = 0; i < 10; i++)
            for (j = 0; j < 9; j++) {
                if (arrival[j] >= arrival[j + 1]) {
                    int temp2 = arrival[j];
                    arrival[j] = arrival[j + 1];
                    arrival[j + 1] = temp2;

                    char temp1 = process[j];
                    process[j] = process[j + 1];
                    process[j + 1] = temp1;
                }
            }
        int time = arrival[0];

        int request[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
        int lottery[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
        for (z = 0; z < 10; z++) {
        	  
            int digit = rand()%20;

            if (digit == 0) {
                digit = 5;
            }

            request[z] = digit;

        }
        for (i = 0; i < 10; i++) {
            printf("\t process : %c",process[i]);
            printf("\t arival : %d",arrival[i]);
            printf("\t request : %d",request[i]);
            printf("\n\n");
        }
        printf(" Above are the processes that are getting arrival time and Requests :\n");
        printf("\n The winner will be generated among these processes having highest number of tickets :\n");
        printf(" Now Want to  generate the list of Winner ?\n Press 1 For Yes\n 0 For No :");
        scanf("%d",&yoyo);
        if(yoyo==1)
        {
        	goto x;
        	
		}
		else 
		{
			exit(0);
		}
		wait(200);
        x:
        {
			
        
        int z = rand()%8;
        if (z == 0)
            z = 5;
        printf("\nQuantom no : %d\n",z);
        printf("\t request");
        printf("\t process");
        printf("\t Lottery");
        printf("\t ticket");

        printf("\n---------------------------------------------------------\n");
        while ((request[0] + request[1] + request[2] + request[3] + 
                request[4] + request[5] + request[6] + request[7] + 
                request[8] + request[9]) > 0) {
            printf("\n---------------------------------------------------------\n");
            p = 0;
            for (i = 0; i < 10; i++) {
                if ((request[i] > 0))  {
                    lottery[i] = request[i] / 2;
                    if ((lottery[i] == 0) && (request[i] > 0))
                        lottery[i] = 1;
                    for (z = 0; z < lottery[i]; z++) {
                        ticket[i][z] = p++;
                        highestticket = p;
                    }
                    temp[i] = process[i];                


                    printf("\t" );
                    printf(" %d",request[i]);
                    printf("\t %c",temp[i]);
                    printf("\t %d",lottery[i]);
                    for (z = 0; z < lottery[i]; z++)
                        printf("\t  :: %d  ::",ticket[i][z]);
                    printf("\n");
                } else if ((request[i] > 0) && (time < arrival[i])) {
                    temp[i] = process[p];
                    lottery[i] = request[i] / 2;
                    if ((lottery[i] == 0) && (request[i] > 0))
                        lottery[i] = 1;
                    for (z = 0; z < lottery[i]; z++){
                        ticket[i][z] = p++;
                        highestticket=p;
                    }

                    if (request[i] > 0) {
                        time += z;
                    } else {
                        time += (request[i] + z);
                    }

                    printf("\t %d",time);
                    printf("\t %d",request[p]);
                    printf("\t %c",temp[i]);
                    printf("\t %d",lottery[i]);
                    for (z = 0; z < lottery[i]; z++)
                    printf("\t  :: %d  ::\n\n",ticket[i][z]);
                    printf("\n");

                }
            }
            int winner = rand()%(highestticket);
            for(i =0;i<10;i++)
                for(z=0;z<lottery[i];z++)
                    if(ticket[i][z]==winner)
                         q=i;
            printf("\n ---------------------------------------------------------");
            printf("\n winner number : %d  \n",winner );
        
            if ((request[q] > 0))  {
            temp[q] = process[q];
            request[q] -= z;


            if (request[q] > 0) {
                time += z;
            } else {
                time += (request[q] + z);
            }

            if (request[q] < 0) {
                request[q] = 0;
            }
            
            printf("\t %d", time);
            printf("\t %d",request[q]);
            printf("\t %c",temp[q]);
                printf("\n ");
            }else if ((request[q] > 0) && (time < arrival[q])) {
                                temp[q] = process[p];
            if (request[q] > 0) {
                time += z;
            } else {
                time += (request[q] + z);
            }

            printf("\t %d",time);
            printf("\t %d",request[q]);
            printf("\t %c",temp[q]);
            printf("\n");
            
        }
    }

}

}





