inherit ROOM;

#include <ansi.h>

void create ()
{
  set ("short","���ϸ��¥�����㡪��÷����");
  set ("long", MAG@LONG


                             ɽ   ԰   С   ÷




    �ڷ�ҡ���������ռ��������С԰          ����ֻ������̨��˭���ϴ�����

    ��Ӱ��бˮ��ǳ�����㸡���»ƻ�          ѩ��ɽ�к�˪�䣬��������������

    ˪��������͵�ۣ��۵���֪�϶ϻ�          ������Ӱ�����񣬴��ڲ���ĮĮ̦

    ����΢�������򣬲���̴�干����          ��ȥ�����޺��ϣ������ż��ؿ�




LONG NOR);

  set("exits",([
  "up" : __DIR__"qingfenglou4",
  "down" : __DIR__"qingfenglou2",
  ]));
//set("objects", ([ __DIR__"" : 1, ]));
  set("outdoors", 0);
 set("no_fight", 1);
  set("no_magic", 1);
  set("no_clean_up", 1);
  setup();
}
