// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "�ڹ�");
  set ("long", @LONG

�ڹ���ʮ�ֿ����������¼�յ���ƣ�����������͡�������
ʯ��һ�����������˺���һ����Ƥ���ӡ�������Ķ�����һ
�����Ρ�

LONG);

  set("exits", ([
        "northeast"   : __DIR__"pian",
      ]));
  set("objects", ([
        __DIR__"npc/shi"   : 1,
      ]));

  setup();
}



