// #include <iostream>
// #include <ctime>
// #include <iomanip>

// int main() {
//     clock_t start, end;
//     double elapsed_time;

//     // Segna l'inizio del tempo
//     start = clock();

//     // Il codice di cui vuoi misurare il tempo trascorso va qui

//     // Segna la fine del tempo
//     end = clock();

//     // Calcola il tempo trascorso in microsecondi
//     elapsed_time = (double)(end - start) / CLOCKS_PER_SEC * 1000000;

//     // Calcola il numero di cifre decimali necessarie per rappresentare il tempo in microsecondi
//     int decimal_places = 0;
//     while (elapsed_time < 1) {
//         elapsed_time *= 10;
//         decimal_places++;
//     }

//     // Stampare il tempo trascorso nel formato desiderato
//     std::cout << std::fixed << std::showpoint << std::setprecision(5) << elapsed_time / 100000 << " us" << std::endl;

//     return 0;
// }
