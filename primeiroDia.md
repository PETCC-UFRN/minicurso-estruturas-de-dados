---
layout: layoutGit
title: Minicurso de Matemática aplicada à Computação
---
<div id="sumario" class="sumario-git">
    <h1>Dia 1</h1>
    <details>
        <summary><a href="#introdução-à-algoritmos">Introdução à Algoritmos</a></summary>
        <ul>
            <li><a href="#definição-e-história">Definição e História</a></li>
            <li><a href="#importância-nos-dias-atuais">Importância nos Dias Atuais</a></li>
        </ul>
    </details>  
    <details>
         <summary><a href="#revisão-de-c">Revisão de C++</a></summary>
        <ul>
            <li><a href="#motivação">Motivação</a></li>
            <li><a href="#diferença-de-sintaxe">Diferença de Sintaxe</a></li>
            <li><a href="#comandos-simples">Comandos Simples</a></li>
            <li><a href="#análise-de-códigos-em-c">Análise de Códigos em C++</a></li>
            <li><a href="#qual-é-o-melhor">Qual é o melhor?</a></li>
        </ul>
    </details>
    <details>
        <summary><a href="#análise-assintótica"> Análise Assintótica</a></summary>
        <ul>
            <li><a href="#introdução"> Introdução</a></li>
            <ul>
                <li><a href="#pior-caso"> Pior Caso </a></li>
                <li><a href="#melhor-caso"> Melhor Caso</a></li>
                <li><a href="#caso-médio"> Caso Médio </a></li>
            </ul>
            <li><a href="#notações-o-θ-e-𝝮"> Notações O, Θ e 𝝮 </a></li>
            <li><a href="#exercícios"> Exercícios</a></li>
        </ul>
    </details>
    <details>
        <summary><a href="#cálculo-assintótico"> Cálculo Assintótico </a></summary>
        <ul>
            <li><a href="#tabela-de-complexidade"> Tabela de Complexidade</a></li>
            <li><a href="#o-que-é-eficiência"> O que é Eficiência? </a></li>
                <li> <a href="#eficiência-de-tempo-x-espaço"> Eficiência de Tempo X Espaço</a></li>
                <ul>
                    <li><a href="#stl"> STL </a></li>
                </ul>
            <li><a href="#exercícios-1"> Exercícios </a></li>
        </ul>
    </details>
  <button class="toggle-button" id="toggle-button">
      Esconder Sumário
  </button>
</div>
<br>


# Introdução à Complexidade Assintótica

## Introdução à Algoritmos  
<!--

Como o nome surgiu

definição

Timeline de acontecimentos históricos sobre algoritmos 

-->


### Definição de Algoritmos

De forma informal, um **algoritmo** pode ser definido como qualquer procedimento computacional bem definido, que recebe um valor (ou conjunto de valores) como **entrada** e produz um valor (ou conjunto de valores) como **saída** (Cormen, 2002).

Outra forma de enxergar algoritmos é como ferramentas para **resolver problemas computacionais específicos**. Nessa perspectiva, o algoritmo descreve a relação **entrada-saída** de um programa (Cormen, 2002).

Assim, pode-se entender um algoritmo como um **conjunto de instruções** destinadas a realizar uma tarefa.

**Exemplo:**  
Dada a sequência `<4, 6, 2, 7, 8>` como entrada, um algoritmo de ordenação pode seguir os seguintes passos:
1. Comparar os elementos da sequência;
2. Identificar pares fora de ordem;
3. Trocar esses elementos de posição;
4. Repetir o processo até que não existam mais elementos fora de ordem.

Assim, o algoritmo retorna `<2, 4, 6, 7, 8>` como saída.

### Etapas para resolver problemas

---

### História e Evolução dos Algoritmos

#### Antiguidade

- **Algoritmo de Euclides (300 a.C.)**  
  Técnica para encontrar rapidamente o **MDC** (máximo divisor comum) de dois inteiros.

#### Idade de Ouro Islâmica (Século IX)

- **Muhammad ibn Musa al-Khwarizmi**, matemático que contribuiu para o desenvolvimento da álgebra.  
- Para resolver equações matemáticas, al-Khwārizmī seguia sistematicamente uma sequência de passos, conceito fundamental de **algoritmo**.  
- Após ser traduzido para o latim, seu livro sobre numerais hindus recebeu o título *Algorithmi de Numero Indorum*, origem da palavra *algoritmo*.

#### Século XIX

- **Ada Lovelace** criou o que é considerado o **primeiro algoritmo de computador**, projetado para calcular números de Bernoulli na máquina analítica de Babbage.

#### Década de 1930


