// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

ɽԭ�����������ľ����д䣬�ߴ����ľ����һ���޼ʸ���
�Ŵ�ء���������бб�غ���һ����ͺͺ��С������ͷ��֪ͨ
��δ���

LONG);

  set("exits", ([
        "northeast"    : __DIR__"qiaolin3",
        "southwest"    : __DIR__"nanpo",
        "southeast"    : __DIR__"qiaolin7",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

