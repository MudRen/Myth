// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "ʯ��");
  set ("long", @LONG

ʯ���ڴ���һ���ת�����ߵ�ʯ���ϳ��ź�ɫ�ĵ��£�������
�����档���Ͽӿ����ݣ����ż�����ˮ��ʯ�ȵ�����ͨ������
�����ڵ

LONG);

  set("exits", ([
        "north"   : __DIR__"shilang1",
        "southwest"   : __DIR__"neidian",
      ]));
  set("objects", ([
        __DIR__"npc/yao2"   : 4,
      ]));

  setup();
}



