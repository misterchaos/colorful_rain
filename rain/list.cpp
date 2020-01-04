#include"rain.h"

void CreatList(rainDrop** ppHead) {
	*ppHead = (rainDrop*)malloc(sizeof(rainDrop));
	(*ppHead)->next = NULL;
}


int Insert(rainDrop** ppHead, rainDrop* pN) { //²åÈë
	if (ppHead == NULL || pN == NULL) {
		printf("can not insert");
		return -1;
	}

	rainDrop *p = (*ppHead);
	if (p==NULL) {
		p = pN;
		pN->next = NULL;
	}
	else {
		while (p->next) {
			p = p->next;
		}
		p->next = pN;
		pN->next = NULL;
	}
	return 0;
}

int Delete(rainDrop** ppHead, rainDrop* pN) { //É¾³ý
	if (ppHead == NULL || pN == NULL) {
		return -1;
	}

	rainDrop* tmp = *ppHead;
	while (tmp->next != pN) {
		tmp = tmp->next;
	}
	tmp->next = pN->next;

	free(pN);
	pN = NULL;
	return 0;
}




int DeleteFellRainDrop(rainDrop** ppHead) { //É¾³ý
	if (ppHead == NULL ) {
		return -1;
	}

	rainDrop* p = (*ppHead)->next;
	
	while (p) {
		if (p->del==1) {
			rainDrop *q = p;
			p = p->next;
			Delete(ppHead, q);
		}
		else {
		    p = p->next;
		}
	}

	return 0;
}



int GetNumber(rainDrop* L) {
	int n=0;
	if (L == NULL) {
		return n;
	}
	rainDrop* p = L->next;
	while (p)
	{
		n++;
		p = p->next;
	}
	return n;
}


int FreeList(rainDrop* L)
{
	rainDrop* p = L;
	if (L == NULL) {
		return -1;
	}
	while (p)
	{
		p = L->next;
		free(L);
		L = p;
	}
	printf("the list has been free\n");
	return 1;
}

void Traverse(rainDrop* L,void (*visit)(rainDrop*)) {
	if (L == NULL) {
		return;
	}
	rainDrop* p = L->next;
	while (p)
	{
		visit(p);
		p = p->next;
	}
}
