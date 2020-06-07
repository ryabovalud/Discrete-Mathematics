#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
using namespace std;

struct MNOGESTVO {char elem; MNOGESTVO *next;};
MNOGESTVO *A_spisok,*B_spisok,*C_spisok,*univ_spisok,*otvet;

string univ_mn, A, B, C;

//Функция считывания информации из файла 
void INFO_FILE()
{
     ifstream fin("C:\\Users\\brrri\\OneDrive\\Study\\Alg Diskr Math\\LB\\LB2 -Mnogestvo -Dinam Spisk\\mnogestvo.txt");
     if (!fin)
         cout << "ФАЙЛ ПУСТ" << endl;
     else
    { 
        	fin >> univ_mn>>A>>B>>C;
        	fin.close();
        	cout << "Множества загружены" << endl;
	}
}

//Выводим множество на экран
void all_elem(MNOGESTVO* in)
{
	if (!in) 
	{
		cout<<"Елементов нет "<<endl;
	}
	
	else 
	{
		MNOGESTVO *node = in;
		while(node)
		{
			cout<<node->elem <<"->";
			node=node->next;
		}
		cout<<endl;
	}	
}

//Функция добавления элемента в множество
MNOGESTVO* inser(MNOGESTVO* in, char elem)
{
	MNOGESTVO *new_node = new MNOGESTVO; //Выделяем участок памяти
    new_node -> elem = elem;
    new_node->next = NULL;
    if (!in)//список пустой 
    {
		return new_node;
	}
    	
    else
    {
    	MNOGESTVO *cur_node = in; //Временный указатель на начало списка
    	while (cur_node->next)//Пока не конец списка
    		{	
				cur_node=cur_node->next;
			}
    	cur_node->next = new_node;
    	return in;
	}
}

//функция преобразования множеств
MNOGESTVO* PREO(string dano, MNOGESTVO* in)
{		
	if (!dano.size())//Множество пустое 
    	{
    		cout<<"Множество пустое"<<endl;
			return in;
		}
    	
    else
    {
    	for(int i=0;i<dano.size();i++)
    	{
    		in=inser(in, dano[i]);
		}
	}
  	return in;
}


//Функция объединения множеств
MNOGESTVO* obedinenie(MNOGESTVO* otvet,MNOGESTVO* mn_1, MNOGESTVO* mn_2)
{
	otvet=NULL;
    MNOGESTVO *cur_mn1 = mn_1, *cur_mn2 = mn_2;  //Временные указатели на начало списков
    
	//Если одно из множеств пусто
	if (cur_mn1 == NULL) {
        otvet = mn_2;
        return otvet;
    }
    if (cur_mn2 == NULL) {
        otvet = mn_1;
        return otvet;
    }
    
	if (cur_mn1->elem < cur_mn2->elem) 
	{
        otvet=inser(otvet,cur_mn1->elem );
        cur_mn1 = cur_mn1->next;
    }  
	else 
	{
        otvet=inser(otvet,cur_mn2->elem );
        cur_mn2 = cur_mn2->next;
    }
    
	while (cur_mn1 && cur_mn2) 
	{
        if (cur_mn1->elem < cur_mn2->elem) 
		{
            otvet=inser(otvet,cur_mn1->elem );
            cur_mn1 = cur_mn1->next;
        } 
		else if (cur_mn1->elem == cur_mn2->elem) 
		{
        	cur_mn1 = cur_mn1->next;
    	}
		else 
		{
            otvet=inser(otvet,cur_mn2->elem  );
            cur_mn2 =cur_mn2->next;
        }
    }
    if (cur_mn1) 
	{
        while (cur_mn1) 
		{
            otvet=inser(otvet,cur_mn1->elem  );
            cur_mn1 =cur_mn1->next;
        }
    }
    if (cur_mn2) {
        while (cur_mn2) {
            otvet=inser(otvet,cur_mn2->elem );
            cur_mn2 = cur_mn2->next;
        }
    }
    return otvet;
}


