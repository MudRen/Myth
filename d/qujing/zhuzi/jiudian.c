// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "�Ƶ�");
  set ("long", @LONG

�������Ѭ�죬����һ�Ǽ��ŷ����������Ǿƹ�������Ŵ�С��
һ�ľ�̳�ӡ�ǽ��д�š������飬���಻�顱��ǽ����Щ���Σ�
һЩ��ò������µľƿ�������������Ϣ��

LONG);

  set("exits", ([ 
    "south" : __DIR__"xi2",
  ]));
  set("objects", ([
"/obj/boss/zhuzi_zui"    : 1,
    "/d/obj/misc/woodtable" : 1,
    "/d/obj/misc/woodseat" : 2,
  ]));
  setup();
}
