
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIW"����̶"NOR);
        set("long", @LONG

ӳ������������һ̶ɢ���ź�������ˮ��һ��ʯ��
���Ƶ���̶ˮ���ȥ������ˮ�£���˵��ȫ����
ˮ��������ָ��һ��ˮ�涼���ú��񶳳��˱���һ
��......

LONG);
  set("exits", ([
         "out" : __DIR__"houting.c",
        ]));
  set("outdoors","hfd");
  setup();
}
void init()
{
        add_action("do_dive","dive");
}

int do_dive()
{
        object me = this_player();
        object zhou;
       if(( !(zhou=present("bishui zhou", me))
       ||(string)zhou->query("unit")!="��" ) )
       return notify_fail("��һ���������������ˮ�У�����\n"+
       "\n��û�����ͱ���ð�����ֻ�øϽ����ϰ�����\n");

        message_vision(HIY "$N����һԾ�������˺�̶֮�С�\n" NOR, me);
        me->move(__DIR__"shuidi1");
        message_vision(HIY "$N��̶������������\n"NOR,me);
        return 1;
}

