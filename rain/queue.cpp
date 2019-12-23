#include "rain.h"

int data_size = sizeof(rainDrop);

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q) {
	Q->front = Q->rear = (Node*)malloc(sizeof(Node));
	if (Q->front == NULL) {
		printf("��������ʧ��...");
		return;
	}
	Q->front->data = (rainDrop*)malloc(data_size);
	Q->length = 0;
	Q->front->data = NULL;
	Q->front->next = NULL;
	printf("�������гɹ�...\n");
	return;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
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
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-OK; δ��-FAIL
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
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-OK; ʧ��-FAIL
 *  @notice      : �����Ƿ��
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
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-OK; ʧ��-FAIL
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q) {
	return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-OK; ʧ��-FAIL
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, rainDrop *data) {
	Node*p = (Node*)malloc(sizeof(Node));
	p->data = (rainDrop*)malloc(data_size);
	if (p == NULL) {
		printf("�޷������Ԫ��...");
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
	printf("��ӳɹ�\n");
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-OK; ʧ��-FAIL
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

	printf("���ӳɹ�,ʣ����������%d\n",Q->length);
	return OK;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
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
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
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

