//Cracked by Roath
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "��ͤ��");
  set ("long", @LONG

��ͤ��������������������Ϸ�����һ�ŵ����ֱ����У����㡱����
�񡱣����䡱�������֡����ڵƻ�ͨ����˿���ֲ��ϴ����ݴ�������
������Ң����֣�����ͨ����ͤ���ڡ�

LONG);

  set("exits", ([
        "west" : __DIR__"yao4",
        "east" : __DIR__"xianglan",
      ]));
  set("objects", ([
        __DIR__"npc/yahuan" :  2,
      ]));

  setup();
}


