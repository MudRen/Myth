// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "����");
  set ("long", @LONG

һ����������ǽ�ߣ���̶ѷ�����ߡ�������һ����������ֻˮͰ
�����Աߡ���ǽ��һ���ӣ�����һЩ�����ϸ��ꡣ

LONG);

  set("exits", ([ 
    "west" : __DIR__"huitong",
  ]));
  setup();
}
