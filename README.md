# Projeto IoT - Monitoramento Inteligente de Estufa

## 📝 Descrição do Projeto
[cite_start]Projeto desenvolvido para simular o monitoramento em tempo real de uma estufa agrícola, captando informações do ambiente interno e comparando com o clima externo.

## [cite_start]🏗️ Arquitetura da Solução [cite: 44]
1. [cite_start]**Coleta**: ESP32 coleta dados de Temperatura (DHT11) e Luminosidade (LDR)[cite: 8, 9, 10, 11].
2. [cite_start]**Transmissão**: O ESP32 envia as informações via MQTT para o broker público HiveMQ.
3. [cite_start]**Processamento**: O Node-RED consome os tópicos MQTT  [cite_start]e consome a API externa do OpenWeather.
4. [cite_start]**Armazenamento**: Os dados de temperatura são persistidos em um banco de dados MySQL local.
5. [cite_start]**Visualização**: Um dashboard em tempo real exibe os sensores e os dados climáticos[cite: 21, 29, 30].

## [cite_start]💻 Tecnologias Utilizadas [cite: 45]
* [cite_start]Hardware: Microcontrolador ESP32, Sensor DHT11, Sensor LDR[cite: 8, 9, 10, 11].
* [cite_start]Comunicação: Protocolo MQTT, Wi-Fi[cite: 15].
* [cite_start]Software/Plataformas: C++ (Arduino IDE), Node-RED, MySQL[cite: 18, 22].
* [cite_start]API Externa: OpenWeatherMap.

## [cite_start]🚀 Instruções de Execução [cite: 46]
1. Monte o circuito conectando o DHT11 no pino 4 e o LDR no pino 34 do ESP32.
2. Altere as credenciais de Wi-Fi no código `esp32_code.ino` e faça o upload para a placa.
3. Crie o banco de dados MySQL utilizando o arquivo `database.sql`.
4. Importe o arquivo `flow.json` no seu Node-RED.
5. No Node-RED, configure as credenciais do seu banco MySQL e insira sua chave da API OpenWeather.
6. [cite_start]Clique em *Deploy* e acesse `http://localhost:1880/ui` para ver o dashboard[cite: 28, 30].

## 🎥 Vídeo Demonstrativo
[Link para o vídeo no YouTube]
