#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	Queue input , time ;
	ElType sajian , waktu ;
	ElType nMasakan = 0;
	ElType nMinimal = 0;
	ElType nMaksimal = 0;
	ElType temp = 0;
	CreateQueue(&input);
	CreateQueue(&time);
	scanf("%d",&sajian);
	if (sajian >= 0 && sajian <= 2){
		if (sajian == 0 || sajian == 2){
		printf("%d\n",nMasakan);
		printf("%d\n",nMinimal);
		printf("%d\n",nMaksimal);

		}
		else{
			
			while(sajian != 0){
				if (sajian == 1){
					scanf(" %d",&waktu);
					enqueue(&input,sajian);
					enqueue(&time,waktu);
				}
				else if (sajian == 2 && nMasakan == 0){
					dequeue(&time,&temp);
					nMasakan = nMasakan + 1;

					nMinimal = temp;
					nMaksimal = temp;
				}

				else if (sajian == 2 && nMasakan != 0){
					dequeue(&time,&temp);
					nMasakan = nMasakan + 1;

					if(temp > nMaksimal){
						nMaksimal = temp;
					}
					else if(temp < nMinimal){
						nMinimal = temp;
					}
					}
				scanf("%d",&sajian);
				
			
		}
		printf("%d\n",nMasakan);
		printf("%d\n",nMinimal);
		printf("%d\n",nMaksimal);

	}
	return 0;
}
}