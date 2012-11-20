#ifndef __MyClass_H 
#define __MyClass_H 
#include <iostream> 
#include <math.h> 
#include <conio.h> 
#include <float.h> //пределы double и float
#include <limits.h> //пределы int
#define ESC 27 //код клавиши ESC

// обьявление ошибок  
char* Error_Res = "проблема с результатом"; 
char* ErrorZero = "деление на 0"; 
char* CONTINUE = "\n\n    Для продолжения нажмите любую клавишу или ESC для выхода .....\n"; 
char* Error_int = "выход за пределы типа int";
char* Error_float = "выход за пределы типа float";
char* Error_double = "выход за пределы типа double";
char* Error_input = "Введенные не корректные символы";

using namespace std; 
 
// Класс для вычисления арифметического выражения 
class TCalc 
{ 
	private:     
		// описание данных – закрытых личных членов класса 
		float a; 
		int c; 
		double b; 
		double Calc();  // вычисление арифметического выражения 

	public: //интерфейс
       // Конструктор  
	TCalc(float av, double bv, int cv) 
    {  // инициализация данных-членов класса 
		a=av; 
        b=bv; 
        c=cv; 
    }
	//Деструктор
	~TCalc()
	{}

	//Функция выводящая результаты вычислений и ошибки на экран
	int show()
	{
		setlocale(LC_ALL,"Russian");
		// начало блока слежения за ошибками
		try
		{
			double res = Calc();  
			if( fabsl( res ) > DBL_MAX ) throw Error_Res; 
			cout << "\nРезультат: y = ";
			cout << res << CONTINUE; 
      
		}
		catch(char* v )  // исключения типа char* со значением v 
		{ 
			cout << "Ошибка: "; 
			cout << v << CONTINUE << endl; 
		} 
		catch(...) // Абсолютный обработчик - перехват ВСЕХ исключений 
		{ 
			cout << "\n!!!!! Обработка незапланированных чрезвычайных ситуаций" << endl; 
			throw; 
		} 
		return 0;
	}
};     // TCalc 
#endif  /* __MYCLASS_H */ 
