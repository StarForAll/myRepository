#include"IOlib.h"
#include"ringBuffer.h"
sem_t mutex,space,product;
static int share=0;
u8 readBuffer[5];
int readLen;
void *consumer(void *param){
	//int i=(int)param;
	while(1){
                sem_wait(&product);
		sem_wait(&mutex);
		//消费
		readLen = readRingbuffer(readBuffer,5);
                printf("readRingbuffer len:%d\n",readLen);
                if(readLen > 0){
                    printf("readRingbuffer:");
                    for(int i=0;i<readLen;i++){
                        //printf("%c ",(char)readBuffer[i]);
			printf("%d ",(int)readBuffer[i]);
                    }
                    printf("\n");
		}
		sem_post(&mutex);
		sem_post(&space);
        }
	return NULL;
}
void *producter(void *param){
        //int i=(int)param;
        while(1){
		sem_wait(&space);
		sem_wait(&mutex);
		share++;
		//生产
		wirteRingbuffer((u8*)&share,1);
		sem_post(&mutex);
		sem_post(&product);
        }
        return NULL;
}
int main(){
	pthread_t tid[TN];
	int ret=0;
	void *(*pt[2])();
	pt[0]=consumer;
	pt[1]=producter;
	ret = sem_init(&mutex,0,1);
	if(ret!=0){
		perror("Semaphore mutex initialization failed!\n");
		exit(1);
	}
	ret = sem_init(&space,0,5);
	if(ret!=0){
                perror("Semaphore space initialization failed!\n");
                exit(2);
        }
	ret = sem_init(&product,0,0);
	if(ret!=0){
                perror("Semaphore product initialization failed!\n");
                exit(3);
        }
	initRingbuffer();
	for(int i=0;i<TN;i++){
		if(i%2==0){
			ret=pthread_create(&tid[i],NULL,pt[1],NULL);
		}else{
			ret=pthread_create(&tid[i],NULL,pt[0],NULL);
		}
		if(ret!=0){
			perror("create thread failed!\n");
			return 1;
		}
	}
	int i=TN;
	while(i-->0){
		pthread_join(tid[i],NULL);
	}
	releaseRingbuffer();
	return 0;
}
