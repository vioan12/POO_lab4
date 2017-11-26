//Problema 2 - Laboratorul 4

#include"Biblioteca.h";

Carte::Carte(const char valueoftitlu[], const char valueofeditura[], const structautori valueofautori, const char valueofisbn[], const char valueofanaparitie[], const char valueofpret[])
{
	char *tempisbn;
	titlu = new char[strlen(valueoftitlu) + 1];
	editura = new char[strlen(valueofeditura) + 1];
	autori = new structautori;
	autori->autor = new lista_autori[valueofautori.n];
	for (int i = 0;i < valueofautori.n;i++)
		autori->autor[i].nume = new char[strlen(valueofautori.autor[i].nume) + 1];
	tempisbn= new char[strlen(valueofisbn) + 1];
	anaparitie = new char[strlen(valueofanaparitie) + 1];
	pret = new char[strlen(valueofpret) + 1];
	
	strcpy(titlu, valueoftitlu);
	strcpy(editura, valueofeditura);
	autori->n = valueofautori.n;
	for (int i = 0;i < autori->n;i++)
		strcpy(autori->autor[i].nume, valueofautori.autor[i].nume);
	strcpy(tempisbn, valueofisbn);
	isbn = new InternationalStandardBookNumber(tempisbn);
	strcpy(anaparitie, valueofanaparitie);
	strcpy(pret, valueofpret);

}

Carte::Carte(const Carte &carte)
{
	titlu = new char[strlen(carte.titlu) + 1];
	editura = new char[strlen(carte.editura) + 1];
	autori = new structautori;
	autori->autor = new lista_autori[carte.autori->n];
	for (int i = 0;i < carte.autori->n;i++)
		autori->autor[i].nume = new char[strlen(carte.autori->autor[i].nume) + 1];
	isbn = new InternationalStandardBookNumber(*carte.isbn);
	anaparitie = new char[strlen(carte.anaparitie) + 1];
	pret = new char[strlen(carte.pret) + 1];

	strcpy(titlu, carte.titlu);
	strcpy(editura, carte.editura);
	autori->n = carte.autori->n;
	for (int i = 0;i < autori->n;i++)
		strcpy(autori->autor[i].nume, carte.autori->autor[i].nume);
	strcpy(anaparitie, carte.anaparitie);
	strcpy(pret, carte.pret);

}

Carte::~Carte()
{
	delete[] titlu;
	delete[] editura;
	delete[] autori;
	delete isbn;
	delete[] anaparitie;
	delete[] pret;
}

void Carte::afisare_titlu()
{
	cout << endl << "Titlu: " << titlu;
}

void Carte::afisare_editura()
{
	cout << endl << "Editura: " << editura;
}

void Carte::afisare_autori()
{
	cout << endl << "Autori: ";
	for(int i=0;i<autori->n;i++)
		cout << endl << "        "<<autori->autor[i].nume;
}

void Carte::afisare_isbn()
{
	cout << endl << "ISBN: " << isbn->Get_isbn();
}

void Carte::afisare_anaparitie()
{
	cout << endl << "Anul aparitiei: " << anaparitie;
}

void Carte::afisare_pret()
{
	cout << endl << "Pretul: " << pret;
}

void Carte::afisaretot()
{
	afisare_titlu();
	afisare_editura();
	afisare_autori();
	afisare_isbn();
	afisare_anaparitie();
	afisare_pret();
}

char* Carte::Get_titlu()
{
	return this->titlu;
}

char* Carte::Get_editura()
{
	return this->editura;
}

char* Carte::Get_isbn()
{
	return this->isbn->Get_isbn();
}
