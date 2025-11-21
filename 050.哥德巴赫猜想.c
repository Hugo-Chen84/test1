#include<stdio.h>
#include<math.h>
int is_prime(int n){
	for(int i=2;i<=sqrt(n)+1;i++){
		if(n%i==0)
			return 0;
	}
	return 1;
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i =3;i<=n/2;i++){
		if(is_prime(i)&&is_prime(n-i)){
			printf("%d = %d + %d",n,i,n-i);
			break; 
		}
	}
	return 0;
} 
