#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class GraphHelper //deklaracja klasy GraphHelper
{
	vector<vector<int>> _incidentMatrix; //deklaracja macierzy, która bêdzie zainicjalizowana w konstruktorze
public:
	GraphHelper(vector<vector<int>> incidentMatrix) { //konstruktor przyjmuj¹cy jeden parametr wektora wektorów liczb ca³kowitych

		_incidentMatrix = incidentMatrix; //przypisanie _incidentMatrix wartoœci przekazanej w konstruktorze
	}

	void GetAllNeighboursOfSpecificVertex() { //funkcja nie zwracaj¹ca niczego, sprawdzaj¹ca s¹siadów poszczególnych wierzcho³ków
		int counter = 0; //liczba wyst¹pieñ s¹siadów - domyœlnie 0
		for (int i = 0; i < _incidentMatrix.size(); i++) { //iterujemy po ka¿dym elemencie wektora (po wektorach)
			counter = 0; // wyzerowanie licznika przy ka¿dej iteracji
			cout << "Neighbours of V" << i << ": ";
			for (int j = 0; j < _incidentMatrix[i].size(); j++) { //iterujemy po ka¿dym elemencie wektorów (po intach)
				if (_incidentMatrix[i][j] == 1) { //jeœli element = 1, to znaczy ¿e ma s¹siada i musimy go znaleŸæ
					for (int k = 0; k < _incidentMatrix.size(); k++) { // iterujemy jeszcze raz po g³ównym wektorze (po wektorach)
						if (k == i) continue; //pomijamy sytuacjê, gdzie porównujemy te same wektory
						for (int l = 0; l < _incidentMatrix[k].size(); l++) { //iterujemy jeszcze raz po ka¿dym elemencie wektorów (po intach)
							if (_incidentMatrix[k][l] == -1 && j == l) { //jeœli wartoœæ elementu = -1 i indeksy porównywanych wektorów siê zgadzaj¹, mamy s¹siada
								cout << "V" << k << ";";
								counter++; //inkrementacja liczby s¹siadów konkretnego wierzcho³ka
							}
						}
					}
				}
				else if (counter == 0 && j == _incidentMatrix[i].size() - 1) { //jeœli licznik s¹siadów = 0 i rozpatrywany wektor zosta³ porównany ze wszystkimi innymi to znaczy ¿e wierzcho³ek nie ma s¹siadów
					cout << "V" << i << " has no neighbour...";
				}
			}
			cout << endl;
		}
	}

	void GetAllVertexesWhereInNeighoudOfAllVertexes() {//funkcja nie zwracaj¹ca niczego, sprawdzaj¹ca wierzcho³ki bêd¹ce s¹siadami wszystkich innych wierzcho³ków
		int counter = 0; //liczba wierzcho³ków bêd¹cych s¹siadami wszystkich innych wierzcho³ków
		int requiredNumberOfOnes = _incidentMatrix.size() - 1; //wymagana liczba jedynek w wektorze (wierzcho³ek ma wszystkich s¹siadów jeœli wektor sk³ada siê z samych ze i jedynek, gdzie liczba jedynek jest równa iloœci wierzcho³ków minus 1)
		int counterOfOnesInRow = 0; //licznik jedynek w wektorze
		bool minusValueHappened = false; //zmienna informuj¹ca czy pojawi³a siê wartoœæ -1 (domyœlnie false)
		for (int i = 0; i < _incidentMatrix.size(); i++) { //iterujemy po ka¿dym wektorze
			minusValueHappened = false; //przy ka¿dej iteracji resetujemy minusValueHappened na false
			counterOfOnesInRow = 0; //przy ka¿dej iteracji resetujemy licznik jedynek
			for (int j = 0; j < _incidentMatrix[i].size(); j++) { //iterujemy ka¿dy element w wektorze
				if (_incidentMatrix[i][j] == -1) { // jeœli element = -1, to znaczy ¿e wierzcho³ek nie jest s¹siadem wszystkich wierzcho³ków
					minusValueHappened = true; //ustawiamy zmienn¹ informuj¹c¹ o pojawieniu siê ujemnej wartoœci
					break;//przerywamy iterowanie i wychodzimy z obecnej pêtli
				}
				else if (_incidentMatrix[i][j] == 1) { //jeœli element = 1, to zwiêkszamy licznik jedynek
					counterOfOnesInRow++;//zwiêkszamy licznik jedynek
				}
			}
			if (counterOfOnesInRow == requiredNumberOfOnes && !minusValueHappened) { //po przeiterowaniu wszystkich elementów, sprawdzamy czy licznik jedynek jest równy wymaganej iloœci jedynek, oraz czy nie pojawi³a siê jakaœ wartoœæ ujemna
				counter++; //jeœli wszystkie powy¿ej warunki s¹ spe³nione, to znaczy ¿e znaleŸliœmy szukany wierzcho³ek i zwiêkszamy liczbê ich wyst¹pieñ
				cout << "V" << i << " is the neighbour of all vertexes";
			}
		}

		if (counter == 0) { // jeœli liczba wyst¹pieñ szukanych wierzcho³ków = 0, wypisujemy ¿e nie znaleŸliœy takiego wierzcho³ka
			cout << "There is no vertex which is neighbour to all...";
		}

		cout << endl;
	}

	void GetDegreesOutFromAllVertexes() {//funkcja nie zwracaj¹ca niczego, sprawdzaj¹ca stopnie wychodz¹ce z wierzcho³ka
		int counter = 0; //liczba stopni wychodz¹ca z wierzcho³ka (domyœlnie równa 0)
		for (int i = 0; i < _incidentMatrix.size(); i++) { //iterujemy po ka¿dym wektorze
			counter = 0; // resetujemy liczbê stopni przy ka¿dej iteracji
			cout << "Degrees out from V" << i << ": ";
			for (int j = 0; j < _incidentMatrix[i].size(); j++) { //iterujemy po ka¿dym elemencie wektora
				if (_incidentMatrix[i][j] == -1) { //jeœli element jest równy -1, zwiêkszamy liczbê stopni o 1
					counter++; //zwiêkszamy liczbê stopni o 1
				}
			}
			cout << counter << endl; //wyœwietlamy wynik dla konkretnego wierzcho³ka
		}
	}

	void GetDegreesInToAllVertexes() {//funkcja nie zwracaj¹ca niczego, sprawdzaj¹ca stopnie wchodz¹ce do wierzcho³ka
		int counter = 0; //liczba stopni wychodz¹ca z wierzcho³ka (domyœlnie równa 0)
		for (int i = 0; i < _incidentMatrix.size(); i++) { //iterujemy po ka¿dym wektorze
			counter = 0; // resetujemy liczbê stopni przy ka¿dej iteracji
			cout << "Degrees in to V" << i << ": ";
			for (int j = 0; j < _incidentMatrix[i].size(); j++) {//iterujemy po ka¿dym elemencie wektora
				if (_incidentMatrix[i][j] == 1) {//jeœli element jest równy 1, zwiêkszamy liczbê stopni o 1
					counter++;//zwiêkszamy liczbê stopni o 1
				}
			}
			cout << counter << endl;//wyœwietlamy wynik dla konkretnego wierzcho³ka
		}
	}

	void GetAllIsolatedVertexes() {//funkcja nie zwracaj¹ca niczego, sprawdzaj¹ca izolowane wierzcho³ki
		int counter = 0; //liczba izolowanych wierzcho³ków (domyœlnie równa 0)
		for (int i = 0; i < _incidentMatrix.size(); i++) {//iterujemy po ka¿dym wektorze
			bool allElementsAreZeros = std::all_of(_incidentMatrix[i].begin(), _incidentMatrix[i].end(), [](int i) { return i == 0; });//izolowany wierzcho³ek to taki, który posiada same zera w wektorze. Sprawdzamy wiêc czy wektor sk³¹da siê z samych zer
			if (allElementsAreZeros) { //jeœli wektor sk³¹da siê z samych zer to:
				cout << "V" << i << " is isolated" << endl; //wyœwietlamy izolowany wektor
				counter++; //zwiêkszamy liczbê izolowanych wierzcho³ków o 1
			}
		}
		if (counter == 0) { //jeœli liczba izolowanych wierzcho³ków = 0, to wyœwietlamy odpowiedni komunikat
			cout << "There is not any isolated vertex..." << endl;
		}
	}

	void GetAllLoops() {//funkcja nie zwracaj¹ca niczego, sprawdzaj¹ca pêtle
		int counter = 0; //liczba pêtli (domyœlnie równa 0)
		int counterOfOnesInColumn = 0; // pêtla jest wtedy, gdy kolumna (czyli spoœród wszystkich elementów wektorów przy tym samym indeksie) zawiera jedn¹ jedynkê i same zera. Dlatego deklarujemy zmienn¹ przechowuj¹c¹ liczbê jedynek w kolumnie
		bool isLooped = true; // zmienna informuj¹ca czy jest pêtla (domyœlnie ustawiona na true, bêdziemy j¹ zmieniaæ jeœli w kolumnie wyst¹pi¹ ujemne wartoœci, lub liczba jedynek jest wiêksza ni¿ 1)
		int numberOfColumns = _incidentMatrix[0].size(); // zmienna informuj¹ca o liczbie kolumn (bierzemy pierwszy lepszy wektor i sprawdzamy ile ma elementów)

		for (int i = 0; i < numberOfColumns; i++) { //poniewa¿ nie chcemy iterowaæ najpierw po wierszach,tylko po kolumnach, dlatego iterujemy od 0 do iloœci kolumn w macierzy
			isLooped = true;// przy ka¿dej iteracji resetujemy zmienn¹ isLooped na true
			counterOfOnesInColumn = 0;//resetujemy liczbê wyst¹pieñ jedynek w kolumnie

			for (int j = 0; j < _incidentMatrix.size(); j++) { //iterujemy po ka¿dym wektorze
				if (_incidentMatrix[j][i] == 1) { //jeœli element jest równy 1, inkrementujemy zmienn¹ counterOfOnesInColumn
					//w poprzednich przyk³¹dach by³o _incidentMatrix[i][j]. Tutaj mamy _incidentMatrix[j][i], poniewa¿ chcemy porównywaæ elementy ró¿nych wektorów o tym samym indeksie. 
					// Czyli zamiast _incidentMatrix[0][0], _incidentMatrix[0][1],_incidentMatrix[0][2], itd. robimy _incidentMatrix[0][0], _incidentMatrix[1][0],_incidentMatrix[2][0] itd.
					counterOfOnesInColumn++;
				}
				else if (_incidentMatrix[j][i] == -1 || counterOfOnesInColumn > 1) { //jeœli wyst¹pi ujemna liczba lub liczba jedynek w kolumnie jest wiêksza ni¿ 1, to znaczy ¿e to nie jest pêtla
					isLooped = false; //oznaczamy ¿e to nie jest pêtla
					break; //przerywamy bie¿¹c¹ pêtlê bo nie ma sensu dalej sprawdzaæ
				}
			}
			if (isLooped) { //jeœli zmienna isLooped wci¹¿ daje true to wyœwietl komunikat i zwiêksz liczbê pêtli
				cout << "V" << i << " is looped" << endl;//wyœwietlamy komunikat
				counter++;// zwiêkszamy liczbê pêtli
			}
		}

		if (counter == 0) { //jeœli liczba pêtli jest równa 0, wyœwietl komunikat
			cout << "There is not any loop..." << endl;
		}
	}

	void GetAllTwoWayEdges() {//funkcja nie zwracaj¹ca niczego, sprawdzaj¹ca dwukierunkowe krawêdzie
		int numberOfRowsToCompare = _incidentMatrix.size() - 1; //liczba wierszy (wektorów) do porównywania (jak porównujemy np. pierwszy, to ni musimy porównywaæ go sam ze sob¹, dlatego jest minus jeden)
		int numberOfColumns = _incidentMatrix[0].size(); //liczba kolumn
		//dwukierunkowe krawêdzie charakteryzuj¹ siê tym, ¿e w jednym wierszu (wektorze) musz¹ wyst¹piæ wartoœci -1 oraz 1, i w innym wierszu (wektorze) pod tymi samymi indeksami musz¹ byæ wartoœci przeciwne. 
		bool checkOfOnes = false; // sprawdzenie czy wyst¹pi³a przeciwna wartoœæ do -1 (domyœlnie false)
		bool checkOfMinusOnes = false;// sprawdzenie czy wyst¹pi³a przeciwna wartoœæ do 1 (domyœlnie false)
		vector<int> vectorOfPositionsToCheck; //deklarujemy osobny wektor, do którego bêdziemy dodawaæ indeksy, pod którymi znajduje siê element -1 lub 1 w danym wektorze
		for (int i = 0; i < _incidentMatrix.size() - 1; i++) {//iterujemy po wektorach (_incidentMatrix.size()-1, poniewa¿ ostatni wektor nie musimy ju¿ z niczym porównywaæ, bo zosta³ porównany ze wszystkimi wektorami w poprzednich iteracjach)
			if (!(std::find(_incidentMatrix[i].begin(), _incidentMatrix[i].end(), 1) != _incidentMatrix[i].end()
				&& std::find(_incidentMatrix[i].begin(), _incidentMatrix[i].end(), -1) != _incidentMatrix[i].end())) {//sprawdzamy czy w wektorze wystêpuje 1 lub -1. Jeœli nie to kontynuuj do nastêpnej iteracji
				continue;
			}


			for (int j = 0; j < _incidentMatrix[i].size(); j++) { //iterujemy po elementach wektora (po intach)
				if (_incidentMatrix[i][j] == 1 || _incidentMatrix[i][j] == -1) { // jeœli element jest równy 1 lub -1, to dodaj jego indeks do wektora vectorOfPositionsToCheck
					vectorOfPositionsToCheck.push_back(j);
				}
			}

			int twoDirectionalEdge1 = -1;//zmienna pomocnicza do zapisania numeru dwukierunkowej krawêdzi jeœli wyst¹pi
			int twoDirectionalEdge2 = -1;//zmienna pomocnicza do zapisania numeru dwukierunkowej krawêdzi jeœli wyst¹pi
			for (int k = i; k < _incidentMatrix.size() - 1; k++) {//iterujemy po wektorach, aby porównywaæ wektor z kolejnymi wektorami
				twoDirectionalEdge1 = -1; // resetujemy zmienn¹ pomocnicz¹ do -1 (-1 poniwa¿ numer krawêdzi nie mo¿e byæ ujemny))
				twoDirectionalEdge2 = -1; // resetujemy zmienn¹ pomocnicz¹ do -1
				checkOfOnes = false; // resetujemy zmienn¹ informuj¹c¹ o poprawnym sprawdzeniu czy znaleziono jedynkê pasuj¹c¹ do elementu przy konkretnym indeksie 
				checkOfMinusOnes = false;// resetujemy zmienn¹ informuj¹c¹ o poprawnym sprawdzeniu czy znaleziono minus jedynkê pasuj¹c¹ do elementu przy konkretnym indeksie 
				for (int kk = 0; kk < vectorOfPositionsToCheck.size(); kk++) { //iterujemy po zapisanych indeksach, które powinny daæ nam wartoœæ 1 lub -1 ¿eby znaleŸæ dwukierunkowe krawêdzie
					if (_incidentMatrix[i][vectorOfPositionsToCheck[kk]] == -_incidentMatrix[k + 1][vectorOfPositionsToCheck[kk]]) { // jeœli znajdziemy odwrotn¹ wartoœæ w kolejnych wektorach k do naszego wektora i, przy tym samym indeksie, to mamy podstawê s¹dziæ ¿e to s¹ nasze dwukierunkowe krawêdzie
						if (_incidentMatrix[k + 1][vectorOfPositionsToCheck[kk]] == 1) { //jeœli w znalezionym liinijkê wczeœniej wierszu, przy indeksie kk element wynosi 1, to mamy za³atwiony check z jedynk¹
							checkOfOnes = true; //ustawiamy flagê na true
							twoDirectionalEdge1 = vectorOfPositionsToCheck[kk];//ustawiamy numer pierwszej krawêdzi dwukierunkowej
						}
						else if (_incidentMatrix[k + 1][vectorOfPositionsToCheck[kk]] == -1) {//jeœli w znalezionym liinijkê wczeœniej wierszu, przy indeksie kk element wynosi -1, to mamy za³atwiony check z minus jedynk¹
							checkOfMinusOnes = true; //ustawiamy flagê na true
							twoDirectionalEdge2 = vectorOfPositionsToCheck[kk];//ustawiamy numer drugiej krawêdzi dwukierunkowej
						}

						if (checkOfOnes && checkOfMinusOnes) {// jeœli oba checki s¹ true, to mamy ustalon¹ nasz¹ dwukierunkowœæ
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

