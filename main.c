
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
#include<unistd.h>
#include"lib.h"
void position(int x,int y) {  		//Printing the data to given co-ordinates of the screen
	printf("%c[%d;%df", 0x1B,y,x);
}

void printmenu(){		//Printing the initial menu
	position(30, 2);
	printf("\n\t====================================== MAIN MENU ================================================ =======\n");
	position(30, 5);
	printf("1. Add Books   ");
	position(30, 7);
	printf("2. Show books available for issue");
	position(30, 9);
	printf("3. Show existing books");
	position(30, 11);
	printf("4. Search Books");
	position(30, 13);
	printf("5. Issue a Book");
	position(30, 15);
	printf("6. Remove Book");
	position(30, 17);
	printf("7. Return the Book");
	position(30, 19);
	printf("8. Exit application\n");
	printf("\t=============================================================================================== ============\n");
};
int main(){
	int i = 0;
	char passw[5] = {"1234"}, *input;
	while(i<=3){
		system("clear");
		position(5, 3);
		printf("=============================================================================================== \n");
		printf("\t\t\t\tLIBRARY MANAGEMENT SYSTEM\n");
		position(5, 5);
		printf("=============================================================================================== \n\n");
		position(5, 7);
		printf("\tUser :\tADMIN\n\n");
		input=getpass("\tEnter password :\t");
		if(strcmp(passw,input) == 0){
			lib l;
			libinit(&l);
	
			book *b;
			update(&l);
			system("clear");
			while(1){
				printmenu();
				position(30, 21);
				printf("plese enter your choice :");
				scanf("%d", &choice);
				switch(choice){
					case 1: {
						system("clear");
						position(10, 1);
						printf("Instead of spacebar please use underscore in case of multiple name ");
						position(30, 2);
						printf("\n\t====================================== ADD BOOK ================================================ \n");
						position(30, 5);
						printf("Enter the following details of the book ");
						position(30, 19);
						printf("\n\t================================================================================================\n");
						position(35, 7);
						printf("Name of book :");
			
						scanf("%s", bname);
						position(35, 9);
						printf("Name auther of book :");
						scanf("%s", bauther);
						position(35, 11);
						printf("Name of publisher of book :");
						scanf("%s", bpublisher);
						position(35, 13);
						printf("Price  of book :");
						scanf("%s", bprice);
						position(35, 15);
						printf("Shelfno of the book :");
						scanf("%s", bshelfno);	
						addbook(&l, bname, bauther, bpublisher, bprice, bshelfno);
						position(30, 17);
						
						printf("Book saved successfully\n");
						writebookdata(&l);
						position(30, 18);
						printf("\tTo continue press 1 :  ");
						scanf("%d", &ch);
						system("clear");
						break;
					}
					case 2:{
						system("clear");
						ch = bookdata(&l);
						position(15, ch+2);
						printf("to continue enter 1 : ");
						scanf("%d", &ch);
						if(ch == 1){
						
							system("clear");
					
							break;
						}
					}
						
					
					
					
					case 3:{
						system("clear");
						ch = printbook(&l);
						position(15, ch+2);
						printf("to continue enter 1 : ");
						scanf("%d", &ch);
						if(ch == 1){
							system("clear");
					
							break;
						}
					}
					case 4:{
						system("clear");
						position(10, 1);
						printf("Instead of spacebar please use underscore in case of multiple name ");
						position(10, 2);
						printf("\n\t================================================================================================\n");
						position(15, 4);
						printf("\n\t Enter the name of the book to be searched : ");
						scanf("%s", bname);
						b = searchbook(&l, bname);
						if(b){
							position(15, 6);
							printf("\tthe book is avialable in the libraray\n");
						}
						else{
							position(15, 6);
							printf("book %s id not available\n", bname);
							break;
						}
						position(20, 8);
						printf("\n\tfor details of the book enter 1 : ");
						scanf("%d", &ch);
						if(ch == 1){
							printsearchedbook(b);
						}
						position(10, 20);
						printf("====================================================================================================\n");
						position(15, 22);
						printf("\n \t\t To return press 1 :  ");
						scanf("%d", &ch);
						system("clear");
						break;
					}
					case 5 : {
						system("clear");
						position(10, 1);
						printf("Instead of spacebar please use underscore in case of multiple name ");
						position(10, 2);
						printf("========================================ISSUE BOOK================================================\n");
						position(10, 22);
						printf("==================================================================================================\n");
						position(15, 4);
						printf("Enter the name of book to be assigned : ");
						scanf("%s", bname);
						b = searchbook(&l, bname);
						
						if(b){
							if(b->studentinfo == NULL){
								position(15, 6);
								printf("\n\tthe book is avialable for issue\n");
								position(20, 8);
								printf("Enter your followiong details ");
								position(25, 10);
								printf("Name : ");
								scanf("%s", sname);
								position(25, 12);
								printf("Branch : ");
								scanf("%s", sbranch);
								position(25, 14);
								printf("Academic year : ");
								scanf("%s", sacademicyear);
								position(25, 16);
								printf("MIS NO : ");
								scanf("%ld", &smis);
								position(25, 18);
								printf("Mobile no  : ");
								scanf("%ld", &smobno);
								assignbook(&l, sname, sbranch, smis, smobno, sacademicyear, b);
								position(20, 20);
								printf("Book is assigned to %s", sname);
								position(15, 24);
								printf("Press 1 to continue : ");
								scanf("%d", &ch);
								system("clear");
								writestudentdata(&l);
								break;
							}
							else{
								position(15, 6);
								printf("\tBook %s is not available for issue\n", bname);
								
								position(15, 24);
								printf("Press 1 to continue : ");
								scanf("%d", &ch);
								writestudentdata(&l);
								system("clear");
								break;
							}
						}
						else{
							position(15, 6);
							printf("The book '%s' does not exist in library ", bname);
							position(15, 24);
							printf("Press 1 to continue : ");
							scanf("%d", &ch);
							writestudentdata(&l);
							system("clear");
							break;
						
						}
						
										
						
					}
					case 6 :{
						system("clear");
						position(10, 1);
						printf("Instead of spacebar please use underscore in case of multiple name ");
						position(10, 2);
						printf("=======================================REMOVE BOOK================================================\n");
						position(10, 10);
						printf("==================================================================================================\n");
						position(15, 4);
						printf("Enter the name of the book which is to be removed :");
						scanf("%s", bname);
						removebook(&l, bname);
						
						
						position(15, 8);
						printf("To comtinue press 1  ");
						scanf("%d", &ch);
						writebookdata(&l);
						
						system("clear");
						break;
					}
					case 7 :{
						book *b;
						system("clear");
						position(10, 1);
						printf("Instead of spacebar please use underscore in case of multiple name ");
						position(10, 2);
						printf("=======================================REMOVE BOOK================================================\n");
						position(10, 12);
						printf("==================================================================================================\n");
						
						position(15, 4);
						printf("Enter the name of the book to be returned : ");
						scanf("%s", bname);
						b = searchbook(&l, bname);
						
						if(b->studentinfo && b){	
							position(15, 6);
							printf("Enter the name of student : ");
							scanf("%s", sname);
							returnbook(&l, b, sname);
							position(10, 10);
							printf("To comtinue press 1  ");
							scanf("%d", &ch);
							writestudentdata(&l);
							system("clear");
							break;
						}
						else
						{
							position(15, 6);
							printf("The book :'%s' already returned\n", bname);
							position(15, 10);
							printf("To comtinue press 1  ");
							scanf("%d", &ch);
							writestudentdata(&l);
							system("clear");
							break;
						}
						
							
					}
					case 8:{
						system("clear");
						int i;
						position(10, 2);
						printf("====================================================================================================\n");
						position(10, 6);
						printf("====================================================================================================\n");
						position(15, 4);
						printf("\n\tyou are about to exit ..... press '1' to exit : ");
						scanf("%d", &i);	
						if(i == 1){
							writebookdata(&l);
							writestudentdata(&l);
							removedata(&l);
							system("clear");
							printf("APPLICATION CLOSED\n");
							exit(1);
						}
						else{
							continue;
						}
						system("clear");
					}
							
				}		
			}
		}
		else
			{
			position(5, 12);
			printf("\tINVALID PASSWORD\n \tTry again..!\n");
			i++;
			if(i == 3)
				break;
		}
	}
	if(i == 3) {
		system("clear");
		printf("You Exceed limit to enter password\nApplication terminated\n");
		exit(0);
	}	
	return 0;
}



