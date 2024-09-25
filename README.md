Documentação do Código de Controle de Semáforo
Descrição
Este código controla um sistema de semáforo que gerencia o fluxo de veículos e pedestres, utilizando LEDs para representar diferentes estados de sinalização. O sistema também inclui um sensor ultrassônico para detectar a proximidade de veículos, ajustando o tempo dos semáforos conforme necessário.

Componentes Utilizados
LEDs:
Veículos:
LED Verde: ledGreenCar (pino 8)
LED Amarelo: ledYellowCar (pino 10)
LED Vermelho: ledRedCar (pino 12)
Pedestres:
LED Verde: ledGreenPed (pino 6)
LED Vermelho: ledRedPed (pino 4)
Sensor Ultrassônico:
Echo: sensorEcho (pino 9)
Trig: sensorTrig (pino 7)
Variáveis
unsigned long tempo: armazena o tempo atual em milissegundos.
long distancia: armazena a distância medida pelo sensor ultrassônico.
Funções
void setup()
Configura os pinos utilizados e inicializa os LEDs. Define o LED verde do carro como ativo e o LED vermelho do pedestre como ativo ao início.

void loop()
A função principal que é executada repetidamente. Ela verifica a distância medida pelo sensor ultrassônico e controla a lógica do semáforo.

Medida de Distância: Chama a função calculaDistancia() para obter a distância atual.
Controle do Semáforo:
Se 5 segundos se passaram ou a distância for menor que 50 cm, altera os LEDs de acordo com as seguintes regras:
Se a distância for menor que 50 cm, o semáforo de veículos muda para amarelo, em seguida, para vermelho, enquanto o semáforo de pedestres muda para verde.
O semáforo para pedestres permanece verde por 15 segundos.
Após esse tempo, o semáforo de pedestres volta a vermelho, e o semáforo de veículos volta a verde.
Atualiza o tempo: A variável tempo é atualizada para o tempo atual em milissegundos.
long calculaDistancia()
Calcula a distância medida pelo sensor ultrassônico:

Emite um pulso de 10 microsegundos pelo pino sensorTrig.
Mede o tempo que o pulso leva para retornar ao pino sensorEcho.
Calcula a distância com base na fórmula: distancia = duracao * 0.034 / 2, onde 0.034 é a velocidade do som em cm/μs.
Funcionamento do Sistema
Início: Ao iniciar, o semáforo de veículos fica verde e o semáforo de pedestres fica vermelho.
Detecção de Veículos: O sensor ultrassônico mede a distância. Se um veículo se aproximar a menos de 50 cm ou se o tempo de 5 segundos se passar, o semáforo muda.
Sinalização:
Verde para Amarelo: O semáforo de veículos muda para amarelo por 2 segundos.
Amarelo para Vermelho: O semáforo de veículos muda para vermelho, e o semáforo de pedestres muda para verde por 15 segundos.
Volta ao Normal: Após 15 segundos, o semáforo de pedestres muda para vermelho e o de veículos volta a verde.
