// create by snowcat.c 4/20/1997
// room: /d/eastway/jinshi.c

inherit ROOM;

void create ()
{
  set ("short", "��ʿ��");
  set ("long", @LONG

��ʿ����һ������С�Ĺ㳡����˵�¿ƽ�ʿ���ܴ�֮��Ҫ�ڽ�ʿ
�������̱�����������Ҳ������ī�ͻ㼯�ĵط��������ｻ���ĵ���
�ᡣ�����Ǳ��֣����߿ɿ���һ��������
LONG);

  set("exits", ([
      "north" : __DIR__"beilin1",
      "east"  : __DIR__"wangnan2",
      "south" : __DIR__"wangnan4",
      "west" : __DIR__"xyt",
    ]));
  set("objects", ([
      __DIR__"npc/xiucai"     : 2,
    ]));
  set("outdoors", __DIR__);

  setup();
}






