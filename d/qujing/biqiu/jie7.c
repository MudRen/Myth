// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "�ַ�");
  set ("long", @LONG

���ٳ��ţ���������ʯ�̾͵Ľַ����м��������߳����߿��
����ʯ��·����ȭͷ���ƽ��ʯ���ֵ�����ֱ��˳���ƶ�����
�иߵ����¡����߿ɼ�����լԺ��

LONG);

  set("exits", ([
        "west"    : __DIR__"ximen",
        "east"    : __DIR__"zhai2",
        "north"    : __DIR__"jie4",
        "south"    : __DIR__"jie9",
      ]));
  set("objects", ([
        __DIR__"npc/people"    : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

