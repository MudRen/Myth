// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "�ַ�");
  set ("long", @LONG

�˴��ֵ���խ��·������ʯ�̾͵Ľַ����м��������߳�����
�������ʯ��·����ȭͷ���ƽ��ʯ���ֵ�����ֱ��˳�ŵ���
���������иߵ����¡�

LONG);

  set("exits", ([
        "west"    : __DIR__"jie1",
        "east"    : __DIR__"jie3",
      ]));
  set("objects", ([
        __DIR__"npc/people"    : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

