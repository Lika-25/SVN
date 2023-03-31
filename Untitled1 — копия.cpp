#include<iostream>
#include<string.h>
#include<string>
using namespace std;

class Redact {
	public:
		char* str1 ; //іскомий ввод
		char* str2 ;// строка для конкатенації
		char str3 ;// підстрока для пошуку
		char* str4 ; // підстрока для пошуку
		char* str5 ; // строка на яку замінять  
		
		char* enter(); // Ввод рядка
		void show();	// вивід рядка на екран
		int amount();		// кількість символів
		Redact add();	// конкатенація
		int finde(Redact str1);		// пошук підрядка str2
		Redact change(); // заміна підрядка
};




char* Redact::enter() {
char*	str1=new char[65535];
	cout<<"Vvedite 1 stroky : "<<endl;
	cin>> str1;
return str1 ;
}

void Redact::show() {
	cout << str1 << " "<< endl;
}

int Redact::amount(){
	int count = strlen( str1 );
	cout<<"Dovgina ryadka : "<<count<<endl;
}

Redact Redact::add(){
	char* str2 = new char[65535];
	cout<<"Vvedite 2 stroky (pidstroky) : "<<endl;
	cin>>str2;
	strcat(str1,str2);
	cout<<"Vidredagovana: "<<str1<<endl;
	
}

int Redact::finde(Redact str1){
char*	str3=new char[65535];
	
	cout<<"Vvedite stroky, yaky shukaty : "<<endl;
	cin>>str3;
	
	size_t pos=0;
	int t=0;
	while( pos!=-1)
{
 pos=str1.find(str3, t);
}
cout<<"Pozucia : "<<t<<endl;
}

Redact Redact::change(){
		char* str4=new char[65535];
	cout<<"Vvedite stroky, yaky shukaty : "<<endl;
	cin>>str4;
	char* str5=new char[65535];
	cout<<"Vvedite stroky, na yaky zaminuty : "<<endl;
	cin>>str5;
	
	{	size_t pos=0;
	int t=0;
	while( pos!=-1)
{
pos=str1.find(str4, t);

		if ( pos!=-1 )

{		
		str1.erase(pos, str4.length());
		str1.insert(pos, str5);
		
}
cout<<str1;
	
}

int main() {
 Redact str1, str2, str3, str4, str5;
 str1.enter();
 str1.show();


}