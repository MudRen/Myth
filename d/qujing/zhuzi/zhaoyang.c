// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "������");
  set ("long", @LONG

����̴��ľ���������ƶ�䣬ǽ��������ͷ׺�ϼ��ǧ�����Ǹ���
��������˿�������Ỻ���Ʈ�ݣ��ּ���Ů�����ʹ�ɽ���������
�߹���

LONG);
  set("exits", ([ 
    "north" : __DIR__"zheng",
    "east" : __DIR__"housan",
  ]));
  set("objects", ([
    __DIR__"npc/taijian" : 1,
    __DIR__"npc/girl" : 2,
  ]));
  setup();
}
