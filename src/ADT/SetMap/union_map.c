/*
NIM             : 18221068
Nama            : Oncar Awwalu Rozaqy
Tanggal         : 31 Oktober 2022
Topik praktikum : Set dan Map
Deskripsi       : implementasi union_map.h
*/

#include <stdio.h>
#include "union_map.h"
#include "boolean.h"

Map UnionMap(Map m1, Map m2, boolean key_based ){
	Map m3;
	CreateEmpty(&m3);
	for(int i=0; i<m1.Count ; i++){
		Insert(&m3,m1.Elements[i].Key,m1.Elements[i].Value);
	}
	for(int j=0; j<m2.Count ; j++){
		Insert(&m3,m2.Elements[j].Key,m2.Elements[j].Value);
	}
	if (key_based) {
		for (int k=0 ; k<m3.Count-1 ; k++){
			for (int l=k+1; l<m3.Count ; l++){	
				if (m3.Elements[k].Key>m3.Elements[l].Key){
					infotype temp;
					temp=m3.Elements[k];
					m3.Elements[k]=m3.Elements[l];
					m3.Elements[l]=temp;
				}
			}
		}
	}
	else{
		for (int k=0 ; k<m3.Count-1 ; k++){
			for (int l=k+1; l<m3.Count ; l++){	
				if (m3.Elements[k].Value>m3.Elements[l].Value){
					infotype temp;
					temp=m3.Elements[k];
					m3.Elements[k]=m3.Elements[l];
					m3.Elements[l]=temp;
				}
				else if (m3.Elements[k].Value==m3.Elements[l].Value) {
					if (m3.Elements[k].Key>m3.Elements[l].Key){
						infotype temp;
						temp=m3.Elements[k];
						m3.Elements[k]=m3.Elements[l];
						m3.Elements[l]=temp;
					}
				}
			}
		}		
	}
	return m3;
}
