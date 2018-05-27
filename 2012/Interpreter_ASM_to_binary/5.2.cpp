#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;
char clear(char metka[], char operat[], char operand[], char comment[],char buffer[])
{
	int i = 0;
	for (i = 0; i < sizeof(metka); i++)
	{
		metka[i] = '\0';
	}
	for (i = 0; i < sizeof(operat); i++)
	{
		operat[i] = '\0';
	}
	for (i = 0; i < sizeof(operand); i++)
	{
		operand[i] = '\0';
	}
	for (i = 0; i < sizeof(comment); i++)
	{
		comment[i] = '\0';
	}
	memset(buffer,0,sizeof(char)*256);
}
void razbor(char metka[], char operat[], char operand[], char comment[],char buffer[])
{
    char *met,*comm,*_operatorptr,*_operandptr;
    int i = 0;
	comm = met = _operatorptr = _operandptr = buffer;
		
        //Поиск метки
			do
			{
				if (*met == '\t' || *met == ' ')
				{
					break;
				}
				metka[i] = *met;
				*met = '\0';
				*met++;
				i++;
			}
			while(1);
			i = 0;
 		//Вывод оператора
		while(*_operatorptr != '\n')
		{
			if (isalpha(*_operatorptr))
			{
				while (isalpha(*_operatorptr))
				{
					operat[i] = *_operatorptr;
					*_operatorptr = '\0';
					_operatorptr++;
					i++;
				}
				i = 0;
				break;
			}
			*_operatorptr++;
		}

		//Вывод операнда
		_operandptr = _operatorptr;
		while (*_operandptr != '\n')
		{
			if (*_operandptr != '\t' && *_operandptr != ' ')
			{
				while (*_operandptr != '\t' && *_operandptr != ' ' && *_operandptr != '\n')
				{
					operand[i] = *_operandptr;
					i++;
					_operandptr++;
				}
				i=0;
				break;
			}
		
			*_operandptr++;
		}		
		//Вывод комментария	
        if(strcmp("BEGIN",operat) == 0 )
        for (i = 0; i < sizeof(comment); i++)comment[i] = '\0';
        else strcpy(comment, buffer + 16 );
//		printf("");
}
int get_hash(char *keyword)
{
	int result = 0;
	int x = 0;
	while (keyword[x] != '\0') 
	{
		result += (int) keyword[x]; // Transform the char to int
		x++;
	} 
	// h = (A * K) >> (w - m)
	result = (7 * (result))>>(8-1);
	return (int) result;
}
struct Point
	{
		int state;
		char *pointname;
		int value;
	};
struct Hash
	{
	   int key;
	   int state;
	   int code;
	};
