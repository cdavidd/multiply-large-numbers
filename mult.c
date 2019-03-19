#include <stdio.h>
#include <string.h>
#include <math.h>

struct numero{
	char  number[70];
};


struct numero mult(struct numero x,struct numero y){
	struct numero res,a,b;
	memset(res.number,'\0',sizeof res.number);
	int lnx=strlen(x.number),lny=strlen(y.number);
	if (lnx==0 || lny==0){
		res.number[0]='0';
		return res;
	}
	if (strlen(x.number)>strlen(y.number)){
		a=x;
		b=y;
	}else{
		a=y;
		b=x;
	}
	strrev(a.number);
	strrev(b.number);
	
	int lna=strlen(a.number), lnb=strlen(b.number), carry,n,i,j;
	for (i=0;i<lnb;i++){
		carry=0;
		int pos=i,mul=0;
		for (j=0;j<lna;j++){
			//printf("%s a\n",res.number);
			if(res.number[pos]=='\0'){
				mul= ((a.number[j]-'0') * (b.number[i]-'0')) + carry;	
			}else{
				mul= ((a.number[j]-'0') * (b.number[i]-'0')) + (res.number[pos]-'0') +carry;
				//printf("%i %i %i %i %i %i mul\n",(a.number[j]-'0'),(b.number[i]-'0'),(res.number[pos]-'0'),carry,pos,j);
			}
			carry=mul/10;
			n= mul%10;
			res.number[pos]=(n + '0');
			//printf("%i %i pos\n",pos,mul);
			pos++;
		}
		if(carry>0){
		res.number[strlen(res.number)]=(carry + '0');
		}
		//printf("%s b\n",res.number);
	}
	strrev(res.number);
	return res;
}


main(){
	struct numero a,b;
	memset(a.number,'\0',sizeof a.number);
	memset(b.number,'\0',sizeof b.number);
	char x[]="1235421415454545454545454544";
	char y[]="1714546546546545454544548544544545";
	int i;
	for (i=0;i<strlen(x);i++){
		a.number[i]=x[i];
	}
	for (i=0;i<strlen(y);i++){
		b.number[i]=y[i];
	}
	struct numero res;
	res=mult(a,b);
	printf("%s",res.number);
}
