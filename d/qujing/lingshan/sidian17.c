//Cracked by Roath
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "�µ�");
  set ("long", @LONG

�µ�����ϼ���������Ƿ��������Ͻ������崮�������΢�ζ�
�����죬����һƬ�����������ơ��������ﲻʱ�Ӹ�������
�����о���������

LONG);

  set("exits", ([
        "south"   : __DIR__"sidian27",
        "west"   : __DIR__"sidian16",
      ]));
  set("objects", ([
        __DIR__"npc/monk" : 1,
     ]));

  setup();
}

