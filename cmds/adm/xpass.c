//Cracked by Roath
//xpasswd.c
// ported to CCTX by JackyBoy@CuteRabbits Studio 1999/4/1

#include <login.h>;
inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	object ob,link_ob;
	string id,password;
	if(!arg||sscanf(arg,"%s %s",id,password)!=2)
		return notify_fail("�÷�:xpasswd ID ������\n�˲���������������棬������ȵ��������\n");
 if (wiz_level(arg) && !is_root(me))
  return notify_fail("��û��Ȩ���޸�����˵Ŀ��\n");
	ob=find_player(id);
	if(!ob)
	{
        ob = new(LOGIN_OB);
        ob->set("id",id);
        if( !ob->restore() )
        	return notify_fail("û�������ҡ�\n");
        else
		{                                    
           ob->set("password",crypt(password,0));
           tell_object(me, "���" + ob->query("id") + "("+ob->query("name")
                + ")�������Ѿ�����Ϊ��"+password+"��\n");
           log_file( "cmds/xpass", sprintf("%s %s(%s)�޸���%s(%s)������\n",
                ctime(time()), me->query("name"), me->query("id"),
                ob->query("name"), ob->query("id")));
           ob->save();
           destruct(ob);
           return 1;
		}
	}
	link_ob=ob->query_temp("link_ob");
	if(link_ob)
	{
		link_ob->set("password",crypt(password,0));
		link_ob->save();
		tell_object(me, "���" + ob->query("id") + "("+ob->query("name")
                        + ")�������Ѿ�����Ϊ��"+password+"��\n");
           log_file( "cmds/xpass", sprintf("%s %s(%s)�޸���%s(%s)������\n",
                ctime(time()), me->query("name"), me->query("id"),
                ob->query("name"), ob->query("id")));
		return 1;
	}
	else
		return notify_fail("�����޷������޸ġ�\n");
	return 1;
}


int help(object me)
{
        write(@HELP
ָ���ʽ : xpasswd ID ������

���ָ������޸���ҵ����룬�����ʹ�á�

HELP
    );
    return 1;
}
