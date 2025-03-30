#include <iostream>
#include <fstream> // Para manipular strings no carregamento do arquivo
#include <sstream> // Para manipular strings no carregamento do arquivo
#include <cstdio> //Biblioteca padrão de C, precisei usar pois não tenho tanto costume com o C++
#include <cstdlib> //Biblioteca padrão de C, precisei usar pois não tenho tanto costume com o C++

#define MAX_CARROS 10 //Estamos definindo o MAX_CARROS e dizendo que ele vale 10, criamos uma constante

using namespace std;


struct Carro{
    string marca;
    string modelo;
    float valor;
    int ano;
    bool ar;
}; //Carro carros[10] --> Poderiamos criar a variável da struct direto nela, antes do ";"


Carro carros[10] = {}; //Podemos iniciar com as informações vazias, visto que o mesmo será preenchido pelo TXT

int qtdCarros=0;

void carregarCarros(){ //Uma função que não retorna nada, apenas executa uma função

    fstream arquivo ("carros.txt");

    if (!arquivo){
        cout << "Erro ao abrir o arquivo 'carros.txt'." << endl;
        return; //Podemos usar o return em void apenas para encerrar o código,
    }           //ele não retornará nenhum valor

    int x=0;
    while(x < MAX_CARROS){

        if (!(arquivo >> carros[x].marca >>
                         carros[x].modelo >>
                         carros[x].valor >>
                         carros[x].ano >>
                         carros[x].ar)) {

        //Os dados saem do arquivo e vão para o array
            break;
        }
        x++;

    }
    qtdCarros = x;
    arquivo.close();

}

void salvarCarros(){ //Vai descartar tudo dentro do arquivo e preencher dnv

    ofstream arquivo ("carros.txt");

    if (!arquivo){
        cout << "Erro ao abrir o arquivo 'carros.txt'." << endl;
        return;
    }

    for(int x=0; x < qtdCarros; x++){

              arquivo << carros[x].marca << " "
                      << carros[x].modelo << " "
                      << carros[x].valor << " "
                      << carros[x].ano << " "
                      << carros[x].ar << "\n";
    }
    arquivo.close();

}

void exibirCarro(int x){

    cout << "Marca: " << carros[x].marca << endl;
    cout << "Modelo: " << carros[x].modelo << endl;
    cout << "Valor: " << carros[x].valor << endl;
    cout << "Ano: " << carros[x].ano << endl;
    if (carros[x].ar == 1){
        cout << "Ar Condiconado: Sim" << endl;
    }else{
        cout << "Ar Condiconado: Nao" << endl;
    }
    cout << "--------------------------------------" << endl;

}

void exibirTodos(){

    for(int x=0; x < qtdCarros;  x++){
        exibirCarro(x);
    }
}

void inserirCarro(){ //Função para adicionar novos carros

    if (qtdCarros >= MAX_CARROS){ //Caso a quantidade máxima já tenha sido atingida
        cout << "Limite maximo de carros atingido.\n";
        cout << "\n--------------------------------------" << endl;
        return;
    }

    Carro novo;
    cout << "Marca: ";     cin >> novo.marca; //O "Cin" é como o "Scanf", preciso dele ao armazenar dados do usuário
    cout << "Modelo: ";     cin >> novo.modelo;
    cout << "Valor: ";     cin >> novo.valor;
    cout << "Ano: ";     cin >> novo.ano;
    cout << "Possui ar condicionado? (1 = Sim, 0 = Nao): "; cin >> novo.ar;
    cout << "\n--------------------------------------" << endl;

    carros[qtdCarros] = novo; //Estamos atualizando a quantidade dos carros
    qtdCarros++;

    salvarCarros(); //Usamos essa função já criada para salva-lo no TXT
    cout << "Carro adicionado com sucesso!\n";
}

int main(){
    cout << "---------- Lista de Carros ----------\n" << endl;
    carregarCarros();
    exibirTodos();
    cout << endl;
    cout << "**************************************" << endl;
    cout << "\n---------- Carro Escolhido ----------\n" << endl;
    exibirCarro(2); //Exibe o carro com base no indice que eu escolher
    cout << "\n**************************************" << endl;
    cout << "\n---------- Adicionar Carro ----------\n" << endl;
    inserirCarro();
    return 0; //Precisamos para indicar que ele teve sucesso, o "return 0" cumpre essa função
}

/*

--Salvamos as informações dos carros em um arquivo externo TXT pois é mais seguro salva-los na memória normal do PC.

--A memória RAM iria torna-los temporários, mas um dos problemas do TXT é que ele pode ser apagado ou modificado facilmente.

*/
