// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "�ַ�");
  set ("long", @LONG

�ֵ��ϻ��ž�¥�����ƣ���������ʯ�̾͵Ľַ����м�������
�߳����߿������ʯ��·����ȭͷ���ƽ��ʯ���ֵ�����ֱ��
˳���ƶ��������иߵ����¡�

LONG);

  set("exits", ([
        "east"    : __DIR__"zhai1",
        "northeast"    : __DIR__"jie1",
        "northwest"    : __DIR__"jiulou",
        "south"    : __DIR__"jie7",
      ]));
  set("objects", ([
        __DIR__"npc/people"    : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

