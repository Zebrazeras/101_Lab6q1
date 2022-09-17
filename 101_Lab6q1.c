#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

int csum;
void *runner(void *param);

int main(int argc, char *argv[]){

    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    pthread_create(&tid, &attr, runner, argv[1]);
    
    int upper = atoi(argv[1]);
    int i;

    int msum = 0;
    if(upper > 0){
        for(i = 0; i <= upper; i++){
            msum += i;
        }    
    }
    pthread_join(tid, NULL);

    //printf("sum (parent thread) = %d\n",msum);
    //printf("sum (child thread) = %d\n",csum);
    printf("The difference between csum and msum = %d\n",abs(csum - msum));
    
    return 0;
}

void *runner(void *param){
    int upper = atoi(param) * 2;
    int i;

    csum = 0;
    if(upper > 0){
        for(i = 0; i <= upper; i++){
            csum += i;
        }    
    }
    pthread_exit(0);
}
/*2.5 หากไม่ join คำตอบที่ได้มีกี่แบบ อะไรบ้าง
Ans 2 แบบ
1.threadลูกทำงานเสร็จก่อนthreadแม่ (แต่แม่เป็นคนพิมพ์ข้อมูลออกมา)
2.threadแม่ทำงานเสร็จก่อนthreadลูก
*/