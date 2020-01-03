#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char *argv[]){

	float num1, num2, ans;
	char op, choice;

restart:
	printf("Enter calculation: ");
	scanf("%f %c %f",&num1,&op,&num2);
	getchar();

	switch(op){
		case '+':
			ans = num1+num2;
			break;
		case '-':
			ans = num1-num2;
			break;
		case '*':
			ans = num1*num2;
			break;
		case '/':
			ans = num1/num2;
			break;
		case '%':
			ans = fmod(num1,num2);
			break;
		case '^':
			ans = pow(num1,num2);
			break;
		default:
			goto fail;
			break;
	
	}
	
	printf("\n%.2f %c %.2f = %.2f\n",num1,op,num2,ans);
	goto check;

fail:
	printf("Calculation failed.");
	goto check;

check:
	printf("Quit? (y/n): ");
	scanf("%c",&choice);
	getchar();
	if(choice == 'n'){
		goto restart;
	}
	else{
		printf("Quitting...\n");
		goto exit;
	}

exit:
	return 0;

}
