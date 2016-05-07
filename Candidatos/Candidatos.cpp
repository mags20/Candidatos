// Candidatos.cpp: define el punto de entrada de la aplicación de consola.
//
#include <iostream>
using namespace std;

char letra(int n)
{
	char letra;
	switch (n)
	{
	case 0:
		letra = 'A';
		break;
	case 1:
		letra = 'B';
		break;
	case 2:
		letra = 'C';
		break;
	case 3:
		letra = 'D';
		break;
	default:
		break;
	}
	return letra;
}

int main()
{
	int Zonas[5][4], sumascand[5] = { 0,0,0,0,0 }, sumaszonas[5] = { 0,0,0,0,0 },total=0, iPosicion1=0, iPosicion2, iNumeroMayor=0;	
	bool SegundaVuelta=false;
	for (int i = 0; i < 5; i++)
	{
		cout << "Zona " << i + 1<<":"<<endl;
		for (int j = 0; j < 4; j++)
		{			
			cout << "\tVotos para el candidato numero " << letra(j) <<": ";
			cin >> Zonas[i][j];
		}
	}	

	cout << "\n\tZona" << "\tCandidato A" << "\tCandidato B" << "\tCandidato C" << "\tCandidato D" << "\t\tTotal";
	for (int i = 0; i < 5; i++)
	{
		cout << "\n\t" << i + 1;
		for (int j = 0; j < 4; j++)
		{
			cout << "\t\t" << Zonas[i][j];			
			total += Zonas[i][j];
			sumaszonas[i] += Zonas[i][j];
			sumascand[j] += Zonas[i][j];
		}
		cout << "\t\t" << sumaszonas[i];
		sumascand[4] += sumaszonas[i];
	}

	cout << "\n\n\tSuma";
	for (int i = 0; i < 5; i++)
	{		
		cout << "\t\t" << sumascand[i];
		if (sumascand[i]>iNumeroMayor) {
			iNumeroMayor = sumascand[i];
			iPosicion2 = iPosicion1;
			iPosicion1 = i;			
		}
	}

	cout << "\n\t%";
	for (int i = 0; i < 5; i++)
	{
		cout << "\t\t" << (sumascand[i]*100)/total<<"%";
		if ((sumascand[i] * 100) / total < 50)
		{
			SegundaVuelta = true;
		}
	}
	
	cout << "\n\nGANADOR: Candidato "<< letra(iPosicion1-1);

	if (SegundaVuelta == true)
	{
		cout << "\n\nSegunda vuelta entre candidatos " << letra(iPosicion1-1)<<" y "<< letra(iPosicion2-1);
	}
	cout << "\n\n";
	system("pause");
    return 0;
}
	

