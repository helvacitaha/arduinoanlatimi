#define led 8 /* LED'mizi hangi dijital pine taktığımızı belirliyoruz. Buradaki "led" ismi sizi yanıltmasın. İstediğiniz şeyi yazabilirsiniz. Bu kod ile artık "led" yazdığımız heryeri
kodumuz "8" olarak anlayacak. */

void setup() {
  // setup içerisindeki kodlar yalnızca bir kez çalıştırılır. Adı üstünde genelde kodumuzu çalışmaya hazırlamak için olan kodlar burada yer alır.
  pinMode(led,OUTPUT);   //LED'mizin bir çıkış(output) pini olduğunu söylüyoruz
}

void loop() {
  // loop içerisindeki kodlar sonsuz döngüdedir. Son kod çalıştıktan sonra anında başa döner ve tekrar çalışır.
  digitalWrite(led,HIGH); // LEDimizin olduğu pini çalıştırıyoruz. Yani LEDimizi yakıyoruz.
  delay(1000); // 1000 milisaniye bekliyoruz. 1000 milisaniye = 1 saniye
  digitalWrite(led,LOW); // LEDimizin olduğu pini kapatıyoruz. Yani LEDimizi söndürüyoruz.
  delay(1000); // 1000 milisaniye bekliyoruz. 1000 milisaniye = 1 saniye
}

 /* Bu kod ile öncelikle LEDimizi yaktık. 1 saniye boyunca beklettik. Yani LEDimiz 1 saniye boyunca açık kaldı.
   *  Daha sonra LEDimizi söndürüp 1 saniye daha bekledik. Yani LEDimiz 1 saniye de kapalı kaldı.
   * Son kodumuz olan "delay (1000);" den sonra kodumuz loop un içerisinde olduğu için tekrar başa döndü ve böylece sonsuz bir döngüde devam etmesini sağladık.
   * "delay(); komutunun içersindeki zamanı değiştirerek çalışma şeklindeki değişimi görebilirsiniz. Eğer çok daha küçük bir zaman dilimi isterseniz (insan gözüyle görülemez muhtemelen)
   "delayMicroseconds(); komutunu kullanın. Buradaki gireceğiniz değer mikrosaniye türünden çalışacak 1000 mikrosaniye = 1 milisaniye = 0.001 saniye  */



//Taha Helvacıoğlu 07.11.2020
