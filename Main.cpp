//Problema 2 - Laboratorul 4

#include"Biblioteca.h";

int main()
{
	structautori tempautori;
	tempautori.n = 0;
	vector<Carte> biblioteca;
	char temp[100], c,*temptitlu,*tempeditura,*tempanaparitie,*temppret,*tempisbn;
	int n_carti;
	ifstream file;
	file.open("in.txt");
	tempautori.n = 0;
	file.getline(temp, 100);
	n_carti = atoi(temp);
	for (int i = 0;i < n_carti;i++) {

		file.getline(temp, 100);
		temptitlu = new char[strlen(temp) + 1];
		strcpy(temptitlu, temp);

		file.getline(temp, 100);
		tempeditura = new char[strlen(temp) + 1];
		strcpy(tempeditura, temp);

		file.getline(temp, 100);
		tempautori.n = atoi(temp);
		tempautori.autor = new lista_autori[tempautori.n];
		for (int j = 0;j < tempautori.n;j++) {
			file.getline(temp, 100);
			tempautori.autor[j].nume = new char[strlen(temp) + 1];
			strcpy(tempautori.autor[j].nume, temp);
		}

		file.getline(temp, 100);
		tempisbn= new char[strlen(temp) + 1];
		strcpy(tempisbn, temp);

		file.getline(temp, 100);
		tempanaparitie = new char[strlen(temp) + 1];
		strcpy(tempanaparitie, temp);

		file.getline(temp, 100);
		temppret = new char[strlen(temp) + 1];
		strcpy(temppret, temp);

		Carte carte(temptitlu, tempeditura, tempautori, tempisbn, tempanaparitie, temppret);
		biblioteca.push_back(carte);

		delete temptitlu;
		delete tempeditura;
		delete tempautori.autor;
		delete tempisbn;
		delete tempanaparitie;
		delete temppret;

	}
	file.close();

	cout << "Introduceti titlul cautat:";
	gets_s(temp, 100);
	temptitlu = new char[strlen(temp) + 1];
	strcpy(temptitlu, temp);

	cout << "Introduceti editura cautata:";
	gets_s(temp, 100);
	tempeditura = new char[strlen(temp) + 1];
	strcpy(tempeditura, temp);

	cout << "Introduceti isbnul cautat:";
	gets_s(temp, 100);
	tempisbn = new char[strlen(temp) + 1];
	strcpy(tempisbn, temp);

	for (int i = 0, sw;i < biblioteca.size();i++) {
		sw = 0;

		if (strcmp(biblioteca.at(i).Get_titlu(), temptitlu) == 0) {
			cout << endl << "----------------------------------------------------";
			biblioteca.at(i).afisaretot();
			sw = 1;
		}

		if (strcmp(biblioteca.at(i).Get_editura(), tempeditura) == 0 && sw == 0) {
			cout << endl << "----------------------------------------------------";
			biblioteca.at(i).afisaretot();
			sw = 1;
		}

		if (strcmp(biblioteca.at(i).Get_isbn(), tempisbn) == 0 && sw == 0) {
			cout << endl << "----------------------------------------------------";
			biblioteca.at(i).afisaretot();
		}

	}

	return 0;
}