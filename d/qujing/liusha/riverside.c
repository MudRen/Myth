//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.7
//  /d/qujing/liusha/dadao1

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "�ӱ�");
  set ("long", @LONG

�ӱ߾��ǿ�ľ���������������Ȼ��һֻ����Ҳû�С�ǰ����
��һ��ʯ������д�š�[1;33m��ɳ��[m���������֣��������ľ����ԡ���
����ɳ�磬��ǧ��ˮ���ëƮ����«�����׳�����ԭ������
���߾���������������

LONG);
  set("exits", ([
        "westup":   "/d/qujing/village/road1",
        "eastdown"  : __DIR__"river",
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
       return notify_fail("��һ����������ˮ�����\n"+
       "\n��û�����ͱ���ð�����ֻ�øϽ����ϰ�����\n");

        message_vision(HIY "$N����һԾ�����������\n" NOR, me);
        me->move(__DIR__"hedi1");
        message_vision(HIY "$N�ӽ�������������\n"NOR,me);
        return 1;
}
