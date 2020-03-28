
# arduino-contador-flexoes-tfm
 
Circuito simples para contar flexões de braço utilizando sensor ultrassônico HC-SR04 numa placa Arduino Uno, com display indicando contagem e LEDS coloridos para o "Abaixo e Acima" dos treinamentos físico militar. Chega de dar o golpe antigão.

### Demonstração prática (vídeo)
<p>
 <a target="_blank" rel="noopener noreferrer" href="https://youtu.be/gDvG_-5g_NA" target="_blank">
  <img src="https://user-images.githubusercontent.com/22710963/77812602-26aa2b80-7081-11ea-8fb7-447110661b62.png" alt="reset" style="max-width:100%;"></a>
</p> 

 ### Circuito
<p>
 <a target="_blank" rel="noopener noreferrer" href="https://user-images.githubusercontent.com/22710963/77810018-15592300-7071-11ea-8ccc-fbe44381f708.png">
  <img src="https://user-images.githubusercontent.com/22710963/77810018-15592300-7071-11ea-8ccc-fbe44381f708.png" alt="reset" style="max-width:100%;"></a>
</p>  
   
## Hardware necessário
```
- a) 1 Placa Arduino com cabo USB
- b) 1 Sensor ultrassônico HC-SR04 
- c) 1 Display LCD 16X2 
- d) 1 Potenciometro Linear 500k  
- e) 1 Buzzer DR-08H
- f) 1 Botão do tipo push
- g) 2 LEDS de 4mm 1 de cada cor
- h) 2 Resistores de 220 - 300Ω 
- i) 1 Protoboard
- j) 25-30 Cabos de conexão   
```

 ### a) Placa Arduino Uno 
 
<p><a target="_blank" rel="noopener noreferrer" href="https://user-images.githubusercontent.com/22710963/77551422-16cbf500-6e91-11ea-850d-7e3989c9f1f2.png">
  <img src="https://user-images.githubusercontent.com/22710963/77551422-16cbf500-6e91-11ea-850d-7e3989c9f1f2.png" alt="reset" style="max-width:100%;"></a></p> 

  ### b) Sensor ultrassônico HC-SR04 
  Emite som e verifica o eco do retorno, assim faz a aferição da distância.
<p><a target="_blank" rel="noopener noreferrer" href="https://user-images.githubusercontent.com/22710963/76180933-37603380-619e-11ea-9ff6-56c12c26a39b.png">
  <img src="https://user-images.githubusercontent.com/22710963/76180933-37603380-619e-11ea-9ff6-56c12c26a39b.png" alt="reset" style="max-width:100%;"></a></p> 

 ### c) Display LCD 16X2 
  
  Atenção os pinos devem estar soldados no display senão não funciona.
 
<p><a target="_blank" rel="noopener noreferrer" href="https://user-images.githubusercontent.com/22710963/77712613-0d3aae00-6fb3-11ea-892b-0d5e8753b394.png">
  <img src="https://user-images.githubusercontent.com/22710963/77712613-0d3aae00-6fb3-11ea-892b-0d5e8753b394.png" alt="reset" style="max-width:100%;"></a></p>

### d) Potenciometro Linear 500k
  <p><a target="_blank" rel="noopener noreferrer" href="https://user-images.githubusercontent.com/22710963/77713295-c1890400-6fb4-11ea-87e0-9f36d23c9042.png">
  <img src="https://user-images.githubusercontent.com/22710963/77713295-c1890400-6fb4-11ea-87e0-9f36d23c9042.png" alt="reset" style="max-width:100%;"></a></p> 
   
 ### e) Buzzer DR-08H
  <p><a target="_blank" rel="noopener noreferrer" href="https://user-images.githubusercontent.com/22710963/77565026-62d36580-6ea2-11ea-9a5e-389752b9158f.png">
  <img src="https://user-images.githubusercontent.com/22710963/77565026-62d36580-6ea2-11ea-9a5e-389752b9158f.png" alt="reset" style="max-width:100%;"></a></p> 
  
  ### f) Botão do tipo push
<p><a target="_blank" rel="noopener noreferrer" href="https://user-images.githubusercontent.com/22710963/77810160-d24b7f80-7071-11ea-9371-8eb08853b890.png">
  <img src="https://user-images.githubusercontent.com/22710963/77810160-d24b7f80-7071-11ea-9371-8eb08853b890.png" alt="reset" style="max-width:100%;"></a></p>     
   
 ### g) LEDS comuns de 4mm
<p><a target="_blank" rel="noopener noreferrer" href="https://user-images.githubusercontent.com/22710963/77499523-14d24980-6e31-11ea-9ee1-2f44635a20be.png">
  <img src="https://user-images.githubusercontent.com/22710963/77499523-14d24980-6e31-11ea-9ee1-2f44635a20be.png" alt="reset" style="max-width:100%;"></a></p> 

 ### h) Resistores  
 <p><a target="_blank" rel="noopener noreferrer" href="https://user-images.githubusercontent.com/22710963/76045740-c0783000-5f3c-11ea-9188-3b239840fbda.png">
  <img src="https://user-images.githubusercontent.com/22710963/76045740-c0783000-5f3c-11ea-9188-3b239840fbda.png" alt="reset" style="max-width:100%;"></a></p> 
  
  ### i) Protoboard 
<p><a target="_blank" rel="noopener noreferrer" href="https://user-images.githubusercontent.com/22710963/77499362-a8574a80-6e30-11ea-9744-a15c3206fd50.png">
  <img src="https://user-images.githubusercontent.com/22710963/77499362-a8574a80-6e30-11ea-9744-a15c3206fd50.png" alt="reset" style="max-width:100%;"></a></p> 

  ### j) Cabos de conexão
<p><a target="_blank" rel="noopener noreferrer" href="https://user-images.githubusercontent.com/22710963/77499606-5662f480-6e31-11ea-96fd-9e268dceb50f.png">
  <img src="https://user-images.githubusercontent.com/22710963/77499606-5662f480-6e31-11ea-96fd-9e268dceb50f.png" alt="reset" style="max-width:100%;"></a></p> 


### Configuração:

Para ajustar distância para contar abaixo e acima altere as váriaveis abaixo:

```

// variáveis limites de altura da distância
int dist_abaixo_cm = 5;
int dist_acima_cm = 25;


```

Orientações sobre o uso:

- Contagem começa no alto na luz verde.

- Posicione o sensor na altura do pescoço.

- Não permita que a pessoa esteja com corrente ou adereço solto, com cabelo longo solto, camisa folgada que possa interferir no sinal entre o sensor com a pessoa (mais ou menos na altura do pescoço).

- Após encerrada uma sessão pode-se zerar o contador clicando no botão.


### Links úteis

- [IDE Arduino](https://www.arduino.cc/en/Main/Software)
 
- [Documentação sintaxe C++](https://www.arduino.cc/reference/en/)

- [Fritzing](https://fritzing.org/home/) - Licença comercial

- [Fritzing](https://softfamous.com/fritzing/download/) - Versão gratuita (antiga mas permite que seja atualizada)

- [TinkerCad](https://www.tinkercad.com) - Ambiente Virtual p/ prototipagem
 
- [Project Hub](https://create.arduino.cc/projecthub/mixpose/pushup-counter-e3ed69?ref=platform&ref_id=424_trending___&offset=46)
 
 
###  Aplicações
 
 - Contador de flexões de braço para testes de aptidão física
   
  
 

