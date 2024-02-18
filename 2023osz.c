#include <stdio.h>
#include <string.h>

typedef struct tarsas{

int dobas;
char sorok[255];



}jatek;

int meret1(){

    int db=0;
    char chr;


FILE *filePtr1=fopen("osvenyek.txt","r");


if(filePtr1==NULL) printf("Az osvenyek.txt-t nem sikerult beolvasni!");


do{
    chr=fgetc(filePtr1);


    if(chr=='\n') db++;


}while(chr!=EOF);


return db;
}
int meret2(){
int chr;
int elemszam=1;

FILE *filePtr2=fopen("dobasok.txt","r");
do{

chr=fgetc(filePtr2);
if(chr==' ') elemszam++;




}while(chr!=EOF);

return elemszam;
}


void beolvas(jatek *tarsas,int db){

FILE *filePtr1=fopen("osvenyek.txt","r");


for(int i=0; i<db;i++){
fscanf(filePtr1,"%s",tarsas[i].sorok);





}

}
void beolvas2(jatek *tarsas,int elemszam2){




FILE *filePtr2=fopen("dobasok.txt","r");
for(int i=0; i<elemszam2;i++){
fscanf(filePtr2,"%d", &tarsas[i].dobas);






}


}
void feladat3(jatek *tarsas,int db){
int karakterszam=0;
int max=0;
int osveny=0;
for(int i=0; i<db;i++){
    for(int j=0; j<250;j++){

        if(tarsas[i].sorok[j]!='\0'){
        karakterszam++;

        }
        if(karakterszam>max){
              osveny=i+1; //tömb indexelése miatt +1;
        max=karakterszam;
}



}
karakterszam=0;
}
printf("\nAz egyik legosszabb a(z) %d osveny, hossza: %d",osveny, max);
}

void beker4(int *osveny,int *jatekosszam){



printf("\nAdja meg egy osveny sorszamat! ");
scanf("%d",osveny);
printf("Adja meg a jatekosok szamat! ");
scanf("%d",jatekosszam);





}

void feladat5(jatek *tarsas, int osveny){
int M=0;
int E=0;
int V=0;
printf("\n%d", osveny);
    for(int j=0; j<250;j++){

    if(tarsas[osveny].sorok[j]=='M') M++;


     if(tarsas[osveny].sorok[j]=='E') E++;


      if(tarsas[osveny].sorok[j]=='V') V++;


    }

    if(M!=0) printf("\nM: %d darab",M);
    if(E!=0) printf("\nE: %d darab",E);
    if(V!=0) printf("\nV: %d darab",V);
}




void feladat6(jatek *tarsas, int osveny){

    FILE *filePtr=fopen("kulonleges.txt","w");

for(int j=0; j<250;j++){



if(tarsas[osveny].sorok[j]=='E') fprintf(filePtr,"\n%d    E",j+1);


if(tarsas[osveny].sorok[j]=='V') fprintf(filePtr,"\n%d    V",j+1);



}

}
void feladat7(jatek *tarsas,int osveny, int jatekosszam,int elemszam2){

int szam=0;
int mezoszam=0;
int tomb[jatekosszam];
memset(tomb,0,sizeof(tomb));
for(int j=0; j<250;j++){

if(tarsas[osveny].sorok[j]!='\0') {
        mezoszam++;


}
}

    for (int i = 0; i < elemszam2; i++) {


if (szam < jatekosszam - 1) szam++;
else szam=0;

            //szam = szam % jatekosszam;


tomb[szam] += tarsas[i].dobas;






        if ((mezoszam - tomb[szam]) <= 0) {

            printf("\nA legtavolabb juto(k) sorszama: %d, Kornek szama: %d\n", szam + 1, i/jatekosszam);
            break;
        }


        //szam++;
    }
}


int main(){
int elemszam2=0;
int db;
int osveny;
int jatekos;

elemszam2=meret2();
db=meret1();


jatek tarsas[elemszam2];
printf("\nA dobasok szama: %d", elemszam2);
printf("%\nAz osvenyek szama: %d", db);

beolvas(tarsas,db);
beolvas2(tarsas,elemszam2);
feladat3(tarsas,db);
beker4(&osveny,&jatekos);
feladat5(tarsas, osveny);
feladat6(tarsas,osveny);
feladat7(tarsas,osveny,jatekos,elemszam2);

return 0;
}
