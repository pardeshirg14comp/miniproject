typedef struct info{
	char *auther;
	char *publisher;
	char *price;
	char *shelfno;
}info;

typedef struct student{
	char *name;
	char *branch;
	long int mis;
	long int mobno;
	char *academicyear;
}student;

typedef struct book{
	char *bookname;
	struct info *binfo;
	struct student *studentinfo;
	struct book *next;
}book;

typedef struct lib{
	struct book *head, *tail;
}lib;


char bname[32], bauther[32], bpublisher[32], bprice[16], bshelfno[16], sname[32], sbranch[16], sacademicyear[16];
int ch, choice;
long int smis, smobno;
char c;

void update(lib *l);

void libinit(lib *l);

void addbook(lib *l, char *bname, char *bauther, char *bpublisher, char *bprice, char *bshelfno);

int printbook(lib *l);

book *searchbook(lib *l, char *bname);

void printsearchedbook(book *b);

void removebook(lib *l, char *bname);

void removedata(lib *l);

void assignbook(lib *l, char *sname, char *sbranch, long int smis, long int smobno, char *academicyear, book *b);

void returnbook(lib *l, book *b, char *sname);

void writebookdata(lib *l);

void writestudentdata(lib *l);

void studentdatabook(lib *l, book *b);

int bookdata(lib *l);
