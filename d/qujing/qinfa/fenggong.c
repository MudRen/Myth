// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "�﹬");
  set ("long", @LONG

�﹬�����ܹ��Ż���������������ʰ������������������
����ͷ�β�ȡ�������һ���������λ���������õ���ԧ���
˿���졣

LONG);

  set("exits", ([
        "west"    : __DIR__"longgong",
        "north"    : __DIR__"qingong1",
        "south"    : __DIR__"qingong2",
      ]));
  set("objects", ([
        __DIR__"npc/queen"    : 1,
      ]));
  set("sleep_room",1);
  set("if_bed",1);
  setup();
}

