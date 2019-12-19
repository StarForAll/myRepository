#include"IOlib.h"
pthread_mutex_t mutex;
pthread_cond_t q=PTHREAD_COND_INITIALIZER;
static int share=0;
void *reader(void *param){
	pthread_mutex_lock(&mutex);
	printf("-------reader-------\n");
	int i=(int)param;
	while(share<100){
		printf("-------readerWhile-------\n");
		share+=2;
		printf("share=%d:reaader.\n",share);
                if(share%2!=0){
                        readFile(FILENAME,i);
                        pthread_cond_signal(&q);
                }else{
                        pthread_cond_wait(&q,&mutex);
                        break;
                }
		pthread_mutex_unlock(&mutex);
        }
	return NULL;
}
void *writer(void *param){
	pthread_mutex_lock(&mutex);
	printf("-------writer-------\n");
        int i=(int)param;
        while(share<100){
		printf("-------writerWhile-------\n");
		printf("share=%d:writer.\n",share);
		if(share%2==0){
			share++;
			writeFile(FILENAME,i,share,NULL);
			pthread_cond_signal(&q);
		}else{
			pthread_cond_wait(&q,&mutex);
			break;
		}
		pthread_mutex_unlock(&mutex);
        }
        return NULL;
}
int main(){
	pthread_t tid[2];
	int ret=0;
	void *(*pt[2])();
	pt[0]=reader;
	pt[1]=writer;
	pthread_mutex_init(&mutex,NULL);
	createNewFile(FILENAME);
	for(int i=0;i<2;i++){
		if(i%2==0){
			printf("writeThread\n");
			ret=pthread_create(&tid[i],NULL,pt[1],(void*)i);
		}else{
			printf("readerThread\n");
			ret=pthread_create(&tid[i],NULL,pt[0],(void*)i);
		}
		if(ret!=0){
			perror("create thread failed!\n");
			return 1;
		}
	}
	int i=2;
	while(i-->0){
		pthread_join(tid[i],NULL);
	}
	return 0;
}