int main()
{
	char metka[10] = "";
    char comment[100] = "";
    char buffer[256] = "";
    char operat[10]	= "";
    char operand[10] = "";
    char filename[] = "5final.asm";
    char *met,*comm,*_operatorptr,*_operandptr;
    int a = 0;
    int d = 0;
    int i = 0;
    int x = 0x0;
    int y = 0x3;
    int z = 0x0;
    int number = 0;
    int cell;
    struct Hash com[29];
	for(a = 0; a < 50; a++)
	{
        com[a].key =0;
    }
	char *keywords[29];  
	keywords[0] = "END";      com[0].state = 1;
	keywords[1] = "RB";       com[1].state = 1;
	keywords[2] = "DB";       com[2].state = 1;
	keywords[3] = "RW";       com[3].state = 1;
	keywords[4] = "DW";       com[4].state = 1;
	keywords[5] = "BEGIN";    com[5].state = 1;
	keywords[6] = "CALL";     com[6].state = 0;
	keywords[7] = "MOV";      com[7].state = 0;
	keywords[8] = "XCHG";     com[8].state = 0;
	keywords[9] = "IN";       com[9].state = 0;
	keywords[10] = "OUT";     com[10].state = 0;
	keywords[11] = "AAA";     com[11].state = 0;
	keywords[12] = "ADD";     com[12].state = 0;
	keywords[13] = "ADC";     com[13].state = 0;
	keywords[14] = "SBB";     com[14].state = 0;
	keywords[15] = "NEG";     com[15].state = 0;
	keywords[16] = "IMUL";    com[16].state = 0;
	keywords[17] = "IDIV";    com[17].state = 0;
	keywords[18] = "MUL";     com[18].state = 0;
	keywords[19] = "DIV";     com[19].state = 0;
	keywords[20] = "AND";     com[20].state = 0;
	keywords[21] = "OR";      com[21].state = 0;
	keywords[22] = "XOR";     com[22].state = 0;
	keywords[23] = "NOT";     com[23].state = 0;
	keywords[24] = "CMP";     com[24].state = 0;
	keywords[25] = "JMP";     com[25].state = 0;
	keywords[26] = "STA";     com[26].state = 0;
	keywords[27] = "HLT";     com[27].state = 0;
	keywords[28] = "LDA";     com[28].state = 0;
	FILE *f = fopen("struct_data.txt", "w");
	fprintf(f,"Name\tDirective/Command\tCode\n");
    for(a = 0; a < 29; a++)
    {
		if(com[a].state == 1)
		{
			com[a].code = 00;
	    }
		else
		{
			cell = get_hash(keywords[a]);
			while(com[cell].key != 0)
			{
				cell++;
                if(cell == 100)
                cell = 0;
			}
			com[a].code = cell;
			com[cell].key = 1;
        }
        fprintf(f,"%s\t\t%d\t\t%d\n",keywords[a],com[a].state,com[a].code);	
    }
    fclose(f);     
	
	struct Point hashes[10]; 
	for(a = 0; a < 10; a++)
	{
		hashes[a].pointname = NULL;
		hashes[a].value = 0;
		hashes[a].state =0;
	}
    a = 0;
	FILE *file;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                              /*ПЕРВЫЙ ПРОХОД*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	file = fopen(filename,"r");
	FILE *list = fopen("List.txt", "w");
	if (file == NULL) 
	{
        return 0;
	}
	while (fgets(buffer,sizeof(buffer),file))
	{
		razbor(metka, operat, operand, comment,buffer);
		printf("\n Metka: %s\tOperator: %s\tOperand: %s\tComment: %s\n",metka,operat,operand,comment);
        fprintf(list,"\nMetka: %s\tOperator: %s\tOperand: %s\tComment: %s\n",metka,operat,operand,comment);
        //Поиск адреса с которого будет загрузка программы
	    if(strcmp("BEGIN",operat) == 0 )//Находим START и берем eго операнд
		{
			sscanf(operand, "%x", &x);//char to int
		}
	    else
		{
			//Таблица меток
			//Анализ метки
	    hashes[a].pointname = (char *)malloc(10*sizeof(char));
	    strcpy(hashes[a].pointname, metka);
	    if (isalpha(*hashes[a].pointname))// если hashes[a].pointname начинается с символа
		{
			i=0;
			for(d=0;d<a;d++)//Цикл проверки на совпадение
			{
				if(strcmp(hashes[d].pointname, hashes[a].pointname) == 0 )//Если метки совпали то проверяем state
				{
					if(hashes[d].state == 1)//если определена метка                   
					{
						hashes[a].pointname= NULL;
						i = 1;
						break;
					}
					if(hashes[d].state == 0)//если не определена метка
					{
						hashes[d].value = x;
						hashes[d].state = 1;
						number++;
						hashes[a].pointname= NULL;
						i = 1;
					    break;
					}
				}
		    }
            if(i == 0)//если совпаления по меткам не было=>добавляем новую метку
           {
 				hashes[a].value = x;
				hashes[a].state = 1;
				number++;
				a++;
			}
			
		}
	    else hashes[a].pointname = NULL;
	    //Анализ операнда
		hashes[a].pointname = (char *)malloc(10*sizeof(char));
		strcpy(hashes[a].pointname, operand);
		if (isalpha(*hashes[a].pointname))
		{
			i=0;
			for(d=0;d<a;d++)//Цикл проверки на совпадение
			{
				if(strcmp(hashes[d].pointname, hashes[a].pointname) == 0 )//Если совпали метки
				{
					hashes[a].pointname= NULL;
					i = 1;
					break;
				}
		    }
		    if(i != 1) // Если совпадений не было
		    {
				hashes[a].value = 0;
				hashes[a].state =0;
		    	a++;
			}
		}
	    else hashes[a].pointname = NULL;
		x = x+ y;
	    }
	    clear(metka,operat,operand,comment,buffer);
	}
	
    fclose(file);
    fclose(list);
	FILE *fp = fopen("point_table.txt", "w");
    fprintf(fp,"Name\tValue\tState\n");
    for(a=0;a<number;a++)
    {
		fprintf(fp,"%s\t%x\t%d\n",hashes[a].pointname,hashes[a].value,hashes[a].state);
    }
    fclose(fp);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                               /*ВТОРОЙ ПРОХОД*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	printf("\n\nObjectcode\n");
	file = fopen(filename,"r");
	FILE *ob = fopen("cod.txt", "w");
	while (fgets(buffer,sizeof(buffer),file))
	{
		razbor(metka, operat, operand, comment,buffer);
		fprintf(ob,"%s\t%s\t%s\t",metka,operat,operand);	
		i=0;
		for(d=0; d<29; d++)
		{
			if(strcmp(operat,keywords[d]) == 0 )//Cравниваем operat с таблицей команд, если совпало то
			{
				if(com[d].state == 0)             //Если operat является командой то
				{
					if (operand[0]!='\0'&& operand[0]!='\n')//Если у оперетора есть операнд
					{
						for(a=0;a<10;a++)           //цикл сравнения operand  и таблицы меток
						{
							if(strcmp(operand,hashes[a].pointname) == 0 )// если operand совпал с таблицей меток,тo
							{
								fprintf(ob, "%d",com[d].code);     
			                    fprintf(ob, "%x\n",hashes[a].value);
								printf("%d",com[d].code);        //Склеиваем команду
								printf("%x\n",hashes[a].value);  // и Значение из таблицы меток
								break;
						    }						
						}
					}
					else//Если у оперптора нет операнда
					{
						printf("%d0000\n",com[d].code);
						fprintf(ob,"%d0000\n",com[d].code);
                        break;
					}										
				}
				else //Если Директива
				{
					if(strcmp("BEGIN",operat) != 0 && strcmp("END",operat) !=0)//Если не START или END
					{
						fprintf(ob,"00000");
						sscanf(operand, "%x", &z);
						fprintf(ob,"%d\n",z);
					}
					else printf("\n");
				}							
			}
		}	
		clear(metka, operat, operand, comment,buffer);
    }
	fclose(ob);        
    fclose(file);
	system("pause");
	return 0;
}
