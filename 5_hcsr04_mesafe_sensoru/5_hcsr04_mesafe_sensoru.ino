#define trig 8 //Ultrasonik sesi gönderdiğimiz pin.
#define echo 7 //Ultrasonik sesi aldığımız pin.
long sure;  // bu değişkenlerde "int" yerine "long" kullanmamızın sebebi int değişkenleri -2^15 ten +(2^15)-1 e kadar değer alabiliyor. Bu bize yeterli olmayacabilir. "long" ise -2^63 ten
long mesafe; // +2^63 e kadar değer alabiliyor. Bu bize burada yeterli.

void setup() {
  pinMode(trig,OUTPUT); //Ultrasonik sesi gönderdiğimiz pin. Çıkış pini olacak.
  pinMode(echo,INPUT); //Ultrasonik sesi aldığımız pin. Giriş pini olacak.
  Serial.begin(9600); //Seri monitörümüzü başlatıyoruz.
}

void loop() {
    digitalWrite(trig,LOW);
    delayMicroseconds(2); // Bu iki satır kod olası bir hatayı engellemek için. "trig" pinimizi kapatıyoruz öncelikle.
    digitalWrite(trig,HIGH);
    delayMicroseconds(10); //Hatırlıyorsanız 1 milisaniye = 1000 mikrosaniye.
    digitalWrite(trig,LOW);
    sure=pulseIn(echo,HIGH); /* "pulseIn" komutu aralık ölçmeye yarar. Buradaki "pulseIn(echo,HIGH);" komutunun yaptığı şey şu:
    * Bu komut kullanıldıktan sonra "echo" pininin "HIGH" olmasını bekler. Saymaya başlar. "echo" pini "LOW" olduğunda saymayı bırakır.
    Böylece "echo" pininin "HIGH" olma süresini bize verir. "echo" pini sesin gidip gelirken geçen süre kadar "HIGH" değer alır. Bize aradaki süreyi verir.  */
    mesafe=sure/58.2; // Sesin hızına göre sesin gidip geldiği yola göre aradaki mesafeyi buluyoruz. İsterseniz ekleyebilirsiniz: "alinanyol=mesafe*2;" ya da "alinanyol=sure/29.1;"
    if(mesafe>200){ //Bu sensörün max. ölçebileceği mesafeye yaklaşınca artık max. değeri vermesini istiyoruz. Daha sonrasındaki değerlerde "mesafe" değerimiz bozulabiliyor.
      mesafe=200;
    }
    Serial.println("Ses gidip gelirken arada geçen süre: ");
    Serial.print(sure);
    Serial.println("Aradaki mesafe: ");
    Serial.print(mesafe);
    Serial.print(" cm");
    Serial.println("--------------------------------");
    delay(50);
}

/*Bu kod ile seri monitöre "Ses gidip gelirken arada geçen süre: x" ve "Aradaki mesafe: y cm" şeklince yazacağız. */


// Taha Helvacıoğlu 07.11.2020
