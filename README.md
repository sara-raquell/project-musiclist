**🎵 MusicList – Sistema de Cadastro de Músicas em C**
----------------------------------------------------------------------
📌 Descrição do Projeto
----------------------------------------------------------------------

O MusicList é um sistema simples desenvolvido em linguagem C, executado no terminal, que permite o gerenciamento de uma lista de músicas.
Com ele, é possível cadastrar, listar, buscar, alterar e remover músicas, simulando um pequeno banco de dados em memória.

O projeto tem fins acadêmicos, sendo ideal para praticar:

Estruturas (struct)

Vetores

Funções

Manipulação de strings

Controle de fluxo

Menus interativos no terminal

**⚙️ Funcionalidades**
----------------------------------------------------------------------

O sistema oferece as seguintes opções no menu principal:

**1️⃣ Cadastro de músicas**
----------------------------------------------------------------------

Permite cadastrar uma nova música informando:

Nome da música

Álbum

Cantor/Banda

Ano de lançamento

Avaliação (nota de 1 a 5)

Cada música recebe:

Um ID automático

Um status ativo, que indica se ela está disponível no sistema

É possível realizar vários cadastros seguidos sem retornar ao menu.


**2️⃣ Listar músicas cadastradas**
----------------------------------------------------------------------

Exibe todas as músicas ativas cadastradas no sistema, mostrando:

ID

Nome da música

Álbum

Cantor/Banda

Ano de lançamento

Avaliação

Caso não exista nenhuma música cadastrada, o sistema informa o usuário.

**3️⃣ Buscar músicas**
----------------------------------------------------------------------

Permite buscar músicas utilizando diferentes critérios:

🔎 Por ID

🔎 Por nome da música

🔎 Por álbum (lista todas as músicas daquele álbum)

🔎 Por cantor/banda (lista todas as músicas daquele artista)

Se nenhuma música for encontrada, o sistema exibe uma mensagem de erro.


**4️⃣ Alterar músicas**
----------------------------------------------------------------------

Permite alterar os dados de uma música existente, buscando-a pelo nome.

O usuário pode escolher alterar:

Nome da música

Álbum

Cantor/Banda

Ano de lançamento

Avaliação

Todos os campos de uma vez

Após a alteração, o sistema exibe os novos dados da música.


**5️⃣ Remover músicas**
----------------------------------------------------------------------

Remove uma música do sistema de forma lógica, ou seja:

A música não é apagada da memória

Apenas seu campo ativo é alterado para 0

Assim, músicas removidas não aparecem mais nas listagens e buscas.


**6️⃣ Sair do sistema**
----------------------------------------------------------------------

Antes de encerrar o programa, o sistema solicita uma confirmação, evitando o fechamento acidental.

**🧱 Estrutura do Código**

📄 Estrutura dados
---------------------------------------
struct dados {
    char musica[50];
    char album[50];
    char cantor[50];
    int ano, id, ativo;
    float avaliacao;
};
\

Essa estrutura armazena todas as informações de uma música.

📦 Armazenamento
----------------------------------------------------------------------

As músicas são armazenadas em um vetor global:

dados music[100];


Capacidade máxima: 100 músicas

Os dados ficam apenas em memória (não há persistência em arquivos)

🔧 Principais Funções
----------------------------------------------------------------------
Função	Descrição
cadastrar()	Cadastra uma nova música
listar()	Lista todas as músicas ativas
buscar()	Realiza buscas por ID, nome, álbum ou cantor
alterar()	Altera dados de uma música
remover()	Remove logicamente uma música
sair()	Confirma e encerra o programa
confimarcao()	Retorna ao menu ou encerra o sistema

**📚 Observações Importantes**
----------------------------------------------------------------------

O sistema não utiliza arquivos, portanto os dados são perdidos ao encerrar o programa.

A remoção é feita de forma lógica (ativo = 0).

O uso de gets() não é recomendado em projetos reais por questões de segurança.

O projeto é indicado para fins educacionais e aprendizado inicial em C.

**👩‍💻 Autoria**
----------------------------------------------------------------------

Projeto desenvolvido para fins acadêmicos, com foco em:

Programação estruturada

Manipulação de dados em C

Criação de menus interativos
