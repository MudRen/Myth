//Cracked by Roath
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "��ɽ��");
  set ("long", @LONG

��ɽ��������ϼ�ɺ���ǧ�������������Ϲ����������ɷ���
�У���ʯ�β�����������滨����������֥��ޥ�����Ǹ���
���������¹֮ʤ�ء�

LONG);

  set("exits", ([
        "eastdown"   : __DIR__"lingyun1",
        "south"   : __DIR__"siqian",
      ]));
  set("objects", ([
        __DIR__"npc/youpo" : 4,
      ]));
  set("outdoors", __DIR__);

  setup();
}



