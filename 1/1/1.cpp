#include "stdafx.h"
#include <iostream>
using namespace std ;
/*Варіант 8. Створити динамічний класовий тип для роботи з рядком - масивом символів. 
Максимальна довжина рядка – 65535 символів. Вважати, що довжина рядка зберігається 
в нульовому елементі масиву.Передбачити операції створення, знищення, ініціалізації 
об’єкта, а також операції динамічного присвоєння та конкатенації. Операції створення, 
знищення та ініціалізації реалізувати за допомогою конструкторів та деструкторів,
решту операцій – за допомогою компонентних функцій.
*/
//-----------------------------------------------------------------------------
class mc {
public:
char * stroka ;
//..............................................................................................
	mc(int dlinna_stroky){
	stroka=new char [dlinna_stroky+1];
	for(int k=0;k<dlinna_stroky;k++)
	{
	stroka[k]='_';
	}
stroka [dlinna_stroky]='\0';
	}
//..............................................................................................
	~mc(){
	cout<<"znychuetza objekt ..."<<endl;
	delete stroka ;
	}
//..............................................................................................
void funkzia_dinamichnogo_prisvoenya(char * source,char * & destination)//source- то что присваеваем, destination-кому присваиваем
{
int source_length=strlen(source);
destination=new char[source_length+1];
for(int k=0;k<source_length;k++)
{
*(destination+k)=source[k];
}
destination[source_length]='\0';
}
//-----------------------------------------------------------------------------
char * concantenation (char * _1,char * _2)
{
int length_1=strlen(_1);
int length_2=strlen(_2);
int length_3=length_1+length_2;
char * _3=new char [length_3+1];
int index=0;
for (int k=0;k<length_1;k++)
{
_3[index]=_1[k];
index++;
}
for (int k=0;k<length_2;k++)
{
_3[index]=_2[k];
index++;
}
_3[length_3]='\0';
return _3;
}
};
//-----------------------------------------------------------------------------
int _tmain(int argc, _TCHAR* argv[])
{
cout<<"rasmer char v baytax ="<<sizeof(char)<<endl;
cout<<"max chislo kotoroe mochno zacodirovat v bayte "<<(2*2*2*2*2*2*2*2-1)<<endl;
mc * ob_1=new mc(20); 
cout<<"pokazyvaem inzialyzirovanuy konstruktorom stroky"<<endl;
cout<<ob_1->stroka<<endl;
char * stroka_1=NULL; 
ob_1->funkzia_dinamichnogo_prisvoenya(ob_1->stroka,stroka_1);
cout<<"pokazyvaem sroky1 : "<<stroka_1<<endl;
cout<<"esce odna demonstrazya prisvoenia"<<endl;
char * stroka_2=NULL; 
ob_1->funkzia_dinamichnogo_prisvoenya(" I love to get high grades",stroka_2);
cout<<"pokazyvaem sroky2 : "<<stroka_2<<endl;
cout<<"demonstrazya concantynazyy  : "<<ob_1->concantenation("loco","motive")<<endl;
ob_1->~mc();
	system ("pause");
	return 0;
}

