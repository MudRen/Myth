// Room: /d/jjf/guest_cabinet.c
// 6-30-97 pickle

inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "�����¥");
  set ("long", @LONG

�ؽ���û��Ů�������������������������Сס��������ѡ�С����
��һ����֬��ƿ���������Ķ��Ǿ�Ө��͸�İ׾գ���֪������˸�
��¯������һ���������޵İ��㡣һ���ҽ�վ��¥�ݿڣ�������¥��
·��Ҳ��֪¥��ס������λ��͡�
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/luochun" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"pavillion",
  "up" : __DIR__"guest_cabinet2",
]));

  setup();
}
int valid_leave(object me, string dir)
{
    object guard, *inv, letter;
    int i;

    if(dir != "up")
        return ::valid_leave(me, dir);
    inv=all_inventory(me);
    i=sizeof(inv);
    me->delete_temp("condition/carrying_player");
    if(objectp(present("luo chun", environment(me))))
	guard=present("luo chun", environment(me));
    if(!guard) return ::valid_leave(me,dir);
    while (i--)
    {
        if (userp(inv[i]))
            me->add_temp("condition/carrying_player", 1);
        continue;
    }
    if(me->query_temp("condition/carrying_player"))
    {
        return notify_fail(CYN "�޴��ȵ���߾��������¥���Ȱѱ��ϵ��Ǹ������ˣ�\n"NOR);
    }
    if (!(letter=present("shu xin", me)
       && letter->query("header")=="�������޳�") 
     && me->query("family/master_id")!="luo cheng"
     && guard)
    {
        return notify_fail(CYN "�޴��ȵ���߾��¥���˹��˾�ס֮���������ô���\n"NOR);
    }

    //finally...
    return ::valid_leave(me, dir);
}
