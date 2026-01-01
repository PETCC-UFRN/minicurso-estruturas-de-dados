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


## Definição de Algoritmos

De forma informal, um **algoritmo** pode ser definido como qualquer procedimento computacional bem definido, que recebe um valor (ou conjunto de valores) como **entrada** e produz um valor (ou conjunto de valores) como **saída** (Cormen, 2002).

Outra forma de enxergar algoritmos é como ferramentas para **resolver problemas computacionais específicos**. Nessa perspectiva, o algoritmo descreve a relação **entrada-saída** de um programa (Cormen, 2002).

Assim, pode-se entender um algoritmo como um **conjunto de instruções** destinadas a realizar uma tarefa.

> **Exemplo:**  
> Dada a sequência `<4, 6, 2, 7, 8>` como entrada, um algoritmo de ordenação retorna `<2, 4, 6, 7, 8>` como saída.

---

## História e Evolução dos Algoritmos

### Antiguidade

- **Algoritmo de Euclides (300 a.C.)**  
  Técnica para encontrar rapidamente o **MDC** (máximo divisor comum) de dois inteiros.

### Idade de Ouro Islâmica (Século IX)

- **Muhammad ibn Musa al-Khwarizmi**, matemático que contribuiu para o desenvolvimento da álgebra.  
- Para resolver equações matemáticas, al-Khwārizmī seguia sistematicamente uma sequência de passos, conceito fundamental de **algoritmo**.  
- Após ser traduzido para o latim, seu livro sobre numerais hindus recebeu o título *Algorithmi de Numero Indorum*, origem da palavra *algoritmo*.

### Século XIX

- **Ada Lovelace** criou o que é considerado o **primeiro algoritmo de computador**, projetado para calcular números de Bernoulli na máquina analítica de Babbage.

### Década de 1930

- **Alan Turing**: Formalizou o conceito de computação com a **Máquina de Turing**, estabelecendo a base teórica da ciência da computação moderna.  
- Introduziu a noção de “computável”.

---

## "Introdução" à Estruturas de Dados
### Definição

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

