// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

��������𲻶ϣ����ݷ���һ����ľ�㰸��������ǩͲ��¯��
��¯����ż����㣬����Ʈ��һ˿˿�����̡���������ٽ֣�
ʱ��ʱ����ͽ���������

LONG);

  set("exits", ([
        "west"   : __DIR__"xiaojie2",
      ]));
  set("objects", ([
        __DIR__"npc/keeper"   : 1,
      ]));

  setup();
}


