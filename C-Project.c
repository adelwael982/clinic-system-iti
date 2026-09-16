/*********************LIBARARIES************************/
#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"

/*********************PARAMETERS************************/
#define ADMIN_MODE     1
#define USER_MODE      2

/*********************STRUCTS************************/
typedef struct patient{
	u8 *name;
	u8 age;
	u32 ID;
	u8 *gender;
	struct patient * NEXT;
	
}pat;


typedef struct reserve{
	u8 time;
	pat *node;
	struct reserve *NEXT;
}res;


/*********************GLOBAL************************/
pat *head=NULL;
res *res_head=NULL;


/*********************FUNCTIONS************************/


//Create the Patient's Data

pat* created_node(u8 *name, u8 age, u32 ID, u8 *gender){
    pat *temp;
    pat *temp2;

    temp2 = (pat*) malloc(sizeof(pat));
    if(temp2==NULL){         
        printf("Full Memory\n");
        return NULL;
    }

    if(head==NULL){
        head=temp2;            
        temp2->name=name;
        temp2->age=age;
        temp2->ID=ID;
        temp2->gender=gender;
        temp2->NEXT=NULL;
	    printf("Succesfully created the patient\n");			
        return temp2;           
    }

    temp=head;   

    while(1){
        if(temp->ID==ID){       
            printf("The ID exists\n");
            free(temp2);
            return NULL;
			break;
        }
        else if(temp->NEXT==NULL){ 
                                   
            temp2->name=name;
            temp2->age=age;
            temp2->ID=ID;
            temp2->gender=gender;
            temp2->NEXT=NULL;  
            temp->NEXT=temp2; 
	    printf("Succesfully created the patient\n");			                               
            break;
        }
        else{
            temp=temp->NEXT;
        }
    }

    return temp2;
}



//Edit The Patients Data

pat* edit_node(u8 *name, u8 age, u32 ID, u8 *gender){
    pat *temp;
	
	temp=head;

    if(head==NULL){
       printf("There is no data\n");
       return NULL;       
    }   

    while(1){
        if(temp->ID==ID){       
            temp->name=name;
            temp->age=age;
            temp->ID=ID;
            temp->gender=gender;
			printf("Succesfully edited the patient\n");
            return temp;
			break;
        }
        else if(temp==NULL){ 
            printf("This Id doesn't exist");   
            return	NULL;		
            break;
        }
        else{
            temp=temp->NEXT;
        }
    }

    return temp;
}



//Delete reservation

void delete_res_node(u32 ID){
    res *temp;
    res *prev;

    temp=res_head;
    prev=NULL;

    while(1){
        if(res_head==NULL){
            printf("There is no reservations\n");
            break;
        }
        if(temp==NULL){                  
            printf("Invalid ID\n");
            break;
        }
        if(temp->node->ID==ID){
            if(prev==NULL) res_head=temp->NEXT;
            else prev->NEXT=temp->NEXT;
            free(temp);
            printf("The reservation was removed successfully\n");
            break;
        }
        else{
            prev=temp;
            temp=temp->NEXT;
        }
    }
}



//Print The Patient's Data

void print_node(u32 ID){
	pat*temp;
	
	temp=head;
	while(1){
		
	//check if there is a list	
	if(head==NULL){
	 printf("List is empty \n");
	 break;
	 }
	 //if the id doesn't exist
	if(temp==NULL)
	{
		printf("Invalid ID\n");
		break;
	}
	//print the data if the id is found 
	if(temp->ID==ID){
	 printf("The ID is %lu\n",temp->ID);
	 printf("The name is %s\n",temp->name);
	 printf("The age is %lu\n",temp->age);
	 printf("The gender is %s\n",temp->gender);
	 break;
	}
	
	//move to the next node 
    else 
	{
		temp=temp->NEXT;
	}
}
}



//Reserve time for the patient

