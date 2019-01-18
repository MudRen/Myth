// smash.c 2-22-95

#include <ansi.h>
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
        object ob;
        string name1, name2;

          if (! SECURITY_D->valid_grant(me, "(arch)"))
                return 0;

        if (! arg)
                return notify_fail("ָ���ʽ: smash <living>\n");

        ob = present(arg, environment(me));
        if (! ob || ! me->visible(ob))
                return notify_fail("�Ҳ���������\n");

        if( wiz_level(me) < wiz_level(ob))
                ob = me;

        name1 = (string)me->query("name");
        name2 = (string)ob->query("name");

        tell_room(environment(me),
                name1 + "�߾�˫�ִ�ȣ�ȥ���ɣ�ֻ������һ�����粻ƫ���еػ���"+name2+
                "����֮��Ϊһ�ѻҽ���\n",
                ({me, ob}));

        if(living(ob))
                tell_object(ob, name1 +
                "�߾�˫�ִ�ȣ�ȥ���ɣ�ֻ������һ�����粻ƫ���еػ����㡣\n");
        
        write("��߾�˫�ִ�ȣ�ȥ���ɣ������Ͻ���һ�����罫" + name2 +
                "����һ�ѻҽ���\n");

        if (! wizardp(ob))
                message("channel:chat",
                HIG"�����꾫�顿ĳ�ˣ�" + "��˵" + me->name(1) +
                "�����罫 "HIW + ob->name(1) + HIG" ���������졣\n"NOR,
                users());

        if (living(ob)) {
                if (userp(ob)) {
                            ob->set_temp("death_msg","��"+me->name(1)+"�����������ˡ�"); 
                        log_file("cmds/smash",
                                sprintf("%s smash %s at %s\n",
                                        geteuid(me), geteuid(ob),log_time() ));
                }
                ob->set("env/immortal", 0);
                ob->die();
        } else
                destruct(ob);

        return 1;

}
 
int help(object me)
{
   write(@HELP
ָ���ʽ: smash <����>
 
hehehehehe...........

HELP
   );
   return 1;
}

