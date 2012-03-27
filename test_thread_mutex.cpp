#include<stdio.h>
#include<iostream>
#include<pthread.h>
#include<stdlib.h>
#include<time.h>

#define size 5

int counter=0;
//pthread_mutex_t mutex_1, mutex_2, mutex_3, mutex_4 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
//pthread_cond_t condition_2 =PTHREAD_COND_INITIALIZER;

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void wait(){
  time_t start_time=time(NULL);

  while(time(NULL)==start_time){

    //Time delay
  }
}
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
void *function_1(void *args);
void *function_2(void *args);
void *function_3(void *args);
void *function_4(void *args);
//*******************************************
main(){
  pthread_t thread_1, thread_2, thread_3, thread_4;
  pthread_create(&thread_1,NULL,function_1,NULL);
  pthread_create(&thread_2,NULL,function_2,NULL);
  pthread_create(&thread_3,NULL,function_3,NULL);
  pthread_create(&thread_4,NULL,function_4,NULL);
  pthread_create(&thread_3,NULL,function_3,NULL);
  pthread_create(&thread_2,NULL,function_2,NULL);
  pthread_create(&thread_1,NULL,function_1,NULL);

  pthread_join(thread_1,NULL);
  pthread_join(thread_2,NULL);
  pthread_join(thread_3,NULL);
  pthread_join(thread_4,NULL);

  exit(0);

}


void *function_1(void *args) {
  for(int ii=0;ii<size;ii++){
    pthread_mutex_lock(&mutex);
    counter++;
    printf("     Value_1: %d\n",counter);
    pthread_mutex_unlock(&mutex);
  }
}
void *function_2(void *args) {
  for(int ii=0;ii<size;ii++){
    pthread_mutex_lock(&mutex);
    counter--;
    printf("       Value_2: %d\n",counter);
    pthread_mutex_unlock(&mutex);
    if(counter>size) return(NULL);
  }
}

void *function_3(void *args) {
  for(int ii=0;ii<size;ii++){
    pthread_mutex_lock(&mutex);
    counter=counter+2;
    printf("         Value_3: %d\n",counter);
    pthread_mutex_unlock(&mutex);
  }
}

void *function_4(void *args) {
  for(int ii=0;ii<size;ii++){
    pthread_mutex_lock(&mutex);
    counter=counter-3;
    printf("           Value_4: %d\n",counter);
    pthread_mutex_unlock(&mutex);
  }
}
