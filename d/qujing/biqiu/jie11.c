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
        "northwest"    : __DIR__"jie10",
        "southeast"    : __DIR__"jie12",
        "west"    : __DIR__"daochang",
      ]));
  set("objects", ([
        __DIR__"npc/people"    : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

