// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "�ַ�");
  set ("long", @LONG

�ַ���ͣ�������ֵ���·������ʯ�̾͵Ľַ����м�������
�߳����߿������ʯ��·����ȭͷ���ƽ��ʯ���ֵ�����ֱ��
˳�ŵ��ƶ��������иߵ����£��ϱ���һ���ơ�

LONG);

  set("exits", ([
        "west"    : __DIR__"jie2",
        "east"    : __DIR__"jinting",
        "south"    : __DIR__"caipu",
        "north"    : __DIR__"yaopu",
        "southeast"    : __DIR__"jie5",
      ]));
  set("objects", ([
        __DIR__"npc/people"    : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

