#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
set ("short", HIW"��ɽ"NOR);
set ("long", @LONG
 
�����ǽ�����滭���˻�ɽ�������м�ֻ��һ����̨��
 
LONG);
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"shendian",
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
         object tiejiang, ob, me;
        me=this_player();
        if( !arg)
                return notify_fail("��Ҫ��ʲô������\n");
 if( !arg || arg!="tie jiang" || !(ob=present(arg, me)))
                return notify_fail("��Ҫ�ҷš�\n");
   message_vision("\n$N��$n���ڼ�̨��һ�������󣬼�̨������������һ��"+HIR" �� "NOR+"�֡�\n\n", me, ob);
    me->set_temp("shendian/huomigong","begin");
    me->move("/d/shendian/huo/huomigong0");
                destruct(ob);
        return 1;
}
