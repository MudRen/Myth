inherit ROOM;

#include <ansi.h>

void create ()
{
  set ("short","���ϸ��¥���Ĳ㡪��ӣ����");
  set ("long", BLU@LONG




                         ��      ��




               ������̬Ū���磬÷�����������

               �ִ�������Ұˮ����ʱ���ǽ�����

               ����ҹ�������ڣ�Ⱦ����֬������

               ʫ������Ϊ�������������ƺ���



               һ�����һ��籣���������������

               ��֪֯Ů�����£���������֯����







LONG NOR);

  set("exits",([
  "up" : __DIR__"qingfenglou5",
  "down" : __DIR__"qingfenglou3",
  ]));
//set("objects", ([ __DIR__"" : 1, ]));
 set("no_fight", 1);
  set("no_magic", 1);
  set("outdoors", 0);
  set("no_clean_up", 1);
  setup();
}
