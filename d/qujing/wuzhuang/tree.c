//Cracked by Roath

//  ����֮�� ������
//  by happ@YSZZ 2000.4.9
//  /d/qujing/wuzhuang/tree.c

#include <room.h>
inherit ROOM;
#include <ansi.h>

void create ()
{
   set ("short", "�˲ι���");
   set ("long", @LONG

����һ���˲ι��������Ǹ���֦�������Ҷ��ɭ����Ҷ��ȴ�ưŽ�
ģ����ֱ��ȥ��ǧ�߶�ߣ��������߰�����Χ�����ϵ�֦�ϣ�¶��
һ���˲ι������������һ�㣬������������졣

LONG);

   set("exits", 
   ([ //sizeof() == 4
        "up" : __DIR__"shugan1",
        "south": __DIR__"baicaidi",
   ]));
   
   setup();
}

int valid_leave(object me, string dir)
{
        if ( dir == "south" && me->query("kill_tree") )
                {
        tell_object(me,HIY"��Ȼ�������һ�����֣�һ�¾Ͱ���ץ���ˣ�ԭ������Ԫ���ɡ�\n"NOR);
        me->move("/d/qujing/wuzhuang/chengyun");
        return notify_fail(HIC"�����ﰵ�룬�������ˡ�\n"NOR);
                }
        return ::valid_leave(me, dir);
}

