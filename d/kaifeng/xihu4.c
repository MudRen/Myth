//Cracked by Roath
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "����·");
  set ("long", @LONG

һ��С·���ź����������ƣ����ߵĺ�ˮ����һ�㣬�紵����ˮ����
����΢�����ں�ˮ�ϻζ��ų����ĵ�Ӱ����ʱ��ݺ����������������
�����Ŀ�������

LONG);

  set("exits", ([
        "northwest" : __DIR__"xihu2",
        "south" : __DIR__"xihu6",
        "east" : __DIR__"guting1",
      ]));

  set("outdoors", __DIR__);

  setup();
}


