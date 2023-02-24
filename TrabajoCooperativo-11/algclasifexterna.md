# ALGORITMOS DE CLASIFICACIÓN EXTERNA (C)

```c
#define MAX 10        /* número de registros en MC para algoritmo MSE */

typedef int tipo_clave;
typedef struct{
            tipo_clave clave;
            /* otros campos */
        } tipo_componente;
typedef tipo_componente tipo_vector[MAX];


/*****************************************************************/
/******************** Mezcla Directa *****************************/
/*****************************************************************/
/* Prototipos de funciones */
void clasificacion_md(char *nombre);
void particion_tramos(char *archi,char *temp1,char *temp2,long n);
void fusion_tramos(char *archi,char *temp1,char *temp2,long n);
long tamano_archivo(char *nombre);

/* Definiciones de funciones */
void clasificacion_md(char *nombre){
      char tempo1[]="tempo1.dat";
      char tempo2[]="tempo2.dat";
      long tamano;
      long n;

      n=1;
      tamano=tamano_archivo(nombre);
      while (n<tamano){
		 particion_tramos(nombre,tempo1,tempo2,n);
		 remove(nombre);
		 fusion_tramos(nombre,tempo1,tempo2,n);
             remove(tempo1);
             remove(tempo2);
             n=n*2;
	}
}

void particion_tramos(char *archi,char *temp1,char *temp2,long n){
      FILE *f,*f1,*f2;
	tipo_componente ventana;
	int cont;
	int conmutador;

	f=fopen(archi,"rb");
	f1=fopen(temp1,"wb");
	f2=fopen(temp2,"wb");
	cont=0;
	conmutador=1;
	fread(&ventana,sizeof(tipo_componente),1,f);
	while (!feof(f)){
		if (conmutador)
		     fwrite(&ventana,sizeof(tipo_componente),1,f1);
		else fwrite(&ventana,sizeof(tipo_componente),1,f2);
		cont++;
		if (cont==n){
		     conmutador=!conmutador;
		     cont=0;
		}
		fread(&ventana,sizeof(tipo_componente),1,f);
	}
	fclose(f);
	fclose(f1);	fclose(f2);
}

long tamano_archivo(char *nombre){
      FILE *f;
	long cont;
	tipo_componente ventana;

	f=fopen(nombre,"rb");
	cont=0;
	fread(&ventana,sizeof(tipo_componente),1,f);
	while(!feof(f)){
		++cont;
		fread(&ventana,sizeof(tipo_componente),1,f);
	}
	fclose(f);
	return (cont);
}

void fusion_tramos(char *archi,char *temp1,char *temp2,long n){
      FILE *f,*f1,*f2;
      tipo_componente ventana1,ventana2;
      int cont1,cont2;

      cont1=0;
      cont2=0;
      f=fopen(archi,"wb");
      f1=fopen(temp1,"rb");
      f2=fopen(temp2,"rb");
      fread(&ventana1,sizeof(tipo_componente),1,f1);
      fread(&ventana2,sizeof(tipo_componente),1,f2);
      while ((!feof(f1))&&(!feof(f2))){
            if (ventana1.clave<=ventana2.clave){
                fwrite(&ventana1,sizeof(tipo_componente),1,f);
	   	    cont1++;
                fread(&ventana1,sizeof(tipo_componente),1,f1);
                if (cont1==n){
                    cont1=0;
                    fwrite(&ventana2,sizeof(tipo_componente),1,f);
                    cont2++;
                    fread(&ventana2,sizeof(tipo_componente),1,f2);
                    while ((!feof(f2))&&(cont2<n)){
                           fwrite(&ventana2,sizeof(tipo_componente),1,f);
                           cont2++;
                           fread(&ventana2,sizeof(tipo_componente),1,f2);
                    }
                    cont2=0;
                }
            }else{
                fwrite(&ventana2,sizeof(tipo_componente),1,f);
                cont2++;
                fread(&ventana2,sizeof(tipo_componente),1,f2);
		    if (cont2==n){
                    cont2=0;
                    fwrite(&ventana1,sizeof(tipo_componente),1,f);
                    cont1++;
                    fread(&ventana1,sizeof(tipo_componente),1,f1);
                    while ((!feof(f1))&&(cont1<n)){
                           fwrite(&ventana1,sizeof(tipo_componente),1,f);
                           cont1++;
                           fread(&ventana1,sizeof(tipo_componente),1,f1);
                    }
                    cont1=0;
                }
            }
      }
      while(!feof(f1)){
            fwrite(&ventana1,sizeof(tipo_componente),1,f);
            fread(&ventana1,sizeof(tipo_componente),1,f1);
      }
	while(!feof(f2)){
            fwrite(&ventana2,sizeof(tipo_componente),1,f);
            fread(&ventana2,sizeof(tipo_componente),1,f2);
      }
      fclose(f);
      fclose(f1);
      fclose(f2);
}


 
/*****************************************************************/
/******************** Mezcla Natural *****************************/
/*****************************************************************/
/* Prototipos de funciones */
void clasificacion_mn(char *nombre);
void particion_tramos_variables(char *archi,char *temp1,char *temp2,
                                int *n);
void fusion_tramos_variables(char *archi,char *temp1,char *temp2);

/* Definiciones de funciones */
void clasificacion_mn(char *nombre){
      char tempo1[]="tempo1.dat";
	char tempo2[]="tempo2.dat";

      int n;
      n=1;
	while (n>0){
		 particion_tramos_variables(nombre,tempo1,tempo2,&n);
             if (n>0){
                 remove(nombre);
                 fusion_tramos_variables(nombre,tempo1,tempo2);
             }
             remove(tempo1);
             remove(tempo2);
      }
}

void particion_tramos_variables(char *archi,char *temp1,char *temp2,
                                int *n){
      FILE *f,*f1,*f2;
      tipo_componente ventana,ventana_ant;
      int conmutador;

f=fopen(archi,"rb");
	f1=fopen(temp1,"wb");
	f2=fopen(temp2,"wb");
	*n=0;
	conmutador=1;
	fread(&ventana,sizeof(tipo_componente),1,f);
	ventana_ant=ventana;
	while (!feof(f)){
		if (ventana.clave<ventana_ant.clave)
			conmutador=!conmutador;
		if (conmutador)
	 		 fwrite(&ventana,sizeof(tipo_componente),1,f1);
		else { fwrite(&ventana,sizeof(tipo_componente),1,f2);
			 *n=*n+1;
		}
		ventana_ant=ventana;
		fread(&ventana,sizeof(tipo_componente),1,f);
	}
	fclose(f);
	fclose(f1);
	fclose(f2);
}
 
void fusion_tramos_variables(char *archi,char *temp1,char *temp2){
      FILE *f,*f1,*f2;
      tipo_componente ventana1,ventana2;
      tipo_componente vent1_ant,vent2_ant;

      f=fopen(archi,"wb");
      f1=fopen(temp1,"rb");
      f2=fopen(temp2,"rb");
      fread(&ventana1,sizeof(tipo_componente),1,f1);
      vent1_ant=ventana1;
      fread(&ventana2,sizeof(tipo_componente),1,f2);
      vent2_ant=ventana2;
      while ((!feof(f1))&&(!feof(f2)))
         if (ventana1.clave<=ventana2.clave){
             fwrite(&ventana1,sizeof(tipo_componente),1,f);
             vent1_ant=ventana1;
             fread(&ventana1,sizeof(tipo_componente),1,f1);
             if ((!feof(f1))&&(ventana1.clave<vent1_ant.clave)){
                 fwrite(&ventana2,sizeof(tipo_componente),1,f);
		     vent2_ant=ventana2;
                 fread(&ventana2,sizeof(tipo_componente),1,f2);
                 while ((!feof(f2))&&(ventana2.clave>=vent2_ant.clave)){
                      fwrite(&ventana2,sizeof(tipo_componente),1,f);
                      vent2_ant=ventana2;
                      fread(&ventana2,sizeof(tipo_componente),1,f2);
                 }
             }
         }else{
             fwrite(&ventana2,sizeof(tipo_componente),1,f);
             vent2_ant=ventana2;
             fread(&ventana2,sizeof(tipo_componente),1,f2);
             if ((!feof(f2))&&(ventana2.clave<vent2_ant.clave)){
                 fwrite(&ventana1,sizeof(tipo_componente),1,f);
                 vent1_ant=ventana1;
                 fread(&ventana1,sizeof(tipo_componente),1,f1);
                 while ((!feof(f1))&&(ventana1.clave>=vent1_ant.clave)){
                      fwrite(&ventana1,sizeof(tipo_componente),1,f);
			    vent1_ant=ventana1;
                      fread(&ventana1,sizeof(tipo_componente),1,f1);
                 }
             }
         }
      while(!feof(f1)){
            fwrite(&ventana1,sizeof(tipo_componente),1,f);
            fread(&ventana1,sizeof(tipo_componente),1,f1);
      }
      while(!feof(f2)){
            fwrite(&ventana2,sizeof(tipo_componente),1,f);
            fread(&ventana2,sizeof(tipo_componente),1,f2);
      }
      fclose(f);
      fclose(f1);
      fclose(f2);
}

 
/*****************************************************************/
/*************** Mezcla de Secuencias Equilibradas ***************/
/*****************************************************************/
/* Prototipos de funciones */
void clasificacion_mse(char *nombre);
void primera_particion(char *nombre,char *nombre1,char *nombre2);
void cargar_vector(FILE *f, tipo_vector a,int *n);
void grabar_vector(FILE *f,tipo_vector a,int n);
void quicksort(tipo_vector a,int n);
void sort(tipo_vector a,int izq,int der);
void fusion_particion(char *nombre1,char *nombre2,char *temp1,
                      char *temp2, int n);
void grabar_registro(FILE *f_v,FILE *f_f,int conmutador,
                     tipo_componente ventana);

/* Definiciones de funciones */
void clasificacion_mse(char *nombre){
	char tempo1[]="tempo1.dat";
	char tempo2[]="tempo2.dat";
	char tempo3[]="tempo3.dat";
	char tempo4[]="tempo4.dat";
	long tamano;
	int n;
	int conmutador;

	tamano=tamano_archivo(nombre);
	primera_particion(nombre,tempo1,tempo2);
	n=MAX;
	conmutador=1;
	while (n<tamano){
		 if (conmutador){
			  fusion_particion(tempo1,tempo2,tempo3,tempo4,n);
			  remove(tempo1);
			  remove(tempo2);
		 }else{ fusion_particion(tempo3,tempo4,tempo1,tempo2,n);
			  remove(tempo3);
			  remove(tempo4);
		 }
		 conmutador=!conmutador;
		 n=n*2;
	}
	remove(nombre);
	if (conmutador){
		 rename(tempo1,nombre);
		 remove(tempo2);
	}else{ rename(tempo3,nombre);
		 remove(tempo4);
	}
}

void primera_particion(char *nombre,char *nombre1,char *nombre2){
	FILE *f,*f1,*f2;
	tipo_vector a;
	int n;
	int conmutador;

	f=fopen(nombre,"rb");
	f1=fopen(nombre1,"wb");
	f2=fopen(nombre2,"wb");
	cargar_vector(f,a,&n);
	conmutador=1;
	while (n>0){
		quicksort(a,n);
		if (conmutador)
		  grabar_vector(f1,a,n);
		else grabar_vector(f2,a,n);
		conmutador=!conmutador;
		cargar_vector(f,a,&n);
	}
	fclose(f);
	fclose(f1);
	fclose(f2);
}

void cargar_vector(FILE *f, tipo_vector a,int *n){
      tipo_componente ventana;

      *n=0;
      fread(&ventana,sizeof(tipo_componente),1,f);
      while ((!feof(f))&&((*n)<MAX)){
         a[*n]=ventana;
         (*n)++;
         if ((*n)<MAX)
             fread(&ventana,sizeof(tipo_componente),1,f);
      }
}

void grabar_vector(FILE *f,tipo_vector a,int n){
      int i;

	for(i=0;i<n;++i)
          fwrite(&a[i],sizeof(tipo_componente),1,f);
}


void sort(tipo_vector a,int izq,int der){
     int i,j;

     tipo_componente x,w;
     i=izq;
     j=der;
     x=a[(izq+der)/2];
     while (i<=j){
         while (a[i].clave<x.clave)
             i++;
         while (x.clave<a[j].clave)
             j--;
         if (i<=j){
             w=a[i];
             a[i]=a[j];
             a[j]=w;
             i++;
             j--;
         }
     }
     if (izq<j)
        sort(a,izq,j);
     if (i<der)
        sort(a,i,der);
}

void quicksort(tipo_vector a,int n){
     sort(a,0,n-1);
}


void fusion_particion(char *nombre1,char *nombre2,char *temp1,
							 char *temp2, int n){
	FILE *f1,*f2,*f3,*f4;
	tipo_componente ventana1,ventana2;
	int conmutador;
	int cont1,cont2;

	cont1=0;
	cont2=0;
	f1=fopen(nombre1,"rb");
	f2=fopen(nombre2,"rb");
	f3=fopen(temp1,"wb");
	f4=fopen(temp2,"wb");
	conmutador=1;
	fread(&ventana1,sizeof(tipo_componente),1,f1);
	fread(&ventana2,sizeof(tipo_componente),1,f2);
	while((!feof(f1))&&(!feof(f2))){
	  if (ventana1.clave<=ventana2.clave){
		grabar_registro(f3,f4,conmutador,ventana1);
		cont1++;
		fread(&ventana1,sizeof(tipo_componente),1,f1);
		if (cont1==n){
			cont1=0;
			grabar_registro(f3,f4,conmutador,ventana2);
			cont2++;
                  fread(&ventana2,sizeof(tipo_componente),1,f2);
                  while ((!feof(f2))&&(cont2<n)){
                        grabar_registro(f3,f4,conmutador,ventana2);
                        cont2++;
                        fread(&ventana2,sizeof(tipo_componente),1,f2);
                  }
                  cont2=0;
                  conmutador=!conmutador;
            }
	  }else{
            grabar_registro(f3,f4,conmutador,ventana2);
            cont2++;
            fread(&ventana2,sizeof(tipo_componente),1,f2);
            if (cont2==n){
                  cont2=0;
                  grabar_registro(f3,f4,conmutador,ventana1);
                  cont1++;
                  fread(&ventana1,sizeof(tipo_componente),1,f1);
                  while ((!feof(f1))&&(cont1<n)){
                        grabar_registro(f3,f4,conmutador,ventana1);
                        cont1++;
                        fread(&ventana1,sizeof(tipo_componente),1,f1);
                  }
                  cont1=0;
                  conmutador=!conmutador;
             }
        }
	}
      while(!feof(f1)){
            grabar_registro(f3,f4,conmutador,ventana1);
            cont1++;
            if (cont1==n){
               conmutador=!conmutador;
               cont1=0;
            }
            fread(&ventana1,sizeof(tipo_componente),1,f1);
      }
      while(!feof(f2)){
            grabar_registro(f3,f4,conmutador,ventana2);
            cont2++;
            if (cont2==n){
                conmutador=!conmutador;
                cont2=0;
            }
            fread(&ventana2,sizeof(tipo_componente),1,f2);
		}
      fclose(f1);
      fclose(f2);
      fclose(f3);
      fclose(f4);
}

void grabar_registro(FILE *f_v,FILE *f_f,int conmutador,
                     tipo_componente ventana){
    if (conmutador)
         fwrite(&ventana,sizeof(tipo_componente),1,f_v);
    else fwrite(&ventana,sizeof(tipo_componente),1,f_f);
}
```



