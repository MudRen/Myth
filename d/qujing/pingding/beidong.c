// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�������濿ǽ�ĵط����ż����ʯͷ��ʯͷ�ѱ�Ѭ����ڣ���
�����һ�ڴ�������ʯͷ�߷���ɽ�񣬸ɲݵȡ����Ϸ���һ��
��ͨ���š�

LONG);

  set("exits", ([
        "southwest"   : __DIR__"dongmen",
      ]));
  set("objects", ([
        __DIR__"npc/yao1"   : 3,
        __DIR__"npc/yinjiao"   : 1,
      ]));

  setup();
}


