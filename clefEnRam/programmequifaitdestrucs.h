#ifndef PROG_H
#define PROG_H

#define KEY_LENGTH 16
#define CARD_ID_LENGTH 16
#define CARD_ID_SEGMENT 4
#define CARD_NAME_LENGTH 28
#define CARD_PIN_LENGTH 1
#define COMMAND_LENGTH 20
#define BUFFER_SIZE 255
#define CMD_COUNT 4 

typedef struct card {
	char idCard[CARD_ID_LENGTH][CARD_ID_SEGMENT];
	char name[CARD_NAME_LENGTH];	
	int pin;
} s_card;

typedef struct command {
	char name [COMMAND_LENGTH];
	(void*) function (char** args);
} s_cmd;

typedef struct {
    const char *start;
    size_t len;
} token;

s_cmd cmd_list[CMD_COUNT];

void generateKey(unsigned char* dest);
void generateKKFrom(unsigned char* k1, unsigned char* k2, unsigned char* dest);
void storeKey(unsigned char* key,unsigned char* encryptKey);
void retreiveKey(unsigned char* key, unsigned char* decryptKey);

char **split(const char *str, char sep);

s_card init_card(int* card, int secret_pin, char* name); 
void show_card(s_card* c);
int compareCardsId(char** id1,char** id2)


void addNewEntry(int file, unsigned char* key, s_card* card);
void findEntry(int file, const unsigned char* key, char** id);
void printFile(int file, unsigned char* key);

void showMenu();
void exitProgram(unsigned char* key, int file);
void execute(char** command, int fichier,const unsigned char* key);

void cmd_add(char** args,int fichier, const unsigned char* key);
void cmd_print(char** args,int fichier, const unsigned char* key);
void cmd_find(char** args,int fichier, const unsigned char* key);
void cmd_exit(char** args,int fichier, const unsigned char* key);

#endif
