#define MAX 100


typedef struct
{
    int data;
    char key;
}Data_type;

typedef struct
{
    Data_type A[MAX + 1];
    int length;
}SqList;

void InsertSort(SqList L)
{
    int j = 0;
    for (int i = 2; i <= L.length; i++)
    {
        if (L.A[i].data < L.A[i - 1].data)
        {

            L.A[0] = L.A[i];
            for (j = i - 1; L.A[0].data < L.A[j].data; j--)
            {
                L.A[j + 1] = L.A[j];
            }
            L.A[j + 1] = L.A[j];
        }
        L.A[j + 1] = L.A[0];
    }
}