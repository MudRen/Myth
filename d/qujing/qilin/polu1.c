// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "��·");
  set ("long", @LONG

��������һ����·бб���򶫱��������Ѷ�ȥ����ĿԶ���ɼ�ɽɫ
ãã�������죬һ���۷嵲ס��ǣ���֪�Ǻ�ȥ����·�����˺���
����ɫ�Ҵҡ�

LONG);

  set("exits", ([ 
    "eastup" : __DIR__"polu2",
    "southwest" : "/d/qujing/zhuzi/tian4",
  ]));
  set("outdoors", __DIR__"");
  setup();
}
