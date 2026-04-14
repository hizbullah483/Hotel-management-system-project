#include <stdio.h>
#include <string.h>
struct Room{
    int roomnum;    float roomcost;
    char roomtype; int isavailable;
};
void roomdetails(struct Room *room, int rnum, float rcost, char rtype, int available){
    room -> roomnum = rnum;
    room -> roomcost = rcost;
    room -> roomtype = rtype;
    room -> isavailable = available;
}
void displayroomdetails(struct Room *room){
    printf("room number %d || ", room-> roomnum);
    printf("room price: %.2f || ", room-> roomcost);
    printf("room type: %c || ", room-> roomtype);
    printf("is available? %s\n", room-> isavailable ? "yes" : "no");
}

void storeroomdetailsinfile(struct Room rooms[]){
	FILE *outfile = fopen("rooms.txt","w");
	if(!outfile){
		perror("error");
		} 
	for(int i = 0; i < 100; i++){
		fprintf(outfile, "%d %.2f %c %d\n",
		rooms[i].roomnum,
		rooms[i].roomcost,
		rooms[i].roomtype,
		rooms[i].isavailable);		
	}
		fclose(outfile);	
	}
//going into array	
int getroomdetailsfromfile(struct Room rooms[]){
	FILE *infile = fopen("rooms.txt","r");
	if(infile == NULL){
		perror("error");
		return 1;
		}
	int i = 0;
	while(fscanf(infile, "%d %f %c %d",	&rooms[i].roomnum,&rooms[i].roomcost,&rooms[i].roomtype,&rooms[i].isavailable)== 4){
		i++;
	}
	fclose(infile);
	return i;	
	}	
struct Customer{ 
    char customername[100]; 
      char customerphone[100];
    int previousbookings;  char status[100];
};
void customerdetails(struct Customer *customer, char *cname, char *cphone, int pbookings, char *stat) {
    strcpy(customer->customername, cname);
    strcpy(customer->customerphone, cphone);
    customer->previousbookings = pbookings;
    strcpy(customer->status, stat);
}
void displaycustomerdetails(struct Customer *customer){
    printf("customer name: %s", customer->customername);
    printf("\ncustomer phone number: %s", customer->customerphone);
    printf("\nprevious bookings: %d", customer->previousbookings);
    printf("\nstatus: %s", customer->status);
}
void storecustomerdetailsinfile(struct Customer customers[],int custcount){
	FILE *outfile = fopen("customer.txt","w");
	if(!outfile){
		perror("error");
		} 
	for(int i = 0; i < custcount; i++){
		fprintf(outfile, "%s %s %d %s\n",
		customers[i].customername,
		customers[i].customerphone,
		customers[i].previousbookings,
		customers[i].status);		
	}
		fclose(outfile);	
	}
//count customers	
int getcustomerdetailsfromfile(struct Customer customers[]){
	FILE *infile = fopen("customers.txt","r");
	if(!infile){
		perror("error");
		return 1;
		}
	int i = 0;
	while(fscanf(infile, "%s %s %d %s",	&customers[i].customername,&customers[i].customerphone,&customers[i].previousbookings,&customers[i].status)== 4){
		i++;
	}
	fclose(infile);
	return i;	
	}
int findcustomer(char cname[],char cphone[]){
		    char customername[100]; 
      char customerphone[100];
    int previousbookings;  
    char status[100];
	int found = 0;
	FILE *file = fopen("customers.txt","r");
	if(!file){
		perror("error");
		}
	while(fscanf(file, "%s %s %d %s",	customername,customerphone,&previousbookings,status)== 4){
		if(strcmp(cname,customername) == 0 && strcmp(cphone,customerphone) == 0 ){
			found = 1;
			}
	}
	fclose(file);	
	return found;
	}		
int main(){
    struct Room room;
    roomdetails(&room, 101, 100, 'D', 1);
    displayroomdetails(&room);
    FILE *infile = fopen("rooms.txt", "r");
    if (!infile) {
        perror("error");
        return 1;
    }
    char line[100];
    while (fgets(line, sizeof(line), infile)!= 0){ 
        printf("%s", line);
    }
    fclose(infile);
   struct Room rooms[100];
   //add cases from here   
   int bookroom;
   printf("enter room that you want to book\n");
   scanf("%d",&bookroom);
int flag = 0,pass;   
int num = getroomdetailsfromfile(rooms);
for(int i = 0; i < num; i++){
    if(rooms[i].roomnum == bookroom && rooms[i].isavailable == 1){
    	printf("set up password for the room\n");
    	scanf("%d",&pass);
    	rooms[i].isavailable = pass; 
    	printf("room booked successfully\n");
    	storeroomdetailsinfile(rooms);
    	flag = 1;
    	break;
    	}
}
if(flag == 0){
printf("either room is not available or doesnt exist\n");
    }  
   printf("enter room that you want to check out of\n");
   scanf("%d",&bookroom);    
flag = 0;   
for(int i = 0; i < num; i++){
    if(rooms[i].roomnum == bookroom && rooms[i].isavailable != 1){
    	printf("enter password\n");
    	scanf("%d",&pass);
    	if(pass == rooms[i].isavailable){
    	rooms[i].isavailable = 1; 
    	printf("room checked out of successfully\n");
    	storeroomdetailsinfile(rooms);
    	flag = 1;
    	break;
    	}
    }
}
if(flag == 0){
printf("either room is vacant,doesnt exist or tou put the wrong password\n");
    }      
    return 0;
}
