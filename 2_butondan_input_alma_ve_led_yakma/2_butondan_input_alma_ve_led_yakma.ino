#define led 8 //LEDimizi bağladığımız dijital pini belirliyoruz.
#define buton 9 //Butonumuzu bağladığımız dijital pini belirliyoruz.

void setup() {
  pinMode(led,OUTPUT); //LEDimizi bağladığımız pinden çıkış vereceğiz. Çıkış olarak ayarlıyoruz.
  pinMode(buton,INPUT); //Butonumuzu bağladığımız pinden giriş alacağız. Giriş olarak ayarlıyoruz.
}

void loop() {
  /* "if" komutunun kullanımı: 
   *  *  if(<durum>){
   *  <yapılmasını istediğimiz şey>
   *  }
   */
   if(digitalRead(buton)==HIGH){ /*Burada digitalRead() komutu ile "buton" olarak belirlediğimiz pindeki değeri okuyoruz. Daha sonra bu değerin "HIGH" mı olduğunu kontrol ediyoruz. "buton"
     olarak belirlediğimiz pine gelen değer yüksek mi olduğuna bakıyoruz. Eğer ki butonumuz basılıysa bu pine "HIGH" değer gelecek. */
    digitalWrite(led,HIGH); //Bu kodumuz if in içerisinde olduğu için if teki durum olduğunda bu kodu çalıştıracak. Bu kod LEDimizin ışık vermesini sağlayacak.
   }else{ //if ten sonra gelen else komutunda if in içerisindeki durum oluşmaz ise çalışacak kodu yazmamız gerekiyor. Aslında "değilse" işlemini yapıyor.
    digitalWrite(led,LOW); //"buton" pinimiz "HIGH" olmadığında yani "LOW" olduğunda  çalışacak kod. Bu kod LEDimizi söndürecek.
   }
}
/* Bu kod ile butona bastığımızda LEDimiz yanacak ve bıraktığımızda sönecek. "if" ve "else" komutlarımız loop un içerisinde olduğu için sürekli buton pininin durumunu kontrol edecek.
 *  Eğer "HIGH" ise ledi de "HIGH" yapacak. Eğer "LOW" ise ledimizi de "LOW" yapacak.
 Bir kez de "HIGH" ve "LOW" un yerini değiştirip deneyin. Ne olacağını muhtemelen tahmin ediyorsunuzdur.  */


 // Taha Helvacıoğlu 07.11.2020
