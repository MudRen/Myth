//Cracked by Roath
// hp cmds
 
#include <ansi.h>
 
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob;
        string *club,id;

        if(!arg) return notify_fail("��Ҫ��˭��������ɣ�\n");
        ob = present(arg, environment(me));
	if(!ob || ob==me ) return notify_fail("����û������ˡ�\n");
	if(!wizardp(me))
	{
		if( !userp(ob) || wizardp(ob) ) return notify_fail("ֻ�����������ɡ�\n");
	
		club = CLUB_D->find_player_club(getuid(me));
		if(sizeof(club)>1)  return notify_fail("���Ѿ�����"+club[0]+"�ˡ�\n");
		club = CLUB_D->find_player_club(getuid(ob));
		if( sizeof(club)<1 ) return notify_fail("�Է��ƺ���û�вμӰ�ᡣ\n");
	}
	id = ob->query("id");
	if(me->query_temp("joinclub") == id) return notify_fail("���Ѿ��������, �Է����ڿ����С�\n");
	message_vision("$N��ʽ��$n����������Ҫ��\n",me,ob);
	tell_object(ob,"�����ͬ��Է�����, ���� jieshou "+me->query("id")+" ָ��������\n");
	me->set_temp("joinclub",id);
	return 1;
}
                          
int help(object me)
{
        write(@HELP
ָ���ʽ : 
           joinclub <��������> 
           
���ָ���������Է��������ᡣ

see also : score
HELP
    );
    return 1;
}

