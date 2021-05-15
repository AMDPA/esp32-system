# ÀMDPA

## _Automação Agropecuária por meio de dispositivos em plataforma arduíno._

Seu principal objetivo é prosseguir com o projeto desenvolvido na XI Semana Nacional de Ciencia e Tecnologia realizada em 2019.

## Grupo de Trabalho

- Danilo Freitas Vieira
- Denis Mendes Souza
- Higor Freitas do Nascimento
- Luiz Felipe Vicente da Costa
- Pedro Henrique de Lima Vieira

## Cordenadores

- Carlos Alexandre Silqueira da Silva
- Creziel Franzoni Costa
  
## Recursos

- R$ 19.200,00

## Edital

- 09/2019 - FAPES

## Compreendendo

Esse repositório possue classes para manuseio dos seguintes módulos/sensores:

- MicroCard SD Adapter
- Umidade e Temperatura (DTH11)
- Sensor de Luminosidade (CJMCU-101)
- Umidade do Solo V2.0
- Detecção de pH (pH-4502c)
- Dióxido de Carbono (CCS881)
- Hidrogênio (MQ-8)
- Chuva (MH-RD)
- Temperatura (18B20)

Todas as classes seguem um mesmo padrão arquitetônico. Sendo:

```bash
Class.init();
```

para inicializar o módulo,

```bash
Class.update();
```

para atualizar os valores de medição e

```bash
Class.get...();
```

para obter os valores lidos.
Além disso, todas as classes possuem headers para indexar seus metodos e funções e cpp's onde são implementados a codificação.
Para se usar uma classe especifica, deve-se importa-la:

```bash
#include "classes/nomeClasse.h";
```

## Desenvolvendo

Para trabalhar em equipe através do GitHub é preciso algumas configurações:

### Ter o GitBash instalado

Instalação Linux:

- Distribuições RPM

```sh
sudo dnf install git-all
```

- Distribuições Debian

```sh
sudo apt install git-all
```

Instalação Windows:

- [32 bit](https://github.com/git-for-windows/git/releases/download/v2.30.1.windows.1/Git-2.30.1-32-bit.exe)
  
- [64 bit](https://github.com/git-for-windows/git/releases/download/v2.30.1.windows.1/Git-2.30.1-64-bit.exe)

### Ter Uma chave SSH associada a conta GitHub

- [Gerando uma chave SSH e adicionando ao SSH-agent](https://docs.github.com/pt/github/authenticating-to-github/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent)

- [Adicionando a chave SSH a conta GitHub](https://docs.github.com/pt/github/authenticating-to-github/adding-a-new-ssh-key-to-your-github-account)

### Ter o Visual Code Studio Instalado

Instalação Linux:

```sh
sudo snap install code --classic
```

Instalação Windows:

[Site oficial do VSCode](https://code.visualstudio.com/download)

### Possuir a Extenção PlatformIo para VSCode

[Marktetplace VSCode](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide)

Com todas as configurações concluidas, pode-se iniciar a contribuição mutua. Para isso:

### Clone o repositorio para sua máquina local

Na pasta como "Docs", por exemplo, execute o seguinte comando. Será criado uma pasta chamada amdpa com o codigo do projeto. Logo apos inicie o VSCode.

```sh
git clone git@github.com:lfvicent3/amdpa.git
```

### Iniciando o Projeto

No VSCode:

- Acesse a extensão do Platformio.

- Clique em Open Project e Selecione a pasta.

- Caso as extensões não sejam automaticamente instaladas, as instale.

### Comandos basicos para cooperação

Antes de modificar um arquivo, alterne para o braço de desenvolvimento:

```sh
git fetch
git checkout desenvolver
```

Ao modificar um arquivo, é importante informar as mudanças. Para isso, utilize:

```sh
git add <locadoarquivo>
git commit -m "Descreva a mudança"
```

Opcionalmente, você pode informar todas as mudanças de uma vez:

```sh
git add .
git commit -m "Descreva a mudança. Ela será aplicada a todos os arquivos modificados"
```

Ao utilizar git add e git commit , você está salvando em sua maquina local as atualizações. Para submeter ao servidor remoto, utilize:

```sh
git push origin desenvolver
```

### Sincronizando dados remotos

Antes de iniciar os trabalhos, é importante trazer as modificações feitas por outros contribuidores para sua máquina. Para isso:

```sh
git pull
```

Pode ocorrer conflitos e o Git não conseguir unir os dados automaticamente. Será preciso que você resolva os conflitos.

Ao fim do trabalho, sincronize com o Braço principal. Depois de analisada será submetida ao braço principal.

```sh
git merge origin/main
```

## Saiba mais

- [Git Docs](https://git-scm.com/book/en/v2/)

## Importante

- É preciso definir quem irá modificar cada parte do projeto para evitar eventuais conflitos.

- Apesar de não ser uma ferramenta de contribuição em tempo real. Git e GitHub permite que todas as alterações feitas sejam salvas, permitindo que todo o trabalho seja monitorado.

---

Escrito por [@lfvicent3](https://github.com/lfvicent3). Contato: [luiz.costa@rav.tec.br](mailto:luiz.costa@rav.tec.br)
