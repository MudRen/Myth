//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", CYN"����"NOR);
        set("long",@LONG
������ǰ�Ƿ���ֱ����ǧ�ߵ��ٲ���������ô�����ٲ���
�㲻����ȥ���Իӽ���ˮ��
LONG
        );

        set("exits", ([
                "westdown" : __DIR__"houshan",
        ]));

        setup();
}

void init()
{
        add_action("do_huijian", "huijian");
}

int do_huijian(string arg)
{
        object room, ob;
        object me = this_player();
        int sk = me->query_skill("shushan-jianfa",1);
        if(me->query("family/family_name") != "��ɽ����")
        {
        tell_object(me,"��о����������ġ�\n"); 
        return 1;
        }
        if(me->query("combat_exp") < (sk*sk*sk/10))
        {
        tell_object(me,"��ĵ��в�����\n");     
        return 1;
        }
        if(me->query("kee") < 50)
        {
        tell_object(me,"�㻹������Ϣһ����ɡ�\n");     
        return 1;
        }
        if (!objectp(ob = me->query_temp("weapon"))
        || (string)ob->query("skill_type") != "sword")
                return notify_fail("���������һ�ѽ����ܻӽ���ˮ��\n");

        message_vision("$N�ӽ�ȥ��ˮ�����Ū�ø����ӽ���ˮˮ������ȫ��ʪ͸��Ҳ������\n",me);
        me->add("kee",-30);
        if(me->query_skill("shushan-jianfa",1) > 249 )
        {
        tell_object(me,"���ƺ�������������ʲô�ˡ�\n");       
        return 1;
        }
        if((int)me->query_skill("mindsword", 1) > 149){
        tell_object(me,HIW"���ƺ��Իӽ���ˮ��������\n"NOR);
//        me->improve_skill("shushan-jianfa", random(me->query_int()*10) +1,0);
        if(!me->query("sp/wanliu"))
        {
        if(random(10000) < 10)
        me->add("shushan/duanshui",1);
        if(me->query("shushan/duanshui",1) > 99)
        {
        me->set("sp/wanliu",1);
        tell_object(me,HIY"���ڲ�֪���������ˡ��������ڡ���Ҫ�졣\n"NOR);
        me->delete("shushan/duanshui");
        }
        }
        }
        else tell_object(me,HIY"Ҳ������Ľ���Ϊ���������޷���ʲô��\n"NOR);
        return 1;
}                

