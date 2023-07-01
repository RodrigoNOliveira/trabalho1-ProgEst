#include<stdio.h>
#include<stdlib.h>
#include <time.h>


void converteCinza(FILE *origem,int linhas, int colunas, int vmax){
	FILE *destino;
	int i, j, k, n;
    int matriz[linhas][colunas][3];
    destino = fopen("imgEscCinza.ppm", "w");
	fprintf(destino, "P3\n");
    fprintf(destino, "#Atividade 1\n");
    fprintf(destino, "%d %d\n", colunas, linhas);
    fprintf(destino, "%d\n", vmax);
        for(i=0; i<linhas;i++){
            for(j=0;j<colunas;j++){
                n = 0;
                for(k=0; k<3; k++){
				fscanf(origem,"%d", &matriz[i][j][k]);
                    n = n + matriz[i][j][k];
                }
                n = n / 3;
                fprintf(destino, "%d %d %d ", n, n, n);
            }

        }
    
    fclose(destino);
}

void espelhaHorizontal(FILE *origem,int linhas, int colunas, int vmax){
	FILE *destino;
	destino = fopen("imgHorizontal.ppm", "w");
	int i, j, k, n;
    int matriz[linhas][colunas][3];
    	fprintf(destino, "P3\n");
        fprintf(destino, "#Atividade 2\n");
        fprintf(destino, "%d %d\n", colunas, linhas);
        fprintf(destino, "%d\n", vmax);

        for(i=0; i<linhas;i++){
            for(j=0; j <colunas;j++){
                n = 0;
                for(k=0; k<3; k++){
                    fscanf(origem,"%d", &matriz[i][j][k]);
                    n = matriz[i][j*-1][k];
                    fprintf(destino, "%d ", n);
                }
            }

        }
    
    fclose(destino);
}

void espelhaVertical(FILE *origem,int linhas, int colunas, int vmax){
	FILE *destino;
	destino = fopen("imgVertical.ppm", "w");
	int i, j, k, n;
    int matriz[linhas][colunas][3];
    	fprintf(destino, "P3\n");
        fprintf(destino, "#Atividade 3\n");
        fprintf(destino, "%d %d\n", colunas, linhas);
        fprintf(destino, "%d\n", vmax);

        for(i=0; i<linhas;i++){
            for(j=0; j <colunas;j++){
                for(k=0; k<3; k++){	
				fscanf(origem,"%d", &matriz[i][j][k]);
       }
            }

        }
  
        for(i=linhas-1; i>=0;i--){
            for(j=0; j <colunas;j++){
                n = 0;
                for(k=0; k<3; k++){
                n = matriz[i][j][k];
                fprintf(destino, "%d ", n);
       }
            }

        }
    
    fclose(destino);
}

void divideEsqDir(FILE *origem,int linhas, int colunas, int vmax){
	FILE *destino;
	destino = fopen("imgMtdEsq.ppm", "w");
	FILE *destino1;
	destino1 = fopen("imgMtdDir.ppm", "w");
	int i, j, k, n;
    int matriz[linhas][colunas][3];
    	fprintf(destino, "P3\n");
        fprintf(destino, "#Atividade 4\n");
        fprintf(destino, "%d %d\n", colunas/2, linhas);
        fprintf(destino, "%d\n", vmax);
        fprintf(destino1, "P3\n");
        fprintf(destino1, "#Atividade 4\n");
        fprintf(destino1, "%d %d\n", colunas/2, linhas);
        fprintf(destino1, "%d\n", vmax);
        
		for(i=0; i<linhas;i++){
        	for(j=0; j <colunas;j++){
            	for(k =0; k<3;k++){
                	n = 0;
                	fscanf(origem,"%d", &matriz[i][j][k]);
                	if(j<=colunas/2-1){
						n = matriz[i][j][k];
                		fprintf(destino, "%d ", n);
					} else if(j >=colunas/2-1){
                		n = matriz[i][j][k];
                		fprintf(destino1, "%d ", n);
					}
            	}
			}
        } 
    fclose(destino);
    fclose(destino1);
}

