#include<stdio.h>
#include<stdlib.h>
#define Pul_Size 30*1024

char* pul;			/*Вершина пула*/
typedef struct Hole_inf{
	char* ptr;
	int size;
	} Hinf;
char* Fhole;			/*Вершина списка "дыр"*/

/*Выделение памяти под пул и настройка вершины списка "дыр" на начало пула*/
int init_pul()
{

	if(!(pul=(char*)malloc(Pul_Size))) return 0;
	Fhole=pul;
	((Hinf*)Fhole)->ptr=NULL;
	((Hinf*)Fhole)->size=Pul_Size-sizeof(Hinf);

	return 1;
}

char* GetMem(int raz)
{
	char* Lhole=Fhole;
	char* npos=((Hinf*)Lhole)->ptr;
    char* Lhole1;
	char* npos1;

    /*Поиск первой подходящей*/
	while(npos!=NULL){
		if(((Hinf*)Lhole)->size<raz){
			Lhole=npos;
			npos=((Hinf*)Lhole)->ptr;
		}
		else break;
 	}
 	
     /*Поиск следующей походящей*/
	if(npos!=NULL){
        Lhole1=Lhole;
        Lhole=npos;
		npos=((Hinf*)Lhole)->ptr;
		int i=0;
		do{
            if(((Hinf*)Lhole)->size<raz){
                Lhole=npos;
			    npos=((Hinf*)Lhole)->ptr;
			    i++;
                }
                else {
                    if(i>=1){
                        Lhole=Lhole1;
                        npos=((Hinf*)Lhole1)->ptr;
                    }
                    break;
                }
            }while(npos!=NULL);
    }
	/*Подходит ли она по размеру*/
	if(((Hinf*)Lhole)->size<raz){
		puts("No memory for pul");
		exit(1);
	}

	if(((Hinf*)Lhole)->size>raz){

		/*Разбиваем и Удаляем подходящую "дырку" из списка*/

		if(Lhole!=Fhole){

			/*Ищем ближайшую верхнюю "дыру" от Lhole*/
			npos=Fhole;
			while(((Hinf*)npos)->ptr!=Lhole)
npos=((Hinf*)npos)->ptr;

			/*переписываем ее указатель*/
			((Hinf*)npos)->ptr=Lhole+sizeof(Hinf)+raz;

			/*вставляем оставшийся "кусок" в список*/
			npos=Lhole+sizeof(Hinf)+raz;
			((Hinf*)npos)->ptr=((Hinf*)Lhole)->ptr;
			((Hinf*)npos)->size=((Hinf*)Lhole)->size-raz-sizeof(Hinf);
			((Hinf*)Lhole)->size=raz;

		}
		else{
			/*Переписываем вершину списка*/
			Fhole+=sizeof(Hinf)+raz;
			((Hinf*)Fhole)->ptr=((Hinf*)Lhole)->ptr;
			((Hinf*)Fhole)->size=((Hinf*)Lhole)->size-raz-sizeof(Hinf);
			((Hinf*)Lhole)->size=raz;
		}
	}
	/*Если размеры "дыры" и запрашиваемой памяти равны */
	else{
		if(Lhole!=Fhole){
			npos=Fhole;
			while(((Hinf*)npos)->ptr!=Lhole)
npos=((Hinf*)npos)->ptr;
			((Hinf*)npos)->ptr=((Hinf*)Lhole)->ptr;
		}
		else{
			Fhole=((Hinf*)Lhole)->ptr;
		}
	}


	return Lhole;
}

void FreeMem(char* pr)
{
	char* hpos=Fhole;
	char* lpos=((Hinf*)Fhole)->ptr;

	if(pr<Fhole){
		/*Ищем смежную снизу "дыру"*/
		if((pr+sizeof(Hinf)+((Hinf*)pr)->size)==Fhole){
			((Hinf*)pr)->ptr=((Hinf*)Fhole)->ptr;
			((Hinf*)pr)->size+=((Hinf*)Fhole)-> size+sizeof(Hinf);
			Fhole=pr;
		}
		/*Если нет смежных дыр*/
		else{
			((Hinf*)pr)->ptr=Fhole;
			Fhole=pr;
		}
	}
	else{
		/*Ищем между каких "дырок" лежит pr*/
		while((lpos<pr)&&(lpos!=NULL)){
			hpos=lpos;
			lpos=((Hinf*)hpos)->ptr;
		}
		if(lpos!=NULL){
			/*Верхняя смежная или верхняя и нижняя смежные*/
			if((hpos+sizeof(Hinf)+((Hinf*)hpos)->size)==pr){
				((Hinf*)hpos)-> size+=sizeof(Hinf)+((Hinf*)pr)->size;
				pr=hpos;
				if((pr+sizeof(Hinf)+((Hinf*)pr)-> size)==lpos){
					((Hinf*)pr)->ptr=((Hinf*)lpos)->ptr;
					((Hinf*)pr)-> size+=sizeof(Hinf)+((Hinf*)lpos)->size;
				}
				return;
			}
			/*Нижняя смежная*/
			else{
				if((pr+sizeof(Hinf)+((Hinf*)pr)-> size)==lpos){
					((Hinf*)pr)->ptr=((Hinf*)lpos)->ptr;
					((Hinf*)pr)-> size+=sizeof(Hinf)+((Hinf*)lpos)->size;
					((Hinf*)hpos)->ptr=pr;
				}
				return;
			}
			/*Если нет смежных "дыр"*/
			((Hinf*)hpos)->ptr=pr;
			((Hinf*)pr)->ptr=lpos;
		}
		if(lpos==NULL){
			((Hinf*)hpos)->size+=sizeof(Hinf)+((Hinf*)pr)-> size;
		}
	}
}




void Get_Print(char* pr)
{
	printf("\n***get mem***\nFhole=%p\t Fhole ptr=%p\tFhole size=%d\npr=%p\tpr size=%d\n",Fhole,
	((Hinf*)Fhole)->ptr,((Hinf*)Fhole)->size,pr,((Hinf*)pr)->size);
}

void Free_Print()
{
	printf("\n***free mem***\nFhole=%p\t Fhole ptr=%p\tFhole size=%d\n",Fhole,
    ((Hinf*)Fhole)->ptr,((Hinf*)Fhole)->size);
}

main()
{
	char* pr[4];
	if(!init_pul()){
		puts("No memory for pul");
		exit(1);
	}

	printf("pul=%p\nsize=%d\n",pul,((Hinf*)pul)->size);

	pr[0]=GetMem(10*1024);
	Get_Print(pr[0]);
	pr[1]=GetMem(7*1024);
	Get_Print(pr[1]);
	pr[2]=GetMem(10*1024);
	Get_Print(pr[2]);
	FreeMem(pr[1]);
	Free_Print();
	pr[3]=GetMem(1*1024);
	Get_Print(pr[3]);
	FreeMem(pr[3]);
	Free_Print();
	FreeMem(pr[0]);
	Free_Print();
	FreeMem(pr[2]);
	Free_Print();
	free(pul);
getchar();
}
