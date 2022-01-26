/* 13218027 - Rafiq Satria Yudha                                    */
/********************************************************************/
/* Tujuan : Program Round Robin                       */
/********************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct qnode{
	int waktu;
	int proses;
	struct qnode* next;
};
struct Queue{
	struct qnode *front,*rear;
};
struct qnode* newNode(int k,int i)
{
    struct qnode* temp = (struct qnode*)malloc(sizeof(struct qnode));
    temp->waktu = k;
    temp->proses=i;
    temp->next = NULL;
    return temp;
}
struct Queue* createQueue()
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}
void enQueue(struct Queue* q, int k, int i)
{
    struct qnode* temp = newNode(k,i);

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
 
    q->rear->next = temp;
    q->rear = temp;
}
void enQueuenode(struct Queue* q, struct qnode *k)
{
    if (q->rear == NULL) {
        q->front = q->rear = k;
        return;
    }
 
    q->rear->next = k;
    q->rear = k;
}
int deQueue(struct Queue* q)
{
	int proses;
    if (q->front == NULL)
        return-1;

    struct qnode* temp = q->front;
 
    q->front = q->front->next;
 
    if (q->front == NULL)
    {
        q->rear = NULL;
	}
	proses=temp->proses;
    free(temp);
    return proses;
}
void deQueueenQueue(struct Queue* q)
{
    if (q->front == NULL)
        return;

    struct qnode* temp = q->front;
 
    q->front = q->front->next;
    temp->next=NULL;
    enQueuenode(q,temp);
}
void printqueue(struct Queue* q)
{
	struct qnode* temp = (struct qnode*)malloc(sizeof(struct qnode));
	temp=q->front;
	while(temp!=NULL)
	{
		printf(" P-%d ",temp->proses);
		temp=temp->next;
	}
}
int main()
{
	int N,kuantum,i=0,totalwaktu=0,posisiinput=0,selesai=0,resetkuantum;
	int* waktudatang;
	int* waktuproses;
	struct Queue* q = createQueue();
	printf("Input Jumlah Proses: ");
	scanf("%d",&N);
	waktudatang = (int*)malloc(N * sizeof(int));
	waktuproses = (int*)malloc(N * sizeof(int));
	printf("Input Kuantum : ");
	scanf("%d",&kuantum);
	for(i=0;i<N;i++)
	{
		printf("Waktu datang P-%d : ",i);
		scanf("%d",(waktudatang+i));
		printf("Waktu proses P-%d : ",i);
		scanf("%d",(waktuproses+i));
		totalwaktu+=*(waktuproses+i);
	}
	i=0;
	printf("\nRound Robin\n%5s|%10s|%10s\n","Waktu","Antrian","Output");
	enQueue(q,*(waktuproses+posisiinput),posisiinput);
	printf("%5d| ",i);
	printqueue(q);
	printf("\n");
	posisiinput+=1;
	resetkuantum=0;
	for(i=1;i<totalwaktu+1;i++)
	{
		q->front->waktu-=1;
		if(q->front->waktu==0)
		{
			
			if(*(waktudatang+posisiinput)==i)
			{
				resetkuantum=i;
				selesai=deQueue(q);
				enQueue(q,*(waktuproses+posisiinput),posisiinput);
				printf("%5d| ",i);
				printqueue(q);
				printf("|%5sP-%d\n"," ",selesai);
				posisiinput+=1;
			} else
			{
				resetkuantum=i;
				selesai=deQueue(q);
				printf("%5d| ",i);
				printqueue(q);
				printf("|%5sP-%d\n"," ",selesai);
			}
			
		}
		else
		{
			if(*(waktudatang+posisiinput)==i)
			{
				if(resetkuantum+kuantum==i)
				{
					resetkuantum=i;
					deQueueenQueue(q);
					enQueue(q,*(waktuproses+posisiinput),posisiinput);
					printf("%5d| ",i);
					printqueue(q);
					printf("\n");
					posisiinput+=1;
				}else
				{
					enQueue(q,*(waktuproses+posisiinput),posisiinput);
					printf("%5d| ",i);
					printqueue(q);
					printf("\n");
					posisiinput+=1;
				}
			}else
			{
				if(resetkuantum+kuantum==i)
				{
					resetkuantum=i;
					deQueueenQueue(q);
					printf("%5d| ",i);
					printqueue(q);
					printf("\n");
				}
			}
				
		}
		
	}
	return 0;
}