res* reserve_time(u32 ID,u8 time){
	res *temp_res;//goes through the whole reservation list
	res *temp_res2;//points to the desired pointer
	pat *temp;//the pointer to the patient which the reversed time will have
	
	
	temp_res2=(res*) malloc (sizeof(res));
	temp=head;
	temp_res=res_head;
	
	if(temp_res2==NULL){
	printf("Memory is full\n");
    return NULL;	
	}
	
    else if(head==NULL){
        printf("There are no patients\n");
		free(temp_res2);
        return NULL;
    }
	
    else if(time<1 || time>5){        
        printf("Invalid time\n");
		free(temp_res2);
        return NULL;
    }


    //ID Loop
    while(1){                                            
        if(temp==NULL){           
            printf("This ID doesn't exist\n");
		     free(temp_res2);
            return NULL;
        }
        if(temp->ID==ID){
            break;                  
        }
        temp=temp->NEXT;
    }
	
	
	//Reservation loop
    temp_res=res_head;  
    while(1){             
        if(temp_res==NULL){
            break;         
        }
        if(temp_res->node->ID==ID){
            printf("A reservation already exists for this ID\n");
			free(temp_res2);
            return NULL;
        }
        if(temp_res->time==time){
            printf("This time slot is already taken\n");
			free(temp_res2);
            return NULL;
        }
        temp_res=temp_res->NEXT;
    }
	
	temp_res2->time=time;
	temp_res2->node=temp;
	temp_res2->NEXT=NULL;
	printf("Succesfully reserved the slot\n");
    if(res_head==NULL){
		res_head=temp_res2;
	}
		
    return temp_res2;
}



//View reservations

void view_reservation_user(void){
		res*temp;
		
	    u8 flag1=0;
		u8 flag2=0;
		u8 flag3=0;
		u8 flag4=0;
		u8 flag5=0;
		
		u32 ID1=0;
		u32 ID2=0;
		u32 ID3=0;
		u32 ID4=0;
		u32 ID5=0;
	temp=res_head;
		
    while(temp!=NULL){
		//check if there is a list	
	 
     if(temp!=NULL)
     {
         	if(temp->time==1){
     		flag1++; ID1=temp->node->ID;   
			}                              
                                            
                                            
        	if(temp->time==2){
     		flag2++; ID2=temp->node->ID;   
			}			
        	if(temp->time==3){
     		flag3++; ID3=temp->node->ID;   
			}
        	if(temp->time==4){
     		flag4++; ID4=temp->node->ID;   
			}
        	if(temp->time==5){
     		flag5++; ID5=temp->node->ID;   
			}
     }
      //move to the next node 
        temp=temp->NEXT;   
                            
                            
                            
	}
	printf("Availble Slots:\n");
	if(flag1!=0){
		printf("Slot 1: 2:00 to 2:30 is reserved by %lu\n",ID1); 
	}                                                            
	else if(flag1==0){                                           
		printf("Slot 1: 2:00 to 2:30\n");                        
	}
	//flag2
		if(flag2!=0){
		printf("Slot 2: 2:30 to 3:00 is reserved by %lu\n",ID2); 
	}
	else if(flag2==0){
		printf("Slot 2: 2:30 to 3:00\n");                        
	}
	//flag3
		if(flag3!=0){
		printf("Slot 3: 3:00 to 3:30 is reserved by %lu\n",ID3); 
	}
	else if(flag3==0){
		printf("Slot 3: 3:00 to 3:30\n");                        
	}
	//flag4
		if(flag4!=0){
		printf("Slot 4: 4:00 to 4:30 is reserved by %lu\n",ID4); 
	}
	else if(flag4==0){
		printf("Slot 4: 4:00 to 4:30\n");                        
	}
	//flag5
		if(flag5!=0){
		printf("Slot 5: 4:30 to 5:00 is reserved by %lu\n",ID5); 
	}
	else if(flag5==0){
		printf("Slot 5: 4:30 to 5:00\n");                        
	}
	
}


void view_reservation_admin(void){
		res*temp;
		
	    u8 flag1=0;
		u8 flag2=0;
		u8 flag3=0;
		u8 flag4=0;
		u8 flag5=0;
		
		u32 ID1=0;
		u32 ID2=0;
		u32 ID3=0;
		u32 ID4=0;
		u32 ID5=0;
	temp=res_head;
		
    while(temp!=NULL){
		//check if there is a list	
	 
     if(temp!=NULL)
     {
         	if(temp->time==1){
     		flag1++; ID1=temp->node->ID;   
			}                              
                                            
                                            
        	if(temp->time==2){
     		flag2++; ID2=temp->node->ID;   
			}			
        	if(temp->time==3){
     		flag3++; ID3=temp->node->ID;   
			}
        	if(temp->time==4){
     		flag4++; ID4=temp->node->ID;   
			}
        	if(temp->time==5){
     		flag5++; ID5=temp->node->ID;   
			}
     }
      //move to the next node 
        temp=temp->NEXT;   
                            
                            
                            
	}
	printf("Availble Slots:\n");                                                           
	if(flag1==0){                                           
		printf("Slot 1: 2:00 to 2:30\n");                        
	}
	//flag2
	if(flag2==0){
		printf("Slot 2: 2:30 to 3:00\n");                        
	}
	//flag3
	if(flag3==0){
		printf("Slot 3: 3:00 to 3:30\n");                        
	}
	//flag4
	if(flag4==0){
		printf("Slot 4: 4:00 to 4:30\n");                        
	}
	//flag5
	if(flag5==0){
		printf("Slot 5: 4:30 to 5:00\n");                        
	}
	
}


