// Copyright 2011 The University of Michigan
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// Authors - Jie Yu (jieyu@umich.edu)

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <pthread.h>

#define NUM_THREADS 3

pthread_mutex_t mutex0 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond0 = PTHREAD_COND_INITIALIZER;

void *thread0(void *arg) {
  int res;
  res = pthread_mutex_lock(&mutex0);
  res = pthread_cond_wait(&cond0, &mutex0);
  res = pthread_mutex_unlock(&mutex0);
  return NULL;
}

void *thread1(void *arg) {
  int res;
  res = pthread_mutex_lock(&mutex0);
  res = pthread_cond_wait(&cond0, &mutex0);
  res = pthread_mutex_unlock(&mutex0);
  return NULL;
}

void *thread2(void *arg) {
  int res;
  res = pthread_cond_signal(&cond0);
  res = pthread_cond_signal(&cond0);
  return NULL;
}

int main(int argc, char *argv[]) {
  pthread_t tids[NUM_THREADS];
  pthread_create(&tids[0], NULL, thread0, NULL);
  pthread_create(&tids[1], NULL, thread1, NULL);
  pthread_create(&tids[2], NULL, thread2, NULL);
  pthread_join(tids[0], NULL);
  pthread_join(tids[1], NULL);
  pthread_join(tids[2], NULL);
  return 0;
}

