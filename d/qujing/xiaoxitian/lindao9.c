// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "�ֵ�");
  set ("long", @LONG

����������������������֦�����������������ǿ�֦��Ҷ����
��ȥ֨֨���졣�ֵ���������������ɢ��������ˮ����������
���Ͽհ���Ʈɢϼ����������

LONG);

  set("exits", ([
        "north"   : __DIR__"lindao2",
        "east"   : __DIR__"lindao10",
        "southeast"   : __DIR__"lindao11",
      ]));
  set("outdoors", __DIR__);

  setup();
}



