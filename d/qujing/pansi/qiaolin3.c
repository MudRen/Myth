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
        "east"    : __DIR__"qiaolin4",
        "southwest"    : __DIR__"qiaolin5",
        "west"    : __DIR__"shiqiao",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

