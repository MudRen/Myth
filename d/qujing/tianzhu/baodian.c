// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

���Ϲ���һ���𣬷������Χ���㰸��¯����¯����ż���
��������ð���̡���������ż���ɾ������ţ����������
��һ���ſ��ţ�ͨ�����档

LONG);

  set("exits", ([
        "west"   : __DIR__"fang",
        "east"   : __DIR__"siyuan",
        "southeast"   : __DIR__"houyuan",
      ]));
  set("objects", ([
        __DIR__"npc/monk"   : 1,
      ]));

  setup();
}


