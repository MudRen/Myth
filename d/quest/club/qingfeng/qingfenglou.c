inherit ROOM;

#include <ansi.h>

void create ()
{
  set ("short","���ϸ��¥");
  set ("long", HIC@LONG
  
                ��  ��  ϸ  ��  ¥

�����ǡ����ϸ��¥������̳���ã����и�����ţ���������ɾ���
��¯�ٳ��������㣬�������˾���һ��ƽʱ�����ϸ��¥�İ���
��ϲ�����������һ�ã��л��ҳ������ʱ������ش����Ҳ��
������С�

LONG NOR);

  set("exits",([
  "out" : "/d/city/center",
  "enter" : __DIR__"qingfenglou1",
//   "enter" : __DIR__"woshi",
  ]));
set("objects", ([ /* sizeof() == 1 */
                "/u/cigar/npc/xiaotong" : 1,
                "/u/cigar/npc/xiaotong" : 2,
        ]));
//set("objects", ([ __DIR__"" : 1, ]));
  set("no_fight", 1);
  set("no_magic", 1);
  set("no_time", 1);
  set("outdoors", 0);
  set("no_clean_up", 1);
  setup();
}
