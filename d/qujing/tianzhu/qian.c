// create by snowcat.c 12/8/1997

inherit BANK;

void create ()
{
  set ("short", "Ǯׯ");
  set ("long", @LONG

Ǯׯ��һ������С¥��������һ���ң�һ�������������ڵ���
���ġ�������һ���߸ߵ���ɫ��̨���ӹ�̨�ﲻʱ����������
ͭ�����̵���������̨�Ϸ���һյ�͵ƣ�һ��һ�����������ӡ�

LONG);

  set("exits", ([
//        "east"   : __DIR__"jiedao68",
		"north"  : __DIR__"jiedao56",
      ]));
  set("objects", ([
        __DIR__"npc/situ"   : 1,
      ]));

  setup();
}


