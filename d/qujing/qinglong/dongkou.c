// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

ֻ��ɽ�л�Ȼһ��Ʈ�������Ķ��ڣ��������ϴ󿪣���������
�������¶������������ߵĹ�ʯ����������������д�ż�����
�֣�����ɽ��Ӣ����

LONG);

  set("exits", ([
        "southwest"   : __DIR__"shanding",
        "north"   : __DIR__"tongdao1",
      ]));
  set("objects", ([
        __DIR__"npc/yao"  : 1,
      ]));

  setup();
}