//Функция пересечения множеств
MNOGESTVO* peresechenie(MNOGESTVO* otvet,MNOGESTVO* mn_1, MNOGESTVO* mn_2)
{
	otvet=NULL;
    MNOGESTVO *cur_mn1 = mn_1, *cur_mn2 = mn_2;  //Временные указатели на начало списков
    
	//Если одно из множеств пусто
	if ((cur_mn1 == NULL) ||  (cur_mn2 == NULL) )
	{
        return otvet;
    }
    
	while (cur_mn1 && cur_mn2) 
	{ 
		if (cur_mn1->elem == cur_mn2->elem) 
		{
        	otvet=inser(otvet,cur_mn1->elem );
			cur_mn1 = cur_mn1->next;
        	cur_mn2 = cur_mn2->next;
    	}
    	else if (cur_mn1->elem < cur_mn2->elem) 
		{
            cur_mn1 = cur_mn1->next;
        }
		else 
		{
            cur_mn2 =cur_mn2->next;
        }
    }
    return otvet;
}

//Функция разности множеств
MNOGESTVO* raznost(MNOGESTVO* otvet,MNOGESTVO* mn_1, MNOGESTVO* mn_2)
{
	otvet=NULL;
    MNOGESTVO *cur_mn1 = mn_1, *cur_mn2 = mn_2;  //Временные указатели на начало списков
    
	//Если второе множество пусто
	if  (cur_mn2 == NULL) 
	{
        otvet = mn_1;
		return otvet;
    }
    
    //Если первое  множество пусто
	if  (cur_mn1 == NULL) 
	{
		return otvet;
    }
    
	while (cur_mn1 && cur_mn2) 
	{ 
		if (cur_mn1->elem == cur_mn2->elem) 
		{
			cur_mn1 = cur_mn1->next;
        	cur_mn2 = cur_mn2->next;
    	}
    	else if (cur_mn1->elem < cur_mn2->elem) 
		{
            otvet=inser(otvet,cur_mn1->elem );
			cur_mn1 = cur_mn1->next;
        }
    	else if (cur_mn1->elem > cur_mn2->elem) 
		{
			cur_mn2 = cur_mn2->next;
        }		
		else 
		{
            otvet=inser(otvet,cur_mn1->elem );
			cur_mn2 =cur_mn2->next;
        }
    }
    if (cur_mn1) 
	{
        while (cur_mn1) 
		{
            otvet=inser(otvet,cur_mn1->elem  );
            cur_mn1 =cur_mn1->next;
        }
    }
    return otvet;
}

//Функция дополнения множеств
MNOGESTVO* dopolnenie(MNOGESTVO* otvet,MNOGESTVO* mn_1)
{
	otvet=NULL;
    MNOGESTVO *cur_mn1 = mn_1, *cur_mn2 = univ_spisok;  //Временные указатели на начало списков
    
	//Если множествo пусто
	if (cur_mn1 == NULL) 
	{
        otvet = univ_spisok;
        return otvet;
    }
    
	if (cur_mn2 == NULL) 
	{
        cout<<"Универсальное множество пустое !!!";
        return NULL;
    }
    
	while (cur_mn1) 
	{
        if (cur_mn1->elem > cur_mn2->elem) 
		{
            otvet=inser(otvet,cur_mn2->elem );
            cur_mn2 = cur_mn2->next;
        } 
		else if (cur_mn1->elem == cur_mn2->elem) 
		{
        	cur_mn1 = cur_mn1->next;
        	cur_mn2 = cur_mn2->next;
    	}
    }
    if (cur_mn2) 
	{
        while (cur_mn2) 
		{
            otvet=inser(otvet,cur_mn2->elem  );
            cur_mn2 =cur_mn2->next;
        }
    }
    return otvet;
}
//Функция вычисления выражения
MNOGESTVO* vuragen(MNOGESTVO* A,MNOGESTVO* B, MNOGESTVO* C)
{
	otvet=NULL;
	otvet=peresechenie(otvet,dopolnenie(otvet,obedinenie(otvet,dopolnenie(otvet,raznost(otvet,A,B)),C)),A);
	return otvet;
}


//Функция menu возвращает выбранный вариант
int menu()
{
	int variant;
    cout << endl << "Выберите вариант >>> ";
    cin >> variant;
    return variant;
}


