// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "�ַ�");
  set ("long", @LONG

�㳡�ı�������ʯ�̾͵Ľַ����м��������߳����߿������
ʯ��·����ȭͷ���ƽ��ʯ���ֵ�����ֱ��˳���ƶ������и�
�����£����߿ɼ����̣�������һЩլԺ��

LONG);

  set("exits", ([
        "north"    : __DIR__"jie7",
        "southeast"    : __DIR__"jinqi",
        "southwest"    : __DIR__"xiaozi",
      ]));
  set("objects", ([
        __DIR__"npc/people"    : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

