// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "�ַ�");
  set ("long", @LONG

�ֵ��Ե��������ƹ���·������ʯ�̾͵Ľַ����м�������
�߳����߿������ʯ��·�����ǵ�ƽ��ʯ���ֵ�˳�ŵ��ƶ�
�������ߵĵ����ﲻʱ����������

LONG);

  set("exits", ([
        "northwest"    : __DIR__"jie11",
        "south"    : __DIR__"nanmen",
      ]));
  set("objects", ([
        __DIR__"npc/people"    : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

