---
layout: layoutGit
title: Minicurso de Matemática aplicada à Computação
---


<div id="sumario" class="sumario-git">
    <h1>Sumário</h1>
    <ul>
    <details>
        <summary><a href="#introdução-aos-inteiros">Introdução aos inteiros</a></summary>
        <ul class="section-content">
            <li><a href="#contextualização" >Contextualização</a></li>
            <li><a href="#ue-questões"> Ue, questões..? </a></li>
            <li><a href="#definição-dos-números"> Definição dos... Números? </a></li>
            <summary><a href="#definição-dos-naturais">Definição dos Naturais</a>
            </summary>
            <ul class="section-content">
              <li><a href="#os-axiomas-de-peano"> Os Axiomas de Peano </a></li>
              <li><a href="#ordinais-de-john-von-neumann"> Ordinais de John von Neumann </a></li>
            </ul>
            <li><a href="#definição-dos-inteiros">Definição dos Inteiros</a></li>
        </ul>
    </details>
    <details>
        <summary><a href="#divisibilidade-e-primos">Divisibilidade e Primos</a></summary>
        <ul class="section-content">
            <li><a href="#relação-de-divisibilidade-e-o-teorema-da-divisão">Relação de Divisibilidade e o Teorema da Divisão</a></li>
            <details>
            <summary><a href="#teorema-fundamental-da-aritmética">Teorema Fundamental da Aritmética</a></summary>
            <ul class="section-content">
              <li><a href="#qualquer-número-é-primo-ou-composto-por-uma-fatoração-de-primos">Qualquer número é primo, ou composto por uma fatoração de primos</a></li>
              <li><a href="#a-fatoração-acima-é-única">A Fatoração acima é Única</a></li>
              <li><a href="#juntando-as-peças">Juntando as peças</a></li>
              </ul>
            </details>
            <details>
            <summary><a href="#múltiplos-e-divisores-comuns">Múltiplos e Divisores comuns</a></summary>
            <ul class="section-content">
              <li><a href="#mmc">MMC</a></li>
              <li><a href="#mdc">MDC</a></li>
              <li><a href="#algoritmo-de-euclides-e-o-teorema-de-bezout">Algoritmo de Euclides e o Teorema de Bezout</a></li>
            </ul></details>
        </ul>
    </details>
    <details>
        <summary><a href="#relações-de-congruência">Relações de Congruência</a></summary>
        <ul class="section-content">
            <li><a href="#conceitualização">Conceitualização</a></li>
            <li><a href="#relações-de-congruência-na-programação">Relações de congruência na programação</a></li>
            <li><a href="#aplicações-e-definição-formal">Aplicações e definição formal</a></li>
            <summary><a href="#propriedades">Propriedades</a></summary>
            <ul class="section-content">
              <li><a href="#propriedades-relacionais">Propriedades Relacionais</a></li>
              <li><a href="#propriedades-operacionais">Propriedades Operacionais</a></li>
            </ul>
            <summary><a href="#congruência-linear-e-inversos-modulares">Congruência Linear e Inversos Modulares </a></summary>
            <ul class="section-content">
            <li><a href="#como-encontrar-um-inverso-modular"> Como encontrar um Inverso Modular</a></li>
            </ul>
        </ul>
    </details>
    <details>
  <summary><a href="#criptografia">Criptografia</a></summary>
    <ul class="section-content">
        <li><a href="#contextualização-histórica">Contextualização histórica</a></li>
        <li><a href="#criptografia-assimétrica">Criptografia Assimétrica</a></li>
        <li><a href="#criptografia-rsa">Criptografia RSA </a></li>
    </ul>
  </details>
</ul>

  <button class="toggle-button" id="toggle-button">
  
      Esconder Sumário
  
  </button>
  
  </div>

###

## O que são Tipos Abstratos de Dados (TADs)?

## O que são Estruturas de Dados?

## Tipos lineares de dados!

<!-- list, queue, stack-->

### Array

<!-- mostrar as diferenças da implementação-->

### Vector

<!-- + implementação -->

### Lista Encadeada

<!-- implementationrrr-->


## Tipos abstratos de dados e suas implementações

### Lista

#### implementação

<!-- atrvés de arrays -->

<!-- Questão conjunta -->


### Fila

#### implementação:

<!-- através de arrays com ponteiros e afins -->

<!-- Questão conjunta -->

### Pilha

#### Implementação:

<!-- da mesma forma -->

<!-- Questão conjunta -->

## Iterando através de estruturas de dados diferentes

## Resolução de questões

<!-- vjudge!! -->











<script>
const dataDia3 = new Date('2025-03-12');
const agora = new Date();

if (agora < dataDia3) {
    document.body.innerHTML = '<h1 style="text-align:center; margin-top:20%;">Página Indisponível</h1>' +
                              '<p style="text-align:center;">Esta página estará disponível a partir de ' + dataDia3.toLocaleDateString() + '.</p>';
}
</script>
{% include petcccopyright.html %}
