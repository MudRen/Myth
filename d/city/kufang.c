
#include <ansi.h>
inherit ROOM;
int do_yuntang(string arg);

void create ()
{
        set ("short", "�ⷿ");
        set ("long", @LONG
���߹�һ����խ��С��֮������һ��ֿ��С���������Ķ�����δ��
���̵Ĳ�ƥ��һЩ���¡���ǽ�ڷ��ż��Ŵ����ӣ������Ϸ��ż�ƥ��ʪ��
���Ϻ�һ������һ���Ѿ��յ÷��̵��ٶ�����������������(yuntang)��
LONG);

        set("exits", ([ /* sizeof() == 1 */
                "west" : __DIR__"xiemao", 
        ]));

        setup();
}

void init()
{
        add_action("do_yuntang","yuntang");
}

int do_yuntang(string arg)
{
        object me=this_player(); 
        object ob;
        if (!me->query_temp("newbiejob/yunbu"))
                return notify_fail("������û���ٲ��Ĺ�����\n");

/*        if (query_temp("bu")==0)
           return notify_fail("����Ĳ��϶��Ѿ��ٺ��ˡ�\n");
*/
        if (!arg || arg != "����")
                return notify_fail("��Ҫ����ʲô��\n");

        if ( (int)me->query("sen")<30)
                return notify_fail("��̫���ˣ���Ϣһ�°ɡ�\n");

        if (me->query_temp("newbiejob/yunbu")==6)
                return notify_fail("�����Ѿ��ٺ��ˣ�����ٺõĲ�����ȥ�ɣ�\n");
   
        message_vision("$N�����ٶ��������ڲ����������ƶ���ֻ������������ð����ɫ��������\n",me);
        this_player()->start_busy(1+random(1));
        me->add("sen",-(15+random(15)));
        me->start_busy(3+random(1));
        me->add_temp("newbiejob/yunbu",1);
        if ( (int)me->query_temp("newbiejob/yunbu")==6)
        {
        message_vision(CYN"��ƥ����������ƽ����$N����ƥ���ú����һ�ߡ�\n"NOR,me);
        ob=new("/d/city/obj/bu.c");
        ob->move(me);
        me->add_temp("bu",-1);      
        return 1;
        }
        if (random(10)>7)
        {
        message_vision(RED"$N����������֮���𽥿�ʼ�������ģ�ֻ���á��ꡱ��һ��$N���ֱ��ٶ�����һ�¡�\n"NOR,me);     
        me->receive_damage("kee", (int)me->query("max_qi")/6);
 
        }             
        return 1;
} 

