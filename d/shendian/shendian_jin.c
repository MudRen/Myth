#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
set ("short", HIW"����"NOR);
set ("long", @LONG
 
������Χ������Ѭ�ĺ�����ģ�����������һ��������
  
LONG);
  set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"shendian",
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
         object chuzi, ob, me;
        me=this_player();
        if( !arg)
                return notify_fail("��Ҫ��ʲô������\n");
 if( !arg || arg!="chu zi" || !(ob=present(arg, me)))
                return notify_fail("��Ҫ�ҷš�\n");
  message_vision("\n$N��$n���ڼ�̨��һ�����ɫ�Ĺ����󣬼�̨������������һ��"+HIY" �� "NOR+"�֡�\n\n", me, ob);
    me->set_temp("shendian/jinmigong","begin");
    me->move("/d/shendian/jin/jinmigong0");
                destruct(ob);
        return 1;
}
