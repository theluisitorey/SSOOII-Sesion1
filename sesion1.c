#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h> 
#include <sys/sem.h>
#include <unistd.h>

int calcular_longitud(int num);
double elevar(int num1, int num2);

int main(int argc, char* argv[]){
	printf("Hola men\n");
	int hijo1, hijo2, hijo3, hijo4;
	float somnolencia;
	int mi_pid, longitud;
	double dividir;
	key_t clave1, clave2;
	int semaforo;

	struct sembuf semOpc;

	/*Creo los semaforos */
	clave1 = ftok(argv[0], 'G');
	printf("La clave es: %d", clave1);
	semaforo = semget(clave1, 1, IPC_CREAT | 0600);

	semOpc.sem_num = 0;
	semOpc.sem_op = 0;
	semOpc.sem_flag = 0;

	semop(semaforo, semOpc, );

	hijo1 = fork();
	switch(hijo1){
		case -1:
			perror("Ha ocurrido un error al crear el Hijo 1");
		break;
		case 0:
			/*Hijo 1*/
			mi_pid = getpid();
			
			somnolencia = ((mi_pid % 10) / 2) + 1;
			printf("## 1 ## Mi somnolencia es: %f, mi pid es: %d\n", somnolencia, mi_pid);
			sleep(somnolencia);
		break;
		default:
			hijo2 = fork();
			switch(hijo2){
				case -1:
					perror("Ha ocurrido un error al crear el Hijo 2\n");
				break;
				case 0:
					/*Hijo 2*/
					mi_pid = getpid();
					
					somnolencia = ((mi_pid % 10) / 2) + 1;
					printf("## 2 ## Mi somnolencia es: %f, mi pid es: %d\n", somnolencia, mi_pid);
					sleep(somnolencia);

				break;
				default:
					hijo3 = fork();
					switch(hijo3){
						case -1:
							perror("Ha ocurrido un error al crear el Hijo 3\n");
						break;
						case 0:
							/*Hijo 3*/
							mi_pid = getpid();
							
							somnolencia = ((mi_pid % 10) / 2) + 1;
							printf("## 3 ## Mi somnolencia es: %f, mi pid es: %d\n", somnolencia, mi_pid);
							sleep(somnolencia);
						break;
						default:
							hijo4 = fork();
							switch(hijo4){
								case -1:
									perror("Ha ocurrido un error error al crear el Hijo 4\n");
								break;
								case 0:
									/*Hijo 4*/
									mi_pid = getpid();
									
									somnolencia = ((mi_pid % 10) / 2) + 1;
									printf("## 4 ## Mi somnolencia es: %f, mi pid es: %d\n", somnolencia, mi_pid);
									sleep(somnolencia);
								break;
								default:

								break;
							}
						break;
					}
				break;
			}
		break;
	}

	return(0);
}

int calcular_longitud(int num){
	int cont = 0;

	while(num / 10 > 0){
		num = num / 10;
		cont++;
	}

	return cont;
}


double elevar(int num1, int num2){
	double resultado = 1;
	int x;

	for(x = 0; x<num2; x++){
		resultado *= num1;
	}

	return resultado;
}