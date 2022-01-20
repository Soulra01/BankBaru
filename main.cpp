#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ll long long
#define ld long double
#define max_limit 256

// alif ardika - 2501990470

//struct

typedef struct{
    char name[max_limit];
    char norek[max_limit];
    char pass[max_limit];
    char time[25];
    unsigned ll money;
}User;

User Nasabah[max_limit];
FILE* fp;
User currUser;
int last = 0;

//function Declare
void enterTo();
void clearBuff();
void sort();
void swap(User*,User*);
void atmMenu();
void login();
//function Declare(main)
void create();
void read();
void update();
void remove();

//function
void clearBuff() { 
    int c; 
    while ((c = getchar()) != '\n' && c != EOF){} 
    }

void enterTo() {
  printf("Tekan enter untuk melanjutkan..\n");
  clearBuff();
}

void sort(){
    fp = fopen("database.in", "r");
    int min;
    for(int i = 0 ; i < last-1;i++){
        min = i;
        for(int j = i+1; j < last; j++){
            if(strcmp(Nasabah[j].name,Nasabah[min].name)<0){
                min = j;
            }
        }
        swap(&Nasabah[min], &Nasabah[i]);
    }
}

void swap(User *first, User *second){
    User temp = *first;
    *first = *second;
    *second = temp;
}

int accValid(const char* nama) {
  FILE* fp = fopen("database.in","r");
  User temp;
  while(!feof(fp)){
      fscanf(fp, "%s %s\n", temp.name, temp.pass);
      if(!strcmp(temp.name, nama)){
          char password[10];
          printf("Masukan Password : ");
          scanf("%s", password);
          if(!strcmp(temp.pass, password)){
              currUser = temp;
              return 2;
          }
          return 1;
      }
  }
  return 0;
  fclose(fp);
}

void atmMenu(){
    system("clear");
    printf("Halo %s\n", currUser.name);

}

//function (main)
void login(){
    system("clear");
    char name[20];
    printf("Masukan Nama Anda : ");
    scanf("%s", name);
    int s = 0;
    while(s < 3){
        switch (accValid(name)){
        case 0:
            printf("Salah Username\n");
            break;
        case 1:
            printf("Salah Password\n");
            printf("Maksimal percobaan 3 : %d\n", s+1);
            break;
        case 2:
            atmMenu();
            break;
    
        }
        s++;
    }
    printf("Salah Password anda harus mengulang dari awal.\n");
}

void create(){
    User add;
    char temp[max_limit];
    int temprek = 0;
    temprek = rand();
    printf("Masukan Nama : ");
    scanf("%[^\n]", add.name); getchar();
    printf("Masukan Password : ");
    scanf("%s", add.pass); getchar();
    printf("No rek anda adalah : ");
    sprintf(add.norek,"%d", temprek);
    printf("%s\n", add.norek);
    add.money = 0;
    strcpy(temp, add.name);
    fp = fopen("database.in", "a");
    fprintf(fp,"%s %s %s %lld\n", add.name, add.pass, add.norek, add.money);
    fclose(fp);
    printf("Halo %s\n", temp);
    puts("Data telah tersimpan");
    enterTo();
}

void read(){

    last = 0;
    fp = fopen("database.in", "r");
    if(fp == NULL){
        printf("Error");
        return;
    }
    while(!feof(fp)){
        fscanf(fp,"%s %s %s %llu\n", Nasabah[last].name, Nasabah[last].pass, Nasabah[last].norek, &Nasabah[last].money);
        last++;
    }
    
}

void display(){
    for(int i = 0;i < last;i++){
        printf("%s\n", Nasabah[i].name);
    }
}

void tof(){
    read();
    sort();
}

int main(){

    login();
    
    

    return 0;
}