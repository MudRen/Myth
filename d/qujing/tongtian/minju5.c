// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG

�����ʮ�����֣����Ŵ�ľ����ƴ��һ����Χ�������ӵ��ӣ�
�������ڴ���һ��Χ����������֪��̸ʲô���ݽǵ�������
����ˮ����֨֨��ˮ�졣

LONG);

  set("exits", ([
        "out"   : __DIR__"chen3",
      ]));
  set("objects", ([
        __DIR__"npc/people"  : random(3)+3,
      ]));

  setup();
}



