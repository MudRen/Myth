inherit ROOM;

#include <ansi.h>

void create ()
{
  set ("short","���ϸ��¥�ڶ��㡪���ɻ���");
  set ("long", CYN@LONG




                  ��   ��   ��



        �貨���Ӿ��з���Ҳ������ѧ��ױ��

        ����ʮ�ֿ���¶������һ����б����

        �����ѩԪ��Ⱦ����Ҷ��������㡣

        ���ʯ�������ã������ƽ���������





LONG NOR);

  set("exits",([
  "up" : __DIR__"qingfenglou3",
  "down" : __DIR__"qingfenglou1",
  ]));
//set("objects", ([ __DIR__"" : 1, ]));
  set("outdoors", 0);
 set("no_fight", 1);
  set("no_magic", 1);
  set("no_clean_up", 1);
  setup();
}
