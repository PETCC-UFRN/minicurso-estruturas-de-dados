---
layout: layoutGit
title: Minicurso de Estruturas de Dados e Algoritmos
---
# Como um programa interage com o computador

Quando um programa é compilado sabemos que é necessário espaço na memória para que ele possa ser executado, mas afinal, de qual espaço estamos falando? Quando somos introduzidos aos tipos de dados de C/C++ aprendemos que `int` ocupa 4 bytes, `char` ocupa 1 byte e por aí vai. Mas será que esses dados ficam jogados de qualquer forma dentro da memória RAM? A resposta é *não*. A memória usada para rodar um programa pode ser dividida em duas partes.

## Stack

Essa parte da memória leva este nome por seguir o padrão [LIFO](https://pt.wikipedia.org/wiki/LIFO), que empilha memória conforme lê as linhas do programa. Ela é responsável por armazenar tudo cujo *tamanho* é sabido em *tempo de compilação* e cujo *tempo de vida* é ditado conforme o escopo.

<div style="text-align: center;"><img src="assets/images/dia2/stack.png" alt="" style="widht:300px;height:300px;"> </div>

Dentro da Stack cada função tem seu *StackFrame*, que é o espaço dedicado para as *variáveis locais* de cada função, cujo acesso é permitido apenas dentro daquele escopo.

### Exercício

> Ilustre a Stack do seguinte programa
```cpp
float hello() {
    std::cout << "hello world" << std::endl;

    return 12.5;
}

bool inverse(bool b) {
    return !b;
}

int main() {
    int a;

    std::cin >> a;

    if (inverse(true)) {
        int b = 1000;
    }

    return 0;
}
```

### Atenção na tela

Que tal resolvermos esse [exercício](https://judge.beecrowd.com/en/problems/view/1176) juntos?
<!-- fazer a solução recursiva e... ué, pq dá erro? -->
<!-- desenhar a stack empilhando várias chamadas da fibonacci -->
<!-- stack overflow -->
<!-- cuidado com a profundidade da recursão em linguagens strict -->

## Heap

A região de memória em questão trabalha de forma complementar à *Stack*, armazenando todos os dados que tornariam o acesso menos performático nesta. Isso é, tudo que precisa ter um espaço reservado mas cujo tamanho só é conhecido em *tempo de execução*. Além disso, aqui temos mais liberdade de gerenciar a memória do programa, entretanto, a natureza dinâmica dessa abordagem faz com que ela seja naturalmente *menos performática*.

```cpp
int main() {
    int n;

    std::cin >> n;

    std::vector<int> vec(n, -1); // mora na stack, e seu conteúdo na heap

    int* a = &n;                 // mora na stack, e seu conteúdo também
    char* b = new char[n];       // mora na stack, seu conteúdo na heap

    delete[] b;                  // necessário desalocar manualmente

    return 0;
}
```

### Exercício

> Ilustre a Stack e Heap do seguinte programa
```cpp
#include <iostream>
#include <vector>
#include <string>

void func(int x) {
    int a = 10;
    int* p = new int(20);

    std::string s = "abc";

    std::vector<int> v(3, 5);

    static int counter = 0;

    delete p;
}

int main() {
    int n = 5;

    int arr[5] = {1,2,3,4,5};

    int* arr2 = new int[n];

    func(n);

    delete[] arr2;

    return 0;
}
```
<!-- stack - n, arr, arr2(conteúdo na heap)
    daí outro stackframe é criado acima de main
    stack - a, p(p* na heap), "s" ...
        como "s" é um literal pequeno fica na stack, mas se tiver 20/30 chars ficaria na heap(small string optimization - sso)
    ... v(conteúdo na heap)
   counter fica... -->


## Variáveis Estáticas

wip
<!-- explicar static -->
<!-- verificar se variáveis const também ficam aqui -->


# Ordenação

Ordenação se trata de um dos problemas mais abordados na área da computação. Comunmente é um exemplo bastante associado para introduzir a análise assintótica, mas além disso, também é um tópico que busca estimular de maneira criativa a forma de pensar uma solução para um problema. 

Dada uma lista `A` de tamanho `n`, sabemos que ela está ordenada quando a seguinte solução é satisfeita:

$$
{a_0 \leq a_1 \leq a_2 \leq ... \leq a_{n-2} \leq a_{n-1}}
$$

Retomando o conceito de análise assintótica, notamos que a verificação acaba em algum dos seguintes casos:

- Quando encontramos o primeiro elemento que não satisfaz a desigualdade, nesse caso retornamos `false`, pois `A` não está ordenada
- Quando chegamos ao fim da lista sem encontrar um elemento assim, nesse caso retornamos `true`, pois `A` está ordenada

### Exercício

>Implemente uma função que verifica se uma lista está ordenada ou não.

<details>
<summary>Spoiler!</summary>
No pior dos casos será necessário percorrer a lista toda para descobrir se ela é ordenada ou não. Sendo assim, sua complexidade é <b>O(n)</b>. Mas para os algoritmos a seguir vamos desconsiderar a verificação da ordenação, considerando no seu custo apenas a ordenação em si.
</details>

## Uma abordagem comum

Caso você precisasse ordenar um grupo de pessoas por altura, como faria? A única restrição é que só se pode mover uma pessoa por vez, mas não fazer "trocas". Uma das abordagens mais comuns seria percorrer o grupo inteiro e verificar quem é a menor pessoa encontrada naquela iteração. Considere o exemplo a seguir:

```cpp
void ordenar(vector<int> &lista) {
    int tamanho = lista.size();

    for (int comeco = 0; comeco < tamanho - 1; comeco++) {
        int indice_do_menor = comeco;

        for (int atual = comeco + 1; atual < tamanho; atual++) {
            if (lista[atual] < lista[indice_do_menor]) {
                indice_do_menor = atual; 
            }
        }

        swap(lista[comeco], lista[indice_do_menor]);
    }
}
```

Vamos analisar em tempo real o que acontece quando executamos esse código.

## Atenção na tela!
<!-- Rodar o script de visualização -->

Agora vamos analisar a complexidade desse algoritmo, partindo de um exemplo do pior cenário. Considere a lista `[7,6,5,4,3,2,1]`.
## Atenção no quadro!
<!-- T(7) = 7 + 6 + 5... -->
<!-- T(4) = 4 + 3 + 2... -->
<!-- T(n) = \sum_{i=1}^{n} i-->
<!-- Criança insuportável chamada friedrich gauss -->
<!-- Mostrar q sempre vai precisar de n(n+1)/2 iterações -->
<!-- Mostrar a ideia dos pares -->
<!-- = O(n²) -->

<details>
<summary>Spoiler!</summary>
Temos $7 + 6 + 5 + 4 + 3 + 2 + 1$ iterações. Logo <b>O($$n²$$)</b>.
</details>

<details>
<summary>Spoiler 2!</summary>
Esse algoritmo tem nome. <b>Selection Sort</b>.
</details>

# Outras formas de ordenar

Note que a abordagem usada anteriormente é dependente de conhecermos o estado da lista de forma ampla, a partir de um elemento em diante. E isso é necessário pois toda troca é "semi-definitiva", isso pois um dos elemento não vai sair mais daquela posição. Mas será que precisamos mesmo que toda a alteração feita tenha que ser definitiva?

Antes de responder isso, que tal pensarmos no escopo que precisamos ter noção para tomar uma decisão. E se só olhassemos apara o elemento vizinho? Perderíamos o escopo do `Selection Sort`, certo? Mas isso necessariamente é ruim?

Considere o código a seguir:

```cpp
void sort(vector<int>& lista) {
    int tamanho = arr.size();

    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (lista[j] > lista[j + 1]) {
                swap(lista[j], lista[j + 1]);
            }
        }
}
```

Perceba que o `Selection Sort` ordenava diretamente, ou seja, se preocupando que o menor elemento estivesse no começo da lista. O que as duas abordagens vistas até o momento têm em comum?
<!-- Ambas acumulam a lista parcialmente ordenada em uma das pontas -->

## Atenção na tela
<!-- Rodar o script de visualização -->

<details>
<summary>Spoiler!</summary>
O método que acabou de ser mostrado consiste no <a href="[https://www.google.com](https://pt.wikipedia.org/wiki/Bubble_sort)">Bubble Sort</a>
</details>

### Exercício
Implemente a `swap` para poder rodar esses algoritmos.
<!-- Questionar:
        - assinatura(para inteiros),
        - por que precisa ter referência?
        - desenhar a pilha de memória
        - fazer versão para chars
        - polimorfizar -->

<!-- void swap_ints(int& x, int& y) -->
<!-- void swap_chars(char& x, char& y) -->

 <!--
 template<typename T> void swap(T& left, T& right) {
	T tmp(left);
	left = right;
	right = tmp;
} -->


<!-- tangente sobre iteradores/endereços de memória
int main() {
	vector<int> vec = {0,1,2,3};

	std::cout << &vec << std::endl;
	std::cout << &vec + 1 << std::endl;
    // subtrair os hexadecimais numa calculadora
    // pq dá 24?
    // pq 1 byte = 8 bits e um int é composto por 4 bytes

    //inclusive...
    //a[i] = *(a+i)
    //     = *(i+a)
    //     = i[a]
	return 0;
} -->

Agora que temos noção do que se trata a *recursão*, podemos usá-la para entender melhor alguns conceitos de *ordenação*. Perceba que os algoritmos que vimos até o momento são todos *O(n²)*, mas será que ordenar sempre se trata de algo custoso assim?

Com essa abordagem, sim. Mas e se a gente pensasse um pouco mais como [Júlio César](https://pt.wikipedia.org/wiki/J%C3%BAlio_C%C3%A9sar) ou [Napoleão Bonaparte](https://pt.wikipedia.org/wiki/Napole%C3%A3o_Bonaparte)?

<div style="text-align: center;"><img src="assets/images/dia2/divideandconquer.jpg" alt="" style="widht:300px;height:300px;"> </div>

## Atenção no quadro
<!-- ordenar [8,6,4,2,5,1,2,7] com merge sort -->

### Exercício

>Qual a complexidade do algoritmo?

<!-- quando n < 2 a lista já está ordenada, logo O(1) -->
<!-- caso contrário, temos merge(mergesort(left), mergesort(right))-->
<!-- qual a complexidade da merge? ela precisa passar por todos os elementos das 2 listas, logo linear -->
<!-- qual a complexidade da mergesort nesse caso? é intuitivo pensar que T(n/2) para cada lista, ou seja, 2T(n/2) -->
<!-- Logo T(n) = { O(1), se n < 2. O(n) + 2T(n/2), c.c. } -->
<!-- Qual complexidade pertence a qual função? merge linear & mergesort log -->

```cpp
void merge(vector<int>& arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp vectors
    vector<int> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    // Merge the temp vectors back 
    // into arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], 
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], 
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right){
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}
```
<!-- chamar como mergeSort(arr, 0, arr.size() - 1); -->

### Exercício

> Dada uma lista de inteiros positivos descubra qual o perímetro do maior triângulo que pode ser formado por esses valores. Caso não seja possível formar um triângulo, retorne `-1`.

<!-- bool triangle(const int& a, const int& b, const int& c) {
    return a + b > c && b + c > a && c + a > b;
    // necessário checar todas as possibilidades pq não tenho garantia dos valores estarem ordenados
}

int maxPerimeter(vector<int> &arr) {
    int n = arr.size();
    int ans = -1;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                if(triangle(arr[i],arr[j],arr[k])) {
                    ans = max(ans, arr[i] + arr[j] + arr[k]);
                }
            }
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {6, 1, 6, 5, 8, 4};
    cout << maxPerimeter(arr);
    return 0;
} -->

<!-- qual a complexidade da abordagem acima? -->

<!-- int maxPerimeter(vector<int> &arr) {
    int n = arr.size();

    mergesort(arr, 0, n-1);

    for(int i = 0; i < n - 2; i++) {
        // só preciso checar a desigualdade uma vez agora que sei que estão ordenados
        if(arr[i] < arr[i + 1] + arr[i + 2]) {
            return arr[i] + arr[i + 1] + arr[i + 2];
            // nem preciso ver os valores seguintes, pois sei que vão ser menores ou iguais ao atual
        }
    }

    return -1;
} -->

<!-- ordenação + busca => O(n*log(n)) + O(n) => O(n*log(n)) -->

> Dadas 2 strings, diga se elas são anagramas.

<!-- void merge(vector<string>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<string> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(vector<string>& arr, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
} -->

# Two Pointers

Dentro do mundo das entrevistas técnicas há um padrão que se faz fortemente presente nas questões propostas, sendo umas das técnicas mais usadas para verificar o conhecimento de algoritmos e estruturas de dados do candidato. Esta se trata do *Two Pointers*, uma forma criativa solucionar problemas de estruturas de dados ordenáveis em *O(n)* ao invés de *O(n²)*.

### Exercício

> Dada uma lista *ordenada* de inteiros, como achar os dois inteiros que juntos somam *x*?

<!-- mostrar solução trivial de tentar todas as possibilidades, O(n²) -->

> E se generalizarmos para somar *m* inteiros ao invés de dois?

<!-- mostrar que vira O(n^m) -->

## Atenção no quadro

<!-- exemplificar com [-1,2,7,9,42,89] somar 16 -->

wip


https://www.geeksforgeeks.org/dsa/merge-sort/
https://www.geeksforgeeks.org/dsa/maximum-perimeter-triangle-from-array/
https://github.com/Chanda-Abdul/Several-Coding-Patterns-for-Solving-Data-Structures-and-Algorithms-Problems-during-Interviews/blob/main/%E2%9C%85%20%20Pattern%2002%3A%20Two%20Pointers.md
