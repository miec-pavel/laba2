#ifndef __MyClass_H 
#define __MyClass_H 
#include <iostream> 
#include <math.h> 
#include <conio.h> 
#include <float.h> //������� double � float
#include <limits.h> //������� int
#define ESC 27 //��� ������� ESC

// ���������� ������  
char* Error_Res = "�������� � �����������"; 
char* ErrorZero = "������� �� 0"; 
char* CONTINUE = "\n\n    ��� ����������� ������� ����� ������� ��� ESC ��� ������ .....\n"; 
char* Error_int = "����� �� ������� ���� int";
char* Error_float = "����� �� ������� ���� float";
char* Error_double = "����� �� ������� ���� double";
char* Error_input = "��������� �� ���������� �������";

using namespace std; 
 
// ����� ��� ���������� ��������������� ��������� 
class TCalc 
{ 
	private:     
		// �������� ������ � �������� ������ ������ ������ 
		float a; 
		int c; 
		double b; 
		double Calc();  // ���������� ��������������� ��������� 

	public: //���������
       // �����������  
	TCalc(float av, double bv, int cv) 
    {  // ������������� ������-������ ������ 
		a=av; 
        b=bv; 
        c=cv; 
    }
	//����������
	~TCalc()
	{}

	//������� ��������� ���������� ���������� � ������ �� �����
	int show()
	{
		setlocale(LC_ALL,"Russian");
		// ������ ����� �������� �� ��������
		try
		{
			double res = Calc();  
			if( fabsl( res ) > DBL_MAX ) throw Error_Res; 
			cout << "\n���������: y = ";
			cout << res << CONTINUE; 
      
		}
		catch(char* v )  // ���������� ���� char* �� ��������� v 
		{ 
			cout << "������: "; 
			cout << v << CONTINUE << endl; 
		} 
		catch(...) // ���������� ���������� - �������� ���� ���������� 
		{ 
			cout << "\n!!!!! ��������� ����������������� ������������ ��������" << endl; 
			throw; 
		} 
		return 0;
	}
};     // TCalc 
#endif  /* __MYCLASS_H */ 
