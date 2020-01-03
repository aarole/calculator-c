#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define PI acos(-1.0)

//Compile with: gcc -o calculator calculator.c -lm

int main(){

	int class;
	float num1, num2, ans;
	char op, sop[4], choice;

restart:
	printf("Enter 1 for single number calculations and 2 for 2 number calculations: ");
	scanf("%d",&class);
	getchar();

	if(class == 1){
		goto single;
	}
	else{
		goto multi;
	}

single:
	printf("Operations: sqrt , sin , cos , tan \n");
	printf("Use degrees for trigonometric operations.\n");
	printf("Enter calculation (format: operation number): ");
	scanf("%s %f",&sop,&num1);
	getchar();

	float rad = num1 * PI / 180;;

	if(strcmp(sop, "sqrt") == 0){
		ans = sqrt(num1);
	}
	else if(strcmp(sop, "sin") == 0){
		ans = sin(rad);
	}
	else if(strcmp(sop, "cos") == 0){
		ans = cos(rad);
	}
	else if(strcmp(sop, "tan") == 0){
		ans = tan(rad);
	}
	else{
		goto fail;
	}
	
	printf("%s(%.2f) = %.2f\n",sop,num1,ans);
	goto check;

multi:
	printf("Operations: + , - , * , / , % , ^ \n");
	printf("Enter calculation (format: numberOne operation numberTwo): ");
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
	printf("Calculation failed.\n");
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
