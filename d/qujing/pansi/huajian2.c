// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�������죬�ٲ���ɽ���ϳ��������������ǽ�ˮ������Ʈ����
����䡣���ϴ��������ɫ��԰��·���������Сʯ�ѣ�ϸϸ
�������¶���䡣

LONG);

  set("exits", ([
        "northeast"    : __DIR__"huajian1",
        "north"    : __DIR__"qianhua",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

