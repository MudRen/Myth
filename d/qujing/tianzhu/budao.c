// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

��������һ���ɾ��Ĵ����ӣ�����ǰ��Ϊ�����ţ����ŷ���һ
һ��һ�ŵ�ľ���ӡ���������̨�Ϸ���һ�������������д��
���˸ߡ�

LONG);

  set("exits", ([
        "east"   : __DIR__"jiedao28",
      ]));

  setup();
}


