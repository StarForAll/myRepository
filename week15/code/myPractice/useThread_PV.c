#include"IOlib.h"
sem_t empty,full;
static int share=0;
void *reader(void *param){
	int i=(int)param;
	while(1){
                sem_wait(&full);
                if(share<100){
                        readFile(FILENAME,i);
                        sem_post(&empty);
                }else{
                        sem_post(&empty);
                        break;
                }
        }
	return NULL;
}
void *writer(void *param){
        int i=(int)param;
        while(1){
		sem_wait(&empty);
		if(share<100){
			//写入操作要在数据操作之前.
			writeFile(FILENAME,i,share,NULL);
			share=share+1;
			sem_post(&full);
		}else{
			sem_post(&full);
			break;
		}
        }
        return NULL;
}
int main(){
	pthread_t tid[TN];
	int ret=0;
	void *(*pt[2])();
	pt[0]=reader;
	pt[1]=writer;
	ret = sem_init(&empty,0,1);
	ret = sem_init(&full,0,0);
	createNewFile(FILENAME);
	for(int i=0;i<TN;i++){
		if(i%2==0){
			ret=pthread_create(&tid[i],NULL,pt[1],(void*)i);
		}else{
			ret=pthread_create(&tid[i],NULL,pt[0],(void*)i);
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
	return 0;
}
