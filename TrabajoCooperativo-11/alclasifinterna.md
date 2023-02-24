
#	ALGORITMOS DE CLASIFICACIÓN INTERNA (C)
```c
#define MAX 1000

typedef struct{
	int clave;
	/*resto de componentes*/
} tipo_elemento;
typedef tipo_elemento tipo_vector[MAX];
```

- Inserción Directa.
```c
void insercion(tipo_vector a,int n){
  int i,j;
  tipo_elemento x;

  for (i=1;i<n;++i){
      x=a[i];
      j=i-1;
      while ((j>=0)&&(x.clave<a[j].clave)){
        a[j+1]=a[j];
        j=j-1;
      }
      a[j+1]=x;
  }
}
```

- Inserción Directa (con búsqueda binaria de posición de inserción).

```c
void insercion_b(tipo_vector a,int n){
  int i,j,izq,der,med;
  tipo_elemento x;
  for(i=1;i<n;i++){
     x=a[i];
     izq=0;
     der=i-1;
     while (izq<=der){
        med=(izq+der)/2;
        if (x.clave<a[med].clave)
           der=med-1;
	else izq=med+1;
     }
     for (j=i-1;j>=izq;--j)
        a[j+1]=a[j];
     a[izq]=x;
   }
}
```
 
- Selección Directa.

```c
void seleccion(tipo_vector a,int n){
  int i,j;
  tipo_elemento x;
  int k;           /* posicion de insercion */
  for (i=0;i<n-1;++i){
     k=i;
     for (j=i+1;j<n;++j)
        if (a[j].clave < a[k].clave)
           k=j;
     x=a[k];
     a[k]=a[i];
     a[i]=x;
  }
}
```

- Intercambio Directo (Burbuja).

```c
void burbuja(tipo_vector a,int n){
  int i,j;
  tipo_elemento x;

  for (i=1;i<n;i++)
     for (j=n-1;j>=i;j--)
        if (a[j].clave<a[j-1].clave){
           x=a[j];
           a[j]=a[j-1];
           a[j-1]=x;
        }
}
```

- Intercambio Directo mejorado I.

```c
void burbuja_2(tipo_vector a,int n){
  int i,j;
  tipo_elemento x;
  int ordenado;

  i=1;
  ordenado=0;
  while (!ordenado){
      ordenado=1;;
      for (j=n-1;j>=i;j--)
         if (a[j].clave<a[j-1].clave){
            x=a[j];
            a[j]=a[j-1];
            a[j-1]=x;
            ordenado=0;
         }
      i++;
  }
}
 
- Intercambio Directo mejorado II.
```c
void burbuja_3(tipo_vector a,int n){
  int i,j,k;
  tipo_elemento x;

  i=1;
  while (i<n){
     k=n-1;
     for (j=n-1;j>=i;--j)
        if (a[j].clave<a[j-1].clave){
           x=a[j];
           a[j]=a[j-1];
           a[j-1]=x;
           k=j;
        }
     i=k+1;
  }
}
```

- Intercambio Directo mejorado III (sacudida).

```c
void sacudida(tipo_vector a,int n){
  int k,j,izq,der;
  tipo_elemento x;

  izq=1;
  der=n-1;
  k=n-1;
  while (izq<=der){
     for (j=der;j>=izq;--j)
        if (a[j].clave<a[j-1].clave){
           x=a[j];
           a[j]=a[j-1];
           a[j-1]=x;
           k=j;
        }
     izq=k+1;
     for (j=izq;j<=der;++j)
        if (a[j].clave<a[j-1].clave){
           x=a[j];
           a[j]=a[j-1];
           a[j-1]=x;
           k=j;
        }
     der=k-1;
  }
}
```


 
- Inserción con Incrementos Decrecientes (D.L. Shell).
```c
void shell(tipo_vector a,int n){
  int i,j,incremento;
  tipo_elemento x;

  incremento=n/2;
  while (incremento>0){
     for (i=incremento;i<n;++i){
        x=a[i];
        j=i-incremento;
        while ((j>=0)&&(x.clave<a[j].clave)){
            a[j+incremento]=a[j];
            j=j-incremento;
        }
        a[j+incremento]=x;
     }
     incremento=incremento/2;
  }
}

