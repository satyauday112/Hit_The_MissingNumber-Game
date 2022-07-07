#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<conio.h>

int timer();
int randomnum();
int form();
int game();
int main(){
    int a;
    printf("Welcome!\nHit the Missing Number\n");
    game(1);
    return 0;
}
int form(int seq0,int lvl0,int elm0[lvl0][lvl0]){
    int rw,clm,elm=1,rep=1;
    if(lvl0<=3){
    for(rw=0;rw<3;rw++){
        for(clm=0;clm<3;clm++){
            if(elm==seq0){
                printf("%c\t",'*');
            }
            else{
                printf("%d\t",elm);
            }
            elm++;
        }
        printf("\n");
    }
    }
    if(lvl0>3){
        for(rw=0;rw<lvl0;rw++){
        for(clm=0;clm<lvl0;clm++){
            if(elm0[rw][clm]==seq0 && rep==1){
                printf("%c\t",'*');
                rep--;
            }
            else{
                printf("%d\t",elm0[rw][clm]);
            }
        }
        printf("\n");
    }
    }
}
int timer(){
        return rand()%4;
}
int randomnum(){
    int rdnum;
    rdnum=rand()%10;
    if(rdnum==0){
        randomnum();
    }
    else{
        return rdnum;
    }
}
int game(int lvl){
    int i,j,opt=0,seq=0,elm_arr[lvl][lvl];
        if(lvl>3){
            elm_arr[lvl][lvl];
            for(i=0;i<=lvl;i++){
                for(j=0;j<lvl;j++){
                    elm_arr[i][j]=randomnum();
                }
            }
        }
        form(seq,lvl,elm_arr);
        seq=randomnum();
        printf("\n");
        form(seq,lvl,elm_arr);
        printf("Enter Number: ");
        sleep(timer());
        if(kbhit()==1){
            opt=getch();
            opt=opt-48;
            printf("%d\n",opt);
        }
        if(opt==seq){
            if(lvl<=10){
                printf("You Won\n");
                printf("You are in Level-%d\n",lvl+1);
                game(lvl+1);
            }
            else{
                printf("You have cleared all levels\nThanks for Playing!");
                return 0;
            }
        }
        else{
            printf("\nTry Again\n\n");
             game(lvl);
        }
}
