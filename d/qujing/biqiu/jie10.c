// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "�ַ�");
  set ("long", @LONG

�ַ�����·������ʯ�̾͵Ľַ����м��������߳����߿����
��ʯ��·����ȭͷ���ƽ��ʯ���ֵ�����ֱ��˳�ŵ��ƶ�����
·����һţ��ݵ����ơ�

LONG);

  set("exits", ([
        "northeast"    : __DIR__"jie8",
        "southeast"    : __DIR__"jie11",
        "east"    : __DIR__"niurou",
      ]));
  set("objects", ([
        __DIR__"npc/people"    : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

