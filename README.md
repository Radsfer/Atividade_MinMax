# Atividade MinMax
Atividade proposta para a matéria de AEDS presente no Curso de Graduação de Engenharia da Computação no ministrada na instiuição CEFET-MG campus Divinópolis.
## Proposta
A ideia da atividade é comparar e analisar 3 algoritmos de busca diferentes, a propostas dos algoritmos é a de encontrar o maior e o menor valor.
Para comparação foi pré definido os ranges de números (0-1000) para busca e as entradas de 1000, 10000, 100000 e 500000 que irão ser preenchidas de forma ordenada
e aleatória.
## Código
Os algoritmos de busca já haviam sido passados em sala de aula, então foi necessário fazer apenas a adaptação de Pascal para C++ e alguma alterações para guardar os dados presentes de forma visualmente agradável e para o procedimento de realização do teste.
### Para o teste
Para o teste foram preparadas funções simples que geram os vetores necessários para a entrada. Ressalto apenas na main:
```cpp
    srand(time(nullptr));
    std::vector<int> tamanhos = {1000,10000,100000,500000};
   
    for(int n=0;n<tamanhos.size();n++)
    {
    RandomVector test1 =RandomVector(tamanhos[n]);
    RandomVector test2 =RandomVector(tamanhos[n]);
    std::vector <int> vec1Ordered= test1.GenerateOrderedVector();
    std::vector<int> vec2Desordered = test2.GenerateDisorderedVector();

    for(int i=0;i<10;i++)
    {
        test1.FindMinMax1(vec1Ordered);
        test1.setOrderedDurantions(test1.getDurations());
    }
    test1.calculateMeanDurantions();
    test1.saveDurantions("datasets/algOrdenado/tempoAlg1_Ordenado.txt", 1);
    test1.saveInMatrix();
    test1.clearTest();
```
Esse trecho serve como exemplo do procedimento de operação, onde como foi pedido em documentação para que o tempo de cada algoritmo fosse medido 10 vezes (por isso o loop for) e para a questão do tamanho das entradas foi feito um loop que itera sobre o vetor que guarda o tamanho das entradas a serem geradas pelas funções de entradas ordenadas e desordenadas. Sendo test1 o objeto separado para a as entradas ordenadas e test2 para as entradas desordenadas. Ao final de cada teste a média simples é calculada, as durações são salvas em um arquivo formatado para fácil compreensão dos dados e em seguida salvo dentro de uma matriz e por fim o teste é limpo se referindo a limpeza dos vetores presentes no objeto.
```cpp
    test1.saveDurantionsMatrix("datasets/Matrix_Dados/Ordenado_", tamanhos[n]);
    test2.saveDurantionsMatrix("datasets/Matrix_Dados/Desordenado_", tamanhos[n]);
    test1.clearMatrixTest();
    test2.clearMatrixTest();
```
Ao final do código a matriz é guardada em um arquivo de texto separada apenas pelo tamanho de sua entrada para facilitar sua compreesão no script do GNUPlot utilizado para gerar os gráficos da análise.
Quanto ao restante do código como a ideia é avaliar os casos gerados pelos algoritmos de busca em relação ao tempo não irei entrar em mais detalhes. Porém caso exista a curiosidade sobre o funcionamento da geração dos vetores, da forma como os dados estão sendo salvos, ou outra dúvida qualquer, envie a pergunta para o email disponibilizado ao final do documento na parte de [Sobre](#sobre). 
### Scripts e compilação
Foram feitos scripts para geração de gráficos além do script Cmake padrão.
Então para a compilação fica recomendado a seguinte ordem de execução:
```bashrc
make clean
make
make run
make plotgraph
```
<font size=3.0 ><b>AVISO: Antes de realizar o comando make plotgraph caso deseja guardar as imagens para realizar o teste em diferente momentos faça um backup das últimas imagens geradas pois o GNU Plot sobreescreve as imagens ao gerar o comando com os dados novos, e as matrizes bases desses gráficos são sobreescritas a cada execução do código</b></font>
## Resultados e discuções
A análise atual ocorreu nos dados presentes no momento da escrita dessa documentação, caso faça nova execução do programa os dados podem alterar. Todos os análisados estão presentes no momento estão matidos no ultimo deploy feito para este repositório nas pastas dentro de datasets e na pasta imgs em relação aos gráficos.
### Gráficos
Os gráficos a seguir foram plotados com base no número de iterações gerado em cada teste e foram separados por quantitadade de entradas para avaliar o tempo médio de execução de cada algoritmo ao longo de 10 iterações, sendo x para iterações. 
#### <a name="#graph1"></a> Gráfico 1 - 1000 entradas.
![comparsion_alg1000](imgs/algorithms1000_comparison.png)
#### <a name="#graph2"></a> Gráfico 2 - 10000 entradas.
![comparsion_alg10000](imgs/algorithms10000_comparison.png)
#### <a name="#graph3"></a> Gráfico 3 - 100000 entradas.
![comparsion_alg100000](imgs/algorithms100000_comparison.png)
#### <a name="#graph4"></a> Gráfico 4 - 500000 entradas.
![comparsion_alg500000](imgs/algorithms500000_comparison.png)
### Tabelas
As tabelas a seguir fazem relação ao tempo médio de cada algoritmo.
#### <a name="#table1"></a> Tabela 1 - Tempo médio dos algoritmos em relação ao tamanho das entradas (Caso Ordenado).

| Tamanho da Entrada | Algoritmo 1 | Algoritmo 2 | Algoritmo 3 |
|--------------------|-------------|-------------|-------------|
| 1000               | 0.0053501 ns| 0.0038226 ns| 0.0040700 ns|
| 10000              | 0.0389838 ns| 0.0375332 ns| 0.0336906 ns|
| 100000             | 0.3829390 ns| 0.4210860 ns| 0.3322550 ns|
| 500000             | 2.0246200 ns| 1.9778600 ns| 1.7052000 ns|

#### <a name="#table2"></a> Tabela 2 - Tempo médio dos algoritmos em relação ao tamanho das entradas (Caso Desordenado).
| Tamanho da Entrada | Algoritmo 1 | Algoritmo 2 | Algoritmo 3 |
|--------------------|-------------|-------------|-------------|
| 1000               | 0.0038919 ns| 0.0038910 ns| 0.0048792 ns|
| 10000              | 0.0374691 ns| 0.0375730 ns| 0.0574034 ns|
| 100000             | 0.3842250 ns| 0.3783530 ns| 0.6463610 ns|
| 500000             | 1.9365100 ns| 1.9361500 ns| 3.0331800 ns|

### Análise dos dados
Para análisamor os dados é de grande imporatancia analisar o comportamento de cada algoritmo.
#### <a name="#table3"></a> Tabela 3 - Notação assintótica de cada algoritmo.
| Algoritmos  | Melhor caso | Pior caso | Caso médio  |
|-------------|-------------|-----------|-------------|
| Algoritmo 1 |    2(n-1)   |  2(n-1)   |   2(n-1)    |
| Algoritmo 2 |    n-1      |  2(n-1)   |   3n/2 - 3/2|
| Algoritmo 3 |    3n/2 - 2 |  3n/2 - 2 |   3n/2 - 2  |

Como pode ser observado o algoritmo 3 supostamente era para apresentar um comportamento padrão idependente do caso. Mas além de instabilidades geradas pelo Sistema Operacional durante os testes, oque provavelmente aconteceu durante os testes pois ao analisar os gráficos pode-se observar que a instabilidade também com os algoritmos 1 e 2, pode ser visto uma diferença do dobro entre os casos Ordenado e Desordenado e por ser um algoritmo de classe Θ(n) era para essa diferença ocorrer pela quantidade de entradas de forma linear e não pela sua ordenação. A suposição até o momento para explicar essa diferença fica no fato das complicações geradas pelo padrão de acesso a memória, talvez pela forma como o vetor gerado pela biblioteca  vector funciona pode haver algumas complicações a respeito do comportamento cache. Afinal ele é, dos três algoritmos, o único que avalia 2 posições de memória do vetor simultaneamente.
Quanto ao algoritmo 2 pode-se observar que mesmo em seu caso desordenado ele acabou por cair no melhor caso possível, provavelmente o vetor gerado aleatóriamente apresentou um padrão próximo ao ideal da situação. E o algoritmo 1 apresentou um comportamento esperado.

## Conclusão

Apesar das notações assintóticas serem um bom parâmetro para a questão de eficiência de um algoritmo, como pode ser visto, a depender de como é feito o acesso a memória, o tempo de execução de um algoritmo pode variar muito. E diferentes processos acontecem simultâneamente dentro de um SO podem também afetar o tempo de execução de um algoritmo.


## <a name="#sobre"></a>Sobre
Rafael Adolfo Silva Ferreira

Formação: Engenharia Química (2017-2022) -UNIFOR-MG

Cursando 3ºp. Engenharia da Computação - CEFET-MG campus Divinópolis

email: rafael.ferreira11.98@gmail.com
