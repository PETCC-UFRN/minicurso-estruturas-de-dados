---
layout: layoutGit
title: Minicurso de Matemática aplicada à Computação
---

<div id="sumario" class="sumario-git">
    <h1>Dia 2</h1>
   <details>
    <summary><a href="#Indução">Indução</a></summary>
      <ul>
        <li><a href="#O que é indução">O que é indução</a>
          <ul>
            <li><a href="#estrutura-da-indução">Estrutura da Indução</a></li>
          </ul>
        </li>
        <li><a href="#soma-de-gauss">Soma de Gauss</a>
          <ul>
            <li><a href="#indução-em-prática">Indução em Prática</a></li>
          </ul>
        </li>
        <li><a href="#indução-forte">Indução forte</a></li>
      </ul>
    </details>
    <details open>
    <summary><a href="#Recursão">Recursão</a></summary>
      <ul>
        <li><a href="#Onde usamos a recursão na programação">Onde usamos a recursão na programação</a>
          <ul>
            <li><a href="#recursão-vs-iteração">Recursão vs. Iteração</a></li>
          </ul>
        </li>
        <li><a href="#Perigos da recursão">Perigos da recursão</a>
          <ul>
            <li><a href="#exemplo-1-chamada-infinita-da-recursão-por-ausência-de-caso-base">Exemplo 1 -> Chamada infinita da recursão por ausência de caso base</a></li>
            <li><a href="#exemplo-2-chamada-infinita-da-recursão-por-buracos-no-caso-base">Exemplo 2 -> Chamada infinita da recursão por buracos no caso base</a></li>
            <li><a href="#exemplo-3-chamada-incompleta-por-problemas-no-passo-recursivo">Exemplo 3 -> Chamada incompleta por problemas no passo recursivo</a></li>
          </ul>
        </li>
        <li><a href="#Recursão bem definida">Recursão bem definida</a>
          <ul>
            <li><a href="#exemplo-de-recursão-bem-definida">Exemplo de recursão bem definida</a></li>
          </ul>
        </li>
        <li><a href="#Elementos básicos da recursão">Elementos básicos da recursão</a>
          <ul>
            <li><a href="#introdução-aos-elementos-básicos-da-recursão">Introdução aos elementos básicos da recursão</a></li>
          </ul>
        </li>
        <li><a href="#construindo-coleções-de-coisas">Construindo coleções de coisas</a>
          <ul>
            <li><a href="#utilizando-a-recursão-para-construir-coleções-de-coisas">Utilizando a recursão para construir coleções de coisas</a></li>
          </ul>
        </li>
        <li><a href="#Recursão em listas">Recursão em listas</a>
          <ul>
            <li><a href="#montando-construtores-de-listas">Montando construtores de listas</a></li>
            <li><a href="#descobrindo-a-função-length">Descobrindo a função LENGTH</a></li>
            <li><a href="#descobrindo-a-função-sum-exercício/desafio">Descobrindo a função SUM (Exercício/desafio)</a></li>
            <li><a href="#descobrindo-a-função-filter">Descobrindo a função FILTER</a></li>
            <li><a href="#descobrindo-a-função-map">Descobrindo a função MAP</a></li>
            <li><a href="#descobrindo-a-função-replicate">Descobrindo a função REPLICATE</a></li>
          </ul>
        </li>
        <li><a href="#Extrapolando para outros tipos">Extrapolando para outros tipos</a>
          <ul>
            <li><a href="#descobrindo-melhores-funções-even-e-odd">Descobrindo melhores funções EVEN e ODD</a></li>
            <li><a href="#verificando-se-uma-função-foi-bem-definida-recursivamente-kahoot">Verificando se uma função foi bem definida recursivamente (kahoot)</a></li>
          </ul>
        </li>
      </ul>
    </details>   <button class="toggle-button" id="toggle-button">
  
      Esconder Sumário
  
  </button>
  </div>

# Ordenação

Ordenação se trata de um dos problemas mais abordados na área da computação. Comunmente é um exemplo bastante associado para introduzir a análise assintótica, mas além disso, também é um tópico que busca estimular de maneira criativa a forma de pensar uma solução para um problema. 

Dada uma lista `A` de tamanho `n`, sabemos que ela está ordenada quando a seguinte solução é satisfeita:

$$
{$a_0 \leq a_1 \leq a_2 \leq ... \leq a_(n-2) \leq a_(n-1)$}
$$

Retomando o conceito de análise assintótica, notamos que a verificação acaba em algum dos seguintes casos:

- Quando encontramos o primeiro elemento que não satisfaz a desigualdade, nesse caso retornamos `false`, pois `A` não está ordenada
- Quando chegamos ao fim da lista sem encontrar um elemento assim, nesse caso retornamos `true`, pois `A` está ordenada

Dito isso, no pior dos casos será necessário percorrer a lista toda para descobrir se ela é ordenada ou não. Sendo assim, sua complexidade é `O(n)`. Mas para os algoritmos a seguir vamos desconsiderar a verificação da ordenação, considerando no seu custo apenas a ordenação em si.

## Uma abordagem comum

Caso você precisasse ordenar um grupo de pessoas por altura, como faria? A única restrição é que só se pode mover uma pessoa por vez, mas não fazer "trocas". Uma das abordagens mais comuns seria percorrer o grupo inteiro e verificar quem é a menor pessoa encontrada naquela iteração. Considere o exemplo a seguir:

```
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

## Atenção no quadro!

Agora vamos analisar a complexidade desse algoritmo, partindo de um exemplo do pior cenário. Considere a lista `[7,6,5,4,3,2,1]`.

## Atenção no quadro de novo!

<details>
<summary>Spoiler!</summary>
<br>
Temos 7 + 6 + 5 + 4 + 3 + 2 + 1 iterações. Logo O($$n²$$).
</details>

<details>
<summary>Spoiler 2!</summary>
<br>
Esse algoritmo tem nome. Selection Sort.
</details>

# Outras formas de ordenar

Note que a abordagem usada anteriormente é dependente de conhecermos o estado da lista de forma ampla, a partir de um elemento em diante. E isso é necessário pois toda troca é "semi-definitiva", isso pois um dos elemento não vai sair mais daquela posição. Mas será que precisamos mesmo que toda a alteração feita tenha que ser definitiva?

Antes de responder isso, que tal pensarmos no escopo que precisamos ter noção para tomar uma decisão. E se só olhassemos apara o elemento vizinho? Perderíamos o escopo do `Selection Sort`, certo? Mas isso necessariamente é ruim?

Considere o código a seguir:

```
void bubbleSort(vector<int>& lista) {
    int tamanho = arr.size();

    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (lista[j] > lista[j + 1]) {
                swap(lista[j], lista[j + 1]);
            }
        }
}
```

<div style="text-align: center;"><img src="assets/images/boxing.jpg" alt="" style="widht:300px;height:300px;"> </div>


### Descobrindo a função <span style="color: #081849; font-weight: bold;">REPLICATE</span>

### Descobrindo melhores funções <span style="color: #081849; font-weight: bold;">EVEN</span> e <span style="color: #081849; font-weight: bold;">ODD</span>

---
<script>
const dataDia2 = new Date('2025-03-11');
const agora = new Date();

if (agora < dataDia2) {
    document.body.innerHTML = '<h1 style="text-align:center; margin-top:20%;">Página Indisponível</h1>' +
                              '<p style="text-align:center;">Esta página estará disponível a partir de ' + dataDia2.toLocaleDateString() + '.</p>';
}
</script>
{% include petcccopyright.html %}
