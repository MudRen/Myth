// create by snowcat.c 4/8/1997
// room: /d/westway/yunti.c

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","���ݸ�");
  set ("long", @LONG

���ݸ�λ�ھ�Ȫ�ı�����ɽ�Բ��Ǻܸߡ��ϱ�һ��ʯͷС·��ɽ
�º�ɽ������������ǰ��ɽ������һ��ɽ��������ȫ����ʯͷ��
����ɽ·��ת������ңң�ɼ�ɽ�����棬��֪ͨ���δ���

LONG);

  set("exits", ([
        "enter"     : __DIR__"shandong",
        "southdown" : __DIR__"jiuquan",
        "north" : "/d/qujing/wuzhuang/shanlu1",
      ]));
  set("outdoors", __DIR__);

  setup();
}

int valid_leave (object me, string dir)
{
  if (random(2)==0 && dir=="enter")
  {
    message_vision ("������һ����ʯͷ�죬$N��ɽ����б����������\n",me);
    me->move(__DIR__"jiuquan");
    message_vision ("$N����һ���µײ�ͣ������\n",me);
    call_out ("fall_back",2,me);
    return notify_fail("");
  }
  return 1;
}

void fall_back (object me)
{
  tell_object (me,"���ڵ��ϴ����˼����ӣ�����վ������\n");
}


