// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "�ַ�");
  set ("long", @LONG

һ���������ų�������ڣ�����·������ʯ�̾͵Ľַ����м�
�������߳����߿������ʯ��·����ȭͷ���ƽ��ʯ���ֵ���
��ֱ��˳�ŵ��ƶ��������иߵ����¡�

LONG);

  set("exits", ([
        "west"    : __DIR__"jie5",
        "east"    : __DIR__"dongmen",
      ]));
  set("objects", ([
        __DIR__"npc/people"    : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

