// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "�ַ�");
  set ("long", @LONG

��������ʯ�̾͵Ľַ����м��������߳����߿������ʯ��·
����ȭͷ���ƽ��ʯ���ֵ�����ֱ��˳�ŵ��ƶ��������иߵ�
���¡�

LONG);

  set("exits", ([
        "southwest"    : __DIR__"jie4",
        "east"    : __DIR__"jie2",
      ]));
  set("objects", ([
        __DIR__"npc/people"    : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

