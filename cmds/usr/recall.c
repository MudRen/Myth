#include <ansi.h>
inherit F_CLEAN_UP;

int help(object me);
int call_pet(object me);
int call_ling(object me);

int main(object me, string arg)
{
	if (!arg || arg == "pet")
	    return call_pet(me);
	if (arg == "ling")
	    return call_ling(me);
}
int call_ling(object me)
{
	object ob;
	string pname;
		
	if (!pname = me->query("party/party_name"))
	    return notify_fail("������ȼ���һ����ᣡ\n");
	if (present("ling pai", me))
        return notify_fail("�����ϲ����Ѿ���������ô����\n");
	ob = new("/obj/misc/ling.c");
	ob->set_name(pname + "��", ({"ling pai", "ling"}));
	ob->set("long", pname + "�İ�������");
	ob->move(me);
	message_vision("$N����������һ�����ͳ���$n��\n",me,ob);
	return 1;
}
int call_pet(object me)
{
        object ob;
        string pet_id;
        string *id_list, *t_list;       
             int tt;
        if (!me->query("pet/pet_id"))
          return notify_fail("�����ڲ�û�������\n");
        if (environment(me)->query("short")=="��̨")
           return notify_fail("��̨����ô�ܽг����æ��\n");
//
          if((tt=me->query_temp("recall_time")) && tt +4 > time()) 
           return notify_fail("�ȵ��ٽг����æ,���������ˡ�\n");
              me->set_temp("recall_time",time());
        pet_id=me->query("pet/pet_id");
        id_list = ({ pet_id });
        t_list = explode( pet_id, " ");
        if( sizeof(t_list) > 1 )   {
                id_list += t_list;
        }
        ob=find_player(pet_id);
if( !ob ) ob=find_living(pet_id);
        if( !ob ) ob = LOGIN_D->find_body(pet_id);
        if( !ob ) {
                ob=new("/d/eastway/npc/pet");
//              ob->set("owner",getuid(me)); 
              ob->set("owner",me->query("id")); 
                  ob->restore();
        ob->clear_condition();
              ob->set("owner",me->query("id")); 
                ob->set_name(ob->query("name"),id_list);
                 ob->set("default_actions", (: call_other, "/adm/daemons/race/beast.c", "query_action" :));
                ob->setup();
        } else if (ob->query("owner") != me->query("id"))
                   return notify_fail("������ĳ��ﲻ������Ļ��ˣ��㻹������ȥ���Ұɣ�\n");
        // nk. mudring Jan/03/2003
        if (!ob->query_temp("invoker") ||
            ob->query_temp("invoker") != me)
                ob->set_temp("invoker", me);
        ob->move(environment(me));
        message_vision("$Nһ�����ڣ�$n�˷ܵش�Զ����$N������\n",me,ob);
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ�� recall

���ָ����������ٻ�����ʧ�ĳ��
HELP
 );
        return 1;
}

