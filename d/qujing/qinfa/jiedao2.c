// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "�ֵ�");
  set ("long", @LONG

�ֵ��������߻����̵����̣�����סլͥԺ��ǽ�������ٻ�
���ݡ����ϸ�ɫ����������������Ϊ���֣�������Ǭ��������
����һ���̵����ơ�

LONG);

  set("exits", ([
        "north"    : __DIR__"bupu",
        "west"    : __DIR__"jiedao1",
        "east"    : __DIR__"qiankun",
      ]));
  set("objects", ([
        __DIR__"npc/people"    : 2,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

