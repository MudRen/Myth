// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "ǰ��");
  set ("long", @LONG

ǰ�����ˢһ�£�����ǽ�ڽ�����������һ��̨����ͭ��С��
¯��������һЩ�㡣�����Ǵ����µĴ��ţ����������������
���á�

LONG);

  set("exits", ([
        "west"   : __DIR__"shanmen",
        "east"   : __DIR__"zheng",
      ]));
  set("objects", ([
        __DIR__"npc/monk" : 2,
      ]));
  setup();
}



