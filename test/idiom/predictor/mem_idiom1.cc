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

#define NUM_THREADS 2

int counter;

void *thread(void *arg) {
  counter += 10;
  return NULL;
}

int main(int argc, char *argv[]) {
  pthread_t tids[NUM_THREADS];
  counter = 0;
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_create(&tids[i], NULL, thread, NULL);
  }
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(tids[i], NULL);
  }
  assert(counter == 10 * NUM_THREADS);
  return 0;
}

