#include <iostream>
#include <fstream> // Para manipular strings no carregamento do arquivo
#include <sstream> // Para manipular strings no carregamento do arquivo
#include <cstdio> //Biblioteca padr�o de C, precisei usar pois n�o tenho tanto costume com o C++
#include <cstdlib> //Biblioteca padr�o de C, precisei usar pois n�o tenho tanto costume com o C++

#define MAX_CARROS 10 //Estamos definindo o MAX_CARROS e dizendo que ele vale 10, criamos uma constante

using namespace std;


struct Carro{
    string marca;
    string modelo;
    float valor;
    int ano;
    bool ar;
}; //Carro carros[10] --> Poderiamos criar a vari�vel da struct direto nela, antes do ";"


Carro carros[10] = {}; //Podemos iniciar com as informa��es vazias, visto que o mesmo ser� preenchido pelo TXT

int qtdCarros=0;

void carregarCarros(){ //Uma fun��o que n�o retorna nada, apenas executa uma fun��o

    fstream arquivo ("carros.txt");

    if (!arquivo){
        cout << "Erro ao abrir o arquivo 'carros.txt'." << endl;
        return; //Podemos usar o return em void apenas para encerrar o c�digo,
    }           //ele n�o retornar� nenhum valor

    int x=0;
    while(x < MAX_CARROS){

        if (!(arquivo >> carros[x].marca >>
                         carros[x].modelo >>
                         carros[x].valor >>
                         carros[x].ano >>
                         carros[x].ar)) {

        //Os dados saem do arquivo e v�o para o array
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

void inserirCarro(){ //Fun��o para adicionar novos carros

    if (qtdCarros >= MAX_CARROS){ //Caso a quantidade m�xima j� tenha sido atingida
        cout << "Limite maximo de carros atingido.\n";
        cout << "\n--------------------------------------" << endl;
        return;
    }

    Carro novo;
    cout << "Marca: ";     cin >> novo.marca; //O "Cin" � como o "Scanf", preciso dele ao armazenar dados do usu�rio
    cout << "Modelo: ";     cin >> novo.modelo;
    cout << "Valor: ";     cin >> novo.valor;
    cout << "Ano: ";     cin >> novo.ano;
    cout << "Possui ar condicionado? (1 = Sim, 0 = Nao): "; cin >> novo.ar;
    cout << "\n--------------------------------------" << endl;

    carros[qtdCarros] = novo; //Estamos atualizando a quantidade dos carros
    qtdCarros++;

    salvarCarros(); //Usamos essa fun��o j� criada para salva-lo no TXT
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
    return 0; //Precisamos para indicar que ele teve sucesso, o "return 0" cumpre essa fun��o
}

/*

--Salvamos as informa��es dos carros em um arquivo externo TXT pois � mais seguro salva-los na mem�ria normal do PC.

--A mem�ria RAM iria torna-los tempor�rios, mas um dos problemas do TXT � que ele pode ser apagado ou modificado facilmente.

*/
