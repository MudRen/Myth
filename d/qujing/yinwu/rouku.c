// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG

һ�����Ҷ���Ȼ�γɵĶ�Ѩ��������Щ����������������Ƥ��
�ݣ�����һЩ�������Ĺ�ͷ�����ڿ���һ�����ӣ����в���
�������ӡ�

LONG);

  set("exits", ([
        "northwest"    : __DIR__"bopiting",
      ]));
  set("objects", ([
        __DIR__"obj/rou" : 10,
      ]));
  setup();
}

