#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
set ("short", HIW"ũ��"NOR);
set ("long", @LONG
 
�����ǽ�����滭���˸�����ũ������м�ֻ��һ����̨��
 
LONG);
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"shendian",
]));
  set("objects", ([ /* sizeof() == 1 */
  ]));
  set("no_clean_up", 1);
  setup();
}
void init()
{
        add_action("do_put", "put");
        set("no_clean_up", 1);
}
int do_put(string arg)
{
         object famugong, ob, me;
        me=this_player();
        if( !arg)
                return notify_fail("��Ҫ��ʲô������\n");
 if( !arg || arg!="nong fu" || !(ob=present(arg, me)))
                return notify_fail("��Ҫ�ҷš�\n");
   message_vision("\n$N��$n���ڼ�̨��һ���ƹ���󣬼�̨������������һ��"+HIY" �� "NOR+"�֡�\n\n", me, ob);
    me->set_temp("shendian/tumigong","begin");
    me->move("/d/shendian/tu/tumigong0");
                destruct(ob);
        return 1;
}
