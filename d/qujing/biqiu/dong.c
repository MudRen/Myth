// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "�廪��");
  set ("long", @LONG

һƬ��ϼ����������͵������������ɣ������޺����ͥ��һ
���ǻ����ʳ�������һ����һСƽ�Ź������٣�����Ȫˮ����
������ʯ�����м������֣����廪�ɸ�����

LONG);

  set("exits", ([
        "out"    : __DIR__"zhuang",
      ]));
  set("objects", ([
        __DIR__"npc/yao"    : 5,
      ]));
  setup();
}

