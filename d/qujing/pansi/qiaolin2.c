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
        "northwest"    : __DIR__"qiaolin1",
        "southeast"    : __DIR__"qiaolin4",
        "eastdown"    : __DIR__"ling6",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