void divideSupInf(FILE *origem,int linhas, int colunas, int vmax){
	FILE *destino;
	destino = fopen("imgMtdSup.ppm", "w");
	FILE *destino1;
	destino1 = fopen("imgMtdInf.ppm", "w");
	int i, j, k, n;
    int matriz[linhas][colunas][3];
    	fprintf(destino, "P3\n");
        fprintf(destino, "#Atividade 5\n");
        fprintf(destino, "%d %d\n", colunas, linhas/2);
        fprintf(destino, "%d\n", vmax);
        fprintf(destino1, "P3\n");
        fprintf(destino1, "#Atividade 5\n");
        fprintf(destino1, "%d %d\n", colunas, linhas/2);
        fprintf(destino1, "%d\n", vmax);
        
		for(i=0; i<linhas;i++){
        	for(j=0; j <colunas;j++){
            	for(k =0; k<3;k++){
                	n = 0;
                	fscanf(origem,"%d", &matriz[i][j][k]);
                	if(i<=linhas/2-1){
						n = matriz[i][j][k];
                		fprintf(destino, "%d ", n);
					} else if(i >=linhas/2-1){
                		n = matriz[i][j][k];
                		fprintf(destino1, "%d ", n);
					}
            	}
			}
        } 
    fclose(destino);
    fclose(destino1);
}

void coloreArtificial(FILE *origem,int linhas, int colunas, int vmax){
	FILE *destino;
	destino = fopen("coloridaArtf.ppm", "w");
	FILE *destino1;
	int i, j, k, n, t;
	srand(time(NULL));
    int matriz[linhas][colunas][3];
    	fprintf(destino, "P3\n");
        fprintf(destino, "#Atividade 6\n");
        fprintf(destino, "%d %d\n", colunas, linhas);
        fprintf(destino, "%d\n", vmax);
		int r;
        int g;
        int b;
        
		for(i=0; i<linhas;i++){
            for(j=0;j<colunas;j++){
                n = 0;
                for(k=0; k<3; k++){
				fscanf(origem,"%d", &matriz[i][j][k]);
                    n = n + matriz[i][j][k];
                }
                n = n / 3;
                fprintf(destino, "%d %d %d ", n, n, n);
                t = rand()%6;
                if(t == 0){
                	r=255; g=0;g=0;
                	fprintf(destino, "%d %d %d ", r, g, b);
				} else if(t == 1){
                	r=255; g=255;g=0;
                	fprintf(destino, "%d %d %d ", r, g, b);
				}  else if(t == 2){
                	r=255; g=255;g=255;
                	fprintf(destino, "%d %d %d ", r, g, b);
				}  else if(t == 3){
                	r=255; g=0;g=255;
                	fprintf(destino, "%d %d %d ", r, g, b);
				}  else if(t == 4){
                	r=0; g=255;g=255;
                	fprintf(destino, "%d %d %d ", r, g, b);
				}  else if(t == 5){
                	r=0; g=0;g=255;
                	fprintf(destino, "%d %d %d ", r, g, b);
				} 
                
            }

        }
        
        
		
                
    fclose(destino);
}

void rot90dir(FILE *origem,int linhas, int colunas, int vmax){
	FILE *destino;
	destino = fopen("img90direita.ppm", "w");
	int i, j, k, n;
    int matriz[linhas][colunas][3];
    	fprintf(destino, "P3\n");
        fprintf(destino, "#Atividade 7\n");
        fprintf(destino, "%d %d\n", colunas, linhas);
        fprintf(destino, "%d\n", vmax);

         for(i=0; i<linhas;i++){
            for(j=0; j <colunas;j++){
                for(k=0; k<3; k++){	
				fscanf(origem,"%d", &matriz[i][j][k]);
       }
            }

        }
  
        for(i=0; i<linhas;i++){
            for(j=colunas-1; j>=0;j--){
                n = 0;
                for(k=0; k<3; k++){
                n = matriz[j][i][k];
                fprintf(destino, "%d ", n);
       }
            }

        } 
    fclose(destino);
}

