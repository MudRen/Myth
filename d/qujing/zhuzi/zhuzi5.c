// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "���Ͻ�");
  set ("long", @LONG

���Ϲ������Ĵ�����ɸ���ɽ����������ʯ�̳ɣ���ͨ����������
�������Կ������Ϲ��Ĺ�¥��������һ����Ӫ���ϱ߾������Ϲ��Ļ�
�����š�

LONG);
  set("exits", ([ 
    "south" : __DIR__"gongmen",
    "north" : __DIR__"zhuzi4",
    "east" : __DIR__"bingying",
  ]));
  set("objects", ([
    __DIR__"npc/people" : 2,
  ]));
  set("outdoors", __DIR__"");
  setup();
}
