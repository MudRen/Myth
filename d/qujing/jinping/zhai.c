// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "ի��");
  set ("long", @LONG

ի�����Ǻܴ�ǽ������һ����̨�������ջ������շ���ˣ�
�����ǽ����һ�Կ�ľͰ����ֻ�ղ����ի��������������
ľ�����������ʡ�

LONG);

  set("exits", ([
        "northwest"   : __DIR__"xiaolu",
      ]));
  set("objects", ([
        __DIR__"npc/monk" : 2,
      ]));

  setup();
}



