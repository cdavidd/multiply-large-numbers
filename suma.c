#include <stdio.h>
#include <string.h>
#include <math.h>

struct numero{
	char  number[70];
};


struct numero suma(struct numero x,struct numero y){
	struct numero res,a,b;
	memset(res.number,'\0',sizeof res.number);
	if (strlen(x.number)>strlen(y.number)){
		a=x;
		b=y;
	}else{
		a=y;
		b=x;
	}
	strrev(a.number);
	strrev(b.number);
	int lna=strlen(a.number), lnb=strlen(b.number), carry=0,n,i;
	for (i=0;i<lnb;i++){
		int sum = (a.number[i]-'0') + (b.number[i]-'0') + carry;
		carry=sum/10;
		n= sum%10;
		res.number[i]=(n + '0');
	}
	
	for(i=lnb;i<lna;i++){
		int sum = (a.number[i]-'0')+carry;
		carry=sum/10;
		n= sum%10;
		res.number[i]=(n + '0');
	}
	if(carry>0){
		res.number[strlen(res.number)]=(carry + '0');
	}
	strrev(res.number);
	return res;
}


main(){
	struct numero a,b;
	memset(a.number,'\0',sizeof a.number);
	memset(b.number,'\0',sizeof b.number);
	char x[]="999999999999";
	char y[]="1";
	int i;
	for (i=0;i<strlen(x);i++){
		a.number[i]=x[i];
	}
	for (i=0;i<strlen(y);i++){
		b.number[i]=y[i];
	}
	struct numero res;
	res=suma(a,b);
	printf("%s",res.number);
}
