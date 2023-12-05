// CMakeProject4.cpp: Definuje vstupní bod pro aplikaci.
//

#include "CMakeProject4.h"
#include "calculatorFuncs.h"
#include <fstream>
using namespace std;
//inicializace promennych nutne k ziskavani cisel

int operace;
double result = 0;
double a = 0;
double b = 0;
double a1 = 0;
double b1 = 0;
double i;
double z = 0;
int mode;
double pametA;
char pamet;
double pametB;
double pametC;
double pametD;

//funkce pro zadavani cisel, navigace v kalkulacce
void scan()
{

	printf(">");
	scanf_s("%d", &operace);
	while (operace == '\n')
	{
		scanf_s("%d", &operace);
	}
}

//zisk cisel - dva mody(1 = ziskavam a a B, 0 - ziskavam jen a)

void getNumbers(int mode)
{

	if (mode == 1)
	{
		printf("Zadejte cislo a\n");
		printf(">          ");
		scanf_s("%lf", &a);
		while (a == '\n')
		{
			scanf_s("%lf", &a);
		}
		printf("Zadejte cislo b\n");
		printf(">          ");
		scanf_s("%lf", &b);
		while (b == '\n')
		{
			scanf_s("%lf", &b);
		}

	}
	else if (mode == 0)
	{
		printf("Zadejte cislo a\n");
		printf(">          ");
		scanf_s("%lf", &a);
		while (a == '\n')
		{
			scanf_s("%lf", &a);
		}
	}
	else if (mode == 2)
	{
		printf("Zadejte cislo a\n");
		printf(">          ");
		scanf_s("%lf", &a);
		while (a == '\n')
		{
			scanf_s("%lf", &a);
		}
		printf("Zadejte cislo b\n");
		printf(">          ");
		scanf_s("%lf", &b);
		while (b == '\n')
		{
			scanf_s("%lf", &b);
		}
		printf("Zadejte cislo a1\n");
		printf(">          ");
		scanf_s("%lf", &a1);
		while (a == '\n')
		{
			scanf_s("%lf", &a1);
		}
		printf("Zadejte cislo b1\n");
		printf(">          ");
		scanf_s("%lf", &b1);
		while (b1 == '\n')
		{
			scanf_s("%lf", &b1);
		}
	}
	else if (mode == 3)
	{
		printf("Zadejte cislo a\n");
		printf(">          ");
		scanf_s("%lf", &a);
		while (a == '\n')
		{
			scanf_s("%lf", &a);
		}
		printf("Zadejte cislo b\n");
		printf(">          ");
		scanf_s("%lf", &b);
		while (b == '\n')
		{
			scanf_s("%lf", &b);
		}
		printf("Zadejte cislo z\n");
		printf(">          ");
		scanf_s("%lf", &z);
		while (z == '\n')
		{
			scanf_s("%lf", &z);
		}
	}
	else if (mode == 4)
	{
		printf("Zadejte cislo a\n");
		printf(">          ");
		scanf_s("%lf", &a);
		while (a == '\n')
		{
			scanf_s("%lf", &a);
		}
		printf("Zadejte cislo z\n");
		printf(">          ");
		scanf_s("%lf", &z);
		while (z == '\n')
		{
			scanf_s("%lf", &z);
		}
	}


}
void uloz(char pamet, double result)
{
	switch (pamet)
	{
	case 'A':
		pametA = result;
		printf("Hodnota uložena do paměti A: %.4lf\n", pametA);
		break;
	case 'B':
		pametB = result;
		printf("Hodnota uložena do paměti B: %.4lf\n", pametB);
		break;
	case 'C':
		pametC = result;
		printf("Hodnota uložena do paměti C: %.4lf\n", pametC);
		break;
	case 'D':
		pametD = result;
		printf("Hodnota uložena do paměti D: %.4lf\n", pametD);
		break;
	}
}
void vypisPameti()
{
	printf("Hodnoty v pamětech:\n");
	printf("A: %.4lf\n", pametA);
	printf("B: %.4lf\n", pametB);
	printf("C: %.4lf\n", pametC);
	printf("D: %.4lf\n", pametD);
}
void ulozVysledekDoSouboru(const char* nazevSouboru, double vysledek)
{
	std::ofstream file(nazevSouboru, std::ios_base::app); // otevření souboru pro přidání 

	if (file.is_open())
	{
		file << "Vysledek: " << vysledek << std::endl;
		file.close();
		printf("		Vysledek byl ulozen do souboru '%s'.\n", nazevSouboru);
	}
	else
	{
		printf("		Chyba: Nelze otevrit soubor pro ulozeni vysledku.\n");
	}
}



