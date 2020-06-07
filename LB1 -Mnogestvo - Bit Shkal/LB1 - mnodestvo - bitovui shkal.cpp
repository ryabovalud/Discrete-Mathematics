#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
using namespace std;
string univ_mn, A,B,C;




//������� ���������� ���������� �� ����� 
void INFO_FILE()
{
     ifstream fin("C:\\Users\\brrri\\OneDrive\\Study\\Alg Diskr Math\\LB\\LB1 -Mnogestvo - Bit Shkal\\mnogestvo.txt");
     if (!fin)
         cout << "���� ����" << endl;
     else
    { 
        	fin >> univ_mn>>A>>B>>C;
        	fin.close();
        	cout << "��������� ���������" << endl;
	}
}


//������� �������������� ��������
string PREO(string dano, string univ_mn)
{
	string str;
	bool ravenstvo=false;
	
	for(int i=0;i<univ_mn.size();i++)
	{
		for(int j=0;j<dano.size();j++)
			if (dano[j]==univ_mn[i])
			{
				str+='1';//������������� �������� �.�. �������� �������� �������
				ravenstvo=true;
			}
		if(!ravenstvo)	
			str+='0';
		ravenstvo=false;	
	}
	

	return str;
}

//������� ����������� ��������
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


//������� ����������� ��������
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

//������� �������� ��������
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

//������� ���������� ���������
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

//������� ���������� ���������
string vuragen(string A,string B, string C)
{
	string otvet;
	otvet=peresechenie(dopolnenie(obedinenie(dopolnenie(raznost(A,B)),C)),A);
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
    string otvet;
        
	
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
            	cout<<endl<<"������������� ���������: "<<univ_mn<<endl;
            	
				cout<<"��������� A: "<<A<<endl;
				A= PREO (A,univ_mn);//��������������� ��������� �
				
				
				cout<<"��������� B: "<<B<<endl;
				B= PREO (B,univ_mn);//��������������� ��������� B
            	
				cout<<"��������� C: "<<C<<endl;
				C= PREO (C,univ_mn);//��������������� ��������� C
				
				
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
							
							cout<<endl<<"��������� �����������: ";
							for(int i=0;i<univ_mn.size();i++)
	  							if(otvet[i]=='1') cout<<univ_mn[i];
							cout<<endl;
							
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
							
							cout<<endl<<"��������� �����������: ";
							for(int i=0;i<univ_mn.size();i++)
	  							if(otvet[i]=='1') cout<<univ_mn[i];
							cout<<endl;
							
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
							
							cout<<endl<<"��������� ��������: ";
							for(int i=0;i<univ_mn.size();i++)
	  							if(otvet[i]=='1') cout<<univ_mn[i];
							cout<<endl;
							
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
					if(name_1=="A") otvet= dopolnenie(A);
					else if(name_1=="B") otvet= dopolnenie(B);
					else if(name_1=="C") otvet= dopolnenie(C);							
					else 
					{
						cout<<"������!!! ��� ��������� ������� �������"<<endl;
						break;
					}		
					
					cout<<endl<<"��������� ����������: ";
					for(int i=0;i<univ_mn.size();i++)
  						if(otvet[i]=='1') cout<<univ_mn[i];
					cout<<endl;
						
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
					otvet= vuragen(A,B,C);		
					
					cout<<endl<<"��������� ���������: ";
					for(int i=0;i<univ_mn.size();i++)
  						if(otvet[i]=='1') cout<<univ_mn[i];
					cout<<endl;
						
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
