// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG

��Ҳ��һ�������˼ң��������沼�õ÷ǳ����ʡ����Ӷ�����
һ��̨�������Ż𣬲�֪����ʲô��ɢ����һ������ζ���ϱ�
����ͨ�����⡣

LONG);

  set("exits", ([
        "out"   : __DIR__"chen2",
      ]));
  set("objects", ([
        __DIR__"npc/people"  : random(2)+3,
        __DIR__"npc/kid"  : random(2),
        __DIR__"npc/ji"  : 1,
      ]));

  setup();
}



