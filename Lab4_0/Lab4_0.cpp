#include <iostream>
#include <vector>
#include <algorithm>

void print_permutations(int n) {
    // Створюємо початкову перестановку {1, 2, ..., n}
    std::vector<int> permutation(n);
    for (int i = 0; i < n; ++i) {
        permutation[i] = i + 1;
    }

    // Виводимо лексикографічно першу перестановку
    do {
        for (int i = 0; i < n; ++i) {
            std::cout << permutation[i] << " ";
        }
        std::cout << std::endl;
    } while (std::next_permutation(permutation.begin(), permutation.end())); 
}

int main() {

    setlocale(LC_ALL, "UKR");

    int n;
    std::cout << "Введiть натуральне число n: ";
    std::cin >> n;

    std::cout << "Усi перестановки в лексикографiчному порядку:" << std::endl;
    print_permutations(n);

    return 0;
}
