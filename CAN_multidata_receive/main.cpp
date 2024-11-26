//#include <PS4Controller.h>
#include <Arduino.h>
#include <CAN.h>
#include "tuushin.h"  // tuushin.hをインクルード
//CAN通信確立成功
//数字を読むことに成功

// setup関数: 初期設定を行う。CANバスの初期化と、送受信の設定を呼び出す
void setup() {
  
  Serial.begin(115200);  // シリアル通信開始
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
/*uint32_t receivedID;         // 受信IDを格納する変数
uint8_t receivedData[8]={0,0,0,0,0,0,0,0};     // 受信データを格納する配列
uint8_t receivedLength;      // 受信データの長さを格納する変数*/

uint32_t id;          // CAN IDを格納する変数
uint16_t data[8]={0,0,0,0,0,0,0,0};      // 受信データを格納する配列（最大8バイト）
uint16_t length=0;       // 受信データの長さを格納する変数
  
receivePacket(id, data, length);

  Serial.print("Received ID: ");
  Serial.println(id);  // 10進数で表示

  Serial.print("Received length ");
  Serial.println(length);  // 10進数で表示

  // CANメッセージを受信
    for (int i = 0; i < length; i++) {
      //Serial.print(data[i]);//⇒こっちで255って出てる
     // Serial.print("A");
    }
    //Serial.println();

    Serial.print(data[0]);
    Serial.print(data[1]);
    Serial.print(data[2]);
    Serial.print(data[3]);

    Serial.println();

    if(data[0]==0){
      //これでHIGHにする
      
      }

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