- **Alan Turing**: Formalizou o conceito de computação com a **Máquina de Turing**, estabelecendo a base teórica da ciência da computação moderna.
- Introduziu a noção de “computável”.

---

<!-- 
Acho que essa parte pode ser no final
-->

## "Introdução" à Estruturas de Dados

Para compreender o conceito de Estruturas de Dados, é fundamental conhecer primeiro os Tipos Abstratos de Dados (TADs). Esses dois conceitos estão diretamente relacionados, mas não são a mesma coisa.

### Tipos Abstrados de Dados (TAD)
Um TAD é formado por:
- um **conjunto de dados**
- um **conjunto de operações** para manipular esses dados

Vamos exemplificar a seguir.

Podemos definir o TAD Pilha da seguinte forma:
- `Pilha{topo, tamanho}`

Para manipular esse conjunto podemos usar as operações:
- `criarPilha()` - cria uma pilha com tamanho n
- `push(x)` - empilha um elemento x
- `pop()` - remove o elemento do topo
- `top()` - consulta o topo
- `isEmpty()` - verifica se está vazia
- `destruirPilha()` - apaga uma pilha

Note que foi definido apenas quais dados existem e quais operações podem ser feitas, sem dizar como isso é implementado.

### Definição de Estruturas de Dados
Uma Estrutura de Dados é a implementação concreta de um TAD em uma linguagem de programação, usando algoritmos.

As estruturas estabelecem:
- a forma que os dados são dispostos na memória
- como as operações são realizadas

Vamos implementar a Pilha, usando um array:

```
truct Pilha {
    int* dados;        // array que armazena os elementos
    int topo;          // índice do topo da pilha
    int capacidade;    // tamanho máximo da pilha
};

Pilha* criarPilha(int capacidade) {
    Pilha* p = new Pilha;
    p->dados = new int[capacidade];
    p->capacidade = capacidade;
    p->topo = -1;
    return p;
}

void push(Pilha* p, int x) {
    if (p->topo == p->capacidade - 1)
        throw std::overflow_error("Pilha cheia");

    p->dados[++p->topo] = x;
}

int pop(Pilha* p) {
    if (isEmpty(p))
        throw std::underflow_error("Pilha vazia");

    return p->dados[p->topo--];
}

bool isEmpty(Pilha* p) {
    return p->topo == -1;
}

void destruirPilha(Pilha* p) {
    delete[] p->dados;
    delete p;
}
```

## Importância nos Dias Atuais <!-- JOGOS :o -->


##  Revisão de C++
### Motivação             <!-- Explicar por que estamos usando C++-->
### Diferença de Sintaxe
<!-- 
     Mostrar e diferenciar códigos análogos em C e C++
     STL
  -->
### Comandos Simples
<!-- melhorar a introdução
     Variaveis
     Condicionais
     Loops
     Funções
     Structs
-->

### Análise de códigos em C++ <!-- Mostrar Busca Binária e Linear -->
###  Qual é o melhor?         <!-- Apenas introduz essa dúvida -->

## Análise de Algoritmos

Um mesmo problema pode ser resolvido por diferentes algoritmos. Nesse contexto, a **análise de algoritmos** permite quantificar o custo computacional de cada solução, possibilitando a comparação entre elas e a escolha do algoritmo mais eficiente.

### Modelo RAM

Uma forma simples de medir a eficiência de um algoritmo é por meio da medição do tempo de execução. No entanto, essa abordagem é fortemente influenciada por fatores externos, como o hardware utilizado, a quantidade de memória disponível e o compilador, o que dificulta comparações justas entre algoritmos.

Para contornar esse problema, utiliza-se uma **abstração do modelo de computação**, chamada **RAM (_Random Access Machine_)**. Nesse modelo, assume-se que o algoritmo é executado em uma máquina ideal que possui instruções aritméticas, de movimentação de dados e de controle, e que cada instrução leva um tempo constante para ser executada.

### Função de Complexidade de Tempo

A função de complexidade de tempo, denotada por `T(n)`, representa o tempo necessário para a execução de um algoritmo em função do tamanho da entrada `n`, considerando o modelo RAM. Essa função permite analisar como o custo do algoritmo cresce à medida que o tamanho da entrada aumenta.

**Exemplo:**

```
  int menorElemento(int v[], int n){
      int i;
      int menor = v[0];

      for(i = 1; i < n; i++){
          if(v[i] < menor){
              menor = v[i];
          }
      }

      return menor;
  }

```
A função de complexidade de tempo desse algoritmo é dada pelo número de comparações entre os elementos do vetor `v[]`. Como o laço realiza uma comparação para cada elemento, exceto o primeiro, temos:

`T(n) = n - 1`. 

