#include <iostream>
#include <string.h>
#include <unistd.h> //sleep(x);
using namespace std;
void entry();
double order();
double setA();
double setB();
double setC();
double preReceipt(double);
void payment();

//List of Global Variables
string time, date, pax;
char name[50];
double preReceipt(char, double, double);

//main 
int main()
{
    double totalSETA, totalSETB, totalSETC, totalAll = 0, totalSET[3];
    char option; 
    
    entry();
    for(int i=0; i<3; i++){
		totalSET[i] = order();
		totalAll=totalAll+totalSET[i];
		cout<<"Add-ons another set?(Y/N): ";
		cin>>option;
    	if (toupper(option) =='N'){
        	i=10;                                                                 
		}
	}
    
    preReceipt(totalAll);
    cout<<endl;
    cout<<"+--------------------------------------------------+"<<endl;
    cout<<"|    THANK YOU FOR USING FOOD ORDERING SYSTEM :)   |"<<endl;
    cout<<"+--------------------------------------------------+"<<endl<<endl;
    return 0;
}
void entry(){
	cout<<"Welcome to The Food Ordering System";
	cout<<"\nEnter your name: ";
	cin.getline(name,50);
	cout<<"\nEnter reservation date(DD/MM): ";
	cin>>date;
	cout<<"\nEnter reservation time(Exp:11.00AM/PM): ";	
	cin>>time;
	cout<<"\nEnter pax: ";
	cin>>pax;
}
    
double order(){
	char code;
	double total=0;
	system("cls");
	double price, qty;
	cout<<"+-----------------------+"<<endl;
    cout<<"|CODE\tMENU		|" <<endl;
    cout<<"+-----------------------+"<<endl;
	cout<<"|A.  \tSET \t\t|"<<endl;       
	cout<<"|B.  \tALA CARTE	|"<<endl;       
	cout<<"|C.  \tBEVERAGES	|"<<endl;
    cout<<"+-----------------------+"<<endl;
    cout<<"Enter code: ";
    cin>>code;
    if(toupper(code)== 'A'){
		total=setA();
		return total;
	}
    else if (toupper(code)== 'B'){
    	total=setB();
    	return total;
    }
    else if (toupper(code)== 'C'){
    	total=setC();
    	return total;
	}
	else{
		cout<<"\aInvalid code. Redirecting to menu selection."<<endl;
		cout<<"3 ";
		sleep(2);
		cout<<"2 ";
		sleep(2);
		cout<<"1 ";
		sleep(2);
		system("cls");
		order();
	}
}

double setA(){

	char code, option;
	double qty, price, totalSETA = 0, totalA = 0, totalB = 0, totalC = 0, sumA = 0, sumB = 0, sumC = 0;
	int briyani =0 , kerabu = 0, arab = 0;
	
	for(int i=0; i>=0; i++){
		
		system("cls");
		
		cout<<"+------------------------------------------------------+"<<endl;
    	cout<<"|CODE    MENU                PRICE(RM)                 |" <<endl;
		cout<<"+------------------------------------------------------+"<<endl;
		cout<<"|A.      NASI BIRYANI SET    28.00                     |"<<endl;       
		cout<<"|B.      NASI KERABU SET     18.00                     |" <<endl;       
		cout<<"|C.      NASI ARAB SET       40.00                     |"<<endl;
	    cout<<"+------------------------------------------------------+"<<endl;
    	cout<<"Enter code: ";
	    cin>>code;
    	cout<<"Enter quantity: ";
	    cin>>qty;
    	if (toupper(code)!='A'&& toupper(code)!='B'&& toupper(code)!='C'){
			cout<<"\aInvalid code. Redirecting to SET selection."<<endl;
			cout<<"3 ";
			sleep(2);
			cout<<"2 ";
			sleep(2);
			cout<<"1 ";
			sleep(2);
			system("cls");
			setA();
		}
		else if (toupper(code)=='A'){
			briyani = briyani + qty;
			price = 28.00;
			totalA = price * qty; 
			sumA = sumA + totalA;
		}
		else if (toupper(code)== 'B'){
			kerabu = kerabu + qty;
    		price = 18.00;
    		totalB = price * qty; 
			sumB = sumB + totalB;
	    }
    	else if (toupper(code)== 'C'){ 
    		arab = arab + qty;
			price = 40.00;
			totalC = price * qty; 
			sumC = sumC + totalC;
		}
		cout<<"Add-ons?(Y/N): ";
    	cin>>option;
    	if (toupper(option) =='N'){
    		i=-10;
		}
		
		totalSETA = sumA +sumB +sumC;
		cout<<"Total for setA is: RM "<<totalSETA<<endl;
		
	}
	//receipt for A
	cout<<"+---------------------------------+"<<endl;
	cout<<"|   ITEM      |   QTY   |  PRICE  |"<<endl;
	cout<<"+-------------+---------+---------+"<<endl;
	cout<<"|Nasi Briyani |    "<< briyani <<"	|    "<<sumA<<"    |"<<endl;
	cout<<"+-------------+---------+---------+"<<endl;
	cout<<"|Nasi Kerabu  |    "<< kerabu <<"	|    "<<sumB<<"    |"<<endl;
	cout<<"+-------------+---------+---------+"<<endl;
	cout<<"|Nasi Arab    |    "<< arab <<"	|   "<<sumC<<"   |"<<endl;
	cout<<"+-------------+---------+---------+"<<endl;
	cout<<"           |Total Purchase|  "<<totalSETA<<"  "<<"|"<<endl;
	cout<<"           +--------------+-------+"<<endl<<endl<<endl<<endl;
		
	return totalSETA;
}

