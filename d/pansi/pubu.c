// pubu.c 
// by/lestat

inherit ROOM;

#include <ansi.h>
void create()
{
        set("short", "�ٲ�");
        set("long", @LONG
��������ˮ�����������¡¡�����糱ˮ����һ�㣬̧ͷһ����ֻ��һ
�����ٲ����������ӵ������Ӹ�����ֱк������������������Ԩ������������
��������ͷ��������
LONG );
        set("exits", ([ /* sizeof() == 2 */
                "south" :  __DIR__"tao_out",
        ]));
        set("objects",([
                __DIR__"npc/qingxia" : 1,
        ]));
        set("outdoors", "xiaoyao" );
        set("no_clean_up", 0);
        set("no_fight", 1); 
        set("no_magic", 1); 

        setup();
}
 
void init()
{
        add_action("do_jump","jump");
}

int do_jump(string arg)
{
        object ob;
        int new_sen;
        ob = this_player();
        new_sen = random( ob->query("max_sen")*3 );
        if ( new_sen > ob->query("sen") ) new_sen = ob->query("sen") + 1;
        if( !arg || arg=="" ) return 0;
        if( arg != "down" )
                return notify_fail("����Ҫ������ɱ����ô�벻������\n");
        tell_object(ob, HIR"�㲻��˼��������һԾ�����������¡�������\n"NOR);
        message("vision", NOR"ֻ��" + ob->query("name") + "�����ң���������������֮�С�������\n"NOR, environment(ob), ob);
        if((ob->query("family/family_name") == "��˿��" ))
        {
                ob->move(__DIR__"yanfeng");
                message("vision", NOR"ͻȻһ����ϼ����������㱻��ȫ���͵��˵��档\n"NOR, ob);
         }      
        else
        {
                if((ob->query_skill("dodge",1)<30)){ ob->unconcious();
                ob->receive_damage("sen",new_sen);
                ob->move(__DIR__"yanfeng");
                }else{
                ob->move(__DIR__"yanfeng");
                }
        }
        return 1;
}



