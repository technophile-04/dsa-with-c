#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int deque[MAX];
int front = -1;
int rear = -1;

int deque_size()
{
    if (front == -1)
    {
        return 0;
    }
    return rear - front + 1;
}

void insert_back(int element)
{

    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (rear == MAX - 1)
        rear = 0;
    else
        rear = rear + 1;

    deque[rear] = element;
}

void insert_front(int element)
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("Queue Overflow \n");
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (front == 0)
        front = MAX - 1;
    else
        front = front - 1;

    deque[front] = element;
}

void delete_front()
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == MAX - 1)
        front = 0;
    else
        front = front + 1;
}

void delete_rear()
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
        rear = MAX - 1;
    else
        rear = rear - 1;
}

void display_queue()
{
    int front_pos = front, rear_pos = rear;
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements :\n");
    if (front_pos <= rear_pos)
    {
        while (front_pos <= rear_pos)
        {
            printf("%d ", deque[front_pos]);
            front_pos++;
        }
    }
    else
    {
        while (front_pos <= MAX - 1)
        {
            printf("%d ", deque[front_pos]);
            front_pos++;
        }
        front_pos = 0;
        while (front_pos <= rear_pos)
        {
            printf("%d ", deque[front_pos]);
            front_pos++;
        }
    }
    printf("\n");
}

int maxSumInWindow(int *arr, int n, int k, int *output)
{

    int i = 0, j = 0, sizeOfOutput = 0;

    while (j < n)
    {

        while (deque_size() > 0 && deque[rear] < arr[j])
        {
            delete_rear();
        }

        insert_back(arr[j]);

        if (j - i + 1 < k)
        {
            j++;
        }
        else
        {
            output[sizeOfOutput++] = deque[front];
            if (arr[i] == deque[front])
            {
                delete_front();
            }
            i++;
            j++;
        }
    }

    return sizeOfOutput;
}

int main()
{
    int *arr, n, i, *output, sizeOfOutput, k = 0;
    printf("Enter number of elements:");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    output = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the window size:");
    scanf("%d", &k);

    sizeOfOutput = maxSumInWindow(arr, n, k, output);

    for (i = 0; i < sizeOfOutput; i++)
    {
        printf("%d ", output[i]);
    }

    return 0;
}
