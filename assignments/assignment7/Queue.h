struct QNode{};
struct Queue{};
void InitQueue(Queue &Q);
int IsEmpty(Queue &Q);
void EnQueue(Queue &Q, QNode* newNode);
QNode* DeQueue(Queue &Q);
