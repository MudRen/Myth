// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "��ͤ");
  set ("long", @LONG

����һ���ɫ�߶���˫���ͤ��ͤ���ϵ��ŷɷ����£�ͤ���
ľ���Ƿ�������ͼ����ͤ��������һʮ�������ȣ�ͨ���е�
����԰��

LONG);

  set("exits", ([
        "west"   : __DIR__"yuhua",
        "north"   : __DIR__"hou4",
      ]));
  set("objects", ([
        __DIR__"npc/taijian"   : 2,
      ]));

  setup();
}


