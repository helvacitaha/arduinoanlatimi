#define potans A0 // Potansitometremizi bağladığımız analog pini belirliyoruz.
#define led1 8 //LEDlerimizi bağladığımız dijital pinleri belirliyoruz.
#define led2 7
#define led3 6
#define led4 5
#define led5 4
int deger; // Potansımızdan gelen değeri aktarmak için bir değişken oluşturduk.

void setup() {
  pinMode(potans,INPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT); // Giriş ve çıkış pinlermizi ayarladık.
  Serial.begin(9600); /* Seri monitörümüzü başlatıyoruz. Seri monitör, Arduino IDE'de sağ üstte büyütece benzer bir işareti olan butona tıklayınca açılır.
  * Genelde değer okumak, kalibrasyon yapmak için kullanılır. Biz burada potansımızdan gelen değeri okumak için kullanacağız.
  * Bu komutta parantez içindeki değer veri akışının hızını belirlememize yardımcı oluyor. Arduino 300, 600, 1200, 2400, 4800, 9600, 14400, 19200, 28800, 31250, 38400, 57600 ve 115200  
  baud değerlerini destekliyor. Biz burada ortalama ve yeterli bir değer olan 9600 ü seçiyoruz.  */
}

void loop() {
  deger=analogRead(potans); // "potans" pininden gelen değeri "deger" değişkenine yazdırıyoruz.
  Serial.println(deger); // "deger" değişkenini satır satır seri monitörümüze yazdırıyoruz. Eğer "println" yerine "print" kullansaydık alt alta değil, yanyana yazacaktı. Karışık görünecekti.
  delay(50); // Seri monitörümüzdeki yazıların aşırı hızlı akmasını istemiyoruz. Bu yüzden küçük bir bekleme koyduk. Daha güzel bir şekilde akacak artık.
  deger=map(deger,0,1023,1,5); /* "map" komutu bir değer aralığını daraltmak için kullanılır. Mesela 0 dan 9 a kadar olan bir değeri 0 ile 5 arasına daraltalım.
  *  Bu durumda 0 ve 1 değerleri 0 değerini, 2 ve 3 değerleri 1 değerini alırdı.
  *  Eğer 0 dan 10 a kadar olan aralığı 0 dan 100 e daraltsaydık da 4 değeri 40 olurdu, 7 değeri 70 olurdu.
  * "map" komutunun kullanım şekli:   map(<daraltılmak istenen değer>,<ilk değerin min. değeri>,<istediğimiz değerin min. değeri>,<istediğimiz değerin max. değeri>);
  Burada analog pinden gelen min. değer 0, max. değer 1023 olduğu için onları o şekilde ayarladık. 5 tane LED yöneteciğimiz için min. değeri 1 olarak, max. değeri 5 olarak ayarladık.  */
  if(deger==1){
    digitalWrite(led1,HIGH); // 1. LEDimizi yaktığımızda diğer LEDleri de söndürüyoruz.
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led5,LOW);
  }else if(deger==2){  // "else if" komutu isminden de anlaşılabileceği üzere "if" te bahsettiğimiz durumun dışındaki belirtmek istediğimiz durumlarda kullanılır. 2'den fazla durum olduğunda kullanılır.
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led5,LOW);
  }else if(deger==3){
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,LOW);
    digitalWrite(led5,LOW);
  }else if(deger==4){
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,HIGH);
    digitalWrite(led5,LOW);
  }else{    // Son durumu yazmamıza gerek olmadığını düşünüyorum. Yukarıdaki durumların dışındaki tek durum "deger" değişkeninin 5'e eşit olması zaten.
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led5,HIGH);
  }
}

/* Bu kodumuzla potansiyometremizi çevirerek LEDlerimizin sıra sıra yanmasını sağladık.
"deger" değişkenimize öncelikle analog pinden gelen değeri yazıp onu seri monitörde gördük. Daha sonra bu değeri daraltıp LEDlerimizi ona bağlantılı olarak çalıştırdık.  */


// Taha Helvacıoğlu 07.11.2020
