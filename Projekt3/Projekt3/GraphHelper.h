#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class GraphHelper //deklaracja klasy GraphHelper
{
	vector<vector<int>> _incidentMatrix; //deklaracja macierzy, kt�ra b�dzie zainicjalizowana w konstruktorze
public:
	GraphHelper(vector<vector<int>> incidentMatrix) { //konstruktor przyjmuj�cy jeden parametr wektora wektor�w liczb ca�kowitych

		_incidentMatrix = incidentMatrix; //przypisanie _incidentMatrix warto�ci przekazanej w konstruktorze
	}

	void GetAllNeighboursOfSpecificVertex() { //funkcja nie zwracaj�ca niczego, sprawdzaj�ca s�siad�w poszczeg�lnych wierzcho�k�w
		int counter = 0; //liczba wyst�pie� s�siad�w - domy�lnie 0
		for (int i = 0; i < _incidentMatrix.size(); i++) { //iterujemy po ka�dym elemencie wektora (po wektorach)
			counter = 0; // wyzerowanie licznika przy ka�dej iteracji
			cout << "Neighbours of V" << i << ": ";
			for (int j = 0; j < _incidentMatrix[i].size(); j++) { //iterujemy po ka�dym elemencie wektor�w (po intach)
				if (_incidentMatrix[i][j] == 1) { //je�li element = 1, to znaczy �e ma s�siada i musimy go znale��
					for (int k = 0; k < _incidentMatrix.size(); k++) { // iterujemy jeszcze raz po g��wnym wektorze (po wektorach)
						if (k == i) continue; //pomijamy sytuacj�, gdzie por�wnujemy te same wektory
						for (int l = 0; l < _incidentMatrix[k].size(); l++) { //iterujemy jeszcze raz po ka�dym elemencie wektor�w (po intach)
							if (_incidentMatrix[k][l] == -1 && j == l) { //je�li warto�� elementu = -1 i indeksy por�wnywanych wektor�w si� zgadzaj�, mamy s�siada
								cout << "V" << k << ";";
								counter++; //inkrementacja liczby s�siad�w konkretnego wierzcho�ka
							}
						}
					}
				}
				else if (counter == 0 && j == _incidentMatrix[i].size() - 1) { //je�li licznik s�siad�w = 0 i rozpatrywany wektor zosta� por�wnany ze wszystkimi innymi to znaczy �e wierzcho�ek nie ma s�siad�w
					cout << "V" << i << " has no neighbour...";
				}
			}
			cout << endl;
		}
	}

	void GetAllVertexesWhereInNeighoudOfAllVertexes() {//funkcja nie zwracaj�ca niczego, sprawdzaj�ca wierzcho�ki b�d�ce s�siadami wszystkich innych wierzcho�k�w
		int counter = 0; //liczba wierzcho�k�w b�d�cych s�siadami wszystkich innych wierzcho�k�w
		int requiredNumberOfOnes = _incidentMatrix.size() - 1; //wymagana liczba jedynek w wektorze (wierzcho�ek ma wszystkich s�siad�w je�li wektor sk�ada si� z samych ze i jedynek, gdzie liczba jedynek jest r�wna ilo�ci wierzcho�k�w minus 1)
		int counterOfOnesInRow = 0; //licznik jedynek w wektorze
		bool minusValueHappened = false; //zmienna informuj�ca czy pojawi�a si� warto�� -1 (domy�lnie false)
		for (int i = 0; i < _incidentMatrix.size(); i++) { //iterujemy po ka�dym wektorze
			minusValueHappened = false; //przy ka�dej iteracji resetujemy minusValueHappened na false
			counterOfOnesInRow = 0; //przy ka�dej iteracji resetujemy licznik jedynek
			for (int j = 0; j < _incidentMatrix[i].size(); j++) { //iterujemy ka�dy element w wektorze
				if (_incidentMatrix[i][j] == -1) { // je�li element = -1, to znaczy �e wierzcho�ek nie jest s�siadem wszystkich wierzcho�k�w
					minusValueHappened = true; //ustawiamy zmienn� informuj�c� o pojawieniu si� ujemnej warto�ci
					break;//przerywamy iterowanie i wychodzimy z obecnej p�tli
				}
				else if (_incidentMatrix[i][j] == 1) { //je�li element = 1, to zwi�kszamy licznik jedynek
					counterOfOnesInRow++;//zwi�kszamy licznik jedynek
				}
			}
			if (counterOfOnesInRow == requiredNumberOfOnes && !minusValueHappened) { //po przeiterowaniu wszystkich element�w, sprawdzamy czy licznik jedynek jest r�wny wymaganej ilo�ci jedynek, oraz czy nie pojawi�a si� jaka� warto�� ujemna
				counter++; //je�li wszystkie powy�ej warunki s� spe�nione, to znaczy �e znale�li�my szukany wierzcho�ek i zwi�kszamy liczb� ich wyst�pie�
				cout << "V" << i << " is the neighbour of all vertexes";
			}
		}

		if (counter == 0) { // je�li liczba wyst�pie� szukanych wierzcho�k�w = 0, wypisujemy �e nie znale�li�y takiego wierzcho�ka
			cout << "There is no vertex which is neighbour to all...";
		}

		cout << endl;
	}

	void GetDegreesOutFromAllVertexes() {//funkcja nie zwracaj�ca niczego, sprawdzaj�ca stopnie wychodz�ce z wierzcho�ka
		int counter = 0; //liczba stopni wychodz�ca z wierzcho�ka (domy�lnie r�wna 0)
		for (int i = 0; i < _incidentMatrix.size(); i++) { //iterujemy po ka�dym wektorze
			counter = 0; // resetujemy liczb� stopni przy ka�dej iteracji
			cout << "Degrees out from V" << i << ": ";
			for (int j = 0; j < _incidentMatrix[i].size(); j++) { //iterujemy po ka�dym elemencie wektora
				if (_incidentMatrix[i][j] == -1) { //je�li element jest r�wny -1, zwi�kszamy liczb� stopni o 1
					counter++; //zwi�kszamy liczb� stopni o 1
				}
			}
			cout << counter << endl; //wy�wietlamy wynik dla konkretnego wierzcho�ka
		}
	}

	void GetDegreesInToAllVertexes() {//funkcja nie zwracaj�ca niczego, sprawdzaj�ca stopnie wchodz�ce do wierzcho�ka
		int counter = 0; //liczba stopni wychodz�ca z wierzcho�ka (domy�lnie r�wna 0)
		for (int i = 0; i < _incidentMatrix.size(); i++) { //iterujemy po ka�dym wektorze
			counter = 0; // resetujemy liczb� stopni przy ka�dej iteracji
			cout << "Degrees in to V" << i << ": ";
			for (int j = 0; j < _incidentMatrix[i].size(); j++) {//iterujemy po ka�dym elemencie wektora
				if (_incidentMatrix[i][j] == 1) {//je�li element jest r�wny 1, zwi�kszamy liczb� stopni o 1
					counter++;//zwi�kszamy liczb� stopni o 1
				}
			}
			cout << counter << endl;//wy�wietlamy wynik dla konkretnego wierzcho�ka
		}
	}

	void GetAllIsolatedVertexes() {//funkcja nie zwracaj�ca niczego, sprawdzaj�ca izolowane wierzcho�ki
		int counter = 0; //liczba izolowanych wierzcho�k�w (domy�lnie r�wna 0)
		for (int i = 0; i < _incidentMatrix.size(); i++) {//iterujemy po ka�dym wektorze
			bool allElementsAreZeros = std::all_of(_incidentMatrix[i].begin(), _incidentMatrix[i].end(), [](int i) { return i == 0; });//izolowany wierzcho�ek to taki, kt�ry posiada same zera w wektorze. Sprawdzamy wi�c czy wektor sk��da si� z samych zer
			if (allElementsAreZeros) { //je�li wektor sk��da si� z samych zer to:
				cout << "V" << i << " is isolated" << endl; //wy�wietlamy izolowany wektor
				counter++; //zwi�kszamy liczb� izolowanych wierzcho�k�w o 1
			}
		}
		if (counter == 0) { //je�li liczba izolowanych wierzcho�k�w = 0, to wy�wietlamy odpowiedni komunikat
			cout << "There is not any isolated vertex..." << endl;
		}
	}

	void GetAllLoops() {//funkcja nie zwracaj�ca niczego, sprawdzaj�ca p�tle
		int counter = 0; //liczba p�tli (domy�lnie r�wna 0)
		int counterOfOnesInColumn = 0; // p�tla jest wtedy, gdy kolumna (czyli spo�r�d wszystkich element�w wektor�w przy tym samym indeksie) zawiera jedn� jedynk� i same zera. Dlatego deklarujemy zmienn� przechowuj�c� liczb� jedynek w kolumnie
		bool isLooped = true; // zmienna informuj�ca czy jest p�tla (domy�lnie ustawiona na true, b�dziemy j� zmienia� je�li w kolumnie wyst�pi� ujemne warto�ci, lub liczba jedynek jest wi�ksza ni� 1)
		int numberOfColumns = _incidentMatrix[0].size(); // zmienna informuj�ca o liczbie kolumn (bierzemy pierwszy lepszy wektor i sprawdzamy ile ma element�w)

		for (int i = 0; i < numberOfColumns; i++) { //poniewa� nie chcemy iterowa� najpierw po wierszach,tylko po kolumnach, dlatego iterujemy od 0 do ilo�ci kolumn w macierzy
			isLooped = true;// przy ka�dej iteracji resetujemy zmienn� isLooped na true
			counterOfOnesInColumn = 0;//resetujemy liczb� wyst�pie� jedynek w kolumnie

			for (int j = 0; j < _incidentMatrix.size(); j++) { //iterujemy po ka�dym wektorze
				if (_incidentMatrix[j][i] == 1) { //je�li element jest r�wny 1, inkrementujemy zmienn� counterOfOnesInColumn
					//w poprzednich przyk��dach by�o _incidentMatrix[i][j]. Tutaj mamy _incidentMatrix[j][i], poniewa� chcemy por�wnywa� elementy r�nych wektor�w o tym samym indeksie. 
					// Czyli zamiast _incidentMatrix[0][0], _incidentMatrix[0][1],_incidentMatrix[0][2], itd. robimy _incidentMatrix[0][0], _incidentMatrix[1][0],_incidentMatrix[2][0] itd.
					counterOfOnesInColumn++;
				}
				else if (_incidentMatrix[j][i] == -1 || counterOfOnesInColumn > 1) { //je�li wyst�pi ujemna liczba lub liczba jedynek w kolumnie jest wi�ksza ni� 1, to znaczy �e to nie jest p�tla
					isLooped = false; //oznaczamy �e to nie jest p�tla
					break; //przerywamy bie��c� p�tl� bo nie ma sensu dalej sprawdza�
				}
			}
			if (isLooped) { //je�li zmienna isLooped wci�� daje true to wy�wietl komunikat i zwi�ksz liczb� p�tli
				cout << "V" << i << " is looped" << endl;//wy�wietlamy komunikat
				counter++;// zwi�kszamy liczb� p�tli
			}
		}

		if (counter == 0) { //je�li liczba p�tli jest r�wna 0, wy�wietl komunikat
			cout << "There is not any loop..." << endl;
		}
	}

	void GetAllTwoWayEdges() {//funkcja nie zwracaj�ca niczego, sprawdzaj�ca dwukierunkowe kraw�dzie
		int numberOfRowsToCompare = _incidentMatrix.size() - 1; //liczba wierszy (wektor�w) do por�wnywania (jak por�wnujemy np. pierwszy, to ni musimy por�wnywa� go sam ze sob�, dlatego jest minus jeden)
		int numberOfColumns = _incidentMatrix[0].size(); //liczba kolumn
		//dwukierunkowe kraw�dzie charakteryzuj� si� tym, �e w jednym wierszu (wektorze) musz� wyst�pi� warto�ci -1 oraz 1, i w innym wierszu (wektorze) pod tymi samymi indeksami musz� by� warto�ci przeciwne. 
		bool checkOfOnes = false; // sprawdzenie czy wyst�pi�a przeciwna warto�� do -1 (domy�lnie false)
		bool checkOfMinusOnes = false;// sprawdzenie czy wyst�pi�a przeciwna warto�� do 1 (domy�lnie false)
		vector<int> vectorOfPositionsToCheck; //deklarujemy osobny wektor, do kt�rego b�dziemy dodawa� indeksy, pod kt�rymi znajduje si� element -1 lub 1 w danym wektorze
		for (int i = 0; i < _incidentMatrix.size() - 1; i++) {//iterujemy po wektorach (_incidentMatrix.size()-1, poniewa� ostatni wektor nie musimy ju� z niczym por�wnywa�, bo zosta� por�wnany ze wszystkimi wektorami w poprzednich iteracjach)
			if (!(std::find(_incidentMatrix[i].begin(), _incidentMatrix[i].end(), 1) != _incidentMatrix[i].end()
				&& std::find(_incidentMatrix[i].begin(), _incidentMatrix[i].end(), -1) != _incidentMatrix[i].end())) {//sprawdzamy czy w wektorze wyst�puje 1 lub -1. Je�li nie to kontynuuj do nast�pnej iteracji
				continue;
			}


			for (int j = 0; j < _incidentMatrix[i].size(); j++) { //iterujemy po elementach wektora (po intach)
				if (_incidentMatrix[i][j] == 1 || _incidentMatrix[i][j] == -1) { // je�li element jest r�wny 1 lub -1, to dodaj jego indeks do wektora vectorOfPositionsToCheck
					vectorOfPositionsToCheck.push_back(j);
				}
			}

			int twoDirectionalEdge1 = -1;//zmienna pomocnicza do zapisania numeru dwukierunkowej kraw�dzi je�li wyst�pi
			int twoDirectionalEdge2 = -1;//zmienna pomocnicza do zapisania numeru dwukierunkowej kraw�dzi je�li wyst�pi
			for (int k = i; k < _incidentMatrix.size() - 1; k++) {//iterujemy po wektorach, aby por�wnywa� wektor z kolejnymi wektorami
				twoDirectionalEdge1 = -1; // resetujemy zmienn� pomocnicz� do -1 (-1 poniwa� numer kraw�dzi nie mo�e by� ujemny))
				twoDirectionalEdge2 = -1; // resetujemy zmienn� pomocnicz� do -1
				checkOfOnes = false; // resetujemy zmienn� informuj�c� o poprawnym sprawdzeniu czy znaleziono jedynk� pasuj�c� do elementu przy konkretnym indeksie 
				checkOfMinusOnes = false;// resetujemy zmienn� informuj�c� o poprawnym sprawdzeniu czy znaleziono minus jedynk� pasuj�c� do elementu przy konkretnym indeksie 
				for (int kk = 0; kk < vectorOfPositionsToCheck.size(); kk++) { //iterujemy po zapisanych indeksach, kt�re powinny da� nam warto�� 1 lub -1 �eby znale�� dwukierunkowe kraw�dzie
					if (_incidentMatrix[i][vectorOfPositionsToCheck[kk]] == -_incidentMatrix[k + 1][vectorOfPositionsToCheck[kk]]) { // je�li znajdziemy odwrotn� warto�� w kolejnych wektorach k do naszego wektora i, przy tym samym indeksie, to mamy podstaw� s�dzi� �e to s� nasze dwukierunkowe kraw�dzie
						if (_incidentMatrix[k + 1][vectorOfPositionsToCheck[kk]] == 1) { //je�li w znalezionym liinijk� wcze�niej wierszu, przy indeksie kk element wynosi 1, to mamy za�atwiony check z jedynk�
							checkOfOnes = true; //ustawiamy flag� na true
							twoDirectionalEdge1 = vectorOfPositionsToCheck[kk];//ustawiamy numer pierwszej kraw�dzi dwukierunkowej
						}
						else if (_incidentMatrix[k + 1][vectorOfPositionsToCheck[kk]] == -1) {//je�li w znalezionym liinijk� wcze�niej wierszu, przy indeksie kk element wynosi -1, to mamy za�atwiony check z minus jedynk�
							checkOfMinusOnes = true; //ustawiamy flag� na true
							twoDirectionalEdge2 = vectorOfPositionsToCheck[kk];//ustawiamy numer drugiej kraw�dzi dwukierunkowej
						}

						if (checkOfOnes && checkOfMinusOnes) {// je�li oba checki s� true, to mamy ustalon� nasz� dwukierunkow��
							cout << "Between V" << i << " and " << "V" << k + 1 << " edges: " <<
								"E" << twoDirectionalEdge1 << " and " <<
								"E" << twoDirectionalEdge2 << " are two-directional" << endl;
						}
					}
				}
			}

		}
	}
};