void rot90esq(FILE *origem,int linhas, int colunas, int vmax){
	FILE *destino;
	destino = fopen("img90esquerda.ppm", "w");
	int i, j, k, n;
    int matriz[linhas][colunas][3];
    	fprintf(destino, "P3\n");
        fprintf(destino, "#Atividade 8\n");
        fprintf(destino, "%d %d\n", colunas, linhas);
        fprintf(destino, "%d\n", vmax);

         for(i=0; i<linhas;i++){
            for(j=0; j <colunas;j++){
                for(k=0; k<3; k++){	
				fscanf(origem,"%d", &matriz[i][j][k]);
       }
            }

        }
  
        for(i=linhas-1; i>=0;i--){
            for(j=0; j <colunas;j++){
                n = 0;
                for(k=0; k<3; k++){
                n = matriz[j][i][k];
                fprintf(destino, "%d ", n);
       }
            }

        } 
    fclose(destino);
}

void parteCinza(FILE *origem,int linhas, int colunas, int vmax){
	FILE *destino;
	srand(time(NULL));
	destino = fopen("imgParteCinza.ppm", "w");
	int i, j, k, n, t;
    int matriz[linhas][colunas][3];
    	fprintf(destino, "P3\n");
        fprintf(destino, "#Atividade 9\n");
        fprintf(destino, "%d %d\n", colunas, linhas);
        fprintf(destino, "%d\n", vmax);
	
         for(i=0; i<linhas;i++){
            for(j=0; j <colunas;j++){
            	n = 0;
            	if(i<=linhas/2-1 && j<=colunas/2-1){
            		for(k=0; k<3; k++){	
                	fscanf(origem,"%d", &matriz[i][j][k]);
    					n = n + matriz[i][j][k];
					}
					n= n/3;
				  	fprintf(destino, "%d %d %d ", n,n,n);
				} else{
					for(k=0; k<3; k++){	
    	            fscanf(origem,"%d", &matriz[i][j][k]);
    				n = matriz[i][j][k];
        	        fprintf(destino, "%d ", n);
					}	
				}
			}
		} 
				

  
    fclose(destino);
}

void rgb(FILE *origem,int linhas, int colunas, int vmax){

	FILE *destinoR;
	FILE *destinoG;
	FILE *destinoB;
	destinoR = fopen("imgR.ppm", "w");
	destinoG = fopen("imgG.ppm", "w");
	destinoB = fopen("imgB.ppm", "w");
	int i, j, k, t, r,g,b;
    int matriz[linhas][colunas][3];
    	fprintf(destinoR, "P3\n");
        fprintf(destinoR, "#Atividade 10\n");
        fprintf(destinoR, "%d %d\n", colunas, linhas);
        fprintf(destinoR, "%d\n", vmax);
        
        fprintf(destinoG, "P3\n");
        fprintf(destinoG, "#Atividade 10\n");
        fprintf(destinoG, "%d %d\n", colunas, linhas);
        fprintf(destinoG, "%d\n", vmax);
        
        fprintf(destinoB, "P3\n");
        fprintf(destinoB, "#Atividade 10\n");
        fprintf(destinoB, "%d %d\n", colunas, linhas);
        fprintf(destinoB, "%d\n", vmax);
	
         for(i=0; i<linhas;i++){
            for(j=0; j <colunas;j++){
            	r=0,g=0,b=0;
            	for (k=0; k<3;k++){
            		fscanf(origem,"%d", &matriz[i][j][k]);
				}
    					r = matriz[i][j][0];
    					g = 0;
    					b = 0;
				  	fprintf(destinoR, "%d %d %d ", r,g,b);
			}
		} 
		for(i=0; i<linhas;i++){
            for(j=0; j <colunas;j++){
            	for (k=0; k<3;k++){
            		fscanf(origem,"%d", &matriz[i][j][k]);
				}
            	r=0,g=0,b=0;
    					r = 0;
    					g =  matriz[i][j][1];
    					b = 0;
				  	fprintf(destinoG, "%d %d %d ", r,g,b);
			}
		} 
		for(i=0; i<linhas;i++){
            for(j=0; j <colunas;j++){
            	for (k=0; k<3;k++){
            		fscanf(origem,"%d", &matriz[i][j][k]);
				}
            	
            	r=0,g=0,b=0;
    					r = 0;
    					g = 0;
    					b =  matriz[i][j][2];
				  	fprintf(destinoB, "%d %d %d ", r,g,b);
			}
		} 
				

  
    fclose(destinoR);
    fclose(destinoG);
    fclose(destinoB);
}

