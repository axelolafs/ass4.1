#ifndef FIFO_H
#define FIFO_H

const int FIFO_SIZE = 5;

class Fifo
{
public:
    Fifo();
    int get();
    void put(int item);
    bool is_empty();
    bool is_full();
    void reset();
private:
    int buffer[FIFO_SIZE];
    int* head = &buffer[0];
    int* tail = &buffer[0];
    int bufferLength = 0;
    // add variables pointing to the front and back of the buffer
};

#endif // FIFO_H