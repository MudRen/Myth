// Room: come to baigudong.c  writted by smile 12/10/1998

inherit ROOM;

void create ()
{
  set ("short", "��Ƥ�㳡");
  set ("long", @LONG

  ����ͻȻתŨ����ζ���أ�����Ѫ���߰ߣ��㳡������
����׮�ӣ�����׮���ϰ��˸�Ѫ���ܵ��ˣ���ϸһ������
Ŀȫ�ǣ����ϵ�Ƥ�Ѿ��������ˡ�����С�����ڵ��ϣ���
��һ����Ƥ�����������죬��֪��˵Щʲô��

LONG);

  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 1 */
  "northeast":__DIR__"banshanpo",
  "eastup" : __DIR__"dongting",
]));

  set("objects",([
     __DIR__"obj/renpi":1,
     __DIR__"npc/xiaoyao":4,
                ]));
  setup();
}






