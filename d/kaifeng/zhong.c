//Cracked by Roath
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

���ฮ�������ﴰ�����������ķ���һ�Ŵ����������Χ����һЩ̫
ʦ���Լ�һЩ�輸��������ʹ�á����ߵ���ͨ���ฮ���ţ��ϱ�����
һ��ͨ������������׳���

LONG);

  set("exits", ([
        "east" : __DIR__"yuxiang",
        "north" : __DIR__"bingqi",
        "south" : __DIR__"kuijia",
      ]));
  set("objects", ([
        __DIR__"npc/xiaotong" :  1,
      ]));

  setup();
}


