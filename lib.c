

/*****************************************************************************
 * Copyright (C) Rushikesh G. Pardeshi pardeshirg14.comp@gmail.com
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include"lib.h"


void libinit(lib *l){		//Initialise the pointers
		l->head = NULL;
		l->tail =  NULL;
}

void addbook(lib *l, char *bname, char *bauther, char *bpublisher, char *bprice, char *bshelfno){		//Add a new book in library
		struct book *tmp;
		tmp = (book *)malloc(sizeof(book));
		if(tmp == NULL){
			perror("failed :");
			exit(1);
		}
		
		tmp->studentinfo = NULL;
		tmp->next = NULL;
		tmp->studentinfo = NULL;
		tmp->bookname = (char *)malloc(strlen(bname)+1);
		if(tmp->bookname == NULL){
			perror("failed :");
			exit(1);
		}
		strcpy(tmp->bookname, bname);
		tmp->binfo = (info *)malloc(sizeof(info));
		if(tmp->binfo == NULL){
			perror("failed :");
			exit(1);
		}
		tmp->binfo->auther = (char *)malloc(strlen(bauther)+1);
		if(tmp->binfo->auther == NULL){
			perror("failed :");
			exit(1);
		}
		tmp->binfo->publisher = (char *)malloc(strlen(bpublisher)+1);
		if(tmp->binfo->publisher == NULL){
			perror("failed :");
			exit(1);
		}
		tmp->binfo->price = (char *)malloc(strlen(bprice)+1);
		if(tmp->binfo->price == NULL){
			perror("failed :");
			exit(1);
		}
		tmp->binfo->shelfno = (char *)malloc(strlen(bshelfno)+1);
		if(tmp->binfo->shelfno == NULL){
			perror("failed :");
			exit(1);
		}

		strcpy(tmp->binfo->auther, bauther);
		strcpy(tmp->binfo->publisher, bpublisher);
		strcpy(tmp->binfo->price, bprice);
		strcpy(tmp->binfo->shelfno, bshelfno);
		
		if(l->tail){
			l->tail->next = tmp;
		}
		else {
			l->head = tmp;
		}
		l->tail = tmp;
}

int printbook(lib *l){		//Prints data of all books available in the library
		struct book *p;
		p = l->head;
		position(10, 2);
		printf("\t_________________________________________________LIST OF BOOKS__________________________________________________________________\n");
		position(15, 4);
		printf("Name of the book ");
		position(45, 4);
		printf("Auther ");
		position(75, 4); 
		printf("Publisher ");
		position(105, 4);
		printf("Price ");
		position(135, 4);
		printf("Shelfno ");
		printf("\n");
		int i = 6;
		while(p){
			position(15, i);
			printf("%s", p->bookname);
			position(45, i);
			printf("%s", p->binfo->auther);
			position(75, i);
			printf("%s", p->binfo->publisher);
			position(105, i);
			printf("%s", p->binfo->price);
			position(135, i);
			printf("%s", p->binfo->shelfno);
			p = p->next;
			i = i + 2;
		}
		position(10, i);
		printf("\t________________________________________________________________________________________________________________________________\n");	
		return i;
	
}


book *searchbook(lib *l, char *bname){		//Searches the book and return the pointer having address of the book
		struct book *p;
		p = l->head;
		while(p){
			if(strcmp(p->bookname, bname) == 0){
				return p;
			}
			else{
				p = p->next;
			}
		}
}

void printsearchedbook(book *b){		//Prints the data of the book which is searched
		
			
		position(10, 9);
		printf("_________________________________________________DETAILS OF BOOK__________________________________________________________________\n");
		position(15, 10);
		printf("Name of the book ");
		position(45, 10);
		printf("Auther ");
		position(75, 10); 
		printf("Publisher ");
		position(105, 10);
		printf("Price ");
		position(135, 10);
		printf("Shelfno ");
		printf("\n");
		position(15, 12);
		printf("%s", b->bookname);
		position(45, 12);
		printf("%s", b->binfo->auther);
		position(75, 12);
		printf("%s", b->binfo->publisher);
		position(105, 12);
		printf("%s", b->binfo->price);
		position(135, 12);
		printf("%s", b->binfo->shelfno);
		position(50, 14);
		printf("Status of book ");
		if(b->studentinfo){
			position(55, 16);
			printf("Not available for issue");
		}
		else{
			position(55, 16);
			printf("Available for issue");
		}
		position(10, 18);
		printf("____________________________________________________________________________________________________________________________________\n");
		
}

void assignbook(lib *l, char *sname, char *sbranch, long int smis, long int smobno, char *sacademicyear, book *b){ 	//Assigns book a student
		student *tmp;
		tmp = (student *)malloc(sizeof(student));
		if(tmp == NULL){
			perror("failed :");
			exit(1);
		}
		tmp->name = (char *)malloc(strlen(sname)+1);
		if(tmp->name == NULL){
			perror("\n\t\tfailed :");
			exit(1);
		}
		tmp->branch = (char *)malloc(strlen(sbranch)+1);
		if(tmp->branch == NULL){
			perror("\n\t\tfailed :");
			exit(1);
		}		
		tmp->academicyear = (char *)malloc(strlen(sacademicyear)+1);
		if(tmp->name == NULL){
			perror("\n\t\tfailed :");
			exit(1);
		}
		
		strcpy(tmp->name, sname);
		strcpy(tmp->branch, sbranch);
		strcpy(tmp->academicyear, sacademicyear);
		tmp->mis = smis;
		tmp->mobno = smobno;
		
		b->studentinfo = tmp;
	
		
}

void removebook(lib *l, char *bname){		//Removes the specific book from the library which is not assigned to anyone
		struct book *tmp, *s, *p;
		tmp = l->head;
		p = l->head;
		while(l->head){
			
			if(strcmp(l->head->bookname, bname) == 0){
				if(l->head->studentinfo == NULL){
					s = l->head;
					free(s->binfo->auther);
					free(s->binfo->publisher);
					free(s->binfo->price);
					free(s->binfo->shelfno);
					free(s->binfo);
					
					if (s == tmp){
						tmp = l->head->next;	
					}
					else
						if(s->next == NULL){
							p->next = NULL;
						}
						else{
				
							p->next = l->head->next;
						}			
					free(s);
					position(15, 6);
					printf("Succesfully Removed");
					break;
				}
				else{
					position(15, 6);
					printf("Can't remove book as it is assigned to '%s ' ", l->head->studentinfo->name);
					break;
				}
				
			}
			else{
				p = l->head;
				l->head = l->head->next;
			}
		
		}
		l->head = tmp;
	
}


void removedata(lib *l){		//This function frees all the data which has been malloc before leaving the program
		struct book *s;
		while(l->head){
				s = l->head;
				free(s->binfo->auther);
				free(s->binfo->publisher);
				free(s->binfo->price);
				free(s->binfo->shelfno);
				free(s->binfo);
				if(s->studentinfo){
					free(s->studentinfo->name);
					free(s->studentinfo->branch);
					free(s->studentinfo->academicyear);
					free(s->studentinfo);
				}
				l->head = s->next;
				free(s);
		}
	}
		


void returnbook(lib *l, book *b, char *sname){		//Returns the book to the library
		student *p, *tmp;
		p = b->studentinfo;
		if(strcmp(p->name, sname) == 0){
			free(p->name);
			free(p->branch);
			free(p->academicyear);
			free(p);
			b->studentinfo = NULL;
			position(15, 8);
			printf("Succesfully returned");
		
		}
		else{
			position(15, 8);
			printf("The name you have entered does not have any bookof library");
			
			
		}
		
	}
			
void writebookdata(lib *l){		///writes the new modified data of books of library in file : "bookdata.txt"
		FILE *fp;
		fp = fopen("bookdata.txt", "w");
		if(fp == NULL){
			perror("\nfailed : ");
			exit(1);
		}
		struct book *b;
		b = l->head;
		
		while(b){
			fprintf(fp, "%s	%s	%s	%s	%s\n", b->bookname, b->binfo->auther, b->binfo->publisher, b->binfo->price, b->binfo->shelfno);
			b = b->next;
		}
		fclose(fp);
		
}
			

void writestudentdata(lib *l){		//writes the new modified data of students in file : "studentdata.txt"
		FILE *fp1;
		fp1 = fopen("studentdata.txt", "w");
		if(fp1 == NULL){
			perror("\nfailed : ");
			exit(1);
		}
		struct book *b;
		b = l->head;
		
		while(b){
			if(b->studentinfo){
				fprintf(fp1, "%s	%s	%s	%ld	%ld	%s\n", b->bookname, b->studentinfo->name, b->studentinfo->branch, b->studentinfo->mis, b->studentinfo->mobno, b->studentinfo->academicyear);
			}
			b = b->next;
		}
		fclose(fp1);
		
}		
		
		
		
void update(lib *l){	//Access the existing data which is stored in the files	
		FILE *fp, *fp1;
		fp = fopen("bookdata.txt", "r");
		if(fp == NULL){
			perror("\nfailed : ");
			exit(1);
		}
		
		while(1){
			fscanf(fp, "%s	%s	%s	%s	%s\n", bname, bauther, bpublisher, bprice, bshelfno);
			struct book *tmp;
			tmp = (book *)malloc(sizeof(book));
			if(tmp == NULL){
				perror("failed :");
				exit(1);
			}
		
			tmp->studentinfo = NULL;	
			tmp->next = NULL;
			tmp->studentinfo = NULL;
			tmp->bookname = (char *)malloc(strlen(bname)+1);
			if(tmp->bookname == NULL){
				perror("failed :");
				exit(1);
			}
			strcpy(tmp->bookname, bname);
			tmp->binfo = (info *)malloc(sizeof(info));
			if(tmp->binfo == NULL){
				perror("failed :");
				exit(1);
			}
			tmp->binfo->auther = (char *)malloc(strlen(bauther)+1);
			if(tmp->binfo->auther == NULL){
				perror("failed :");
				exit(1);
			}
			tmp->binfo->publisher = (char *)malloc(strlen(bpublisher)+1);	
			if(tmp->binfo->publisher == NULL){
				perror("failed :");
				exit(1);
			}
			tmp->binfo->price = (char *)malloc(strlen(bprice)+1);
			if(tmp->binfo->price == NULL){
				perror("failed :");
				exit(1);
			}
			tmp->binfo->shelfno = (char *)malloc(strlen(bshelfno)+1);
			if(tmp->binfo->shelfno == NULL){
				perror("failed :");
				exit(1);
			}	

			strcpy(tmp->binfo->auther, bauther);
			strcpy(tmp->binfo->publisher, bpublisher);
			strcpy(tmp->binfo->price, bprice);
			strcpy(tmp->binfo->shelfno, bshelfno);
		
			if(l->tail){	
				l->tail->next = tmp;
			}
			else {
				l->head = tmp;
			}
			l->tail = tmp;
		
			if(feof(fp)){
				break;
			}
		}
		
		fclose(fp);
		fp1 = fopen("studentdata.txt","r");
		book *b;
		
		while(1){
			fscanf(fp1, "%s	%s	%s	%ld	%ld	%s\n", bname, sname, sbranch, &smis, &smobno, sacademicyear);
			student *tmp;
			tmp = (student *)malloc(sizeof(student));
			if(tmp == NULL){
				perror("failed :");
				exit(1);
			}
			tmp->name = (char *)malloc(strlen(sname)+1);
			if(tmp->name == NULL){
				perror("\n\t\tfailed :");
				exit(1);
			}
			tmp->branch = (char *)malloc(strlen(sbranch)+1);
			if(tmp->branch == NULL){
				perror("\n\t\tfailed :");
				exit(1);
			}		
			tmp->academicyear = (char *)malloc(strlen(sacademicyear)+1);
			if(tmp->name == NULL){
				perror("\n\t\tfailed :");
				exit(1);
			}
			
			strcpy(tmp->name, sname);
			strcpy(tmp->branch, sbranch);
			strcpy(tmp->academicyear, sacademicyear);
			tmp->mis = smis;
			tmp->mobno = smobno;
			
			b = searchbook(l, bname);
			b->studentinfo = tmp;
			
			if(feof(fp)){
				break;
			}
	}		
			
}	
		

int bookdata(lib *l){			//Prints the data of book which are available for issue and returns a int for the use
		book *b;
		int i;
		b = l->head;
		position(10, 9);
		printf("_________________________________________________DETAILS OF BOOK__________________________________________________________________\n");
		position(15, 10);
		printf("Name of the book ");
		position(45, 10);
		printf("Auther ");
		position(75, 10); 
		printf("Publisher ");
		position(105, 10);
		printf("Price ");
		position(135, 10);
		printf("Shelfno ");
		printf("\n");
		i = 12;
		while(b){
			if(b->studentinfo == NULL){
				position(15, i);
				printf("%s", b->bookname);
				position(45, i);
				printf("%s", b->binfo->auther);
				position(75, i);
				printf("%s", b->binfo->publisher);
				position(105, i);
				printf("%s", b->binfo->price);
				position(135, i);
				printf("%s", b->binfo->shelfno);
				i = i+2;
			}
			
			b = b->next;
		}
		
		position(10, i);
		printf("____________________________________________________________________________________________________________________________________\n");
		return i;
		
	}
		
		
		
		
		
		
