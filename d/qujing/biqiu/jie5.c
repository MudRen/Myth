// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "�ַ�");
  set ("long", @LONG

����Ϊ����·�ڣ�����·������ʯ�̾͵Ľַ����м���������
�����߿������ʯ��·����ȭͷ���ƽ��ʯ���ֵ�����ֱ��˳
�ŵ��ƶ��������иߵ����¡�

LONG);

  set("exits", ([
        "northwest"    : __DIR__"jie3",
        "east"    : __DIR__"jie6",
        "south"    : __DIR__"jie8",
      ]));
  set("objects", ([
        __DIR__"npc/people"    : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

