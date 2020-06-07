#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
using namespace std;
string univ_mn, A,B,C;




//Функция считывания информации из файла 
void INFO_FILE()
{
     ifstream fin("C:\\Users\\brrri\\OneDrive\\Study\\Alg Diskr Math\\LB\\LB1 -Mnogestvo - Bit Shkal\\mnogestvo.txt");
     if (!fin)
         cout << "ФАЙЛ ПУСТ" << endl;
     else
    { 
        	fin >> univ_mn>>A>>B>>C;
        	fin.close();
        	cout << "Множества загружены" << endl;
	}
}


//функция преобразования множеств
string PREO(string dano, string univ_mn)
{
	string str;
	bool ravenstvo=false;
	
	for(int i=0;i<univ_mn.size();i++)
	{
		for(int j=0;j<dano.size();j++)
			if (dano[j]==univ_mn[i])
			{
				str+='1';//устанавливаем единичку т.к. элементы множеств совпали
				ravenstvo=true;
			}
		if(!ravenstvo)	
			str+='0';
		ravenstvo=false;	
	}
	

	return str;
}

//Функция объединения множеств
string obedinenie(string mn_1,string mn_2)
{
	string otvet;
	for(int i=0;i<univ_mn.size();i++)
	{
		if (mn_1[i]=='0')
		{
			if(mn_2[i]=='1')
				otvet+= '1';
			else
				otvet+= '0'; 
		}
		else otvet+='1';
	}
	return otvet;
}


//Функция пересечения множеств
string peresechenie(string mn_1,string mn_2)
{
	string otvet;
	for(int i=0;i<univ_mn.size();i++)
	{
		if (mn_1[i]=='0')
			otvet+= '0';
		else if (mn_2[i]=='0')
				otvet+= '0'; 
		else otvet+='1';
	}
	return otvet;
}

//Функция разности множеств
string raznost(string mn_1,string mn_2)
{
	string otvet;
	for(int i=0;i<univ_mn.size();i++)
	{
		if (mn_1[i]=='0')
			otvet+= '0';
		else if (mn_2[i]=='1')
				otvet+= '0'; 
		else otvet+='1';
	}
	return otvet;
}

//Функция дополнения множества
string dopolnenie(string mn_1)
{
	string otvet;
	for(int i=0;i<univ_mn.size();i++)
	{
		if (mn_1[i]=='1')
			otvet+= '0';
		else otvet+= '1';
	}
	return otvet;
}

//Функция вычисления выражения
string vuragen(string A,string B, string C)
{
	string otvet;
	otvet=peresechenie(dopolnenie(obedinenie(dopolnenie(raznost(A,B)),C)),A);
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
    string otvet;
        
	
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
            	cout<<endl<<"Универсальное множество: "<<univ_mn<<endl;
            	
				cout<<"Множество A: "<<A<<endl;
				A= PREO (A,univ_mn);//Преобразовываем множество А
				
				
				cout<<"Множество B: "<<B<<endl;
				B= PREO (B,univ_mn);//Преобразовываем множество B
            	
				cout<<"Множество C: "<<C<<endl;
				C= PREO (C,univ_mn);//Преобразовываем множество C
				
				
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
								if(name_1=="A") otvet= A;
								if(name_1=="B") otvet= B;
								if(name_1=="C") otvet= C;
							}
							else if(name_1=="A")
							{
								if(name_2=="B") otvet= obedinenie(A,B);
								if(name_2=="C") otvet= obedinenie(A,C);
							}
							else if(name_1=="B")
							{
								if(name_2=="A") otvet= obedinenie(B,A);
								if(name_2=="C") otvet= obedinenie(B,C);
							}
							else if(name_1=="C")
							{
								if(name_2=="A") otvet= obedinenie(C,A);
								if(name_2=="B") otvet= obedinenie(C,B);
							} 
							
							cout<<endl<<"РЕЗУЛЬТАТ ОБЪЕДИНЕНИЯ: ";
							for(int i=0;i<univ_mn.size();i++)
	  							if(otvet[i]=='1') cout<<univ_mn[i];
							cout<<endl;
							
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
								if(name_1=="A") otvet= A;
								if(name_1=="B") otvet= B;
								if(name_1=="C") otvet= C;
							}
							else if(name_1=="A")
							{
								if(name_2=="B") otvet= peresechenie(A,B);
								if(name_2=="C") otvet= peresechenie(A,C);
							}
							else if(name_1=="B")
							{
								if(name_2=="A") otvet= peresechenie(B,A);
								if(name_2=="C") otvet= peresechenie(B,C);
							}
							else if(name_1=="C")
							{
								if(name_2=="A") otvet= peresechenie(C,A);
								if(name_2=="B") otvet= peresechenie(C,B);
							} 
							
							cout<<endl<<"РЕЗУЛЬТАТ ПЕРЕСЕЧЕНИЯ: ";
							for(int i=0;i<univ_mn.size();i++)
	  							if(otvet[i]=='1') cout<<univ_mn[i];
							cout<<endl;
							
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
								if(name_1=="A") otvet= A;
								if(name_1=="B") otvet= B;
								if(name_1=="C") otvet= C;
							}
							else if(name_1=="A")
							{
								if(name_2=="B") otvet= raznost(A,B);
								if(name_2=="C") otvet= raznost(A,C);
							}
							else if(name_1=="B")
							{
								if(name_2=="A") otvet= raznost(B,A);
								if(name_2=="C") otvet= raznost(B,C);
							}
							else if(name_1=="C")
							{
								if(name_2=="A") otvet= raznost(C,A);
								if(name_2=="B") otvet= raznost(C,B);
							} 
							
							cout<<endl<<"РЕЗУЛЬТАТ РАЗНОСТИ: ";
							for(int i=0;i<univ_mn.size();i++)
	  							if(otvet[i]=='1') cout<<univ_mn[i];
							cout<<endl;
							
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
					if(name_1=="A") otvet= dopolnenie(A);
					else if(name_1=="B") otvet= dopolnenie(B);
					else if(name_1=="C") otvet= dopolnenie(C);							
					else 
					{
						cout<<"ОШИБКА!!! Имя множества введено неверно"<<endl;
						break;
					}		
					
					cout<<endl<<"РЕЗУЛЬТАТ ДОПОЛНЕНИЯ: ";
					for(int i=0;i<univ_mn.size();i++)
  						if(otvet[i]=='1') cout<<univ_mn[i];
					cout<<endl;
						
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
					otvet= vuragen(A,B,C);		
					
					cout<<endl<<"РЕЗУЛЬТАТ ВЫРАЖЕНИЯ: ";
					for(int i=0;i<univ_mn.size();i++)
  						if(otvet[i]=='1') cout<<univ_mn[i];
					cout<<endl;
						
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
