//Room: gaotai.c ���ҹ���̨
//lpg 19991005

#include <ansi.h>
inherit ROOM;

void create()
{
      set("short","���ҷ��̨");
      set("long",@LONG
�����Ǿ������ҷ��̨����̨�����²࣬������Ԩ����ɲ⡣ɽ���
����������棬�پ����ϴ󿪡�
    �䵱���佣�����������佣�����������е��Ӱ������ϱ��е�ľ��
�𡢻�ˮ������λ���������Ե��Ӱ�Ǭ�����������롢�㡢���ޡ��Ұ�
���졢�ء�ˮ���𡢷硢�ס�ɽ�������С�
LONG);
      set("objects", ([
           __DIR__"npc/bagua": 2,
           __DIR__"npc/wuxing": 2,
           __DIR__"npc/yan": 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "northdown" : __DIR__"nanyanfeng",
      ]));
      set("outdoors", "wudang");
//      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
