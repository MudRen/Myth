// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "ǰ��");
  set ("long", @LONG

ǰ����������������ʯ�ڣ�ʯ��������һ�εε�ˮ�飬������
���̦޺������������һ�����ڣ�ͨ���ţ�������һʯ�Ŷ���
����ȼ������

LONG);

  set("exits", ([
        "west"   : __DIR__"dongmen",
        "east"   : __DIR__"dating",
      ]));
  set("objects", ([
        __DIR__"npc/yao1"   : 3,
      ]));

  setup();
}



