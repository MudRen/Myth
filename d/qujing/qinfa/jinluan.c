// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "���ǵ�");
  set ("long", @LONG

�˵�Ϊ���������ͻ������ĳ����������������һ��������
̨�ף�ÿһ��̨�������Ҹ�һ�Խ�����ȼ����������������
�Ĵ���ͨ����⣬��������������ͨ���ڡ�

LONG);

  set("exits", ([
        "west"    : __DIR__"gongmen",
        "east"    : __DIR__"longgong",
      ]));
  set("objects", ([
        __DIR__"npc/taijian"    : 2,
      ]));
  setup();
}

