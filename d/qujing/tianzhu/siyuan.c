// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "��Ժ");
  set ("long", @LONG

������������Ժ����ż���ǧ���������֦ï�ܽ���Ժ��һ
�뼸����ס����Ժ�ϱ���һԲ������ͨ����Ժ��������и�
̨��ͨ��һ����

LONG);

  set("exits", ([
        "west"   : __DIR__"baodian",
        "north"   : __DIR__"shanmen",
        "south"   : __DIR__"houyuan",
      ]));
  set("objects", ([
        __DIR__"npc/monk"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}