- Inserción con Incrementos Decrecientes (D.L. Shell) se usa una secuencia diferente de incrementos decrecientes.
```c
void shell_2(tipo_vector a,int n){
  int i,j,k,t,incremento;
  tipo_elemento x;
  int h[50];

  t=(log(n)/log(2))-1;
  h[t-1]=1;
  for (k=t-2;k>=0;--k)
     h[k]=2*h[k+1]+1;
  for (k=0;k<t;++k){
     incremento=h[k];
     for (i=incremento;i<n;++i){
        x=a[i];
        j=i-incremento;
        while ((j>=0)&&(x.clave<a[j].clave)){
            a[j+incremento]=a[j];
            j=j-incremento;
        }
        a[j+incremento]=x;
     }
  }
}
```
 
- Método del montículo (“Heapsort”).
```c
void criba(tipo_vector a,int izq,int der){
  int i,j;
  tipo_elemento x;
  int cribado;

  i=izq;
  j=2*i;
  x=a[i];
  cribado=0;
  while ((j<=der)&&(!cribado)){
     if (j<der)
       if (a[j].clave<a[j+1].clave)
         j=j+1;
     if (x.clave>=a[j].clave)
       cribado=1;
     else{ a[i]=a[j];  /*criba por hundimiento*/
           i=j;
           j=2*i;
     }
  }
  a[i]=x;
}


void heapsort(tipo_vector a,int n){
  int izq,der;
  tipo_elemento x;

  izq=n/2;
  der=n-1;
  while (izq>0){
     izq=izq-1;
     criba(a,izq,der);
  }
  while (der>0){
     x=a[0];
     a[0]=a[der];
     a[der]=x;
     der=der-1;
     criba(a,izq,der);
  }
}
```
 
- Método Rápido (“Quicksort”) versión recursiva
```c
void sort(tipo_vector a,int izq,int der){
  int i,j;
  tipo_elemento x,w;

  i=izq;
  j=der;
  x=a[(izq+der)/2];
  while (i<=j){
     while (a[i].clave<x.clave)
        ++i;
     while (x.clave<a[j].clave)
        --j;
     if (i<=j){
        w=a[i];
        a[i]=a[j];
        a[j]=w;
        ++i;
        --j;
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
```
 
- Método Rápido (“Quicksort”) versión no recursiva
```c
void quicksort_pila(tipo_vector a,int n){
#define max 12
  int i,j,izq,der;
  tipo_elemento x,w;
  int cima;
  struct { int izq;
           int der;
  } pila[max];

  cima=0;
  pila[0].izq=0;
  pila[0].der=n-1;
  while (cima>=0){      /* tomar la demanda superior de la pila */
     izq=pila[cima].izq;
     der=pila[cima].der;
     cima=cima-1;
     while (izq<der){   /* subdivision de a[izq]..a[der] */
        i=izq;
        j=der;
        x=a[(izq+der)/2];
        while (i<=j){
           while (a[i].clave<x.clave)
              ++i;
           while (x.clave<a[j].clave)
              --j;
           if (i<=j){
              w=a[i];
              a[i]=a[j];
              a[j]=w;
              ++i;
              --j;
           }
        }
        if ((j-izq)<(der-i)){
           if (i<der){
              cima=cima+1;
              pila[cima].izq=i;
              pila[cima].der=der;
           }
           der=j;
        }else{ if (j>izq){
                   cima=cima+1;
                   pila[cima].izq=izq;
                   pila[cima].der=j;
               }
               izq=i;
        }
     }
  }
}
```
