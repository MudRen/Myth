// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

������һ�ϴ�Ķ�Ѩ�����涴���ϲ������ͻ�ѣ��м���ʯ��
ʯ�ʡ��������һ���ű����ܣ����Ķ��Ϸ�����һͨ����ͨ
���⡣

LONG);

  set("exits", ([
        "southeast"   : __DIR__"tongdao1",
      ]));
  set("objects", ([
        __DIR__"npc/yao"  : 1,
      ]));

  setup();
}



