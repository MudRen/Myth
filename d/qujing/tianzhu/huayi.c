// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "���ĸ�");
  set ("long", @LONG

���ĸ���ʮ����֮�ߣ��Ծ���ľ���ͣ����ܻ��Ų�ɫͼ������
�ߵĸ���ͨ��һ�����ȡ�����ɫ������װ諻������紵������
���������嶣�����졣

LONG);

  set("exits", ([
        "west"   : __DIR__"gongyuan",
      ]));
  set("objects", ([
        __DIR__"npc/taijian"   : 1,
      ]));

  setup();
}