int main(){
    
    int linhas, colunas, vmax;
    int opt;
    char buffer[250];

    
    FILE *origem;
    FILE *cinza;
    origem = fopen("tigre.ppm", "r");
    cinza = fopen("tigre.ppm", "r");
    
    if(origem == NULL || cinza == NULL){
        printf("Erro ao abrir o arquivo.");
        return 1;
    }else{
        fgets(buffer, 250, origem);
        fgets(buffer, 250, origem);
        fscanf(origem, "%d %d", &colunas, &linhas);
        fscanf(origem, "%d", &vmax);
        fgets(buffer, 250, cinza);
        fgets(buffer, 250, cinza);
        fscanf(cinza, "%d %d", &colunas, &linhas);
        fscanf(cinza, "%d", &vmax);
        
        printf("\n>>>>>Tratamento de imagens<<<<<\n\n");
        printf(">>>>>>>>MENU<<<<<<<<\n\n");
        printf("1- Converter uma imagem colorida para escala de cinza\n");
        printf("2- Espelhar uma imagem horizontalmente\n");
        printf("3- Espelhar uma imagem verticalmente\n");
        printf("4- Dividir uma imagem em dois arquivos (um arquivo com a metade esquerda, e outro arquivo com a metade direita)\n");
        printf("5- Dividir uma imagem em dois arquivos (um arquivo com a metade superior, e outro arquivo com a metade inferior)\n");
        printf("6 - Colorir uma imagem artificialmente\n");
        printf("7 - Rotacionar uma imagem 90 graus para a direita\n");
    	printf("8 - Rotacionar uma imagem 90 graus para a esquerda\n");
    	printf("9 - Gerar uma imagem cópia da original, porém com uma parte da imagem em escala de cinza\n");
    	printf("10 - Gerar três arquivos de saída. Um para cada camada (R, G e B)\n");
    
		printf("0- Encerrar Programa\n");
        do{
        printf("\n\nInsira a opção desejada: ");
        scanf("%d", &opt);
        	switch(opt){
        		case 1:
        			converteCinza(cinza, linhas, colunas, vmax);
        			break;
        		case 2:
        			espelhaHorizontal(origem, linhas, colunas, vmax);
        			break;
        		case 3:
        			espelhaVertical(origem, linhas, colunas, vmax);
        			break;
        		case 4:
        			divideSupInf(origem, linhas, colunas, vmax);
        			break;
        		case 5:
        			divideEsqDir(origem, linhas, colunas, vmax);
        			break;
        		
        		case 6:
        			coloreArtificial(origem, linhas, colunas, vmax);
        			break;
        		case 7:
        			rot90dir(origem, linhas, colunas, vmax);
        			break;
        		case 8:
        			rot90esq(origem, linhas, colunas, vmax);
        			break;
        		case 9:
        			parteCinza(origem, linhas, colunas, vmax);
        			break;
        		case 10:
        			rgb(origem, linhas, colunas, vmax);
        			break;
        		case 0:
        			printf("\n\nPrograma Encerrado!\n\n");
        			break;
        		default:
        			printf("\nValor inserido invalido!\n\n");
        			break;
			}
        	
		}while(opt!=0);
    }
    fclose(origem);
    fclose(cinza);
    return 0;
}





