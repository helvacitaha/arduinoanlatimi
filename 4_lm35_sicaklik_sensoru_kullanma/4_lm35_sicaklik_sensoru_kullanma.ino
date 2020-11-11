#define lm35 A0   //LM35 sıcaklık sensörümüzü bağladığımız pini belirliyoruz.
#define led 8
#define buzzer 7 //LED ve buzzerımızı aynı anda çalıştıracağımız için ikisini aynı pine bağlayabilirsiniz. Ben göstermek için bu şekilde yaptım.
float sensordeger;
float sicaklik;
// "float" türündeki değişkeni kullanıyoruz. Bu değişken türünde ondalık kısımları da alabiliyoruz.

void setup() {
  pinMode(lm35,INPUT);
  pinMode(led,OUTPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensordeger=analogRead(lm35); // "lm35" pinindeki değeri okuyup "sensordeger" değişkenine yazdırıyoruz.
  Serial.println("Sensörün verdiği değer: "); /*Seri monitörde daha düzenli göstermesi için başlık tarzı bir şey yazıyoruz. Dikkat edin tırnak işaretleri kullandım.
  Seri monitöre veya daha ileride kullanacağımız zamanlarda ekrana yazı yazdırırken tırnak işaretinin içinde yazın. Yoksa bu yazıyı bir kod olarak anlar ve hata verir.  */
  Serial.print(sensordeger); // "println" kullanmadım çünkü bu değerin az önce yazdığımız yazının yanında yazmasını istiyorum. "Sensörün verdiği değer: x" olarak görünecek.
  sicaklik=(sensordeger/1023)*500; /* Burada sıcaklığı Celsius cinsinden almak için kullanılan denklemi kullandık. Sensörlerin verdiği değerlerden referans değerlere dönüşümünü sağlayan
  değerler vardır. Bu da LM35 için olan denklem. */
  Serial.println("Ortam sıcaklığı: ");
  Serial.print(sicaklik);
  Serial.print(" °C");
  Serial.println("----------------------------------"); //Seri monitörde daha düzenli görünmesi için bir çizgi ekledik.
  delay(50); //  Değerlerin çok hızlı akmaması için küçük bir bekleme ekledik.
  if(sicaklik>=29){    // Burada kendime göre bir değer belirledim ve eğer sıcaklık bu değerden büyükse veya eşitse LED ve buzzerımı çalıştırıyoruz. Buradaki değeri kendinize göre değiştirebilirsiniz.
    digitalWrite(led,HIGH);
    digitalWrite(buzzer,HIGH);
  }else{         // Eğer sıcaklık 29 a eşit veya 29 dan büyük değil ise (29 dan küçük ise) led ve buzzerımızı kapatıyoruz.
    digitalWrite(led,LOW);
    digitalWrite(buzzer,LOW);
  }
}
/* Bo kod ilke sıcaklık 29 celsius derecenin üstüne çıktığında led ve buzzerımızın çalışarak uyarı vermesini sağlıyoruz. Kendiniz isterseniz yanıp söndürerek veya başka şekillerde
uyarma yaparak bu projeyi değiştirebilirsiniz. */

// Taha Helvacıoğlu 07.11.2020
 
