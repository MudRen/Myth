#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
set ("short", HIW"����"NOR);
set ("long", @LONG
 
�����ǽ�����滭���˺����������м�ֻ��һ����̨��
 
LONG);
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"shendian",
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
         object shaogong, ob, me;
        me=this_player();
        if( !arg)
                return notify_fail("��Ҫ��ʲô������\n");
 if( !arg || arg!="shao gong" || !(ob=present(arg, me)))
                return notify_fail("��Ҫ�ҷš�\n");
   message_vision("\n$N��$n���ڼ�̨��һ��������󣬼�̨������������һ��"+HIB" ˮ "NOR+"�֡�\n\n", me, ob);
    me->set_temp("shendian/shuimigong","begin");
    me->move("/d/shendian/shui/shuimigong0");
                destruct(ob);
        return 1;
}
