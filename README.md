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
## Análise dos dados
A análise atual ocorreu nos dados presentes no momento da escrita dessa documentação, caso faça nova execução do programa os dados podem alterar. Todos os análisados estão presentes no momento estão matidos no ultimo deploy feito para este repositório nas pastas dentro de datasets e na pasta imgs em relação aos gráficos.
### Gráficos
!(comparsion_alg1000)[imgs/algorithms1000_comparison.png]
!(comparsion_alg10000)[imgs/algorithms10000_comparison.png]
!(comparsion_alg100000)[imgs/algorithms100000_comparison.png]
!(comparsion_alg500000)[imgs/algorithms500000_comparison.png]
## <a name="#sobre"></a>Sobre
