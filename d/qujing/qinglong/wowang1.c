// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

��������ʮ�ָ����ûʣ������ϵ�����յ�����͵ơ���������
һ�㻨��Ƥ�죬���ķ���һ����������Ϻ��ҵض��ż�ֻ��
յ���ѡ�

LONG);

  set("exits", ([
        "southwest"   : __DIR__"tongdao2",
      ]));
  set("objects", ([
        __DIR__"npc/pi1"  : 1,
      ]));

  setup();
}



