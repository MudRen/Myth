// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "�ֵ�");
  set ("long", @LONG

�ֵ��������߻����̵����̣�����סլͥԺ��ǽ�������ٻ�
���ݡ����ϸ�ɫ����������������Ϊ���֣�����ĵ����ſ�ɹ
��һЩƤ����

LONG);

  set("exits", ([
        "east"    : __DIR__"jiedao5",
        "west"    : __DIR__"pihuopu",
      ]));
  set("objects", ([
        __DIR__"npc/people"    : 2,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

