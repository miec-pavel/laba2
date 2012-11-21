// Main.cpp: ������� ���� �������.

#include "MyClass.h"

Edit by miec-pavel1)))))))

//������� �������� �� ���� �����, ��������� � �������� � �������� �� ���� ����
bool Sim ()
{
	if( cin.bad() || cin.fail() )
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		throw Error_input;
		return true;
	}
	else 
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		return false;
	}
}

double TCalc::Calc()  // ���������� ��������������� ��������� 
{  
    if (a==0 || 4*b/a+1==0) 
		throw ErrorZero;  
	return (atan(a-c)*b+28)/(4*b/a+1); 
}

int main ()
{	
	double a, c;  
	long double b;
	int k;
	setlocale(LC_ALL,"Russian");
	do
	{
		// ������ ����� �������� �� �������� �����
		try
		{
			cout << "������� ��������: "<< endl << "a = ";
			cin >> a;
			if ( Sim() || a > FLT_MAX || fabs(a) < -FLT_MIN ) 
			{
				cout<<a;
				throw Error_float;
				continue;
			}
			else
			{
				cout<<a;
				cout << "������� ��������: "<< endl  << "b = "; 
				cin >> b;  
				if ( Sim() || b > DBL_MAX || fabs(b) < -DBL_MIN )
				{
					throw Error_double;
					continue;
				}
				else
				{
					cout << "������� ��������: "<< endl  << "c = ";
					cin >> c;
					if ( Sim() || c > INT_MAX || c < INT_MIN ) 
					{
						throw Error_int;
						continue;
					}
					else
					{
						a = float(a);
						b = double(b);
						c = int(c);
						TCalc Object(a,b,c);
						Object.show();
					}
				}
			}
		}
		catch(char* v)
		{
			cout << "������: " << v << endl << CONTINUE;
		}
		a = 0;
		b = 0;
		c = 0;
		k = getch( );
		system("cls"); 
	}while ( k != ESC ); //����� ��� ����������
	return 0;
}

