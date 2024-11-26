#include <PS4Controller.h>
#include <Arduino.h>
#include <CAN.h>
#include "tuushin.h"  // tuushin.hをインクルード


// setup関数: 初期設定を行う。CANバスの初期化と、送受信の設定を呼び出す
void setup() {
  
  Serial.begin(115200);  // シリアル通信開始
  PS4.begin("1c:69:20:e6:20:d2");//ここにアドレス
  Serial.println("Ready.");
  while (!Serial);  // シリアル接続待機

 const int CAN_TX_PIN = 27;  // 送信ピン（GPIO27）
const int CAN_RX_PIN = 26;  // 受信ピン（GPIO26）

  Serial.println("CAN Communication");

  CAN.setPins(CAN_RX_PIN, CAN_TX_PIN);

  // CANバスの初期化（通信速度500kbps）
  CAN.begin(500E3);

  // CANバスの初期化。500kbpsで動作を設定
  if (!CAN.begin(500E3)) {
    // CAN初期化に失敗した場合、エラーメッセージを表示して停止
    Serial.println("CANの初期化に失敗しました！");
    while (1);  // 永久ループで停止
  }

  // 受信と送信の初期化関数を呼び出し
  setupReceiver();
  setupSender();
  Serial.println("Start");
}

// loop関数: 受信と送信を繰り返す
void loop() {

  int PS4_Circle=0;
  int PS4_Triangle=0;
  int PS4_R1=0;
  int PS4_L1=0;
  
  //Serial.println("Start");
  // 受信処理を実行
  //receivePacket();
  if (PS4.isConnected()) {
    //if (PS4.Cross()) Serial.println("Cross Button");
    if (PS4.Circle()){
      Serial.println("Circle Button");
      PS4_Circle=1;
      Serial.printf("%d\n", PS4_Circle); 
    }
    if (PS4.Triangle()) {
      Serial.println("Triangle Button");
      PS4_Triangle=1;
      Serial.printf("%d\n", PS4_Triangle);
      };
    if (PS4.R1()){
      Serial.println("R1 Button");
      PS4_R1=1;
      Serial.printf("%d\n", PS4_R1);
      };
     if (PS4.L1()){
      Serial.println("L1 Button");
      PS4_L1=1;
      Serial.printf("%d\n", PS4_L1);
      };
  }

  // 送信処理を実行
  //sendPacket(PS4_Circle);
  sendPacket(PS4_Circle, PS4_Triangle, PS4_R1, PS4_L1);

  //delay(1000);  // 1秒の遅延
}

/*
int PS4_Circle=0;

void setup() {
  Serial.begin(115200);
  PS4.begin("1c:69:20:e6:20:d2");//ここにアドレス
  Serial.println("Ready.");
}

void loop() {
  // Below has all accessible outputs from the controller
  if (PS4.isConnected()) {

    if (PS4.Square()) {
      Serial.println("Square Button");
      
    }
    if (PS4.Cross()) Serial.println("Cross Button");
    if (PS4.Circle()){
      Serial.println("Circle Button");
      PS4_Circle=1;
      Serial.println("%d",PS4_Circle);
    }
    if (PS4.Triangle()) Serial.println("Triangle Button");

    if (PS4.Charging()) Serial.println("The controller is charging");
    if (PS4.Audio()) Serial.println("The controller has headphones attached");
    if (PS4.Mic()) Serial.println("The controller has a mic attached");

    Serial.printf("Battery Level : %d\n", PS4.Battery());

    
    
    Serial.println();
    // This delay is to make the output more human readable
    // Remove it when you're not trying to see the output
  }
  
//ここで

  
    delay(1000);
  
}*/
