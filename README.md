# Sistema de Reserva de Poltronas

Este é um sistema simples de reserva de poltronas em um ambiente simulado, escrito em C++. O programa permite que os usuários reservem assentos em duas categorias: Executiva e Econômica. O status de cada assento é exibido em um quadro colorido, com assentos disponíveis marcados em azul e assentos reservados em vermelho.

## Funcionalidades

- Reservar poltronas em duas categorias (Executiva e Econômica).
- Visualizar o quadro de poltronas, onde assentos disponíveis são exibidos em azul e assentos reservados são exibidos em vermelho.
- Tratamento de entradas inválidas para garantir uma boa experiência do usuário.
- Possibilidade de fazer múltiplas reservas até que o usuário decida sair do programa.

## Requisitos

- Um compilador C++ (como `g++`) instalado em seu sistema.
- Sistema operacional compatível com ANSI escape codes para colorização (a maioria dos sistemas UNIX e Linux).

## Compilação e Execução

Para compilar e executar o programa, siga os passos abaixo:

1. **Clone o repositório:**
   ```bash
   git clone https://github.com/DevRarosh/Projeto-Sistema-Aereo-Reserva
   ```

2. **Compile o programa:**
   ```bash
   g++ -o sistema_reserva SistemaAereoReserva.cpp
   ```

3. **Execute o programa:**
   ```bash
   ./sistema_reserva
   ```

## Como Usar

1. Ao iniciar o programa, você verá um menu com três opções:
   - **[1] Reservar poltrona:** Para reservar um assento.
   - **[2] Mostrar quadro de poltronas:** Para visualizar a disponibilidade das poltronas.
   - **[3] Sair:** Para encerrar o programa.

2. Siga as instruções na tela para reservar um assento. O programa solicitará a categoria de reserva e a poltrona desejada.

3. O quadro de poltronas será atualizado conforme você faz reservas.

## Contribuições

Contribuições são bem-vindas! Sinta-se à vontade para abrir um *issue* ou enviar um *pull request*.

## Licença

Este projeto é licenciado sob a MIT License - veja o arquivo [LICENSE](LICENSE) para mais detalhes.

## Autor

[Ramon Brito](https://github.com/DevRarosh)
