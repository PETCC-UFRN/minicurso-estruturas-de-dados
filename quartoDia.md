---
layout: layoutGit
title: Minicurso de Matemática aplicada à Computação
---

<div id="sumario" class="sumario-git">
    <h1>Dia 4</h1>
    <details>
        <summary><a href="#teoria-dos-conjuntos">Teoria dos Conjuntos</a></summary>
        <ul>
            <li><a href="#conjuntos">Conjuntos</a>
              <ul> 
                  <li><a href='#"interface"-dos-conjuntos'>"Interface" dos conjuntos</a></li>
                  <li><a href='#definindo-um-conjunto'>Definindo um conjunto</a></li>
                  <li><a href='#conjunto-vazio'>Conjunto Vazio</a></li>
                  <li><a href='#conjunto-universo'>Conjunto Universo</a></li>
                  <li><a href='#paradoxo-de-russell'>Paradoxo de Russell</a></li>
              </ul>
            </li>
            <li><a href="#operações-de-conjuntos">Operações de Conjuntos</a>
              <ul> 
                  <li><a href='#união'>União</a></li>
                  <li><a href='#interseção'>Interseção</a></li>
                  <li><a href='#diferença'>Diferença</a></li>
                  <li><a href='#complemento'>Complementoo</a></li>
              </ul>
            </li>
            <li><a href="#relações-entre-conjuntos">Relações entre Conjuntos</a>
              <ul> 
                  <li><a href='#contém-e-contido'>Contém e Contido</a></li>
                  <li><a href='#igualdade'>Igualdade</a></li>
              </ul>
            </li>
            <li><a href="#demonstrações-sobre-conjuntos">Demonstrações sobre Conjuntos</a></li>
        </ul>
    </details>
    <details>
        <summary><a href="#conjuntos-e-programação">Conjuntos e Programação</a></summary>
        <ul>
            <li><a href="#tipos-x-objetos-x-conjuntos/sets">Tipos ⨯ Objetos ⨯ Conjuntos/Sets</a></li>
            <li><a href="#conjuntos-como-inspiração-para-a-montagem-da-lógica-de-tipos">Conjuntos como inspiração para a montagem da lógica de tipos</a></li>
            <li><a href="#sets-como-coleções-de-coisas">Sets como coleções de coisas</a>
                <ul>
                    <li><a href="#especificacao/tipo-abstrato-de-dados">Especificação/Tipo Abstrato de Dados</a></li>
                    <li><a href="#implementacao">Implementação</a></li>
                </ul>
            </li>
            <li><a href="#tipos-de-coleções-semelhantes">Tipos de coleções semelhantes</a></li>
            <li><a href="#especificação-elementar-dos-sets">Especificação elementar dos Sets</a></li>
            <li><a href="#ocasiões-em-que-sets-podem-aparecer">Ocasiões em que Sets podem aparecer</a></li>
        </ul>
    </details>
    <details>
        <summary><a href="#funções-na-matemática-vs-funções-na-programação">Funções na Matemática vs funções na programação</a></summary>
        <ul>
            <li><a href="#o-que-são-funções">O que são funções?</a></li>
                <ul>
                    <li><a href="#pontos-em-comum">Pontos em comum</a></li>
                </ul>
            <li><a href="#aplicação-de-funções-matemáticas-na-programação">Aplicação de funções matemáticas na programação</a></li>
        </ul>
    </details>
  <button class="toggle-button" id="toggle-button">
  
      Esconder Sumário
  
  </button>
</div>

# Introdução a Árvores Binárias

## Definição 

Árvores são estruturas de dados **não lineares**, ou seja, seus elementos não estão armazenados de forma sequencial e não seguem uma única cadeia de encadeamento, como ocorre em listas ou vetores.

**Exemplos:**

Uma árvore binária é formada por um número finito de elementos, chamados de **nós**.

- O primeiro nó da árvore é denominado **raiz**.

- A partir da raiz, os nós se ramificam.

- Os nós que não possuem filhos são chamados de **folhas**.

Cada nó de uma árvore binária pode possuir nenhum ou **no máximo dois filhos**:

- um filho à **esquerda**.

- um filho à **direita**.

Sendo assim, quando não está vazia, ela pode ser dividida em três **subconjuntos disjuntos**:
	1. **Nó raiz**.
    2. **Sub-árvore esquerda**.
    3. **Sub-árvore direita**.
    
**Exemplo:**

## Propiedades 

A árvore binária possui as seguintes **propriedades principais**:

1. Todos os nós de uma sub-ávore **direita** são **maiores** que o valor do nó raiz.

2. Todos os nós de uma sub-ávore **esquerda** são **menores** que o valor do nó raiz 

3. Cada sub-árvore é, por si mesma, uma árvore binária. Isso torna a **estrutura recursiva**, em que cada nó pode ser considerado a raiz de uma nova árvore binária.

Essa organização permite operações eficientes de **busca** e **inserção**, com garantia de que a árvore estará estruturada de forma **hieráquica** e **balanceada**.

## Balanceamento 
## Estrutura
## Operações
