// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "�϶�");
  set ("long", @LONG

�϶��Ｘ���ʯ��������Ƥ֮��Ķ�������Ѩ��������ת��
�������ص����졣�����ʹ������Ϲ�������ʯ�����ı���ͨ��
���ĳ��ڡ�

LONG);

  set("exits", ([
        "north"   : __DIR__"dongmen",
      ]));
  set("objects", ([
        __DIR__"npc/yao1"   : 2,
        __DIR__"npc/jinjiao"   : 1,
      ]));

  setup();
}


