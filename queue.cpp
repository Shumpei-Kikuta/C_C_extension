#include <iostream>
using namespace std;

int head, tail;

struct ProcessQueue{
    char name[11];
    int time;
};

void dequeue(){
    head += 1;
}

void enqueue(ProcessQueue *queue, ProcessQueue *process){
    queue[tail] = *process;
    tail += 1;
    head += 1;
}

void process(ProcessQueue *queue, int q){
    int sum = 0;
    while (tail != head){
        if ((queue[head]).time <= q){
            sum += (queue[head]).time;
            cout << queue[head].name << " " << sum << endl;
            dequeue();
        }
        else if (queue[head].time > q){
            sum += q;
            queue[head].time -= q;
            enqueue(queue, &queue[head]);
        }
        head %= 100000;
        tail %= 100000;
    }
}


int main(){
    int n, q;
    cin >> n >> q;
    head = 0;
    tail = n;
    ProcessQueue queue[100000];
    for (int i = 0; i < n; i++){
        cin >> queue[i].name >> queue[i].time;
    }
    process(queue, q);
    return 0;
}