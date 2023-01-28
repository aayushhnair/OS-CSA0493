(i) #include <pthread.h>

void *thread_function(void *arg);

int main() {
    pthread_t thread_id;
    int status;
    status = pthread_create(&thread_id, NULL, thread_function, NULL);
    if (status != 0) {
        printf("Error creating thread\n");
        return 1;
    }
    printf("Thread created with ID: %ld\n", thread_id);
    // Other code here
    return 0;
}

void *thread_function(void *arg) {
    // Code for thread to execute
}

(ii) #include <pthread.h>

void *thread_function(void *arg);

int main() {
    pthread_t thread_id;
    int status;
    status = pthread_create(&thread_id, NULL, thread_function, NULL);
    if (status != 0) {
        printf("Error creating thread\n");
        return 1;
    }
    status = pthread_join(thread_id, NULL);
    if (status != 0) {
        printf("Error joining thread\n");
        return 1;
    }
    printf("Thread with ID %ld has joined\n", thread_id);
    // Other code here
    return 0;
}

void *thread_function(void *arg) {
    // Code for thread to execute
}

(iii)#include <pthread.h>

int main() {
    pthread_t thread1_id, thread2_id;
    int status;
    status = pthread_create(&thread1_id, NULL, thread_function1, NULL);
    if (status != 0) {
        printf("Error creating thread1\n");
        return 1;
    }
    status = pthread_create(&thread2_id, NULL, thread_function2, NULL);
    if (status != 0) {
        printf("Error creating thread2\n");
        return 1;
    }
    if (pthread_equal(thread1_id, thread2_id) != 0) {
        printf("Thread1 and Thread2 are equal\n");
    } else {
        printf("Thread1 and Thread2 are not equal\n");
    }
    // Other code here
    return 0;
}

void *thread_function1(void *arg) {
    // Code for thread1 to execute
}

void *thread_function2(void *arg) {
    // Code for thread2 to execute
}

(iv) #include <pthread.h>

void *thread_function(void *arg);

int main() {
    pthread_t thread_id;
    int status;
    status = pthread_create(&thread_id, NULL, thread_function, NULL);
    if (status != 0) {
        printf("Error creating thread\n");
        return 1;
    }