double setB(){

	char code, option;
	double qty, price, totalSETB = 0, totalA =0, totalB = 0, totalC = 0, totalD = 0, totalE =0, totalF = 0, sumA =0, sumB = 0, sumC = 0, sumD = 0, sumE = 0, sumF = 0 ;
	int pasemboq = 0, telur = 0, kailan = 0, toye = 0, ikanKembung = 0, patin = 0;
	
	for(int i=0; i>=0; i++){
		
		system("cls");
		
		cout<<"+------------------------------------------------------------+"<<endl;
		cout<<"|CODE\tMENU                               PRICE(RM)         |" <<endl;
		cout<<"+------------------------------------------------------------+"<<endl;
		cout<<"|A.  \tPASEMBOQ                           10.00             |"<<endl;       
		cout<<"|B.  \tTELUR BISTIQ/BUNGKUS               5.00              |"<<endl;       
		cout<<"|C.  \tKAILAN IKAN MASIN                  6.00              |"<<endl;
		cout<<"|D.  \tTOMYAM                             10.00             |"<<endl;
		cout<<"|E.  \tIKAN KEEMBUNG BAKAR PETAI          20.00             |"<<endl;
		cout<<"|F.  \tIKAN PATEN MASAK PAEH              18.00             |"<<endl;
    	cout<<"+------------------------------------------------------------+"<<endl;
    	cout<<"Enter code: ";
	    cin>>code;
    	cout<<"Enter quantity: ";
	    cin>>qty;
    	if (toupper(code)!='A'&& toupper(code)!='B'&& toupper(code)!='C' && toupper(code)!='D'&& toupper(code)!='E'&& toupper(code)!='F'){
			cout<<"\aInvalid code. Redirecting to SET selection."<<endl;
			cout<<"3 ";
			sleep(2);
			cout<<"2 ";
			sleep(2);
			cout<<"1 ";
			sleep(2);
			system("cls");
			setB();
		}
		else if (toupper(code)=='A'){
			pasemboq = pasemboq + qty;
			price = 10.00;
			totalA = price * qty; 
			sumA = sumA + totalA;
		}
		else if (toupper(code)== 'B'){
			telur = telur + qty;
    		price = 5.00;
    		totalB = price * qty; 
			sumB = sumB + totalB;
	    }
    	else if (toupper(code)== 'C'){ 
    		kailan = kailan + qty;
			price = 6.00;
			totalC = price * qty; 
			sumC = sumC + totalC;
		}
		else if (toupper(code)=='D'){
			toye = toye + qty;
			price = 10.00;
			totalD = price * qty; 
			sumD = sumD + totalD;
		}
		else if (toupper(code)== 'E'){
			ikanKembung = ikanKembung + qty;
    		price = 20.00;
    		totalE = price * qty; 
			sumE = sumE + totalE;
	    }
    	else if (toupper(code)== 'F'){
    		patin = patin + qty;
		  	price = 18.00;
		  	totalF = price * qty; 
			sumF = sumF + totalF;
		}
		cout<<"Add-ons?(Y/N): ";
    	cin>>option;
    	if (toupper(option) =='N'){
    		i=-10;
		}
	
		totalSETB = sumA + sumB + sumC + sumD + sumE +sumF;
		cout<<"Total for setB is: RM "<<totalSETB<<endl<<endl;
		
	}
	//receipt for B
	cout<<"+-----------------------------------------------+"<<endl;
	cout<<"|   ITEM            |	QTY	|  PRICE  	|"<<endl;
	cout<<"+-------------------+-----------+---------------+"<<endl;
	cout<<"|Pasemboq           |	"<<pasemboq<<"	|	"<<sumA<<"\t|"<<endl;
	cout<<"+-----------------------------------------------+"<<endl;
	cout<<"|Telur              |	"<<telur<<"	|	"<<sumB<<"\t|"<<endl;
	cout<<"+-----------------------------------------------+"<<endl;
	cout<<"|Kailan Ikan Masin  |	"<<kailan<<"	|	"<<sumC<<"\t|"<<endl;
	cout<<"+-----------------------------------------------+"<<endl;
	cout<<"|Tom Yam            |	"<<toye<<"	|	"<<sumD<<"\t|"<<endl;
	cout<<"+-----------------------------------------------+"<<endl;
	cout<<"|Ikan Bakar Petai   |	"<<ikanKembung<<"	|	"<<sumE<<"\t|"<<endl;
	cout<<"+-----------------------------------------------+"<<endl;
	cout<<"|Paeh Patin         |	"<<patin<<"	|	"<<sumF<<"\t|"<<endl;
	cout<<"+-----------------------------------------------+"<<endl;
	cout<<"           |Total Purchase| "<<totalSETB<<" \t "<<"\t\t|"<<endl;
	cout<<"           +--------------+---------------------+"<<endl<<endl<<endl<<endl;
	
	return totalSETB;
}
double setC(){

	char code, option;
	double qty, price, totalSETC = 0, totalA =0, totalB = 0, totalC = 0, totalD = 0, totalE =0, totalF = 0, sumA =0, sumB = 0, sumC = 0, sumD = 0, sumE = 0, sumF = 0 ;
	int airKosong = 0, tehO = 0, tehTarik = 0, tehOP = 0 , extra = 0, neslo = 0;
	
	for(int i=0; i>=0; i++){
		
		system("cls");
		
		cout<<"+---------------------------------------------------------------+"<<endl;
		cout<<"|CODE\tBEVERAGES                             \tPRICE(RM)       |"<<endl;
		cout<<"+---------------------------------------------------------------+"<<endl;
		cout<<"|A.  \tSKYJUICE                              \t00.00           |"<<endl;       
		cout<<"|B.  \tTEH O AIS                             \t2.50            |"<<endl;       
		cout<<"|C.  \tTEH TARIK                             \t2.00            |"<<endl;
		cout<<"|D.  \tTEH O PANAS                           \t2.00            |"<<endl;
		cout<<"|E.  \tEXTRA JOSS                            \t3.50            |"<<endl;
		cout<<"|F.  \tNESLO                                 \t2.00            |"<<endl;
		cout<<"+---------------------------------------------------------------+"<<endl;
    	cout<<"Enter code: ";
	    cin>>code;
    	cout<<"Enter quantity: ";
	    cin>>qty;
    	if (toupper(code)!='A'&& toupper(code)!='B'&& toupper(code)!='C' && toupper(code)!='D'&& toupper(code)!='E'&& toupper(code)!='F'){
			cout<<"\aInvalid code. Redirecting to SET selection."<<endl;
			cout<<"3 ";
			sleep(2);
			cout<<"2 ";
			sleep(2);
			cout<<"1 ";
			sleep(2);
			system("cls");
			setC();
		}
		else if (toupper(code)=='A'){
			airKosong += qty;
			price = 00.00;
			totalA = price * qty; 
			sumA = sumA + totalA;
		}
		else if (toupper(code)== 'B'){
			tehO += qty;
    		price = 2.50;
    		totalB = price * qty; 
			sumB = sumB + totalB;
	    }
    	else if (toupper(code)== 'C'){ 
    		tehTarik += qty;
			price = 2.00;
			totalC = price * qty; 
			sumC = sumC + totalC;
		}
		else if (toupper(code)=='D'){
			tehOP += qty;
			price = 2.00;
			totalD = price * qty; 
			sumD = sumD + totalD;
		}
		else if (toupper(code)== 'E'){
			extra += qty;
    		price = 3.50;
    		totalE = price * qty; 
			sumE = sumE + totalE;
	    }
    	else if (toupper(code)== 'F'){ 
    		neslo += qty;
			price = 2.00;
			totalF = price * qty; 
			sumF = sumF + totalF;
		}
		cout<<"Add-ons?(Y/N): ";
    	cin>>option;
    	if (toupper(option) =='N'){
    		i=-10;
		}

		totalSETC = sumA + sumB + sumC + sumD + sumE +sumF;
		cout<<"Total for setC is: RM "<<totalSETC<<endl<<endl;
		
	}
	//receipt for C
	cout<<"+-----------------------------------------------+"<<endl;
	cout<<"|   ITEM            |      QTY      |    PRICE  |"<<endl;
	cout<<"+-------------------+--------------+------------+"<<endl;
	cout<<"|Skyjuice           |       "<< airKosong <<"       |"<<"    "<<sumA<<"\t|"<<endl;
	cout<<"+-------------------+--------------+------------+"<<endl;
	cout<<"|Teh 'O' Ais        |       "<< tehO <<"       |"<<"    "<<sumB<<"\t|"<<endl;
	cout<<"+-------------------+--------------+------------+"<<endl;
	cout<<"|Teh Tarik          |       "<< tehTarik <<"       |"<<"    "<<sumC<<"\t|"<<endl;
	cout<<"+-------------------+---------------------------+"<<endl;
	cout<<"|Teh 'O' Panas      |       "<< tehOP <<"       |"<<"    "<<sumD<<"\t|"<<endl;
	cout<<"+-------------------+---------------------------+"<<endl;
	cout<<"|Extra Joss         |       "<< extra <<"       |"<<"    "<<sumE<<"\t|"<<endl;
	cout<<"+-------------------+---------------------------+"<<endl;
	cout<<"|Neslo              |       "<< neslo <<"       |"<<"    "<<sumF<<"\t|"<<endl;
	cout<<"+----------+--------------+---------------------+"<<endl;
	cout<<"           |Total Purchase|    "<<totalSETC<<" \t "<<"|"<<endl;
	cout<<"           +--------------+---------------+"<<endl<<endl<<endl<<endl;
	return totalSETC;
}

