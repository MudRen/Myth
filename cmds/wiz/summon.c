// summon command..
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string str)
{
	object ob, env;
	int i;
     if (! SECURITY_D->valid_grant(me, "(wizard)"))
             return 0;

	if (!str) return notify_fail("<Syntax>: Summon <player id>\n");
	ob = LOGIN_D->find_body(str);
	if (!ob) return notify_fail("�ף����� ���������\n");

/*
    if(wizardp(ob) && wiz_level(me) < wiz_level(ob))
      return notify_fail("�㲻��ץ�ȼ�����ߵ���ʦ��\n");
*/
/*
    if (! wizardp(ob) && wiz_level(me) < wiz_level("(arch)"))
        return notify_fail("ץ��ץȥ��ʲô��\n");
*/
if (ob->query_temp("reported/too_much_money")) 
{
return notify_fail("�����ط���Ҳ���ץ��������\n");
}
				  
	// moving
	tell_room(environment(ob),"��������һֻ���ְ�"+
	(string)ob->query("name")+"ץ��������Ȼ�󲻼��ˡ�\n", ob);
	tell_object(ob,"һֻ�ְ���ץ������������ǰһ��ڣ�����\n");
	ob->move(environment(me));
        tell_object(me, "���"+(string)ob->query("name")+"ץ�������ǰ��\n");
	tell_object(ob,"������ ����ʱ������"+(string)me->query("name")+
	"����Ū�����ġ�\n");
	tell_room(environment(ob),(string)ob->query("name")+"ͻȻ����"+
	"������ǰ��\n",({me,ob}));
	// ok ..
	env = environment(ob);
    	while (env && env->is_character())
        env = environment(env);
	if (!wizardp(ob)){
    message("channel:chat",HIG"���ٻ����顿ĳ�ˣ�"+"��˵"+me->query("name")+"�� "HIW+ob->query("name")+HIG" ץ���� "+env->query("short")+"��\n"NOR,users());
        }
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : summon <ĳ��>

��ָ������㽫ĳ��ץ������ǰ��
HELP
    );
    return 1;
}
