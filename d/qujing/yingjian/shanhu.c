//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.3
//  /d/qujing/yingjian/shanhu.c

inherit ROOM;

void create ()
{
  set ("short", "ɺ����");
  set ("long", @LONG

�����澡��Щ��ʵ�ɺ��������۾��������ˡ�

LONG);

  set("exits", ([
        "up" : __DIR__"jiandi2",
      ]));
      set("objects", ([
        "/d/jz/obj/fish": 3,
        __DIR__"npc/long":1,
        ]));
  setup();

}
