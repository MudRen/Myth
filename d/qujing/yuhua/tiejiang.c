// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

����������Ϊ��󣬿�ǽ��һ�Ŵ��¯������������ͨ��Ļ�
�档���Ӻ������һ��������¯����������ר�ŵ��ش������
�ͱ�����

LONG);

  set("exits", ([
        "east"   : __DIR__"xiaojie2",
      ]));
  set("objects", ([
        __DIR__"npc/tiejiang"  : 1,
      ]));

  setup();
}



