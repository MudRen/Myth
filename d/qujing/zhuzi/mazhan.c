// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "��ջ");
  set ("long", @LONG

��ջΪԶ�������Ŀ���׼������Ϣ���Σ�ջ��ʮ�ֿ���ǽ����һ
˨����������һЩ�տյ���ۼ��������רΪ�ڴ���ŵĿ�����
�ṩ���㡣

LONG);

  set("exits", ([ 
    "south" : __DIR__"tian3",
    "north" : __DIR__"beixia6",
  ]));
  set("objects", ([
    __DIR__"npc/horse" : 1,
  ]));
  setup();
}
