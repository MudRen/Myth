// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "ʯ��");
  set ("long", @LONG

��������������խ�����Ҷ��Ǵֲڵ�ʯ�ڣ��е�ˮ�������£�
���ڵ��Ϸ������˵��������������й��ߴӶ���б�ս�������
����Ȼ����һ��ʯ�ڡ�

LONG);

  set("exits", ([
        "northwest"   : __DIR__"shimen",
        "south"   : __DIR__"shilang2",
      ]));
  set("objects", ([
        __DIR__"npc/yao2"   : 3,
      ]));

  setup();
}



