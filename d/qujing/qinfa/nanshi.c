// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

������һƬסլ���Ϳ͵꣬�����ֵ����߸ߵ͵͵�ʯǽ��ǽΧ
ס���п����������������������ǽ������ԶԶ��ȥ�ɼ��ֵ�
�Ϲ����˵������ƣ��������Կ������С�

LONG);

  set("exits", ([
        "north"    : __DIR__"zhongshi",
        "south"    : __DIR__"jiedao8",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

