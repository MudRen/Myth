// by snowcat 6/21/1997
// whohave.c

inherit F_CLEAN_UP;

mixed main(object me, string arg, int remote)
{
	object *ulist;
	int i;
	string str;
       if (me != this_player()) return 0;
     if (! SECURITY_D->valid_grant(me, "(immortal)")) return 0;

	str="\n\n";

	ulist = users();
	i = sizeof(ulist);

	while (i--) {
		object who = ulist[i];
		object ridee = ulist[i]->query_temp("ridee");
		
		if (! ridee)
			continue;
		if (ridee->query_temp("rider") != who) {
			continue;
		}	
str=str+
sprintf("  %12s %-8s  (%2d)%s��%s(%s)�ϡ�\n",
who->query("name"), who->query("id"), 
ridee->query("ride/dodge"), ridee->query("ride/msg"), 
ridee->query("name"), ridee->query("id"));
/*

		write (who->query("name")+"("+who->query("id")+")");
		write (ridee->query("ride/msg")+"��");
		write (ridee->query("name")+"("+ridee->query("id")+")");
*/
	}
	str=str+"\n";
	me->start_more(str);
	return 1;
}

int help (object me)
{
        write(@HELP
ָ���ʽ : whoride 
 
���г�Ŀǰ�����������ҡ�
 
 
HELP
);
        return 1;
}
