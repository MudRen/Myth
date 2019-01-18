inherit F_CLEAN_UP;
// pkl

#include <ansi.h>
#include <obstacle.h>

int telling (object me, object who);

string name;

int main(object me, string arg)
{
    object ob;

    if( !arg ) {
	ob = me;
	name = "��";
    } else if (wizardp (me)) {
	ob = find_player(arg);
	if(!ob) ob = find_living(arg);

	if(!ob) ob = LOGIN_D->find_body(arg);

	if(!ob || !me->visible(ob)) return notify_fail("û������ˡ�\n");

	name = ob->query("name");
    } else
	return 0;

    telling(me, ob);

    return 1;
}

int help()
{
    write(@TEXT
ָ���ʽ��quests <ĳ��>

��ʾĳ�˽��յ����ϡ� 

TEXT
    );
    return 1;
}

int telling (object me, object who)
{
    mapping mapp;

    write ("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    write (HIY+name+"���������񣺣����һ��������\n"NOR);
    write ("    ��ʼʱ�䣺"+ctime(who->query("mieyao/time_start"))+"\n");
    if (!who->query("mieyao/done")) write ("    ���ʱ�䣺��δ���\n"NOR);
    else write ("    ���ʱ�䣺"+ctime(who->query("mieyao/time_finish"))+"\n"NOR);
    write ("    �������ƣ�"+who->query("mieyao/name")+"("+who->query("mieyao/id")+")\n");
    write ("    ���ֳ�ʼ�ص㣺"+who->query("mieyao/where")+"\n");
    write ("    Ŀǰ���ѵȼ���"+chinese_number(who->query_temp("mieyao/level"))+"����\n\n");
    write (HIR+name+"���������������£�\n"NOR);
    write ("   �ܹ��ĵõ���"+to_chinese(who->query("mieyao/number"))+"��ɱ������\n");
    write ("   �ܹ������"+to_chinese(who->query("mieyao/number_fns"))+"��ɱ������\n");
    write ("    ����ã�\n"NOR);
    write ("    Ǳ�ܣ�"NOR+to_chinese(who->query("mieyao/reward/pot"))+"�㡣\n");
    write ("    ��ѧ��"NOR+to_chinese(who->query("mieyao/reward/exp"))+"��ѧ��\n");
    write ("    ���ܣ�"NOR+to_chinese(who->query("mieyao/reward/skills"))+"��skills������\n");
/*
    mapp = who->query("mieyao/reward/skills");
    if (mapp)
    {
	string *my_keys = keys (mapp);
	int i = sizeof (my_keys);

	while (i--)
	{
	    write ("        "+to_chinese(my_keys[i])+to_chinese(mapp[my_keys[i]])
	      +"��\n");
	}
    }
*/
    write ("\n");
  write ("\n");
  write (HIY+name+"�������������񣺣����һ��������\n"NOR);
  write ("    �������ƣ�"+who->query("secmieyao/name")+"("+who->query("secmieyao/id")+")\n");
  write ("    ���ֳ�ʼ�ص㣺"+who->query("secmieyao/place")+"\n");
    write ("   �ܹ������"+to_chinese(who->query("mieyao/menpai_num"))+"������ɱ������\n");
  write (HIR+name+"�������������������£�\n"NOR);
  write ("    Ǳ�ܣ�"NOR+to_chinese(who->query("mieyao/menpai_reward/pot"))+"�㡣\n");
  write ("    ���У�"NOR+to_chinese(who->query("mieyao/menpai_reward/dh"))+"�㡣\n");
  write ("\n");
    write ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

