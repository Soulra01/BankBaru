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