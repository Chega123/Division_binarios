#include <iostream>
using namespace std;

int* convertir_bit(int bin[], int num,int largo_cad){
  for(int i=0; i<largo_cad;i++){
    bin[i]=num%2;
    num=num/2;
  }
  return bin;
}

int* suma_bin(int bin_1[],int bin_2[],int largo_cad,int suma[]){
  for (int k=0;k<largo_cad-1;k++){
    suma[k]=0;}
  for(int i=0;i<largo_cad;i++){
    if(bin_1[i]+bin_2[i]==0){
      suma[i]=0;
    }
    if(bin_1[i]+bin_2[i]==1){
      suma[i]=1;
    }
    if(bin_1[i]+bin_2[i]==2){
      suma[i]=0;
      bin_1[i+1]=bin_1[i+1]+1;
    }
    if(bin_1[i]+bin_2[i]==3){
      suma[i]=1;
      bin_1[i+1]=bin_1[i+1]+1;
    }
  } 
  return suma;
}
int* cambio_c2(int bin[],int largo_cad){
  int convertido[largo_cad];
  for (int k=0;k<largo_cad;k++){
    convertido[k]=0;}
  for (int i=0;i<largo_cad;i++){
    if (bin[i]==0){convertido[i]=1;}
    else if (bin[i]==1){convertido[i]=0;}
  }
  int resultado[largo_cad];
  int numero_c2=1;
  int num_binario_c2[largo_cad];
  int* b=convertir_bit(num_binario_c2, numero_c2,largo_cad-1);
  int* res=suma_bin(convertido,b,largo_cad-1,resultado);
  return res;
}
int* resta_c2(int bin_1[],int bin_2[],int largo_cad,int almacen[]){
  int bin_1_extendido[largo_cad+1];
  int bin_2_extendido[largo_cad+1];
  for (int k=0;k<largo_cad+1;k++){
    bin_1_extendido[k]=0;
    bin_2_extendido[k]=0;} 
  for (int i=0;i<largo_cad;i++){
    if (bin_1[i]==0){
      bin_1_extendido[i]=0;}
    if (bin_1[i]==1){
      bin_1_extendido[i]=1;}
    if (bin_2[i]==0){
      bin_2_extendido[i]=0;}
    if (bin_2[i]==1){
      bin_2_extendido[i]=1;}
    }
  int* bin_2ex_c2 =cambio_c2(bin_2_extendido,largo_cad+1);
  
  int resultado_suma[largo_cad];
  int* sumatoria =suma_bin(bin_1_extendido,bin_2ex_c2,largo_cad+1,resultado_suma);
  sumatoria[largo_cad]=0;
  for(int i=0;i<largo_cad;i++){almacen[i]=0;}
  for(int i=0;i<largo_cad;i++){
    almacen[i]=sumatoria[i];}
  return almacen;
}
int *invertir(int bin[],int largo_cad) {
  char temp;
  for (int i = 0, d = largo_cad - 1; i < (largo_cad / 2);
       i++, d--) {
    temp = bin[i];
    bin[i] = bin[d];
    bin[d] = temp;
  }
  return bin;
}
void division(int divisor[],int dividendo[],int largo_cad,int residuo[]){  
  int* guardar_res=residuo;
  for (int i=0;i<largo_cad;i++){guardar_res[i]=0;}  
  for (int i=0;i<largo_cad;i++){
    int guardar= divisor[largo_cad-1];
    for (int k=largo_cad;k>=0;k--){
        divisor[k]=divisor[k-1];}    
    for (int k=0;k<largo_cad;k++){
      if(k==largo_cad-1){guardar_res[k]=guardar;}
      else{
         guardar_res[k]=guardar_res[k+1];}
      }
    int copiar_res[largo_cad];
    for (int i=0;i<largo_cad;i++){copiar_res[i]=0;copiar_res[i]=guardar_res[i];}
    int *cambiar_orden=invertir(copiar_res,largo_cad);      
    int almacen_resta[largo_cad];
    int* resultado_resta=resta_c2(cambiar_orden,dividendo,largo_cad,almacen_resta);  
    if(resultado_resta[largo_cad-1]==1){
      divisor[0]=0;  
    }
    else if(resultado_resta[largo_cad-1]==0){
      int* cambio_res_resta=invertir(resultado_resta,largo_cad);
      for(int i=0;i<largo_cad;i++){
        guardar_res[i]=cambio_res_resta[i];}
        divisor[0]=1;    
    }
  }
  cout<<"cociente"<<endl;
    for (int l=largo_cad-1;l>=0;l--){cout<<divisor[l];}  
     cout<<endl;
    cout<<"residuo"<<endl;
    for (int l=0;l<largo_cad;l++){cout<<guardar_res[l];}  
      cout<<endl;
}
int main() {
    int numero; 
    cout << "inserte un numero"<<endl;
    cin >>numero;
    int cantidad_bits;
    cout << "cantidad de bits"<<endl;
    cin >>cantidad_bits;
    int numero2; 
    cout << "inserte un numero"<<endl;
    cin >>numero2;
    int cantidad_bits2;
    cout << "cantidad de bits"<<endl;
    cin >>cantidad_bits2;
    int resi[cantidad_bits];
    int num_binario[cantidad_bits];
    int num_binario2[cantidad_bits];
    
    int* b =convertir_bit(num_binario2, numero2,cantidad_bits2);
    int* a =convertir_bit(num_binario, numero,cantidad_bits);
    int bin1 [cantidad_bits];
    int bin2 [cantidad_bits];
    for(int i=0;i<cantidad_bits;i++){
      bin1[i]=a[i];
      bin2[i]=b[i];
    };   
    int sumas[cantidad_bits];
    int* res_suma=suma_bin(bin1,bin2,cantidad_bits,sumas);     
    division(a,b,cantidad_bits,resi);

}