int main()
{
	//hlavicka kalkulacky
	printf("------------------------Vitejte ve vedecke kalkulacce-------------\n\n");
	printf("-------------Pro pocitani zadejte prislusnou operaci a ridte se pokyny. \n");
	printf("-------------Pro menu funkci zadejte -1 -------------------------------\n\n");

	scan();


	//nekonecny loop, aby se dalo neustale pocitat
	while (true)
	{
		if (operace != 0) //pokud uzivatel zada 0, kalkulacka se vypne
		{

			switch (operace) //switch pro volbu funkce
			{

			case -1: //menu funkcí
				printf("~~~~Funkce vedecke kalkulacky~~~~ \n");
				printf("(1) a + b\n");
				printf("(2) a - b\n");
				printf("(3) a * b\n");
				printf("(4) a / b \n");
				printf("(5) a % b \n");
				printf("(6) sin a\n");
				printf("(7) cos a\n");
				printf("(8) tg a\n");
				printf("(9) a!\n");
				printf("(11) log a o zakladu b\n");
				printf("(12) log a o zakladu a\n");
				printf("(13) ln a\n");
				printf("(14) e^a\n");
				printf("(15) a^b\n");
				printf("(16) prevod teploty na stupne celsia\n");
				printf("(17) prevod teploty na stupne fahrenheita\n");
				printf("(18) prevod uhlu na stupne\n");
				printf("(19) prevod uhlu na radiany\n");
				printf("(20) ulozene vysledeky do pameti (A,B,C,D)\n");
				printf("(21) komplexni soucet\n");
				printf("(22) komplexni rozdil\n");
				printf("(23) komplexni soucin\n");
				printf("(24) komplexni podil\n");
				printf("(25) prevod na goniometricky tvar\n");
				printf("(26) prevod na algebraicky tvar\n");

				scan();
				break;

			case 1:
				getNumbers(1);
				result = scitani(a, b);

				printf("				Vysledek scitani je %.4lf \n", result);
				ulozVysledekDoSouboru("vysledky.txt", result);
				scan();
				break;

			case 2:
				getNumbers(1);
				result = odcitani(a, b);

				printf("				Vysledek odcitani je %.4lf \n", result);
				ulozVysledekDoSouboru("vysledky.txt", result);
				scan();
				break;

			case 3:
				getNumbers(1);
				result = nasobeni(a, b);

				printf("				Vysledek nasobeni je %.4lf \n", result);
				ulozVysledekDoSouboru("vysledky.txt", result);
				scan();
				break;

			case 4:
				getNumbers(1);
				result = deleni(a, b);

				printf("				Vysledek deleni je %.4lf \n", result);
				ulozVysledekDoSouboru("vysledky.txt", result);
				scan();
				break;

			case 5:
				getNumbers(1);
				result = modulo(a, b);

				printf("				Vysledek modula je %.4lf \n", result);
				ulozVysledekDoSouboru("vysledky.txt", result);
				scan();
				break;

			case 6:
				getNumbers(0);
				result = sinus(a);

				printf("				Vysledek sinusu je %.4lf \n", result);
				ulozVysledekDoSouboru("vysledky.txt", result);
				scan();
				break;

			case 7:
				getNumbers(0);
				result = cosinus(a);

				printf("				Vysledek cosinu je %.4lf \n", result);
				ulozVysledekDoSouboru("vysledky.txt", result);
				scan();
				break;

			case 8:
				getNumbers(0);
				result = tangens(a);

				printf("				Vysledek tangensu je %.4lf \n", result);
				ulozVysledekDoSouboru("vysledky.txt", result);
				scan();
				break;

			case 9:
				getNumbers(0);
				result = faktorial(a);

				printf("				Vysledek faktorialu je %.4lf \n", result);
				ulozVysledekDoSouboru("vysledky.txt", result);
				scan();
				break;

			case 11:
				getNumbers(1);
				result = logaritmus(a, b);

				printf("			   Vysledek logaritmu je %4lf\n", result);
				ulozVysledekDoSouboru("vysledky.txt", result);
				scan();
				break;

			case 12:
				getNumbers(0);
				result = logaritmusDeset(a);

				printf("				Vysledek logaritmu je %.4lf \n", result);
				ulozVysledekDoSouboru("vysledky.txt", result);
				scan();
				break;

			case 13:
				getNumbers(0);
				result = logaritmusPrirozeny(a);

				printf("				Vysledek prirozeneho logaritmu je %.4lf \n", result);
				ulozVysledekDoSouboru("vysledky.txt", result);
				scan();
				break;

			case 14:
				getNumbers(0);
				result = exponencial(a);

				printf("				Vysledek exponencialu je %.4lf \n", result);
				ulozVysledekDoSouboru("vysledky.txt", result);
				scan();
				break;

			case 15:
				getNumbers(1);
				result = mocnina(a, b);

				printf("				Vysledek mocniny je %.4lf \n", result);
				ulozVysledekDoSouboru("vysledky.txt", result);
				scan();
				break;

			case 16:
				getNumbers(0);
				result = (a);

				printf("				Vysledek °C je %.4lf \n", result);
				ulozVysledekDoSouboru("vysledky.txt", result);
				scan();
				break;

			case 17:
				getNumbers(0);
				result = fahrenheit(a);

				printf("				Vysledek farnheitu je %.4lf \n", result);
				ulozVysledekDoSouboru("vysledky.txt", result);
				scan();
				break;

			case 18:
				getNumbers(0);
				result = uhel_stupne(a);

				printf("			   Vysledek stupnu je %.4lf \n", result);
				ulozVysledekDoSouboru("vysledky.txt", result);
				scan();
				break;

			case 19:
				getNumbers(0);
				result = uhel_radiany(a);

				printf("			Vysledek radianu je %4lf\n", result);
				ulozVysledekDoSouboru("vysledky.txt", result);
				scan();
				break;

			case 20:
				printf("			Vysledek ulozen do pameti. Vyberte pamet (A, B, C, D): ");
				scanf_s(" %c", &pamet);
				uloz(pamet, result);
				vypisPameti();
				scan();
				break;

			case 21:
				getNumbers(2);
				result = komp_soucet(a, b, a1, b1, i);

				printf("				Vysledek souctu je %4lf\n", result);
				ulozVysledekDoSouboru("vysledky.txt", result);
				scan();
				break;

			case 22:
				getNumbers(2);
				result = komp_rozdil(a, b, a1, b1, i);

				printf("				Vysledek rozdilu je %4lf\n", result);
				ulozVysledekDoSouboru("vysledky.txt", result);
				scan();
				break;

			case 23:
				getNumbers(2);
				result = komp_soucin(a, b, a1, b1, i);

				printf("				Vysledek soucinu je %4lf\n", result);
				ulozVysledekDoSouboru("vysledky.txt", result);
				scan();
				break;

			case 24:
				getNumbers(2);
				result = komp_podil(a, b, a1, b1, i);

				printf("				Vysledek podilu je %4lf\n", result);
				ulozVysledekDoSouboru("vysledky.txt", result);
				scan();
				break;

			case 25:
				getNumbers(3);
				result = komp_prevod(a, b, i, z);

				printf("				Goniometricky tvar je %4lf\n", result);
				ulozVysledekDoSouboru("vysledky.txt", result);
				scan();
				break;

			case 26:
				getNumbers(4);
				result = komp_zpet(a, i, z);

				printf("				Algebraicky tvar je %4lf\n", result);
				ulozVysledekDoSouboru("vysledky.txt", result);
				scan();
				break;

			default:
				printf("Takovou akci neznam. Zkuste to znovu. \n");
				scan();
			}

		}
		else {
			printf("\n\n			Vypinam se. \n\n\n");
			return 0;
		}

	}
}