//ГЛАВНАЯ ФУНКЦИЯ
int main()
{
	bool exit = false; //кнопка выхода из программы  
	bool preo = false;//кнопка преобразования множеств
    int variant; //Номер варианта из меню
    string name_1,name_2;
        
	
	//Выводим на экран наше меню
	cout <<endl<<endl
		 << "1. Загрузить \n"
         << "2. Преобразовать и Вывести на экран\n"
         << "3. Операция объединения двух множеств\n"
         << "4. Операция пересечения двух множеств\n"
         << "5. Операция разности двух множеств\n"
         << "6. Операция дополнения\n"
         << "7. Вычисление выражения\n"
         << "8. Выйти\n" << endl;
	
	while (!exit)
	{
		variant = menu(); //Получаем номер варианта из меню

    	switch (variant) 
		{
        	case 1:
            	
				cout <<endl<< " **Загружаем информацию из файла**" << endl;
            	INFO_FILE (); //Вызываем соответствующую функцию
            	break;
        	
			case 2:
            	
				cout <<endl<< " **Преобразовать и вывести на экран**" << endl;
            	cout<<endl<<"Универсальное множество: "<<univ_mn;
            	univ_spisok=NULL;
            	univ_spisok= PREO (univ_mn,univ_spisok);//Преобразовываем множество А
				cout<<" and ";
				all_elem(univ_spisok);
            	
				cout<<"Множество A: "<<A;
				A_spisok=NULL;
				A_spisok= PREO (A,A_spisok);//Преобразовываем множество А
				cout<<" and ";
				all_elem(A_spisok);
				
				cout<<"Множество B: "<<B;
				B_spisok=NULL;
				B_spisok= PREO (B, B_spisok);//Преобразовываем множество B
				cout<<" and ";
				all_elem(B_spisok);
            	
				cout<<"Множество C: "<<C;
				C_spisok=NULL;
				C_spisok= PREO (C,C_spisok);//Преобразовываем множество C
				cout<<" and ";
				all_elem(C_spisok);
				
				preo=true;
				break;
        	
			case 3:
        		
				cout<<endl<< " **Операция Объединения множеств** "<< endl;
        		if(!preo)//Если множества не преобразованны
        		{
        			cout<<"ОШИБКА!!!  Преобразуйте множества!!!!!!!"<<endl;
            		break;
				}
				else
				{
					cout<<"Задайте имя первого множества:"<<endl<<"A, В, С: ";
					cin>>name_1;
					cout<<"Задайте имя второго множества:"<<endl<<"A, В, С: ";
					cin>>name_2;
					if ((name_1=="A"||name_1=="B"||name_1=="C")&&(name_2=="A"||name_2=="B"||name_2=="C"))
						{
							if(name_1==name_2) 
							{
								if(name_1=="A") otvet = A_spisok;
								if(name_1=="B") otvet = B_spisok;
								if(name_1=="C") otvet = C_spisok;
							}
							else if(name_1=="A")
							{
								if(name_2=="B") otvet= obedinenie(otvet,A_spisok,B_spisok);
								if(name_2=="C") otvet= obedinenie(otvet,A_spisok,C_spisok);
							}
							else if(name_1=="B")
							{
								if(name_2=="A") otvet= obedinenie(otvet,B_spisok,A_spisok);
								if(name_2=="C") otvet= obedinenie(otvet,B_spisok,C_spisok);
							}
							else if(name_1=="C")
							{
								if(name_2=="A") otvet= obedinenie(otvet,C_spisok,A_spisok);
								if(name_2=="B") otvet= obedinenie(otvet,C_spisok,B_spisok);
							} 
							
							cout<<endl<<"РЕЗУЛЬТАТ ОБЪЕДИНЕНИЯ: ";
							all_elem(otvet);

							
							break;	
						}
					else 
					{
						cout<<"ОШИБКА!!! Имена множеств введены неверно"<<endl;
						break;
					}
				}
			case 4:
        		
				cout<<endl<< " **Операция Пересечения множеств** "<< endl;
        		if(!preo)//Если множества не преобразованны
        		{
        			cout<<"ОШИБКА!!!  Преобразуйте множества!!!!!!!"<<endl;
            		break;
				}
				else
				{
					cout<<"Задайте имя первого множества:"<<endl<<"A, В, С: ";
					cin>>name_1;
					cout<<"Задайте имя второго множества:"<<endl<<"A, В, С: ";
					cin>>name_2;
					if ((name_1=="A"||name_1=="B"||name_1=="C")&&(name_2=="A"||name_2=="B"||name_2=="C"))
						{
							if(name_1==name_2) 
							{
								if(name_1=="A") otvet= A_spisok;
								if(name_1=="B") otvet= B_spisok;
								if(name_1=="C") otvet= C_spisok;
							}
							else if(name_1=="A")
							{
								if(name_2=="B") otvet= peresechenie(otvet,A_spisok,B_spisok);
								if(name_2=="C") otvet= peresechenie(otvet,A_spisok,C_spisok);
							}
							else if(name_1=="B")
							{
								if(name_2=="A") otvet= peresechenie(otvet,B_spisok,A_spisok);
								if(name_2=="C") otvet= peresechenie(otvet,B_spisok,C_spisok);
							}
							else if(name_1=="C")
							{
								if(name_2=="A") otvet= peresechenie(otvet,C_spisok,A_spisok);
								if(name_2=="B") otvet= peresechenie(otvet,C_spisok,B_spisok);
							} 
							
							cout<<endl<<"РЕЗУЛЬТАТ ПЕРЕСЕЧЕНИЯ: ";
							all_elem(otvet);
							
							break;	
						}
					else 
					{
						cout<<"ОШИБКА!!! Имена множеств введены неверно"<<endl;
						break;
					}
				}
			case 5:
        		
				cout<<endl<< " **Операция Разности множеств** "<< endl;
        		if(!preo)//Если множества не преобразованны
        		{
        			cout<<"ОШИБКА!!!  Преобразуйте множества!!!!!!!"<<endl;
            		break;
				}
				else
				{
					cout<<"Задайте имя первого множества:"<<endl<<"A, В, С: ";
					cin>>name_1;
					cout<<"Задайте имя второго множества:"<<endl<<"A, В, С: ";
					cin>>name_2;
					if ((name_1=="A"||name_1=="B"||name_1=="C")&&(name_2=="A"||name_2=="B"||name_2=="C"))
						{
							if(name_1==name_2) 
							{
								if(name_1=="A") otvet= A_spisok;
								if(name_1=="B") otvet= B_spisok;
								if(name_1=="C") otvet= C_spisok;
							}
							else if(name_1=="A")
							{
								if(name_2=="B") otvet= raznost(otvet,A_spisok,B_spisok);
								if(name_2=="C") otvet= raznost(otvet,A_spisok,C_spisok);
							}
							else if(name_1=="B")
							{
								if(name_2=="A") otvet= raznost(otvet,B_spisok,A_spisok);
								if(name_2=="C") otvet= raznost(otvet,B_spisok,C_spisok);
							}
							else if(name_1=="C")
							{
								if(name_2=="A") otvet= raznost(otvet,C_spisok,A_spisok);
								if(name_2=="B") otvet= raznost(otvet,C_spisok,B_spisok);
							} 
							
							cout<<endl<<"РЕЗУЛЬТАТ РАЗНОСТИ: ";
							all_elem(otvet);
							
							break;	
						}
					else 
					{
						cout<<"ОШИБКА!!! Имена множеств введены неверно"<<endl;
						break;
					}
				}
			
			case 6:
        		
				cout<<endl<< " **Операция Дополнения** "<< endl;
        		if(!preo)//Если множества не преобразованны
        		{
        			cout<<"ОШИБКА!!!  Преобразуйте множества!!!!!!!"<<endl;
            		break;
				}
				else
				{
					cout<<"Задайте множество:"<<endl<<"A, В, С: ";
					cin>>name_1;
					if(name_1=="A") otvet= dopolnenie(otvet,A_spisok);
					else if(name_1=="B") otvet= dopolnenie(otvet,B_spisok);
					else if(name_1=="C") otvet= dopolnenie(otvet,C_spisok);						
					else 
					{
						cout<<"ОШИБКА!!! Имя множества введено неверно"<<endl;
						break;
					}		
					
					cout<<endl<<"РЕЗУЛЬТАТ ДОПОЛНЕНИЯ: ";
					all_elem(otvet);
						
					break;	
				}
			
				case 7:
        		
				cout<<endl<< " **Вычисление выражения: ** "<< endl;
        		if(!preo)//Если множества не преобразованны
        		{
        			cout<<"ОШИБКА!!!  Преобразуйте множества!!!!!!!"<<endl;
            		break;
				}
				else
				{
					otvet= vuragen(A_spisok,B_spisok,C_spisok);		
					
					cout<<endl<<"РЕЗУЛЬТАТ ВЫРАЖЕНИЯ: ";
					all_elem(otvet);
						
					break;	
				}
	
        	case 8:
            	cout << "Выход из программы..." << endl;
            	exit=true;
            	break;
        	default:
            	cout << "Вы выбрали неверный вариант" << endl;
    	}
	}
	
    return 0;
}



