//whois.c

int main(object me, string arg)
{
     if (! SECURITY_D->valid_grant(me, "(immortal)")) return 0;
	if( ! arg )
		return notify_fail("whois <��������>\n");

printf("%s", NAME_D->who_is(arg));
	return 1;
	
}


int help(object me)
{
    write(@HELP
ָ���ʽ��whois <��������> 
 
���ָ����Ը�����ҵ��������ֲ����Ӧ��Ӣ�ģ�䡣 
HELP
    );
	return 1;
}