Nesse caso, o tempo de execução é **uniforme** para qualquer entrada de tamanho `n`, ou seja, independe da ordem ou dos valores dos elementos.

Porém, existem algoritmos que gastam menos tempo dependendo da organização da entrada. Um exemplo clássico é a **busca sequencial**, cujo tempo de execução varia conforme a posição do elemento procurado.

**Exemplo:**

```
	int buscaSequencial(int v[], int n, int chave){
    	int i;
        
        for (i = 0; i < n; i++){
        	if(v[i] == chave){
            	return i;
            }
        }
        
        return -1;
    }

```
Nesse algoritmo, identificam-se **três casos de análise**: o melhor caso, o pior caso e o caso médio.

#### Melhor Caso

O melhor caso ocorre quando o valor que estamos procurando (`chave`) se encontra no primeiro elemento do vetor. Nesse cenário, apenas uma comparação é realizada. Logo:

`T(n) = 1`

#### Pior Caso

O pior caso ocorre quando o valor `chave` se encontra no último elemento do vetor ou não está presente. Nesse caso, é necessário percorrer todo o vetor`v[]`, realizando n comparações. Assim:

`T(n) = n`.

#### Caso Médio

O **caso médio** representa o tempo de execução esperado do algoritmo considerando **todas as possíveis posições** do elemento procurado no vetor, assumindo que cada posição tem **a mesma probabilidade** de conter a chave buscada.

Na busca sequencial, se o elemento `chave` estiver presente no vetor `v[]`, ele pode estar em qualquer uma das `n` posições com probabilidade igual a `1/n`. Nesse caso, o número de comparações realizadas será igual à posição do elemento no vetor (considerando indexação iniciando em 1).

Assim, o tempo médio é dado pela **média aritmética** do número de comparações necessárias em cada posição:

`T(n) = (1 + 2 + 3 + ... + n) / n`

Sabemos que a soma dos primeiros `n` números naturais é:

`1 + 2 + ... + n = n(n + 1) / 2`

Substituindo na expressão do tempo médio, temos:

`T(n) = [n(n + 1) / 2] / n`

`T(n) = (n + 1) / 2`

#### Importância da Análise Assintótica

Para valores pequenos de `n`, qualquer algoritmo, mesmo que ineficiente, tende a apresentar um tempo de execução baixo. No entanto, à medida que o tamanho da entrada aumenta, a complexidade do algoritmo torna-se um fator crítico.

Ao escolher um algoritmo, deve-se analisar aquele que possui **maior escalabilidade**, de acordo com o seu **comportamento assintótico**.

## Notações Assintóticas

As notações assintóticas são utilizadas para representar o **comportamento assintótico** das funções de complexidade de tempo, descrevendo como o custo de execução de um algoritmo cresce à medida que o tamanho da entrada aumenta.

### Notação O

Uma função `f(n)` é dita **O(g(n))** se existem constantes positivas `c` e `n₀` tais que:

f(n) ≤ c · g(n), para todo n ≥ n₀.

Essa notação fornece um **limite superior assintótico** para a função de complexidade, ou seja, descreve o pior crescimento possível do tempo de execução de um algoritmo a partir de um determinado tamanho de entrada, ignorando constantes e termos de menor ordem.

#### Exemplos

1. Seja f(n) = (n + 1)².  
   Para n ≥ 2, temos:

   (n + 1)² = n² + 2n + 1 ≤ 3n²

   Logo, f(n) é **O(n²)**, considerando c = 3 e n₀ = 2.

2. Seja f(n) = 2n³ + 3n² + n.  
   Para n ≥ 8, temos:

   2n³ + 3n² + n ≤ 4n³

   Assim, f(n) é **O(n³)**, considerando c = 4 e n₀ = 8.
   
Quando dizemos que um algoritmo é **O(n²)**, por exemplo, queremos dizer que o seu tempo de execução cresce, no pior caso, de forma proporcional a `n²` à medida que o tamanho da entrada aumenta. 

### Notação Θ

### Notação 𝝮 

##   Análise Assintótica
###  Introdução 
<!--


Definição e uso 

Olhando um gráfico, e vendo a similaridade com funções matemáticas
Definição formal
Gatilho puxando para análise de pior/melor/medio caso.

-->

#### Pior Caso
#### Melhor Caso
#### Caso Médio
###  Exemplo <!-- Pegar um código como exemplo e ver seu pior/melhor/médio caso -->
###  Notações O, Θ e 𝝮 
###  Exercícios

## Cálculo Assintótico
###  Tabela de Complexidade
<!-- Mostrar que 1 << logn << n <<...  -->
###  O que é Eficiência?
###  Eficiência de Tempo X Espaço
#### Aplicação com STL
###  Exercícios

