inherit ROOM;

#include <ansi.h>

void create ()
{
  set ("short","���ϸ��¥�����㡪��Ĩ����");
  set ("long", HIM@LONG





                      С����������


              ����Ҷ��ѩ�⺮��������Ѭ��ľ��

              ��ֲС�ṩ�������������ڰٻ���



              ���������С�⣬����ԭ����Ǧ��

              ����͵������ȥ������������޻�






LONG NOR);

  set("exits",([
  "up" : __DIR__"qingfenglou7",
  "down" : __DIR__"qingfenglou5",
  ]));
//set("objects", ([ __DIR__"" : 1, ]));
        set("no_fight", 1);
        set("no_magic", 1);
  set("outdoors", 0);
  set("no_clean_up", 1);
  setup();
}