void main(void){
	u8 choice_m;
	u8 choice_a;
	u8 choice_u;
	
	u8 check=0;
	
	u32 ID;
	u8 name[20];
	u8 age;
	u8 gender[5];
	u8 time;
	
	u32 passcode;
	 while(1){
		 
		printf("////////////////////////////////////////////////\n");
		 printf("Choose the setting\n");
		 printf("1: Admin Mode\n");
		 printf("2: User Mode\n");
		 scanf("%hhu",&choice_m);
		 printf("////////////////////////////////////////////////////\n");
		 //ADMIN MODE
	 if(choice_m==ADMIN_MODE){
	      printf("What is the Password\n");
		  scanf("%lu",&passcode);
		  while(1){
			  
			  
		   	 //Incorrect password
            if(passcode!=1234) {
        	 if(check==2){
        		 printf("You finished the number of trials try again later\n");
        		 break;
        	 }
        	 else{
        		 printf("Incorrect passwaord you have %d more trials\n",2-check);
        		 check++;
				 printf("What is the Password\n");
                scanf("%lu", &passcode);  
        	 } 
        }
	 
			  //CORRECT CODE
		  else {
		printf("/////////////////////////////////////////////////\n");
		 printf("Which operation do u want to perform\n");
		 printf("1: Create a patient\n");
		 printf("2: Edit the patient\n");
		 printf("3: Create a reservation\n");
		 printf("4: Cancel the reservation\n");
		 printf("5: Exit Admin Mode\n");
		 scanf("%hhu",&choice_a);
		 
		 
		 
		 //CREATE A PATIENT
		 if (choice_a ==1){
          printf("What is the ID\n");
          scanf("%lu",&ID);	
          printf("What is the name\n");
          scanf("%s",name);
          printf("What is the age\n");
          scanf("%hhu",&age);
          printf("What is the gender\n");
          scanf("%s",gender);	
         

         created_node(name,age,ID,gender);		 
		 } 
		 
		 
		 //EDIT THE PATIENT
		 else if(choice_a==2){   
		  printf("What is the ID\n");
          scanf("%lu",&ID);	
          printf("What is the new name\n");
          scanf("%s",name);
          printf("What is the new age\n");
          scanf("%hhu",&age);
          printf("What is the new gender\n");
          scanf("%s",gender);	
         

         edit_node(name,age,ID,gender);
		 }
		 
		 
		 //RESERVE A TIME SLOT
		 else if(choice_a==3) {
			 view_reservation_admin();
			 printf("Please enter the ID that has the reservation\n");
			 scanf("%lu",&ID);
			 printf("Please choose a slot\n");
			 scanf("%hhu",&time);
			 
			 
			 reserve_time(ID,time);
		 }	 
          
		  else if(choice_a==4){
			  printf("Please enter the ID that you will cancel the reservation for\n");
			  scanf("%lu",&ID);
			  
			  delete_res_node(ID);
			  view_reservation_admin();
		  }
         
		 else if(choice_a==5)  break;
		 
		 else printf("Invalid choice");
  
	 }
	 

	 
	 
}

	 }
	 
	 
	 if(choice_m==USER_MODE){
		 while(1){
		printf("////////////////////////////////////////////////\n");
		 printf("Choose the Mode\n");
		 printf("1: View Patient\n");
		 printf("2: Show all reservations\n");
		 printf("3: Exit User Mode\n");
		 scanf("%hhu",&choice_u);
        
        if(choice_u==1){
			printf("What is the ID of the patient");
			scanf("%lu",&ID);
			print_node(ID);
		}	
        
        else if (choice_u==2){
			view_reservation_user();
		}	

        else if (choice_u==3){
			break;
		}
        
        else printf("Invalid Mode");		
	 }
	 
	 
}
	 }
}