double preReceipt(double totalAll){
	system("cls");
	int code;
	cout<<"+----------------------------------------------------+"<<endl;
	cout<<"Name		: "<<name<<"		"<<endl;
	cout<<"+----------------------------------------------------+"<<endl<<endl;
	cout<<"Date		: "<<date<<"		"<<endl;
	cout<<"+----------------------------------------------------+"<<endl<<endl;
	cout<<"Time		: "<<time<<"		"<<endl;
	cout<<"+----------------------------------------------------+"<<endl<<endl;
	cout<<"Pax		: "<<pax<<"		"<<endl;
	cout<<"+----------------------------------------------------+"<<endl;
	cout<<"Total Purchase:   RM"<<totalAll<<"	"<<endl;
	cout<<"+----------------------------------------------------+"<<endl<<endl;
		
	cout<<"+-------------------------------+"<<endl;
	cout<<"| PLEASE CHOOSE MODE OF PAYMENT |"<<endl;
	cout<<"+-------------------------------+"<<endl;
	cout<<"| 1. CREDIT CARD (10% off)      |"<<endl;
	cout<<"| 2. CASH                       |"<<endl;
	cout<<"+-------------------------------+"<<endl;
	cout<<"Enter Code: ";
	cin>> code;
	//system("cls"); // CLEARING SCREEN
	if(code == 1) {
		int creditCardNo;
		double total = (total * 0.10);
		totalAll = totalAll - total;
		
		cout<<"Please Enter Credit Card Number (8-Digit): ";
		cin>> creditCardNo;
		cout<<"Your Credit Card: " << creditCardNo <<" has been charged with RM " << totalAll <<"."<<endl;
	}
	else if(code == 2){
		double cash;
		cout<<"You Pay: RM ";
		cin>> cash;
		cout<<"Your balance is RM: " <<cash-totalAll <<endl;
	}
}
