#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
using namespace std;

struct MNOGESTVO {char elem; MNOGESTVO *next;};
MNOGESTVO *A_spisok,*B_spisok,*C_spisok,*univ_spisok,*otvet;

string univ_mn, A, B, C;

//������� ���������� ���������� �� ����� 
void INFO_FILE()
{
     ifstream fin("C:\\Users\\brrri\\OneDrive\\Study\\Alg Diskr Math\\LB\\LB2 -Mnogestvo -Dinam Spisk\\mnogestvo.txt");
     if (!fin)
         cout << "���� ����" << endl;
     else
    { 
        	fin >> univ_mn>>A>>B>>C;
        	fin.close();
        	cout << "��������� ���������" << endl;
	}
}

//������� ��������� �� �����
void all_elem(MNOGESTVO* in)
{
	if (!in) 
	{
		cout<<"��������� ��� "<<endl;
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

//������� ���������� �������� � ���������
MNOGESTVO* inser(MNOGESTVO* in, char elem)
{
	MNOGESTVO *new_node = new MNOGESTVO; //�������� ������� ������
    new_node -> elem = elem;
    new_node->next = NULL;
    if (!in)//������ ������ 
    {
		return new_node;
	}
    	
    else
    {
    	MNOGESTVO *cur_node = in; //��������� ��������� �� ������ ������
    	while (cur_node->next)//���� �� ����� ������
    		{	
				cur_node=cur_node->next;
			}
    	cur_node->next = new_node;
    	return in;
	}
}

//������� �������������� ��������
MNOGESTVO* PREO(string dano, MNOGESTVO* in)
{		
	if (!dano.size())//��������� ������ 
    	{
    		cout<<"��������� ������"<<endl;
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


//������� ����������� ��������
MNOGESTVO* obedinenie(MNOGESTVO* otvet,MNOGESTVO* mn_1, MNOGESTVO* mn_2)
{
	otvet=NULL;
    MNOGESTVO *cur_mn1 = mn_1, *cur_mn2 = mn_2;  //��������� ��������� �� ������ �������
    
	//���� ���� �� �������� �����
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


//������� ����������� ��������
MNOGESTVO* peresechenie(MNOGESTVO* otvet,MNOGESTVO* mn_1, MNOGESTVO* mn_2)
{
	otvet=NULL;
    MNOGESTVO *cur_mn1 = mn_1, *cur_mn2 = mn_2;  //��������� ��������� �� ������ �������
    
	//���� ���� �� �������� �����
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

//������� �������� ��������
MNOGESTVO* raznost(MNOGESTVO* otvet,MNOGESTVO* mn_1, MNOGESTVO* mn_2)
{
	otvet=NULL;
    MNOGESTVO *cur_mn1 = mn_1, *cur_mn2 = mn_2;  //��������� ��������� �� ������ �������
    
	//���� ������ ��������� �����
	if  (cur_mn2 == NULL) 
	{
        otvet = mn_1;
		return otvet;
    }
    
    //���� ������  ��������� �����
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

//������� ���������� ��������
MNOGESTVO* dopolnenie(MNOGESTVO* otvet,MNOGESTVO* mn_1)
{
	otvet=NULL;
    MNOGESTVO *cur_mn1 = mn_1, *cur_mn2 = univ_spisok;  //��������� ��������� �� ������ �������
    
	//���� ��������o �����
	if (cur_mn1 == NULL) 
	{
        otvet = univ_spisok;
        return otvet;
    }
    
	if (cur_mn2 == NULL) 
	{
        cout<<"������������� ��������� ������ !!!";
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
//������� ���������� ���������
MNOGESTVO* vuragen(MNOGESTVO* A,MNOGESTVO* B, MNOGESTVO* C)
{
	otvet=NULL;
	otvet=peresechenie(otvet,dopolnenie(otvet,obedinenie(otvet,dopolnenie(otvet,raznost(otvet,A,B)),C)),A);
	return otvet;
}


//������� menu ���������� ��������� �������
int menu()
{
	int variant;
    cout << endl << "�������� ������� >>> ";
    cin >> variant;
    return variant;
}


//������� �������
int main()
{
	bool exit = false; //������ ������ �� ���������  
	bool preo = false;//������ �������������� ��������
    int variant; //����� �������� �� ����
    string name_1,name_2;
        
	
	//������� �� ����� ���� ����
	cout <<endl<<endl
		 << "1. ��������� \n"
         << "2. ������������� � ������� �� �����\n"
         << "3. �������� ����������� ���� ��������\n"
         << "4. �������� ����������� ���� ��������\n"
         << "5. �������� �������� ���� ��������\n"
         << "6. �������� ����������\n"
         << "7. ���������� ���������\n"
         << "8. �����\n" << endl;
	
	while (!exit)
	{
		variant = menu(); //�������� ����� �������� �� ����

    	switch (variant) 
		{
        	case 1:
            	
				cout <<endl<< " **��������� ���������� �� �����**" << endl;
            	INFO_FILE (); //�������� ��������������� �������
            	break;
        	
			case 2:
            	
				cout <<endl<< " **������������� � ������� �� �����**" << endl;
            	cout<<endl<<"������������� ���������: "<<univ_mn;
            	univ_spisok=NULL;
            	univ_spisok= PREO (univ_mn,univ_spisok);//��������������� ��������� �
				cout<<" and ";
				all_elem(univ_spisok);
            	
				cout<<"��������� A: "<<A;
				A_spisok=NULL;
				A_spisok= PREO (A,A_spisok);//��������������� ��������� �
				cout<<" and ";
				all_elem(A_spisok);
				
				cout<<"��������� B: "<<B;
				B_spisok=NULL;
				B_spisok= PREO (B, B_spisok);//��������������� ��������� B
				cout<<" and ";
				all_elem(B_spisok);
            	
				cout<<"��������� C: "<<C;
				C_spisok=NULL;
				C_spisok= PREO (C,C_spisok);//��������������� ��������� C
				cout<<" and ";
				all_elem(C_spisok);
				
				preo=true;
				break;
        	
			case 3:
        		
				cout<<endl<< " **�������� ����������� ��������** "<< endl;
        		if(!preo)//���� ��������� �� ��������������
        		{
        			cout<<"������!!!  ������������ ���������!!!!!!!"<<endl;
            		break;
				}
				else
				{
					cout<<"������� ��� ������� ���������:"<<endl<<"A, �, �: ";
					cin>>name_1;
					cout<<"������� ��� ������� ���������:"<<endl<<"A, �, �: ";
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
							
							cout<<endl<<"��������� �����������: ";
							all_elem(otvet);

							
							break;	
						}
					else 
					{
						cout<<"������!!! ����� �������� ������� �������"<<endl;
						break;
					}
				}
			case 4:
        		
				cout<<endl<< " **�������� ����������� ��������** "<< endl;
        		if(!preo)//���� ��������� �� ��������������
        		{
        			cout<<"������!!!  ������������ ���������!!!!!!!"<<endl;
            		break;
				}
				else
				{
					cout<<"������� ��� ������� ���������:"<<endl<<"A, �, �: ";
					cin>>name_1;
					cout<<"������� ��� ������� ���������:"<<endl<<"A, �, �: ";
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
							
							cout<<endl<<"��������� �����������: ";
							all_elem(otvet);
							
							break;	
						}
					else 
					{
						cout<<"������!!! ����� �������� ������� �������"<<endl;
						break;
					}
				}
			case 5:
        		
				cout<<endl<< " **�������� �������� ��������** "<< endl;
        		if(!preo)//���� ��������� �� ��������������
        		{
        			cout<<"������!!!  ������������ ���������!!!!!!!"<<endl;
            		break;
				}
				else
				{
					cout<<"������� ��� ������� ���������:"<<endl<<"A, �, �: ";
					cin>>name_1;
					cout<<"������� ��� ������� ���������:"<<endl<<"A, �, �: ";
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
							
							cout<<endl<<"��������� ��������: ";
							all_elem(otvet);
							
							break;	
						}
					else 
					{
						cout<<"������!!! ����� �������� ������� �������"<<endl;
						break;
					}
				}
			
			case 6:
        		
				cout<<endl<< " **�������� ����������** "<< endl;
        		if(!preo)//���� ��������� �� ��������������
        		{
        			cout<<"������!!!  ������������ ���������!!!!!!!"<<endl;
            		break;
				}
				else
				{
					cout<<"������� ���������:"<<endl<<"A, �, �: ";
					cin>>name_1;
					if(name_1=="A") otvet= dopolnenie(otvet,A_spisok);
					else if(name_1=="B") otvet= dopolnenie(otvet,B_spisok);
					else if(name_1=="C") otvet= dopolnenie(otvet,C_spisok);						
					else 
					{
						cout<<"������!!! ��� ��������� ������� �������"<<endl;
						break;
					}		
					
					cout<<endl<<"��������� ����������: ";
					all_elem(otvet);
						
					break;	
				}
			
				case 7:
        		
				cout<<endl<< " **���������� ���������: ** "<< endl;
        		if(!preo)//���� ��������� �� ��������������
        		{
        			cout<<"������!!!  ������������ ���������!!!!!!!"<<endl;
            		break;
				}
				else
				{
					otvet= vuragen(A_spisok,B_spisok,C_spisok);		
					
					cout<<endl<<"��������� ���������: ";
					all_elem(otvet);
						
					break;	
				}
	
        	case 8:
            	cout << "����� �� ���������..." << endl;
            	exit=true;
            	break;
        	default:
            	cout << "�� ������� �������� �������" << endl;
    	}
	}
	
    return 0;
}



