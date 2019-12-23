#include "rain.h"

int data_size = sizeof(rainDrop);

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q) {
	Q->front = Q->rear = (Node*)malloc(sizeof(Node));
	if (Q->front == NULL) {
		printf("创建队列失败...");
		return;
	}
	Q->front->data = (rainDrop*)malloc(data_size);
	Q->length = 0;
	Q->front->data = NULL;
	Q->front->next = NULL;
	printf("创建队列成功...\n");
	return;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q) {
	ClearLQueue(Q);
	free(Q->front);
	Q->front = Q->rear = NULL;
	Q = NULL;
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-OK; 未空-FAIL
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q) {
	if (Q->length == 0) {
		return OK;
	}
	else
	{
		return FAIL;
	}
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-OK; 失败-FAIL
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, rainDrop *e) {

	memcpy(e, Q->front->data, data_size);
	if (e == NULL) {
		return FAIL;
	}
	else {
		return OK;
	}
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-OK; 失败-FAIL
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q) {
	return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-OK; 失败-FAIL
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, rainDrop *data) {
	Node*p = (Node*)malloc(sizeof(Node));
	p->data = (rainDrop*)malloc(data_size);
	if (p == NULL) {
		printf("无法入队新元素...");
		return FAIL;
	}
	memcpy(p->data, data, data_size);
	p->next = NULL;

	if (Q->length == 0) {
		Q->front = Q->rear = p;
	}
	else
	{
		Q->rear->next = p;
		Q->rear = p;
	}
	Q->length++;
	printf("入队成功\n");
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-OK; 失败-FAIL
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q) {

	Node*  p = Q->front;
	if (Q->length == 1) {
		Q->front = Q->rear = (Node*)malloc(sizeof(Node));
		Q->length = 0;
	}
	else
	{
		Q->front = p->next;
		Q->length--;
		free(p);
		p = NULL;
	}

	printf("出队成功,剩余结点数量：%d\n",Q->length);
	return OK;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q) {
	if (Q->length == 0) {
		return;
	}
	Node*p = Q->front;
	Node*q = p;
	Q->front = Q->rear = (Node*)malloc(sizeof(Node));
	Q->length = 0;
	while (p != NULL) {
		q = p;
		p = p->next;
		free(q->data);
		free(q);
	}
}


/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void(*foo)(rainDrop *q)) {
	if (Q == NULL || IsEmptyLQueue(Q)) {
		return FAIL;
	}
	Node* p = Q->front;
	while (p) {
		(*foo)(p->data);
		if (p->next == NULL) {
			return OK;
		}
		//printf("->");
		p = p->next;
	}
}

