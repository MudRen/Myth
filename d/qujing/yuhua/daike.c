// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "���͹�");
  set ("long", @LONG

�����ǽӴ�Զ�����ͺ͹���ĵط���ѩ�׵�ǽ�����ż�ֽ����
���ߵ�ǽͷ����һ���衣�ϱ߹��м���ϸ���ʣ��ֱ����ż���
�����Ĵ�ʹ���

LONG);

  set("exits", ([
        "west"   : __DIR__"xiaojie9",
      ]));
  set("objects", ([
        __DIR__"npc/chaiguan"  : 1,
      ]));
  set("valid_startroom",1);
  set("sleep_room",1);
  set("if_bed",1);
  set("no_fight",1);
  set("no_magic",1);
  setup();
}



