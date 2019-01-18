// title.c (Mon  09-04-95) 
//mofied for set title...Weiqi 09/31/97.

#include <ansi.h>
inherit F_CLEAN_UP;

int check_legal_title(string, int);
 
int main(object me, string arg)
{
	int titlelength=0;

	if( !arg ){
    		printf("��Ŀǰ��ͷ�μ����ɣ�\n");
    		printf(BOLD "%s" NOR " %s\n\n", RANK_D->query_rank(me), me->short(1));
    		if(strlen(me->query("added_title"))>1)
		  printf("����ͷ�����貿�ݣ�%s\n", (string)me->query("added_title"));
    		return 1;
	}
	
	if( arg=="none" ) {
		me->delete("added_title");
		printf("�ã�ɾ��ͷ�����貿�ݡ�\n");
		return 1;
	}

	if(me->query("daoxing") >= 500000){
		titlelength=8;
	}
	else if(me->query("daoxing") >= 100000){
		titlelength=4;
	}
	else titlelength=0;
	
	if(check_legal_title(arg, titlelength) == 0) return 1;	
	
	me->set("added_title", arg);

    	return 1;
}
 
int check_legal_title(string addtitle, int titlelength)
{
       	int i;

	i = strlen(addtitle);

	if(titlelength<=0){
		write("�Բ���Ŀǰ�㻹���ܸ��Լ���ͷ�Ρ�\n");
    		return 0;
	}

	if(titlelength < strlen(addtitle)){
    		printf("�Բ���Ŀǰ�����ֻ����%s����������Ϊͷ�Ρ�\n", chinese_number(titlelength/2));
    		return 0;
	}

	while(i--) {
               	if( addtitle[i]<=' ' ) {
                       	write("�Բ������ͷ�β����ÿ�����Ԫ��\n");
                       	return 0;
               	}
               	if( i%2==0 && !is_chinese(addtitle[i..<0]) ) {
                       	write("�Բ��������á����ġ���ͷ�Ρ�\n");
                       	return 0;
               	}
       	}

	return 1;
}

int help(object me)
{
    write(@HELP
ָ���ʽ: title ***
 
�Լ��趨ͷ�Ρ����г���500�������4�������֣�
����100�������2�������֣�����100�껹�ü���:)

title ���Ӳ�����ʾ��Ŀǰ��ͷ�μ����ɡ�
title none  ɾ��ͷ�����貿�ݡ�

HELP
    );
	return 1;
}
 
