//Cracked by Roath

//  ����֮�� ������
//  by happ@YSZZ 2000.4.6
//  /d/qujing/yunzhan/road5.c

inherit ROOM;

void create ()
{
  set ("short", "�ƴ�");
  set ("long", @LONG

���ϵ���Щ�ɲݣ������Ѿ�������ԭ������ɫ������������
�дˣ��ɸ�С������ڴ˾�ס����Ҫ���������
LONG);

  set("exits", ([
        "south" : __DIR__"in2",
      ]));
  set("objects",([
        __DIR__"npc/lady":1,
        ]));
  set("sleep_room",1);
  setup();
}
